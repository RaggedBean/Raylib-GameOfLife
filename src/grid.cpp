#include <raylib.h>
#include "grid.hpp"

void Grid::Draw()
{
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < columns; col++) {
            Color color;

            if (cells[row][col]) color = {0, 255, 0, 255};
            else color = {50, 50, 50, 255};

            DrawRectangle(row * cellSize, col * cellSize, cellSize - 1, cellSize - 1, color);
        }
    }
}

void Grid::SetValue(int row, int column, int value)
{
    if (row >= 0 && row < rows && column >= 0 && column < columns)
    {
        cells[row][column] = value;
    }
}
