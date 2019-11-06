#include "raylib.h"

int main() 
{
    int height = 600;
    int width = 800;

    InitWindow(width,height,"Cena1");
    while (!WindowShouldClose())
    {
        BeginDrawing();
                ClearBackground(WHITE);
                DrawCircle((width/2),(height/2),50,BLUE);
        EndDrawing(); 
    };
    return 0;
}