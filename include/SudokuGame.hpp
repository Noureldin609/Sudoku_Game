#ifndef SUDOKUGAME_HPP
#define SUDOKUGAME_HPP

#include "SudokuBoard.hpp"
#include "SudokuSolver.hpp"
#include <fstream>
class SudokuGame
{
private:
    SudokuBoard board;
    SudokuSolver solver;

public:
    SudokuGame();
    void menu();
};
class FileManager{
    private:
    std::ifstream inputFile;
    std::ofstream outputFile;
    std::string filename;
    public:
    FileManager(const std::string &filename);
    void readFromfile(SudokuBoard &board);
    void writeToFile(const SudokuBoard &board);
};
class InvalidMoveException : public std::exception
{
private:
    std::string message;

public:
    InvalidMoveException()
        : message("Invalid move. That cell might be occupied or the placement breaks Sudoku rules.") {}

    const char *what() const noexcept override
    {
        return message.c_str();
    }
};
class RowColNumException : public std::exception
{
private:
    std::string message;

public:
    RowColNumException()
        : message("Row , column and number must be between 1 and 9.") {}

    const char *what() const noexcept override
    {
        return message.c_str();
    }
};

#endif // SUDOKUGAME_HPP
