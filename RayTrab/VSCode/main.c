
#include "raylib.h"
#include <stdio.h>

//const int largura = 1280;
//const int altura = 720;

typedef struct 
{
    int x;
    int contador;
    int animar;
    float frame_largura;
    int max_frames;
    float timer;
    int frame;
    Vector2 posicao_quadrado;
    Texture2D char_walk

}Jogador;

void personagem_movimentacao( Jogador* jogador )
{
    if( (jogador->posicao_quadrado.x + 2.0f) <= 60+(24*40) && (jogador->posicao_quadrado.x - 2.0f) >= 60+(1*40) &&  (jogador->posicao_quadrado.y + 2.0f) <= (16*40) - 20 && (jogador->posicao_quadrado.y - 2.0f) >= (1*40) - 20 )
    {
        if (IsKeyDown(KEY_UP))
        {
            jogador->posicao_quadrado.y -= 2.0f+4;
            jogador->contador += 1;
            jogador->animar++; 
        } 
        if (IsKeyDown(KEY_DOWN))
        {
            jogador->posicao_quadrado.y += 2.0f+4;
            jogador->contador += 2;
            jogador->animar++;
        } 
        if (IsKeyDown(KEY_RIGHT))
        {
            jogador->posicao_quadrado.x += 2.0f+4;
            jogador->contador += 3;
            jogador->animar++;
        } 
        if (IsKeyDown(KEY_LEFT))
        {
            jogador->posicao_quadrado.x -= 2.0f+4;
            jogador->contador += 4;
            jogador->animar++;
        } 
        if(IsKeyDown(KEY_UP) && IsKeyDown(KEY_RIGHT))
        {
            jogador->posicao_quadrado.y -= 1.0f+2;
            jogador->contador += 1;
            jogador->animar++; 
            jogador->posicao_quadrado.x += 1.0f+2;
        }
        if(IsKeyDown(KEY_UP) && IsKeyDown(KEY_LEFT))
        {
            jogador->posicao_quadrado.y -= 1.0f+2;
            jogador->contador += 1;
            jogador->animar++; 
            jogador->posicao_quadrado.x -= 1.0f+2;
        }
        if(IsKeyDown(KEY_DOWN) && IsKeyDown(KEY_RIGHT))
        {
            jogador->posicao_quadrado.y += 1.0f+2;
            jogador->contador += 2;
            jogador->animar++;
            jogador->posicao_quadrado.x += 1.0f+2;
        }
        if(IsKeyDown(KEY_DOWN) && IsKeyDown(KEY_LEFT))
        {
            jogador->posicao_quadrado.y += 1.0f+2;
            jogador->contador += 2;
            jogador->animar++;
            jogador->posicao_quadrado.x -= 1.0f+2;
        }
        if(IsKeyReleased(KEY_UP))
        {
            UnloadTexture(jogador->char_walk);
            jogador->char_walk = LoadTexture("img/prisioneiro_pose02.png");
            jogador->animar = 0;
        }
        if(IsKeyReleased(KEY_DOWN))
        {
            UnloadTexture(jogador->char_walk);
            jogador->char_walk = LoadTexture("img/prisioneiro_pose01.png");
            jogador->animar = 0;
        }
        if(IsKeyReleased(KEY_RIGHT))
        {
            UnloadTexture(jogador->char_walk);
            jogador->char_walk = LoadTexture("img/prisioneiro_pose03.png");
            jogador->animar = 0;
        }
        if(IsKeyReleased(KEY_LEFT))
        {
            UnloadTexture(jogador->char_walk);
            jogador->char_walk = LoadTexture("img/prisioneiro_pose04.png");
            jogador->animar = 0;
        }
    }
    else if ( (jogador->posicao_quadrado.x + 2.0f) >= 60+(24*40) )
    {
        jogador->posicao_quadrado.x = jogador->posicao_quadrado.x - 0.5;
    }
    else if ( (jogador->posicao_quadrado.y + 2.0f) >= (16*40) - 20 )
    {
        jogador->posicao_quadrado.y = jogador->posicao_quadrado.y - 0.5;
    }
    else if ( (jogador->posicao_quadrado.x - 2.0f) <= 60+(1*40) )
    {
        jogador->posicao_quadrado.x = jogador->posicao_quadrado.x + 0.5;         
    }
    else if( (jogador->posicao_quadrado.y - 2.0f) <= (1*40) - 20 )
    {
        jogador->posicao_quadrado.y = jogador->posicao_quadrado.y + 0.5;
    }
}

void draw_jogador(Jogador* jogador)
{
    if(jogador->contador == 1)
    {
        UnloadTexture(jogador->char_walk);
        jogador->char_walk = LoadTexture("img/prisioneiro_animacao02.png");
        jogador->contador = 0;
    }
    if(jogador->contador == 2)
    {
        UnloadTexture(jogador->char_walk);
        jogador->char_walk = LoadTexture("img/prisioneiro_animacao01.png");
        jogador->contador = 0;
    }
    if(jogador->contador == 3)
    {
        UnloadTexture(jogador->char_walk);
        jogador->char_walk = LoadTexture("img/prisioneiro_animacao03.png");
        jogador->contador = 0;
    }
    if(jogador->contador == 4)
    {
        UnloadTexture(jogador->char_walk);
        jogador->char_walk = LoadTexture("img/prisioneiro_animacao04.png");
        jogador->contador = 0;
    }
    if( jogador->animar != 0 )
    {
        jogador->timer += GetFrameTime();
        if( jogador->timer >= 0.2f )
        {
            jogador->timer = 0.0f;
            jogador->frame++;
        }
        jogador->frame_largura = (float)( jogador->char_walk.width/2 );
        jogador->max_frames = (int)( jogador->char_walk.width / (int)jogador->frame_largura);
        jogador->frame = jogador->frame % jogador->max_frames;
        jogador->x = (jogador->frame_largura*jogador->frame);
    }
    else
    {
        jogador->frame_largura = (float)(jogador->char_walk.width);
        jogador->max_frames = 0;
        jogador->frame = 1;
        jogador->x = 0;
        jogador->animar = 0;
    }   
    Rectangle rectangle_walk = { jogador->x, 0, jogador->frame_largura,(float) jogador->char_walk.height };
    Vector2 vector_walk = { jogador->posicao_quadrado.x, jogador->posicao_quadrado.y };
    DrawTextureRec(
        jogador->char_walk,
        rectangle_walk,
        vector_walk,
        RAYWHITE);;
}

int main() 
{
    //variáveis de tela
    int largura_tela = GetScreenWidth();
    int altura_tela = GetScreenHeight();

    //jogador
    Jogador jogador;
    jogador.x = 0;
    jogador.animar = 0;
    jogador.contador = 0;
    
    printf("\nXDXDXD\n");
    //tela
    InitWindow(largura_tela,altura_tela,"teste");
    SetTargetFPS(60);
    ToggleFullscreen();

    Texture2D chao = LoadTexture("img/chao3.png");
    Texture2D parede01 = LoadTexture("img/paredes01.png");
    Texture2D parede02 = LoadTexture("img/paredes02.png");
    Texture2D parede03 = LoadTexture("img/paredes03.png");
    Texture2D parede04 = LoadTexture("img/paredes04.png");
   
    jogador.posicao_quadrado.x = (float)altura_tela + 500;
    jogador.posicao_quadrado.y = (float)largura_tela + 500;
    jogador.char_walk = LoadTexture("img/prisioneiro_pose02.png");

    int Mapa1[24][16];
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j <24 ; j++)
        {
            Mapa1[i][j]=0;
        }   
    } 

    while (!WindowShouldClose())
    {
        personagem_movimentacao(&jogador);
        
        BeginDrawing();

            ClearBackground(WHITE);
            for (int i = 0; i < 15; i++)
            {
                for (int j = 0; j <24 ; j++)
                {
                    DrawTexture(chao, 100+(j*40) + 100, 20+(i*40) + 100,RAYWHITE);
                }  
            }
            
            DrawFPS(30,30);

            DrawTexture( parede01, 100+(1*40) + 20, (1*40) + 45, RAYWHITE);
            DrawTexture( parede02, 100+(1*40) + 1030, (1*40) + 45, RAYWHITE);
            DrawTexture( parede03, 100+(1*40) + 60, (1*40) + 45, RAYWHITE);
            DrawTexture( parede04, 100+(1*40) + 60, (1*40) + 688, RAYWHITE);

            draw_jogador(&jogador);
            
            jogador.contador = 0;

        EndDrawing();
    }

    CloseWindow();
    
    return 0;
}