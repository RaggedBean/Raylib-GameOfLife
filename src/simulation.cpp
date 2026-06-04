#include "simulation.hpp"
#include <iostream>

void Simulation::Draw()
{
    grid.Draw();
}

void Simulation::SetValue(int row, int col, int value)
{
    grid.SetValue(row, col, value);
}

int Simulation::CountLiveNeighbors(int row, int col)
{
    int neighbors = 0;
    std::vector<std::pair<int, int>> offsets =
    {
        {-1, -1},
        {0, -1},
        {1, -1},
        {-1, 0},
        {1, 0},
        {-1, 1},
        {0, 1},
        {1, 1},
    };

    std::pair<int, int> center = {row, col};

    for (auto o : offsets)
    {
        int rowNeighbors = row + o.second; // coords in y
        int colNeighbors = col + o.first; // coords in x


        if (rowNeighbors < 0 || rowNeighbors >= grid.GetRows()) // insert grid size
            continue;

        if (colNeighbors < 0 || colNeighbors >= grid.GetColumns()) // insert grid size
            continue;
        

        if (grid.GetValue(rowNeighbors, colNeighbors) == 1) {
             neighbors++;
        }
    }

    return neighbors;
    
}

void Simulation::Update()
{
    bool test = true;
    for (int row = 0; row < grid.GetRows(); row++)
    {
        for (int col = 0; col < grid.GetColumns(); col++)
        {
            int cellValue = grid.GetValue(row, col);
            int neighbors = CountLiveNeighbors(row, col);

            if (cellValue == 1) {
                if (neighbors < 2 || neighbors > 3) { //
                    tempGrid.SetValue(row, col, 0);
                } else {
                    tempGrid.SetValue(row, col, 1);
                }
            }
            else {
                if (neighbors == 3) {
                    tempGrid.SetValue(row, col, 1);
                } else {
                    tempGrid.SetValue(row, col, 0);
                }
            }
        }
    }

    grid = tempGrid;
}
