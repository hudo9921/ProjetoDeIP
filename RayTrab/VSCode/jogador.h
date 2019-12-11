#include "raylib.h"

#ifndef JOGADOR_H
#define JOGADOR_H


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
    Texture2D char_walk;
    Rectangle rectangle_walk;
    Rectangle Up;
    Rectangle Down;
    Rectangle Right;
    Rectangle Left;
    int item;

}Jogador;

typedef struct
{
    Rectangle colisao[31];
    Rectangle interacao[13];
    int chave;

}Colisao_cenario;


#endif



void personagem_movimentacao( Jogador* jogador , Colisao_cenario* colisao_cenario, int contador[],Portas* porta)
{
    Rectangle C;
    Rectangle E;

    for( int i = 0 ; i < 31 ; i++ )
    {
        if( CheckCollisionRecs( jogador->Up, colisao_cenario->colisao[i] ) )
        {
            C = colisao_cenario->colisao[i];
        }
        if( CheckCollisionRecs( jogador->Right, colisao_cenario->colisao[i]) )
        {
            C = colisao_cenario->colisao[i];
        }
        if( CheckCollisionRecs( jogador->Left, colisao_cenario->colisao[i]) )
        {
            C = colisao_cenario->colisao[i];
        }
        if( CheckCollisionRecs( jogador->Down, colisao_cenario->colisao[i]) )
        {
            C = colisao_cenario->colisao[i];
        }
    }
    for( int i = 0 ; i < 12 ; i++ )
    {
        if( CheckCollisionRecs( jogador->Up, colisao_cenario->interacao[i]) )
        {
            E = colisao_cenario->interacao[i];
        }
    }

    if( !CheckCollisionRecs( jogador->Up, C) && !CheckCollisionRecs( jogador->Right, C) && !CheckCollisionRecs( jogador->Left, C) && !CheckCollisionRecs( jogador->Down, C))
    {
        if ( IsKeyDown(KEY_UP) && !CheckCollisionRecs( jogador->Up, C) && !CheckCollisionRecs( jogador->Right, C) && !CheckCollisionRecs( jogador->Left, C) && !CheckCollisionRecs( jogador->Down, C))
        {
            jogador->posicao_quadrado.y -= 2.0f+2;
            jogador->contador += 1;
            jogador->animar++;
        } 
        if (IsKeyDown(KEY_DOWN) && !CheckCollisionRecs( jogador->Up, C) && !CheckCollisionRecs( jogador->Right, C) && !CheckCollisionRecs( jogador->Left, C) && !CheckCollisionRecs( jogador->Down, C))
        {
            jogador->posicao_quadrado.y += 2.0f+2;
            jogador->contador += 2;
            jogador->animar++;
        } 
        if (IsKeyDown(KEY_RIGHT) && !CheckCollisionRecs( jogador->Up, C) && !CheckCollisionRecs( jogador->Right, C) && !CheckCollisionRecs( jogador->Left, C) && !CheckCollisionRecs( jogador->Down, C))
        {
            jogador->posicao_quadrado.x += 2.0f+2;
            jogador->contador += 3;
            jogador->animar++;
        } 
        if (IsKeyDown(KEY_LEFT) && !CheckCollisionRecs( jogador->Up, C) && !CheckCollisionRecs( jogador->Right, C) && !CheckCollisionRecs( jogador->Left, C) && !CheckCollisionRecs( jogador->Down, C))
        {
            jogador->posicao_quadrado.x -= 2.0f+2;
            jogador->contador += 4;
            jogador->animar++;
        } 
        if(IsKeyDown(KEY_UP) && IsKeyDown(KEY_RIGHT) && !CheckCollisionRecs( jogador->Up, C) && !CheckCollisionRecs( jogador->Right, C) && !CheckCollisionRecs( jogador->Left, C) && !CheckCollisionRecs( jogador->Down, C))
        {
            jogador->posicao_quadrado.y -= 1.0f+1;
            jogador->contador += 1;
            jogador->animar++; 
            jogador->posicao_quadrado.x += 1.0f+1;
        }
        if(IsKeyDown(KEY_UP) && IsKeyDown(KEY_LEFT) && !CheckCollisionRecs( jogador->Up, C)  && !CheckCollisionRecs( jogador->Right, C) && !CheckCollisionRecs( jogador->Left, C) && !CheckCollisionRecs( jogador->Down, C))
        {
            jogador->posicao_quadrado.y -= 1.0f+1;
            jogador->contador += 1;
            jogador->animar++; 
            jogador->posicao_quadrado.x -= 1.0f+1;
        }
        if(IsKeyDown(KEY_DOWN) && IsKeyDown(KEY_RIGHT) && !CheckCollisionRecs( jogador->Up, C) && !CheckCollisionRecs( jogador->Right, C) && !CheckCollisionRecs( jogador->Left, C) && !CheckCollisionRecs( jogador->Down, C))
        {
            jogador->posicao_quadrado.y += 1.0f+1;
            jogador->contador += 2;
            jogador->animar++;
            jogador->posicao_quadrado.x += 1.0f+1;
        }
        if(IsKeyDown(KEY_DOWN) && IsKeyDown(KEY_LEFT) && !CheckCollisionRecs( jogador->Up, C) && !CheckCollisionRecs( jogador->Right, C) && !CheckCollisionRecs( jogador->Left, C) && !CheckCollisionRecs( jogador->Down, C))
        {
            jogador->posicao_quadrado.y += 1.0f+1;
            jogador->contador += 2;
            jogador->animar++;
            jogador->posicao_quadrado.x -= 1.0f+1;
        }
        if(IsKeyReleased(KEY_UP) && !CheckCollisionRecs( jogador->Up, C) && !CheckCollisionRecs( jogador->Right, C) && !CheckCollisionRecs( jogador->Left, C) && !CheckCollisionRecs( jogador->Down, C))
        {
            UnloadTexture(jogador->char_walk);
            jogador->char_walk = LoadTexture("img/prisioneiro_pose02.png");
            jogador->animar = 0;
        }
        if(IsKeyReleased(KEY_DOWN) && !CheckCollisionRecs( jogador->Up, C) && !CheckCollisionRecs( jogador->Right, C) && !CheckCollisionRecs( jogador->Left, C) && !CheckCollisionRecs( jogador->Down, C))
        {
            UnloadTexture(jogador->char_walk);
            jogador->char_walk = LoadTexture("img/prisioneiro_pose01.png");
            jogador->animar = 0;
        }
        if(IsKeyReleased(KEY_RIGHT) && !CheckCollisionRecs( jogador->Up, C) && !CheckCollisionRecs( jogador->Right, C) && !CheckCollisionRecs( jogador->Left, C) && !CheckCollisionRecs( jogador->Down, C))
        {
            UnloadTexture(jogador->char_walk);
            jogador->char_walk = LoadTexture("img/prisioneiro_pose03.png");
            jogador->animar = 0;
        }
        if(IsKeyReleased(KEY_LEFT) && !CheckCollisionRecs( jogador->Up, C) && !CheckCollisionRecs( jogador->Right, C) && !CheckCollisionRecs( jogador->Left, C) && !CheckCollisionRecs( jogador->Down, C))
        {
            UnloadTexture(jogador->char_walk);
            jogador->char_walk = LoadTexture("img/prisioneiro_pose04.png");
            jogador->animar = 0;
        }
    }
    if( CheckCollisionRecs( jogador->Up, C) )
    {
        jogador->posicao_quadrado.y = jogador->posicao_quadrado.y - (2.0f+8)*-1;
        UnloadTexture(jogador->char_walk);
        jogador->char_walk = LoadTexture("img/prisioneiro_pose02.png");
        jogador->animar = 0;
    }
    if( CheckCollisionRecs( jogador->Right, C) )
    {
        jogador->posicao_quadrado.x = jogador->posicao_quadrado.x + (2.0f+8)*-1;
        UnloadTexture(jogador->char_walk);
        jogador->char_walk = LoadTexture("img/prisioneiro_pose03.png");
        jogador->animar = 0;
    }
    if( CheckCollisionRecs( jogador->Left, C) )
    {
        jogador->posicao_quadrado.x = jogador->posicao_quadrado.x - (2.0f+8)*-1;
        UnloadTexture(jogador->char_walk);
        jogador->char_walk = LoadTexture("img/prisioneiro_pose04.png");
        jogador->animar = 0;
    }
    if( CheckCollisionRecs( jogador->Down, C) )
    {
        jogador->posicao_quadrado.y = jogador->posicao_quadrado.y + (2.0f+8)*-1;
        UnloadTexture(jogador->char_walk);
        jogador->char_walk = LoadTexture("img/prisioneiro_pose01.png");
        jogador->animar = 0;
    }
    if( CheckCollisionRecs( jogador->Up, E) && IsKeyDown(KEY_E))
    {
        contador[1] += 1;
        for( int i = 0 ; i < 12 ; i++ )
        {
            if( CheckCollisionRecs( jogador->Up, colisao_cenario->interacao[i]) && colisao_cenario->chave == ( i + 1 ) && IsKeyDown(KEY_E) )
            {
                jogador->item += 1;
                colisao_cenario->chave = 0;
            }
        }
    }
    else if( CheckCollisionRecs( jogador->Up, E) )
    {
        contador[0] += 1;
    }
    if( jogador->item == 1 && CheckCollisionRecs( jogador->Up, colisao_cenario->interacao[12]) && IsKeyDown(KEY_E) ) 
    {
        contador[2] += 1;
        jogador->item = 0;
        porta->estadoDaPorta=-porta->estadoDaPorta;
        
        
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

    jogador->rectangle_walk.x = jogador->x;
    jogador->rectangle_walk.y = 0;
    jogador->rectangle_walk.width = jogador->frame_largura;
    jogador->rectangle_walk.height = (float) jogador->char_walk.height;

    DrawTextureRec(
        jogador->char_walk,
        jogador->rectangle_walk,
        jogador->posicao_quadrado,
        RAYWHITE);;
}
