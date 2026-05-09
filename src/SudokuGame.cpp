#include "../include/SudokuGame.hpp"

#include <iostream>
#include <sstream>
SudokuGame::SudokuGame() : board(), solver() {}

void SudokuGame::menu()
{

    solver.solve(board);
    std::cout << "Enter the difficulty level (easy, medium, hard): ";
    std::string difficulty;
    std::cin >> difficulty;

    board.generatePuzzle(difficulty);
    board.printBoard();
    int choice;

    do
    {
        try
        {
            std::cout << "1) Enter a move \n";
            std::cout << "2) Solve automatically  \n";
            std::cout << "3) Load puzzle from file  \n";
            std::cout << "4) Save current puzzle to file  \n";
            std::cout << "5) Exit  \n";

            std::cin >> choice;
            int row, col, num;
            switch (choice)
            {
            case 1:
                std::cout << "Enter row (1-9), column (1-9), and value (1-9) ";
                std::cin >> row >> col >> num;
                if (solver.isvalid(board, row - 1, col - 1, num))
                {
                    std::cout << "Move accepted! " << std::endl;
                    board.setCell(row - 1, col - 1, num);
                }
                else
                {
                    if (row > 9 || row < 1 || col > 9 || col < 1 || num > 9 || num < 1)
                        throw RowColNumException();

                    else
                        throw InvalidMoveException();
                }
                board.printBoard();
                break;
            case 2:
                // Solve automatically
                std::cout << "Puzzle solved! " << std::endl;
                solver.solve(board);
                board.printBoard();
                break;
            case 3:
                // Load puzzle from file
                {
                    std::string filename;
                    std::cout << "Enter filename to load the puzzle: ";
                    std::cin >> filename;
                    FileManager fileManager(filename);
                    fileManager.readFromfile(board);
                }
                break;
            case 4:
                // Save current puzzle to file
                {
                    std::string filename;
                    std::cout << "Enter filename to save the puzzle: ";
                    std::cin >> filename;
                    FileManager fileManager(filename);
                    fileManager.writeToFile(board);
                    std::cout << "Puzzle saved to " << filename << "\n";
                }
                break;
            default:
                break;
            }
        }
        catch (const RowColNumException &e)
        {
            std::cerr << e.what() << '\n';
        }
        catch (const InvalidMoveException &e)
        {
            std::cerr << e.what() << '\n';
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }

    } while (choice != 5);
}

FileManager::FileManager(const std::string &filename) : filename(filename) {};
void FileManager::readFromfile(SudokuBoard &board)
{
    inputFile.open("../Sudoku_Examples/" + filename);
    if (inputFile.is_open())
    {
        
        std::string line;
        int row = 0;

        while (std::getline(inputFile, line) && row < 9)
        {
            std::istringstream iss(line);
            std::string token;
            int col = 0;

            while (iss >> token && col < 9)
            {
                if (token == ".")
                    board.setCell(row, col, 0);
                else
                    board.setCell(row, col, std::stoi(token));

                col++;
            }
            row++;
        }

        inputFile.close();
        board.printBoard();
    }
    else
    {
        throw std::ios_base::failure("Failed to open file for reading: " + filename);
    }
}

void FileManager::writeToFile(const SudokuBoard &board)
{
    outputFile.open("../Saved/" + filename);
    if (outputFile.is_open())
    {
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                int val = board.getCell(i, j);
                if (val == 0)
                    outputFile << ". ";
                else
                    outputFile << val << " ";
            }
            outputFile << "\n";
        }
        outputFile.close();
    }
    else
    {
        throw std::ios_base::failure("Failed to open file for writing: " + filename);
    }
}
