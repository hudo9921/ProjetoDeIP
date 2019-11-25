
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
    Texture2D char_walk;
    Rectangle rectangle_walk;

}Jogador;

typedef struct
{
    Rectangle colisao[30];
    Rectangle interacao[12];

}Colisao_cenario;

void personagem_movimentacao( Jogador* jogador , Rectangle A, Rectangle B[], Rectangle D[], int* contador)
{
    Rectangle C;
    Rectangle E;
    //int direcao_UP = 0, direcao_DOWN = 0, direcao_RIGHT = 0, direcao_LEFT = 0;
    for( int i = 0 ; i < 30 ; i++ )
    {
        if( CheckCollisionRecs( A, B[i]) )
        {
            C = B[i];
        }
    }
    for( int i = 0 ; i < 12 ; i++ )
    {
        if( CheckCollisionRecs( A, D[i]) )
        {
            E = D[i];
        }
    }
    /*if( IsKeyDown(KEY_UP) ) direcao_UP++;
    if( IsKeyDown(KEY_DOWN) ) direcao_DOWN++;
    if( IsKeyDown(KEY_RIGHT) ) direcao_RIGHT++;
    if( IsKeyDown(KEY_LEFT) ) direcao_LEFT++;*/

    if( !CheckCollisionRecs( A, C) )
    { 
        if ( IsKeyDown(KEY_UP) && !CheckCollisionRecs( A, C) )
        {
            jogador->posicao_quadrado.y -= 2.0f+2;
            jogador->contador += 1;
            jogador->animar++;
        } 
        if (IsKeyDown(KEY_DOWN) && !CheckCollisionRecs( A, C))
        {
            jogador->posicao_quadrado.y += 2.0f+2;
            jogador->contador += 2;
            jogador->animar++;
        } 
        if (IsKeyDown(KEY_RIGHT) && !CheckCollisionRecs( A, C))
        {
            jogador->posicao_quadrado.x += 2.0f+2;
            jogador->contador += 3;
            jogador->animar++;
        } 
        if (IsKeyDown(KEY_LEFT) && !CheckCollisionRecs( A, C))
        {
            jogador->posicao_quadrado.x -= 2.0f+2;
            jogador->contador += 4;
            jogador->animar++;
        } 
        if(IsKeyDown(KEY_UP) && IsKeyDown(KEY_RIGHT) && !CheckCollisionRecs( A, C) )
        {
            jogador->posicao_quadrado.y -= 1.0f+1;
            jogador->contador += 1;
            jogador->animar++; 
            jogador->posicao_quadrado.x += 1.0f+1;
        }
        if(IsKeyDown(KEY_UP) && IsKeyDown(KEY_LEFT) && !CheckCollisionRecs( A, C) )
        {
            jogador->posicao_quadrado.y -= 1.0f+1;
            jogador->contador += 1;
            jogador->animar++; 
            jogador->posicao_quadrado.x -= 1.0f+1;
        }
        if(IsKeyDown(KEY_DOWN) && IsKeyDown(KEY_RIGHT) && !CheckCollisionRecs( A, C) )
        {
            jogador->posicao_quadrado.y += 1.0f+1;
            jogador->contador += 2;
            jogador->animar++;
            jogador->posicao_quadrado.x += 1.0f+1;
        }
        if(IsKeyDown(KEY_DOWN) && IsKeyDown(KEY_LEFT) && !CheckCollisionRecs( A, C) )
        {
            jogador->posicao_quadrado.y += 1.0f+1;
            jogador->contador += 2;
            jogador->animar++;
            jogador->posicao_quadrado.x -= 1.0f+1;
        }
        if(IsKeyReleased(KEY_UP) && !CheckCollisionRecs( A, C) )
        {
            UnloadTexture(jogador->char_walk);
            jogador->char_walk = LoadTexture("img/prisioneiro_pose02.png");
            jogador->animar = 0;
        }
        if(IsKeyReleased(KEY_DOWN) && !CheckCollisionRecs( A, C))
        {
            UnloadTexture(jogador->char_walk);
            jogador->char_walk = LoadTexture("img/prisioneiro_pose01.png");
            jogador->animar = 0;
        }
        if(IsKeyReleased(KEY_RIGHT) && !CheckCollisionRecs( A, C))
        {
            UnloadTexture(jogador->char_walk);
            jogador->char_walk = LoadTexture("img/prisioneiro_pose03.png");
            jogador->animar = 0;
        }
        if(IsKeyReleased(KEY_LEFT) && !CheckCollisionRecs( A, C))
        {
            UnloadTexture(jogador->char_walk);
            jogador->char_walk = LoadTexture("img/prisioneiro_pose04.png");
            jogador->animar = 0;
        }
    }
    if ( (CheckCollisionRecs( A, C) && (IsKeyDown(KEY_RIGHT))) || (CheckCollisionRecs( A, C) && (IsKeyReleased(KEY_RIGHT))) )
    {
        jogador->posicao_quadrado.x = jogador->posicao_quadrado.x + (2.0f+8)*-1;
    }
    if ( (CheckCollisionRecs( A, C) && (IsKeyDown(KEY_UP))) || (CheckCollisionRecs( A, C) && (IsKeyReleased(KEY_UP))) )
    {
        jogador->posicao_quadrado.y = jogador->posicao_quadrado.y - (2.0f+8)*-1;
    }
    if ( (CheckCollisionRecs( A, C) && (IsKeyDown(KEY_LEFT))) || (CheckCollisionRecs( A, C) && (IsKeyReleased(KEY_LEFT))) )
    {
        jogador->posicao_quadrado.x = jogador->posicao_quadrado.x - (2.0f+8)*-1;
    }
    if( (CheckCollisionRecs( A, C) && (IsKeyDown(KEY_DOWN))) || (CheckCollisionRecs( A, C) && (IsKeyReleased(KEY_DOWN))) )
    {
        jogador->posicao_quadrado.y = jogador->posicao_quadrado.y + (2.0f+8)*-1;
    }
    if( CheckCollisionRecs( A, E) )
    {
        *contador += 1;
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
    //Rectangle rectangle_walk = { jogador->x, 0, jogador->frame_largura,(float) jogador->char_walk.height };
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
    int contador = 0;

    //camera
    Camera2D camera = { 0 };
    camera.target = (Vector2){ jogador.posicao_quadrado.x + 2.0f+2, jogador.posicao_quadrado.y + 2.0f+2 };
    camera.offset = (Vector2){ largura_tela/2 - 110, altura_tela/2 - 55};
    camera.rotation = 0.0f;
    camera.zoom = 2.0f;
    
    printf("\nXDXDXD\n");
    //tela
    InitWindow(largura_tela,altura_tela,"teste");
    SetTargetFPS(60);
    ToggleFullscreen();

    //texturas
    Texture2D chao = LoadTexture("img/chao3.png");
    Texture2D parede01 = LoadTexture("img/paredes01.png");
    Texture2D parede02 = LoadTexture("img/paredes02.png");
    Texture2D parede03 = LoadTexture("img/paredes03.png");
    Texture2D parede04 = LoadTexture("img/paredes04.png");
    Texture2D parede05 = LoadTexture("img/paredes05.png");
    Texture2D parede06 = LoadTexture("img/paredes06.png");

    Texture2D cela01 = LoadTexture("img/cela01.png");
    Texture2D cela02 = LoadTexture("img/cela02.png");
    Texture2D cela03 = LoadTexture("img/cela03.png");

    Texture2D porta_cela01 = LoadTexture("img/Porta_cela01.png");
    Texture2D porta_cela02 = LoadTexture("img/Porta_cela02.png");
    Texture2D porta_cela03 = LoadTexture("img/Porta_cela03.png");

    Texture2D cama = LoadTexture("img/cama.png");
    Texture2D estante = LoadTexture("img/estante.png");
   
    jogador.posicao_quadrado.x = (float)altura_tela + 500;
    jogador.posicao_quadrado.y = (float)largura_tela + 600;
    jogador.char_walk = LoadTexture("img/prisioneiro_pose02.png");

    //Colisao com o cenario
    Colisao_cenario colisao_cenario;
    {
        //parede 01
        colisao_cenario.colisao[0].x = 100+(1*40) + 20; 
        colisao_cenario.colisao[0].y = (1*40) + 45;
        colisao_cenario.colisao[0].width = parede01.width;
        colisao_cenario.colisao[0].height = parede01.height;
        //parede 02
        colisao_cenario.colisao[1].x = 100+(1*40) + 1030; 
        colisao_cenario.colisao[1].y = (1*40) + 45;
        colisao_cenario.colisao[1].width = parede02.width;
        colisao_cenario.colisao[1].height = parede02.height;
        //parede 03
        colisao_cenario.colisao[2].x = 100+(1*40) + 60; 
        colisao_cenario.colisao[2].y = (1*40) + 45;
        colisao_cenario.colisao[2].width = parede03.width;
        colisao_cenario.colisao[2].height = parede03.height;
        //parede 04
        colisao_cenario.colisao[3].x = 100+(1*40) + 60; 
        colisao_cenario.colisao[3].y = (1*40) + 688;
        colisao_cenario.colisao[3].width = parede04.width;
        colisao_cenario.colisao[3].height = parede04.height;
        //parede 05
        colisao_cenario.colisao[4].x = 100+(1*40) + 735; 
        colisao_cenario.colisao[4].y =  (1*40) + 49;
        colisao_cenario.colisao[4].width = parede05.width;
        colisao_cenario.colisao[4].height = parede05.height;
        //parede 06
        colisao_cenario.colisao[5].x =  100+(1*40) + 735 - 590; 
        colisao_cenario.colisao[5].y =  (1*40) + 49;
        colisao_cenario.colisao[5].width = parede05.width;
        colisao_cenario.colisao[5].height = parede05.height;
        //parede 07
        colisao_cenario.colisao[6].x =  100+(1*40) + 735 - 295; 
        colisao_cenario.colisao[6].y =  (1*40) + 49;
        colisao_cenario.colisao[6].width = parede05.width;
        colisao_cenario.colisao[6].height = parede05.height;
        //parede 08
        colisao_cenario.colisao[7].x =  100+(1*40) + 735 - 295; 
        colisao_cenario.colisao[7].y =  (1*40) + 486;
        colisao_cenario.colisao[7].width = parede05.width;
        colisao_cenario.colisao[7].height = parede05.height;
        //parede 09
        colisao_cenario.colisao[8].x =  100+(1*40) + 735 - 590; 
        colisao_cenario.colisao[8].y =  (1*40) + 486;
        colisao_cenario.colisao[8].width = parede05.width;
        colisao_cenario.colisao[8].height = parede05.height;
        //parede 10
        colisao_cenario.colisao[9].x =  100+(1*40) + 735; 
        colisao_cenario.colisao[9].y =  (1*40) + 486;
        colisao_cenario.colisao[9].width = parede05.width;
        colisao_cenario.colisao[9].height = parede05.height;
        //cela 01
        colisao_cenario.colisao[10].x =  100+(1*40) + 885; 
        colisao_cenario.colisao[10].y =  (1*40) + 250;
        colisao_cenario.colisao[10].width = cela01.width;
        colisao_cenario.colisao[10].height = cela01.height;
        //cela 02
        colisao_cenario.colisao[11].x =  100+(1*40) + 885 - 295; 
        colisao_cenario.colisao[11].y =  (1*40) + 250;
        colisao_cenario.colisao[11].width = cela01.width;
        colisao_cenario.colisao[11].height = cela01.height;
        //cela 03
        colisao_cenario.colisao[12].x =  100+(1*40) + 885 - 590; 
        colisao_cenario.colisao[12].y =  (1*40) + 250;
        colisao_cenario.colisao[12].width = cela01.width;
        colisao_cenario.colisao[12].height = cela01.height;
        //cela 04
        colisao_cenario.colisao[13].x =  100+(1*40) + 885; 
        colisao_cenario.colisao[13].y =  (1*40) + 487;
        colisao_cenario.colisao[13].width = cela01.width;
        colisao_cenario.colisao[13].height = cela01.height;
        //cela 05
        colisao_cenario.colisao[14].x =  100+(1*40) + 885 - 295; 
        colisao_cenario.colisao[14].y =  (1*40) + 487;
        colisao_cenario.colisao[14].width = cela01.width;
        colisao_cenario.colisao[14].height = cela01.height;
        //cela 06
        colisao_cenario.colisao[15].x =  100+(1*40) + 885 - 590; 
        colisao_cenario.colisao[15].y =  (1*40) + 487;
        colisao_cenario.colisao[15].width = cela01.width;
        colisao_cenario.colisao[15].height = cela01.height;
        //cela 07
        colisao_cenario.colisao[16].x =  100+(1*40) + 750; 
        colisao_cenario.colisao[16].y =  (1*40) + 250;
        colisao_cenario.colisao[16].width = cela02.width;
        colisao_cenario.colisao[16].height = cela02.height;
        //cela 08
        colisao_cenario.colisao[17].x =  100+(1*40) + 750 - 295; 
        colisao_cenario.colisao[17].y =  (1*40) + 250;
        colisao_cenario.colisao[17].width = cela02.width;
        colisao_cenario.colisao[17].height = cela02.height;
        //cela 09
        colisao_cenario.colisao[18].x =  100+(1*40) + 750 - 590; 
        colisao_cenario.colisao[18].y =  (1*40) + 250;
        colisao_cenario.colisao[18].width = cela02.width;
        colisao_cenario.colisao[18].height = cela02.height;
        //cela 10
        colisao_cenario.colisao[19].x =  100+(1*40) + 750; 
        colisao_cenario.colisao[19].y =  (1*40) + 487;
        colisao_cenario.colisao[19].width = cela02.width;
        colisao_cenario.colisao[19].height = cela02.height;
        //cela 11
        colisao_cenario.colisao[20].x =  100+(1*40) + 750 - 295; 
        colisao_cenario.colisao[20].y =  (1*40) + 487;
        colisao_cenario.colisao[20].width = cela02.width;
        colisao_cenario.colisao[20].height = cela02.height;
        //cela 12
        colisao_cenario.colisao[21].x =  100+(1*40) + 750 - 590; 
        colisao_cenario.colisao[21].y =  (1*40) + 487;
        colisao_cenario.colisao[21].width = cela02.width;
        colisao_cenario.colisao[21].height = cela02.height;
        //cela 13
        colisao_cenario.colisao[22].x = 175; 
        colisao_cenario.colisao[22].y = 200;
        colisao_cenario.colisao[22].width = cela03.width;
        colisao_cenario.colisao[22].height = cela03.height;
        //porta
        colisao_cenario.colisao[23].x = 238; 
        colisao_cenario.colisao[23].y = 200;
        colisao_cenario.colisao[23].width = porta_cela01.width;
        colisao_cenario.colisao[23].height = porta_cela01.height;
        //estante01
        colisao_cenario.colisao[24].x = 323 + 216; 
        colisao_cenario.colisao[24].y = 123;
        colisao_cenario.colisao[24].width = estante.width;
        colisao_cenario.colisao[24].height = estante.height;
        //estante02
        colisao_cenario.colisao[25].x = 323 + 216 + 295; 
        colisao_cenario.colisao[25].y = 123;
        colisao_cenario.colisao[25].width = estante.width;
        colisao_cenario.colisao[25].height = estante.height;
        //estante03
        colisao_cenario.colisao[26].x = 323 + 216 + 295*2; 
        colisao_cenario.colisao[26].y = 123;
        colisao_cenario.colisao[26].width = estante.width;
        colisao_cenario.colisao[26].height = estante.height;
        //estante04
        colisao_cenario.colisao[27].x = 323 + 216; 
        colisao_cenario.colisao[27].y = 123 + 445;
        colisao_cenario.colisao[27].width = estante.width;
        colisao_cenario.colisao[27].height = estante.height;
        //estante02
        colisao_cenario.colisao[28].x = 323 + 216 + 295; 
        colisao_cenario.colisao[28].y = 123 + 445;
        colisao_cenario.colisao[28].width = estante.width;
        colisao_cenario.colisao[28].height = estante.height;
        //estante03
        colisao_cenario.colisao[29].x = 323 + 216 + 295*2; 
        colisao_cenario.colisao[29].y = 123 + 445;
        colisao_cenario.colisao[29].width = estante.width;
        colisao_cenario.colisao[29].height = estante.height;
        //interacao
        //cama01
        colisao_cenario.interacao[0].x = 323;
        colisao_cenario.interacao[0].y = 123;
        colisao_cenario.interacao[0].width = cama.width;
        colisao_cenario.interacao[0].height = cama.height;
        //cama02
        colisao_cenario.interacao[1].x = 323 + 295;
        colisao_cenario.interacao[1].y = 123;
        colisao_cenario.interacao[1].width = cama.width;
        colisao_cenario.interacao[1].height = cama.height;
        //cama03
        colisao_cenario.interacao[2].x = 323 + 295*2;
        colisao_cenario.interacao[2].y = 123;
        colisao_cenario.interacao[2].width = cama.width;
        colisao_cenario.interacao[2].height = cama.height;
        //cama01
        colisao_cenario.interacao[3].x = 323;
        colisao_cenario.interacao[3].y = 123 + 445;
        colisao_cenario.interacao[3].width = cama.width;
        colisao_cenario.interacao[3].height = cama.height;
        //cama02
        colisao_cenario.interacao[4].x = 323 + 295;
        colisao_cenario.interacao[4].y = 123 + 445;
        colisao_cenario.interacao[4].width = cama.width;
        colisao_cenario.interacao[4].height = cama.height;
        //cama03
        colisao_cenario.interacao[5].x = 323 + 295*2;
        colisao_cenario.interacao[5].y = 123 + 445;
        colisao_cenario.interacao[5].width = cama.width;
        colisao_cenario.interacao[5].height = cama.height;
    }

    Rectangle movimentacao = { jogador.posicao_quadrado.x, jogador.posicao_quadrado.y, jogador.char_walk.width, jogador.char_walk.height};

    int Mapa1[24][16];
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j <24 ; j++)
        {
            Mapa1[i][j] = 0;
        }   
    } 

    while (!WindowShouldClose())
    {
        personagem_movimentacao(&jogador, movimentacao, colisao_cenario.colisao, colisao_cenario.interacao, &contador);

        camera.target.x = jogador.posicao_quadrado.x;
        camera.target.y = jogador.posicao_quadrado.y;
        
        BeginDrawing();

            ClearBackground(WHITE);
            BeginMode2D(camera);
                for (int i = 0; i < 15; i++)
                {
                    for (int j = 0; j <24 ; j++)
                    {
                        DrawTexture(chao, 100+(j*40) + 100, 20+(i*40) + 100,RAYWHITE);
                    }  
                }

                //desenhando cenário
                DrawFPS(30,30);
                {
                    DrawTexture( parede01, 100+(1*40) + 20, (1*40) + 45, RAYWHITE);
                    DrawTexture( parede02, 100+(1*40) + 1030, (1*40) + 45, RAYWHITE);
                    DrawTexture( parede03, 100+(1*40) + 60, (1*40) + 45, RAYWHITE);
                    DrawTexture( parede04, 100+(1*40) + 60, (1*40) + 688, RAYWHITE);
                    DrawTexture( parede05, 100+(1*40) + 735, (1*40) + 49, RAYWHITE);

                    DrawTexture( cela01, 100+(1*40) + 885, (1*40) + 250, RAYWHITE);
                    DrawTexture( cela02, 100+(1*40) + 750, (1*40) + 250, RAYWHITE);
                    DrawTexture( porta_cela03, 100+(1*40) + 845 + 33, (1*40) + 250, RAYWHITE);

                    DrawTexture( parede05, 100+(1*40) + 735 - 295, (1*40) + 49, RAYWHITE);    
                    DrawTexture( cela01, 100+(1*40) + 885 - 295, (1*40) + 250, RAYWHITE);
                    DrawTexture( cela02, 100+(1*40) + 750 - 295, (1*40) + 250, RAYWHITE);
                    DrawTexture( porta_cela03, 100+(1*40) + 845 - 295 + 33, (1*40) + 250, RAYWHITE);

                    DrawTexture( parede05, 100+(1*40) + 735 - 590, (1*40) + 49, RAYWHITE);
                    DrawTexture( cela01, 100+(1*40) + 885 - 590, (1*40) + 250, RAYWHITE);
                    DrawTexture( cela02, 100+(1*40) + 750 - 590, (1*40) + 250, RAYWHITE);
                    DrawTexture( porta_cela03, 100+(1*40) + 845 - 590 + 33, (1*40) + 250, RAYWHITE);

                    DrawTexture( cela01, 100+(1*40) + 885, (1*40) + 487, RAYWHITE);
                    DrawTexture( cela02, 100+(1*40) + 750, (1*40) + 487, RAYWHITE);
                    DrawTexture( porta_cela03, 100+(1*40) + 845 + 33, (1*40) + 487, RAYWHITE);

                    DrawTexture( cela01, 100+(1*40) + 885 - 295, (1*40) + 487, RAYWHITE);
                    DrawTexture( cela02, 100+(1*40) + 750 - 295, (1*40) + 487, RAYWHITE);
                    DrawTexture( porta_cela03, 100+(1*40) + 845 - 295 + 33, (1*40) + 487, RAYWHITE);

                    DrawTexture( cela01, 100+(1*40) + 885 - 590, (1*40) + 487, RAYWHITE);
                    DrawTexture( cela02, 100+(1*40) + 750 - 590, (1*40) + 487, RAYWHITE);
                    DrawTexture( porta_cela03, 100+(1*40) + 845 - 590 + 33, (1*40) + 487, RAYWHITE);

                    DrawTexture( cela03, 175, 200, RAYWHITE);
                    DrawTexture( porta_cela01, 238, 200, RAYWHITE);

                    DrawTexture( parede06, 100+(1*40) + 735 - 590, (1*40) + 486, RAYWHITE);
                    DrawTexture( parede06, 100+(1*40) + 735 - 295, (1*40) + 486, RAYWHITE);
                    DrawTexture( parede06, 100+(1*40) + 735, (1*40) + 486, RAYWHITE);

                    DrawTexture( cama, 323, 123, LIGHTGRAY);
                    DrawTexture( cama, 323 + 295, 123, LIGHTGRAY);
                    DrawTexture( cama, 323 + 295*2, 123, LIGHTGRAY);
                    DrawTexture( cama, 323, 123 + 445, LIGHTGRAY);
                    DrawTexture( cama, 323 + 295, 123 + 445, LIGHTGRAY);
                    DrawTexture( cama, 323 + 295*2, 123 + 445, LIGHTGRAY);

                    DrawTexture( estante, 323 + 216, 123, GRAY);
                    DrawTexture( estante, 323 + 216 + 295, 123, GRAY);
                    DrawTexture( estante, 323 + 216 + 295*2, 123, GRAY);
                    DrawTexture( estante, 323 + 216, 123 + 445, GRAY);
                    DrawTexture( estante, 323 + 216 + 295, 123 + 445, GRAY);
                    DrawTexture( estante, 323 + 216 + 295*2 , 123 + 445, GRAY);
                }

                draw_jogador(&jogador);

                movimentacao.x = jogador.posicao_quadrado.x;
                movimentacao.y = jogador.posicao_quadrado.y;
                movimentacao.width = jogador.char_walk.width;
                movimentacao.height = jogador.char_walk.height;
                if( jogador.animar > 0 )
                {
                    movimentacao.width = jogador.char_walk.width / 2;
                }

                if( contador > 0 )
                {
                    DrawText("Aperte E para procurar.", jogador.posicao_quadrado.x - 40, jogador.posicao_quadrado.y - 20, 10 , RED);
                    contador = 0;
                }
                
                jogador.contador = 0;
            EndMode2D();

        EndDrawing();
    }

    CloseWindow();
    
    return 0;
}