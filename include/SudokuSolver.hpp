#ifndef SUDOKUSOLVER_HPP
#define SUDOKUSOLVER_HPP

#include "SudokuBoard.hpp"

class SudokuSolver
{
private:
    bool findEmptyCell(const SudokuBoard &board, int &row, int &col);

public:
    bool solve(SudokuBoard &board);
    bool isvalid(const SudokuBoard &board ,int row, int col, int num);
    bool inbox(const SudokuBoard &board, int row, int col, int num);
};

#endif // SUDOKUSOLVER_HPP
