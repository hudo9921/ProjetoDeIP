#include "raylib.h"

int main() 
{
    int Tela_Largura=1200;
    int Tela_Altura=800;
    int Mapa1[24][16];

    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j <24 ; j++)
        {
            Mapa1[i][j]=0;
        }
        
    }

    SetTargetFPS(60);
    
    InitWindow(Tela_Largura,Tela_Altura,"Cena1");
    while (!WindowShouldClose())
    {
        
        BeginDrawing();
            ClearBackground(WHITE);
            for (int i = 0; i < 16; i++)
                {
                    for (int j = 0; j <24 ; j++)
                        {
                            DrawRectangle(120+(j*40),80+(i*40),50,50,BLACK);
                        }
                    
                }
        EndDrawing();    
    }
    CloseWindow();
    
}