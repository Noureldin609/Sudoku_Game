#include "../include/SudokuSolver.hpp"
#include "../include/SudokuBoard.hpp"
#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>

std::vector<int> shuffledNumbers()
{
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    static bool seeded = false;
    if (!seeded)
    {
        srand(time(0));
        seeded = true;
    }

    std::random_shuffle(nums.begin(), nums.end(), [](int i)
                        { return rand() % i; });

    return nums;
}

bool SudokuSolver::solve(SudokuBoard &board)
{
    int row, col;
    if (!findEmptyCell(board, row, col))
        return true;

    for (int num : shuffledNumbers())
    {
        if (isvalid(board, row, col, num))
        {
            board.setCell(row, col, num);
            if (solve(board))
                return true;
            board.setCell(row, col, 0);
        }
    }
    return false;
}
bool SudokuSolver::findEmptyCell(const SudokuBoard &board, int &row, int &col)
{
    for (row = 0; row < 9; row++)
    {
        for (col = 0; col < 9; col++)
        {
            if (board.getCell(row, col) == 0)
            {
                return true;
            }
        }
    }
    return false;
}

bool SudokuSolver::inbox(const SudokuBoard &board, int row, int col, int num)
{

    int boxRowStart = ((row) / 3) * 3;
    int colRowStart = ((col) / 3) * 3;
    for (int i = boxRowStart; i < boxRowStart + 3; i++)
    {
        for (int j = colRowStart; j < colRowStart + 3; j++)
        {
            if (board.getCell(i, j) == num)
            {
                return false;
            }
        }
    }
    return true;
}

bool SudokuSolver::isvalid(const SudokuBoard &board, int row, int col, int num)
{
    if (num > 9 || num < 1)
    {
        // std::cout << "Invalid number. Please enter a number between 1 and 9.\n";
        return false;
    }
    for (int i = 0; i < 9; i++)
    {

        if (board.getCell(row, i) == num)
        {

            return false;
        }
    }
    for (int j = 0; j < 9; j++)
    {

        if (board.getCell(j, col) == num)
        {

            return false;
        }
    }

    return inbox(board, row, col, num);
}