#pragma once
#include "grid.hpp"

class Simulation
{
    public:
        Simulation(int width, int height, int cellSize)
        : grid(width, height, cellSize), tempGrid(width, height, cellSize) { grid.FillRandom(); };

        void Draw();
        void Update();
        void SetValue(int row, int col, int value);
        int GetValue(int row,  int col) { return grid.GetValue(row, col); }
        int CountLiveNeighbors(int row, int col);

    private:
        Grid grid;
        Grid tempGrid;
};