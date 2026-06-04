#include "raylib.h"
#include <iostream>

#include "src/simulation.hpp"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;
const int CELL_SIZE = 16;


int main(void)
{
    int FPS = 12;


    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
    SetTargetFPS(FPS);

    Simulation simulation(WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE);

    

    while (!WindowShouldClose())
    {

        // Events

        // Update
        simulation.Update();

        // Drawing
        BeginDrawing();

        ClearBackground(BLACK);
        simulation.Draw();   

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
