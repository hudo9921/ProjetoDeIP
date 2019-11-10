#include "raylib.h"

int main() 
{
    int Tela_Largura=1200;
    int Tela_Altura=800;
    int Mapa1[24][16];
    Vector2 movimento_personagem = {(float)Tela_Altura/2,(float)Tela_Largura/2};
    //textura do chão
    Texture2D chao = LoadTexture("chao3.png");

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
        if( ( movimento_personagem.x + 2.0f ) <= 120+(24*40) - 46 && ( movimento_personagem.x - 2.0f ) >= 120+(1*40) - 35 && ( movimento_personagem.y + 2.0f ) <= 80+(16*40) - 46 && ( movimento_personagem.y - 2.0f ) >= 80+(1*40) - 36 )
        {
            if (IsKeyDown(KEY_RIGHT)) movimento_personagem.x += 2.0f + 4;
            if (IsKeyDown(KEY_LEFT)) movimento_personagem.x -= 2.0f + 4;
            if (IsKeyDown(KEY_UP)) movimento_personagem.y -= 2.0f + 4;
            if (IsKeyDown(KEY_DOWN)) movimento_personagem.y += 2.0f + 4;
        }
        else if( ( movimento_personagem.x + 2.0f ) >= 120+(24*40) - 46)
        {
            movimento_personagem.x = movimento_personagem.x - 1.0;
        }
        else if( ( movimento_personagem.y + 2.0f ) >= 80+(16*40) - 46)
        {
            movimento_personagem.y = movimento_personagem.y - 1.0;
        }
        else if( ( movimento_personagem.x - 2.0f ) <= 120+(1*40) - 35)
        {
            movimento_personagem.x = movimento_personagem.x + 1.0;
        }
        else if( ( movimento_personagem.y - 2.0f ) <= 80+(1*40) - 36)
        {
            movimento_personagem.y = movimento_personagem.y + 1.0;
        }
        
        
        BeginDrawing();
            ClearBackground(WHITE);
            for (int i = 0; i < 16; i++)
            {
                for (int j = 0; j <24 ; j++)
                {
                    //DrawRectangle(120+(j*40),80+(i*40),50,50,BLACK);
                    DrawTexture(chao, 120+(j*40), 80+(i*40), RAYWHITE);
                }  
            }
            DrawFPS(50,50);
            DrawRectangle(movimento_personagem.x,movimento_personagem.y,50,50,RED);
        EndDrawing();    
    }
    CloseWindow();
    UnloadTexture(chao);
    
}