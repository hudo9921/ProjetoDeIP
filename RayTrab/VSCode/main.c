
#include "raylib.h"
#include <stdio.h>

const int largura = 1280;
const int altura = 720;

void textura()
{

}

int main() 
{
    int x1 = 0;
    int contador = 0, animar = 0;
    printf("\nXDXDXD\n");
    InitWindow(largura,altura,"teste");
    SetTargetFPS(60);
    Texture2D chao = LoadTexture("img/chao3.png");

    //personagem animação andar1
    Texture2D char_walk1 = LoadTexture("img/char_sprite_parado1.png");
    float frame_largura1 = (float)(char_walk1.width);
    int max_frames1 = 0;
    float timer1 = 0.0f;
    int frame1 = 0;

    int Mapa1[24][16];
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j <24 ; j++)
        {
            Mapa1[i][j]=0;
        }
        
    }

    Vector2 posicao_quadrado = { (float)altura/2+50 , (float)largura/2-50 };

    while (!WindowShouldClose())
    {
        if( (posicao_quadrado.x + 2.0f) <= 60+(24*40) && (posicao_quadrado.x - 2.0f) >= 60+(1*40) &&  (posicao_quadrado.y + 2.0f) <= (16*40) - 20 && (posicao_quadrado.y - 2.0f) >= (1*40) - 20 )
        {
            if (IsKeyDown(KEY_UP))
            {
               posicao_quadrado.y -= 2.0f+4;
               contador += 1;
               animar++; 
            } 
            if (IsKeyDown(KEY_DOWN))
            {
                posicao_quadrado.y += 2.0f+4;
                contador += 2;
                animar++;
            } 
            if (IsKeyDown(KEY_RIGHT))
            {
                posicao_quadrado.x += 2.0f+4;
                contador += 3;
                animar++;
            } 
            if (IsKeyDown(KEY_LEFT))
            {
                posicao_quadrado.x -= 2.0f+4;
                contador += 4;
                animar++;
            } 
            if(IsKeyDown(KEY_UP) && IsKeyDown(KEY_RIGHT))
            {
                posicao_quadrado.y -= 1.0f+2;
                contador += 1;
                animar++; 
                posicao_quadrado.x += 1.0f+2;
            }
            if(IsKeyDown(KEY_UP) && IsKeyDown(KEY_LEFT))
            {
                posicao_quadrado.y -= 1.0f+2;
                contador += 1;
                animar++; 
                posicao_quadrado.x -= 1.0f+2;
            }
            if(IsKeyDown(KEY_DOWN) && IsKeyDown(KEY_RIGHT))
            {
                posicao_quadrado.y += 1.0f+2;
                contador += 2;
                animar++;
                posicao_quadrado.x += 1.0f+2;
            }
            if(IsKeyDown(KEY_DOWN) && IsKeyDown(KEY_LEFT))
            {
                posicao_quadrado.y += 1.0f+2;
                contador += 2;
                animar++;
                posicao_quadrado.x -= 1.0f+2;
            }
            if(IsKeyReleased(KEY_UP))
            {
                UnloadTexture(char_walk1);
                char_walk1 = LoadTexture("img/char_sprite_parado1.png");
                animar = 0;
            }
            if(IsKeyReleased(KEY_DOWN))
            {
                UnloadTexture(char_walk1);
                char_walk1 = LoadTexture("img/char_sprite_parado3.png");
                animar = 0;
            }
            if(IsKeyReleased(KEY_RIGHT))
            {
                UnloadTexture(char_walk1);
                char_walk1 = LoadTexture("img/char_sprite_parado2.png");
                animar = 0;
            }
            if(IsKeyReleased(KEY_LEFT))
            {
                UnloadTexture(char_walk1);
                char_walk1 = LoadTexture("img/char_sprite_parado4.png");
                animar = 0;
            }
        }
        else if ( (posicao_quadrado.x + 2.0f) >= 60+(24*40) )
        {
            posicao_quadrado.x = posicao_quadrado.x - 0.5;
        }
        else if ( (posicao_quadrado.y + 2.0f) >= (16*40) - 20 )
        {
            posicao_quadrado.y = posicao_quadrado.y - 0.5;
        }
        else if ( (posicao_quadrado.x - 2.0f) <= 60+(1*40) )
        {
            posicao_quadrado.x = posicao_quadrado.x + 0.5;         
        }
        else if( (posicao_quadrado.y - 2.0f) <= (1*40) - 20 )
        {
            posicao_quadrado.y = posicao_quadrado.y + 0.5;
        }
        BeginDrawing();

            ClearBackground(WHITE);
            for (int i = 0; i < 16; i++)
            {
                for (int j = 0; j <24 ; j++)
                {
                    DrawTexture(chao,100+(j*40),20+(i*40),RAYWHITE);
                }  
            }
            DrawFPS(30,30);
            if(contador == 1)
            {
                UnloadTexture(char_walk1);
                char_walk1 = LoadTexture("img/char_sprite_andando1.png");
                contador = 0;
            }
            if(contador == 2)
            {
                UnloadTexture(char_walk1);
                char_walk1 = LoadTexture("img/char_sprite_andando2.png");
                contador = 0;
            }
            if(contador == 3)
            {
                UnloadTexture(char_walk1);
                char_walk1 = LoadTexture("img/char_sprite_andando3.png");
                contador = 0;
            }
            if(contador == 4)
            {
                UnloadTexture(char_walk1);
                char_walk1 = LoadTexture("img/char_sprite_andando4.png");
                contador = 0;
            }
            if( animar != 0 )
            {
                timer1 += GetFrameTime();
                if( timer1 >= 0.4f )
                {
                    timer1 = 0.0f;
                    frame1++;
                }
                frame_largura1 = (float)( char_walk1.width/2 );
                max_frames1 = (int)( char_walk1.width / (int)frame_largura1);
                frame1 = frame1 % max_frames1;
                x1 = (frame_largura1*frame1);
            }
            else
            {
                frame_largura1 = (float)(char_walk1.width);
                max_frames1 = 0;
                frame1 = 1;
                x1 = 0;
                animar = 0;
            }   
            Rectangle rectangle_walk1 = { x1, 0, frame_largura1,(float) char_walk1.height };
            Vector2 vector_walk1 = { posicao_quadrado.x, posicao_quadrado.y };
            DrawTextureRec(
                char_walk1,
                rectangle_walk1,
                vector_walk1,
                RAYWHITE);
            contador = 0;
        EndDrawing();
    }

    CloseWindow();
    
    return 0;
}