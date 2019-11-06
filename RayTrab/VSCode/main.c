#include "raylib.h"
#include <stdio.h>

int main() 
{
    printf("\nTESTE\n");
    int height = 600;
    int width = 800;

    InitWindow(width,height,"Cena1");
    while (!WindowShouldClose())
    {
        BeginDrawing();
                ClearBackground(WHITE);
                DrawRectangle(width/8,height/8,40,30,BLUE);
                DrawCircle((width/2),(height/2),50,RED);
        EndDrawing(); 
    };
    return 0;
}