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
        if (IsKeyPressed(KEY_ENTER)) // Start simulation
        {
            if (!simulation.IsRunning())
            {
                simulation.Start();
                SetWindowTitle("Press ENTER to stop the simulation");
            }
            else
            {
                simulation.Stop();
                SetWindowTitle("Press ENTER to start the simulation");
            }
        }

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
