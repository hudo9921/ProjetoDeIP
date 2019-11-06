#include "raylib.h"

int main() 
{
    int Tela_Largura=GetScreenWidth();
    int Tela_Altura=GetScreenHeight();
    SetTargetFPS(60);
    

    InitWindow(Tela_Largura,Tela_Altura,"Cena1");
    while (!WindowShouldClose())
    {
        
        BeginDrawing();
            ClearBackground(WHITE);
            DrawRectangle(GetScreenWidth()/2,GetScreenHeight()/2,40,50,RED);
        EndDrawing();    
    }
    CloseWindow();
    
}