#ifndef SUDOKUBOARD_HPP
#define SUDOKUBOARD_HPP
#include <vector>
#include <string>
class SudokuBoard
{
private:
 
    std::vector<std::vector<int>> board;
   

public:

    SudokuBoard();
    ~SudokuBoard();
    int getEmptyCells() const;
    void printBoard() const;
    const std::vector<std::vector<int>> &getBoard() const;
    void setCell(int row, int col, int value);
    int getCell(int row, int col) const;
    void generatePuzzle(const std::string &difficulty);

    friend class SudokuSolver;
};

#endif // SUDOKUBOARD_HPP