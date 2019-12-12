#include "raylib.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "guardas.h"
#include "portas.h"
#include "jogador.h"
#include "cronometro.h"
#include "fase2.h"
#include "fase3.h"


void passouDeFaseUm(Jogador* jogador,Portas* porta,int* estadoFase){
    
    if(jogador->posicao_quadrado.x >= porta->imagem.width &&  jogador->posicao_quadrado.x <= porta->imagem.width+porta->x && jogador->posicao_quadrado.y <= porta->imagem.height/2+porta->y){
        

        *estadoFase=1;
        
        
    }else{
        
        
    *estadoFase=0;        
    }  
    
}



int main() 
{
    
   
    srand(time(NULL));

    int estadoFaseUm=0; //estadoFaseUm=0,jogo continua; estadoFaseUm=1,jogador passou de fase; estadoFaseUm=-1, jogador perdeu a fase; 
    
    int estadoFaseDois=0;
    int estadoFaseTres=0;

    int estadoMenu=0; //0=Menu continua qq coisa diferente o menu sai

    int estadoTelaPerdeu=0;

    int EstadoSelectLVL=0;

    int estadoJogo=0;//0=CarregarMenu. 2=LVLselect,3=CarregarFase1,4=CarregarFase2,5=CarregarFase3,6=CarregarHS 
        
    int frameAtual=0;
    int tempoDoFrame=0;

    //variáveis de tela
    int largura_tela = GetScreenWidth();
    int altura_tela = GetScreenHeight();
    
    int comecoLarguraAreaJogo=200;
    int fimLarguraAreaJogo=1150;
    //
    
    //INICIANDO AS VARIAVEIS DO CRONOMETRO
    
    Cronometro cronometro;
    cronometro.tempo=0;
    cronometro.segundos=0;
    cronometro.minutos=0;
    
    // FIM DAS VARIAVEOS DO CRONOMETRO


    //jogador
    Jogador jogador;
    jogador.x = 0;
    jogador.animar = 0;
    jogador.contador = 0;
    jogador.item = 0;
    int contador[3];
    contador[0] = 0;
    contador[1] = 0;
    contador[2] = 0;

    //camera
    Camera2D camera = { 0 };
    camera.target = (Vector2){ jogador.posicao_quadrado.x + 2.0f+2, jogador.posicao_quadrado.y + 2.0f+2 };
    camera.offset = (Vector2){ largura_tela/2 - 110, altura_tela/2 - 55};
    camera.rotation = 0.0f;
    camera.zoom = 2.0f;
    
    //tela
    InitWindow(largura_tela,altura_tela,"teste");
    SetTargetFPS(60);
    
    InitAudioDevice();
    
    //INICIANDO Musica do Fase
    Music somFase = LoadMusicStream("audios/musicaFases.mp3"); //carrega o som no jogo
    SetMusicVolume(somFase,0.50f);//muda o volume do jogo;
    PlayMusicStream(somFase); //toca a musica
    //FIM INICIANDO MUSICA DA FASE
    
    
    
   //' ToggleFullscreen();
    bool SomLigadoBool=1;
   //Texturas do Menu
    
    Texture2D HighScore = LoadTexture("img/Trofeu.png");
    Rectangle HighScoreClick;
    HighScoreClick.x=0;
    HighScoreClick.y=0;
    HighScoreClick.width=120;
    HighScoreClick.height=120;

    Texture2D SomLigado = LoadTexture("img/soundOnBlack.png");
    Rectangle SomClick;
    SomClick.x=125;
    SomClick.y=0;
    SomClick.width=100;
    SomClick.height=100;

    Texture2D SomDesligado = LoadTexture("img/SoundOffBlack.png");
    Texture2D LogoJogo = LoadTexture("img/Logo_do_jogo.png");
    Texture2D BotaoPlay = LoadTexture("img/BotaoPlay.png");
    Rectangle BotaoPlayClick;
    BotaoPlayClick.x=490;
    BotaoPlayClick.y=590;
    BotaoPlayClick.width=340;
    BotaoPlayClick.height=195;

    Texture2D BG = LoadTexture("img/tela_de_fundo_do_menu.png");

    //Assets da tela perdeu
    Texture2D TelaPerdeu = LoadTexture("img/Tela_Perdeu.png");
    Rectangle TelaPerdeuClick;
    TelaPerdeuClick.x=0;
    TelaPerdeuClick.y=0;
    TelaPerdeuClick.width=1368;
    TelaPerdeuClick.height=1368;

    //Assets Select LvL
    
    


    //vetor do mouse
    Vector2 Mouse={0.0f,0.0f};

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
    Texture2D porta_cela03 = LoadTexture("img/Porta_cela03.png");

    Texture2D cama = LoadTexture("img/cama.png");
    Texture2D estante = LoadTexture("img/estante.png");
    Texture2D mensagem_procurar = LoadTexture("img/mensagem_procurar.png");
    Texture2D procurando = LoadTexture("img/procurando.png");
    Texture2D key = LoadTexture("img/key.png");
    Texture2D chave_encontrada = LoadTexture("img/Chave_encontrada.png");
    
    Texture2D imagemGuardas = LoadTexture("img/guardas.png");


    jogador.posicao_quadrado.x = (float)altura_tela + 500;
    jogador.posicao_quadrado.y = (float)largura_tela + 600;
    jogador.char_walk = LoadTexture("img/prisioneiro_pose02.png");

    
    //INICIANDO GUARADA 1
      Guardas guarda1;
      guarda1.x=comecoLarguraAreaJogo;
      guarda1.y=360;
      guarda1.campoDeVisao=100;
      guarda1.movimento =-5;
      guarda1.imagem=(Rectangle){0.0f,0.0f,imagemGuardas.width/3,imagemGuardas.height/4};
      guarda1.imagem.y=2*imagemGuardas.height/4;   
      guarda1.sentidoCampoDeVisao= -1;
        
    // FIM INICIANDO GURADA 1
    
    
    //INICIANDO GUARADA 2
      Guardas guarda2;
      guarda2.x=fimLarguraAreaJogo-imagemGuardas.width/3;
      guarda2.y=350+imagemGuardas.height/4+50;
      guarda2.campoDeVisao=100;
      guarda2.movimento =5
;
      guarda2.imagem=(Rectangle){0.0f,0.0f,imagemGuardas.width/3,imagemGuardas.height/4};
      guarda2.imagem.y=imagemGuardas.height/4;
      guarda2.sentidoCampoDeVisao =1;
    
    
    // FIM INICIANDO GURADA 2
    
    
    //INICIANDO PORTA DE SAIDA
    
        Texture2D imagemPorta=LoadTexture("img/porta.png");
        
        Portas portaSaida;
        portaSaida.x=comecoLarguraAreaJogo;
        portaSaida.y=95;
        portaSaida.estadoDaPorta=1;
        portaSaida.imagem=(Rectangle) {0.0f,0.0f,imagemPorta.width,imagemPorta.height/2};
        
    
    //FIM INICIANDO PORTA DE SAIDA



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
        //estante05
        colisao_cenario.colisao[28].x = 323 + 216 + 295; 
        colisao_cenario.colisao[28].y = 123 + 445;
        colisao_cenario.colisao[28].width = estante.width;
        colisao_cenario.colisao[28].height = estante.height;
        //estante06
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
        //estante01.1
        colisao_cenario.interacao[6].x = 323 + 216; 
        colisao_cenario.interacao[6].y = 123 + 35;
        colisao_cenario.interacao[6].width = estante.width;
        colisao_cenario.interacao[6].height = estante.height;
        //estante02.1
        colisao_cenario.interacao[7].x = 323 + 216 + 295; 
        colisao_cenario.interacao[7].y = 123 + 35;
        colisao_cenario.interacao[7].width = estante.width;
        colisao_cenario.interacao[7].height = estante.height;
        //estante03.1
        colisao_cenario.interacao[8].x = 323 + 216 + 295*2; 
        colisao_cenario.interacao[8].y = 123 + 35;
        colisao_cenario.interacao[8].width = estante.width;
        colisao_cenario.interacao[8].height = estante.height;
        //estante04.1
        colisao_cenario.interacao[9].x = 323 + 216; 
        colisao_cenario.interacao[9].y = 123 + 445 + 35;
        colisao_cenario.interacao[9].width = estante.width;
        colisao_cenario.interacao[9].height = estante.height;
        //estante05.1
        colisao_cenario.interacao[10].x = 323 + 216 + 295; 
        colisao_cenario.interacao[10].y = 123 + 445 + 35;
        colisao_cenario.interacao[10].width = estante.width;
        colisao_cenario.interacao[10].height = estante.height;
        //estante06.1
        colisao_cenario.interacao[11].x = 323 + 216 + 295*2; 
        colisao_cenario.interacao[11].y = 123 + 445 + 35;
        colisao_cenario.interacao[11].width = estante.width;
        colisao_cenario.interacao[11].height = estante.height;
        //porta_saida
        colisao_cenario.interacao[12].x = 238; 
        colisao_cenario.interacao[12].y = 200 + 40;
        colisao_cenario.interacao[12].width = porta_cela01.width;
        colisao_cenario.interacao[12].height = porta_cela01.height;
    }

    colisao_cenario.chave = 0;
    colisao_cenario.chave = rand()%12 + 1;

    jogador.Up.x = jogador.posicao_quadrado.x + 5;
    jogador.Up.y = jogador.posicao_quadrado.y;
    jogador.Up.width = jogador.char_walk.width/3;
    jogador.Up.height = jogador.char_walk.height/7;

    jogador.Right.x = jogador.posicao_quadrado.x + 20;
    jogador.Right.y = jogador.posicao_quadrado.y + 10;
    jogador.Right.width = jogador.char_walk.width/6;
    jogador.Right.height = jogador.char_walk.height/1.5;

    jogador.Left.x = jogador.posicao_quadrado.x;
    jogador.Left.y = jogador.posicao_quadrado.y + 10;
    jogador.Left.width = jogador.char_walk.width/6;
    jogador.Left.height = jogador.char_walk.height/1.5;

    jogador.Down.x = jogador.posicao_quadrado.x + 5;
    jogador.Down.y = jogador.posicao_quadrado.y + 40;
    jogador.Down.width = jogador.char_walk.width/3;
    jogador.Down.height = jogador.char_walk.height/7;

    int Mapa1[24][16];
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j <24 ; j++)
        {
            Mapa1[i][j] = 0;
        }   
    } 

    while (!WindowShouldClose()){

        UpdateMusicStream(somFase);

        if(SomLigadoBool)
        {
            SetMusicVolume(somFase,0.50f);
        }
        else
        {
            SetMusicVolume(somFase,0.00f);
        }
        

        if(estadoJogo==0)
        {   
            while (estadoMenu==0)
            {   Mouse=GetMousePosition();
               if  (CheckCollisionPointRec(Mouse,BotaoPlayClick)) 
               {
                if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
                    {
                        estadoJogo=1;
                        estadoMenu=1;
                        estadoFaseUm=0;
                        jogador.posicao_quadrado.x=500;
                        jogador.posicao_quadrado.y=600;
                        jogador.item=0;
                    }
               }
               if (CheckCollisionPointRec(Mouse,SomClick))
                {   
                    if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
                    {
                        SomLigadoBool=!SomLigadoBool;
                    }
                    
                }

                BeginDrawing();
                    ClearBackground(WHITE);
                    DrawTexture(BG,0,0,WHITE);
                    DrawTexture(HighScore,0,0,WHITE);
                    DrawTexture(LogoJogo,510,0,WHITE);
                    DrawTexture(BotaoPlay,490,590,WHITE);
                    if(SomLigadoBool)
                    {
                        DrawTexture(SomLigado,125,0,WHITE);
                    }
                    else
                    {
                        DrawTexture(SomDesligado,125,0,WHITE);
                    }
                    
                EndDrawing();
            }
            
        }
         else if(estadoJogo==1)
           {
             while(estadoFaseUm==0){ 
        
          
  
        
    // MUDA FRAME DOS GUARDAS;
        tempoDoFrame++;
        
        if(tempoDoFrame >= 10){
            
            tempoDoFrame=0;
            
            frameAtual++;
            
            if(frameAtual > 3){
                frameAtual=0;
            }
            
            guarda1.imagem.x=(float) frameAtual*imagemGuardas.width/3;
            guarda2.imagem.x=(float) frameAtual*imagemGuardas.width/3;
        }   
    
    
    //FIM MUDA FRAME DOS GUARDAS

    // LOGICA DO CRONOMETRO
    
        cronometro.tempo++;
        contarTempo(&cronometro);
        
    
    //FIM LOGICA CRONOMETRO



    {
        personagem_movimentacao(&jogador, &colisao_cenario, contador,&portaSaida);

        camera.target.x = jogador.posicao_quadrado.x;
        camera.target.y = jogador.posicao_quadrado.y;
        //teste
        jogador.Up.x = jogador.posicao_quadrado.x + 5;
        jogador.Up.y = jogador.posicao_quadrado.y;
        jogador.Up.width = jogador.char_walk.width/3;
        jogador.Up.height = jogador.char_walk.height/7;

        jogador.Right.x = jogador.posicao_quadrado.x + 20;
        jogador.Right.y = jogador.posicao_quadrado.y + 10;
        jogador.Right.width = jogador.char_walk.width/6;
        jogador.Right.height = jogador.char_walk.height/1.5;

        jogador.Left.x = jogador.posicao_quadrado.x;
        jogador.Left.y = jogador.posicao_quadrado.y + 10;
        jogador.Left.width = jogador.char_walk.width/6;
        jogador.Left.height = jogador.char_walk.height/1.5;

        jogador.Down.x = jogador.posicao_quadrado.x + 5;
        jogador.Down.y = jogador.posicao_quadrado.y + 40;
        jogador.Down.width = jogador.char_walk.width/3;
        jogador.Down.height = jogador.char_walk.height/7;

        if(jogador.animar > 0)
        {
            jogador.Up.width = jogador.char_walk.width/4;

            jogador.Right.x = jogador.posicao_quadrado.x + 15;
            jogador.Right.width = jogador.char_walk.width/8;

            jogador.Left.width = jogador.char_walk.width/8;

            jogador.Down.width = jogador.char_walk.width/4;
        }
               
        BeginDrawing();

            ClearBackground(WHITE);
           // BeginMode2D(camera);
                for (int i = 0; i < 15; i++)
                {
                    for (int j = 0; j <24 ; j++)
                    {
                        DrawTexture(chao, 100+(j*40) + 100, 20+(i*40) + 100,RAYWHITE);
                    }  
                }

                //desenhando cenário
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
                    if( contador[2] == 0 )
                    {
                        DrawTexture( porta_cela01, 238, 200, RAYWHITE);
                    }
                    else
                    {
                        DrawTexture( porta_cela03, 238, 200, RAYWHITE);
                    }
                    
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
                //DrawFPS(jogador.posicao_quadrado.x - 190,jogador.posicao_quadrado.y - 270);

                if (contador[1] > 0 )
                {
                    DrawTexture(procurando, jogador.posicao_quadrado.x - 40, jogador.posicao_quadrado.y - 20, RAYWHITE);
                    contador[1] = 0;
                }
                else if( contador[0] > 0 )
                {
                    DrawTexture(mensagem_procurar, jogador.posicao_quadrado.x - 40, jogador.posicao_quadrado.y - 20, RAYWHITE);
                    contador[0] = 0;
                }
                if( contador[2] > 0 )
                {
                    colisao_cenario.colisao[23].height = porta_cela03.height;
                    colisao_cenario.colisao[23].width = porta_cela03.width;
                }
                if( jogador.item == 1 )
                {
                    DrawTexture(chave_encontrada, jogador.posicao_quadrado.x - 40, jogador.posicao_quadrado.y - 20, RAYWHITE);
                }
                jogador.contador = 0;

            //LOGICA GUARDA 1
            
                moverGuardas(&imagemGuardas,&guarda1,"horizontal",comecoLarguraAreaJogo,fimLarguraAreaJogo);
                desenharGuardas(&imagemGuardas,&guarda1);
                desenharCampoDeVisao(&guarda1,"horizontal",&imagemGuardas);
            
            // FIM LOGICA GUADA 1
            
            
            // LOGICA GURADA 2
     
     
                moverGuardas(&imagemGuardas,&guarda2,"horizontal",comecoLarguraAreaJogo,fimLarguraAreaJogo);
                desenharGuardas(&imagemGuardas,&guarda2);
                desenharCampoDeVisao(&guarda2,"horizontal",&imagemGuardas);
            //FIM LOGICA GUARDA 2;
            
            //LOGICA Porta
                
                desenharPorta(&portaSaida,imagemPorta);
            
            //FIM LOGICA PORTA
     
           // EndMode2D();
            DrawText(FormatText("%2i:%2i",cronometro.minutos,cronometro.segundos),0,0,50,LIGHTGRAY);
            
            
            if( jogador.item == 1 )
            {
                DrawTexture( key, largura_tela/2 + 1240, altura_tela/2 + 625, RAYWHITE);
            }


        EndDrawing();
      
       //VERIFICA O ESTADO DO FASE 1
      
       passouDeFaseUm(&jogador,&portaSaida,&estadoFaseUm);
       
       seEntrouNoCampoDeVisao(&guarda1,&imagemGuardas,"horizontal",jogador.posicao_quadrado.x,jogador.posicao_quadrado.y,jogador.char_walk,&estadoFaseUm); // verifica se emtrou na area do guarda 1
                
       seEntrouNoCampoDeVisao(&guarda2,&imagemGuardas,"horizontal",jogador.posicao_quadrado.x,jogador.posicao_quadrado.y,jogador.char_walk,&estadoFaseUm); // verifica se emtrou na area do guarda 2
                
      
      //FIM DA VERIFICAO DO ESTADO DA FASE 1
      
    }
    
    }
        }
        else if (estadoJogo==2)
        {
            //drawfase2
        }
        else if(estadoJogo==3)
        {
            //drawfase3
        }
        else if(estadoJogo==4)
        {
            EstadoSelectLVL=0;
            while(EstadoSelectLVL==0)
                {

                }
        }
        else if(estadoJogo==5)
        {
            //drawHighScore
        }
        else if(estadoJogo==6)
        {   estadoTelaPerdeu=0;
            while(estadoTelaPerdeu==0)
            {
                Mouse=GetMousePosition();
               if  (CheckCollisionPointRec(Mouse,TelaPerdeuClick)) 
               {
                if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
                    {
                        estadoTelaPerdeu=1;
                        estadoMenu=0;
                        estadoJogo=0;
                        BeginDrawing();
                        DrawRectangle(0,0,300,300,RED);
                        EndDrawing();
                    }
               }
                BeginDrawing();
                        ClearBackground(WHITE);
                        DrawTexture(TelaPerdeu,0,0,WHITE);
                EndDrawing();
               
            }
        }
        
        //FIM WHILE(!acabouFaseUm) // while da fase 1
    
        
        
        BeginDrawing();
        
        if(estadoFaseUm == -1)
        {
            
            estadoJogo=6;
            estadoFaseUm=0;
           
        } 
        else if(estadoFaseUm==1) { 
            estadoJogo=5;
            //ChecarHS();
            comecarFaseDois(&estadoFaseDois,largura_tela,altura_tela);
            ClearBackground(RAYWHITE);
       
        if(estadoFaseDois==-1){
            
            DrawText("Perdeu2",100,100,50,RED);
           
           
            
        }else{
            
               comecarFaseTres();
               ClearBackground(RAYWHITE);
               
               if(estadoFaseTres==-1){
                    
                      DrawText("Perdeu3",100,100,50,RED);
          
               }else{
                   
                     DrawText("Ganhou essa bagaça",100,100,50,RED);
                   
               }
        
        }
      
    }
        
        
        
        
            
        
        EndDrawing(); 
    
    
    
    }//FIM WHILE(!WINDOWSHOULDCLOSE())
        
        UnloadTexture(imagemGuardas);
        UnloadMusicStream(somFase);
        CloseAudioDevice(); 
 
 CloseWindow();*/
 
  
   
  //int estadoFaseDois=0;
InitWindow(GetScreenWidth(),GetScreenHeight(),"");
    SetTargetFPS(60);
         
    
  
  
      
      while(!WindowShouldClose()){

       comecarFaseTres(&estadoFaseDois);
       // comecarFaseDois(&estadoFaseDois);
   
     // testar();
      
      ClearBackground(RAYWHITE);
      BeginDrawing();
      
     

EndDrawing();  
      }
      
   CloseWindow();
    
    
    return 0;

}
   

