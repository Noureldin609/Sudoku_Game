#include "../include/SudokuBoard.hpp"
#include "../include/SudokuSolver.hpp"
#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib> 
#include <set>

SudokuBoard::SudokuBoard()
{
    board = std::vector<std::vector<int>>(9, std::vector<int>(9, 0));
}

SudokuBoard::~SudokuBoard()
{
}
const std::vector<std::vector<int>> &SudokuBoard::getBoard() const
{
    return board;
}

int SudokuBoard::getEmptyCells() const
{
    int count = 0;
    for (const auto &row : board)
    {
        for (int cell : row)
        {
            if (cell == 0)
            {
                count++;
            }
        }
    }
    return count;
}

void SudokuBoard::printBoard() const
{
    std::cout << "---------------------------------\n";
    for (int i = 0; i < 9; i++)
    {
        if (i > 0 && i % 3 == 0)
        {
            std::cout << "------+-------+------\n";
        }

        for (int j = 0; j < 9; j++)
        {
            if (j > 0 && j % 3 == 0)
            {
                std::cout << "| ";
            }

            if (board[i][j] == 0)
                std::cout << ". ";
            else
                std::cout << board[i][j] << " ";
        }
        std::cout << "\n";
        
    }
    std::cout << "---------------------------------\n";
}

void SudokuBoard::setCell(int row, int col, int value)
{
    board.at(row).at(col) = value;
}

int SudokuBoard::getCell(int row, int col) const
{
    return board.at(row).at(col);
}

void SudokuBoard::generatePuzzle(const std::string &difficulty)
{
     srand(static_cast<unsigned>(time(0)));

    std::cout << "Generating " << difficulty << " Sudoku puzzle...\n";

    int removed = 0;
    if (difficulty == "easy")
    {
        while (removed < 45)
        {
            int row = rand() % 9;
            int col = rand() % 9;
            if (board[row][col] != 0)
            {
                board[row][col] = 0;
                removed++;
            }
        }
    }
    else if (difficulty == "medium")
    {
        while (removed < 51)
        {
            int row = rand() % 9;
            int col = rand() % 9;
            if (board[row][col] != 0)
            {
                board[row][col] = 0;
                removed++;
            }
        }
    }
    else if (difficulty == "hard")
    {
        while (removed < 57)
        {
            int row = rand() % 9;
            int col = rand() % 9;
            if (board[row][col] != 0)
            {
                board[row][col] = 0;
                removed++;
            }
        }
    }
}
