#include "raylib.h"

int main() 
{
    int Tela_Largura=1200;
    int Tela_Altura=800;
    int Mapa1[24][16];
    Vector2 movimento_personagem = {(float)Tela_Altura/2,(float)Tela_Largura/2};

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
        if (IsKeyDown(KEY_RIGHT)) movimento_personagem.x += 2.0f;
        if (IsKeyDown(KEY_LEFT)) movimento_personagem.x -= 2.0f;
        if (IsKeyDown(KEY_UP)) movimento_personagem.y -= 2.0f;
        if (IsKeyDown(KEY_DOWN)) movimento_personagem.y += 2.0f;
        
        BeginDrawing();
            ClearBackground(WHITE);
            for (int i = 0; i < 16; i++)
            {
                for (int j = 0; j <24 ; j++)
                {
                    DrawRectangle(120+(j*40),80+(i*40),50,50,BLACK);
                }  
            }
            DrawFPS(50,50);
            DrawRectangle(movimento_personagem.x,movimento_personagem.y,50,50,RED);
        EndDrawing();    
    }
    CloseWindow();
    
}