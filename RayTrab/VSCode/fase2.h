#include "raylib.h"
#include <string.h>
#include "objetos.h" 

#ifndef FASE2_H
#define FASE2_H



#endif


void passouFaseDois(Jogador* jogador,int* estadoFase){
      
   if(jogador->posicao_quadrado.y==58){
        
      *estadoFase=1;
        
    }else{
        
    *estadoFase=0;        
    }  
    
}
    

void cortarArame(Jogador* jogador,int condicao,Texture2D* campo,int* podePassarPeloArame){
    
    
    if(condicao==1){
     
        *campo = LoadTexture("img/mapa_fase02_1.png");
        *podePassarPeloArame=1;
    }
    if(condicao==2){ 
    
        *campo = LoadTexture("img/mapa_fase02_2.png");
        *podePassarPeloArame=1;
    }
    if(condicao==3){
        
        *campo = LoadTexture("img/mapa_fase02_3.png");
        *podePassarPeloArame=1;
    }
    
    jogador->item=0;
    
}
    


void comecarFaseDois(int* estadoFaseDois){
    
    srand(time(NULL));
    
    int podePassarPeloArame[3];
    int objetoDeCelaSorteado= (rand()%4) + 1;
    int objetoDeSalaSorteado= (rand()%3)+1;
    int achouObjeto=0; 
    int pegouAlicate=0;
    int pegouChave=0;
     
    Font fonte= LoadFont("fonte.otf");
    
    Texture2D campo = LoadTexture("img/mapa_fase02.png");
    Texture2D imagemGuarda = LoadTexture("img/guardas.png");
    Texture2D procurando = LoadTexture("img/Procurando.png");
    Texture2D mensagemProcurar = LoadTexture("img/Mensagem_procurar.png");
    Texture2D cela1= LoadTexture("img/cela01_fase02.png");
    Texture2D estanteImagem= LoadTexture("img/estante.png");
    Texture2D cela2= LoadTexture("img/cela02_fase02.png");
    Texture2D imagemCama = LoadTexture("img/cama.png");
    Texture2D alicate = LoadTexture("img/alicate.png");
    Texture2D chave = LoadTexture("img/key.png");
    Texture2D imagemPortaFinal = LoadTexture("img/porta_cela01.png");
    
    podePassarPeloArame[0]=0;
    podePassarPeloArame[1]=0;
    podePassarPeloArame[2]=0;
    
    
    //Porta Final
    Portas portaFinal;
    portaFinal.x=528;
    portaFinal.y=152-imagemPortaFinal.height;
    portaFinal.estadoDaPorta =1;
    portaFinal.imagem = (Rectangle){0.0f,0.0f,imagemPortaFinal.width,imagemPortaFinal.height};
    
    //FIM PORTA FINAL
    
    //Iniciando objetos daS celas
    
        Objetos estanteCelas[2];
        
        estanteCelas[0].x=150;
        estanteCelas[0].y= 210;
        estanteCelas[0].imagem=estanteImagem;
        estanteCelas[0].numeroIdentificador=1;
        
        
        estanteCelas[1].x=150 ;
        estanteCelas[1].y= 530;
        estanteCelas[1].imagem=estanteImagem;
        estanteCelas[1].numeroIdentificador=2;
        
        Objetos camaCelas[2];
        
        camaCelas[0].x= 298;
        camaCelas[0].y= 160;
        camaCelas[0].imagem = imagemCama;
        camaCelas[0].numeroIdentificador=3;
        
        camaCelas[1].x=298;
        camaCelas[1].y=480;
        camaCelas[1].imagem = imagemCama;    
        camaCelas[1].numeroIdentificador=4;
        
        for(int i=0;i<2;i++){
            
            if(objetoDeCelaSorteado == estanteCelas[i].numeroIdentificador){
                
                estanteCelas[i].possuiItem=1;
                   
            }else estanteCelas[i].possuiItem=0;
                  
        }
        
        for(int i=0;i<2;i++){
            
            if(objetoDeCelaSorteado == camaCelas[i].numeroIdentificador){
                
                camaCelas[i].possuiItem=1;
                
                
            }else camaCelas[i].possuiItem=0;
                
        }
        
    //Fim da iniciando Objetos  daS celas
    
    
    //Iniciando obejtos da sala
    
        Objetos estanteSala[3];
        
        estanteSala[0].x= 1000;
        estanteSala[0].y= 355;
        estanteSala[0].numeroIdentificador= 1 ;
        estanteSala[0].interagiuComJogador= 0;
        
        estanteSala[1].x= 1124;
        estanteSala[1].y= 355;
        estanteSala[1].numeroIdentificador= 2 ;
        estanteSala[1].interagiuComJogador= 0;
        
        estanteSala[2].x= 1160;
        estanteSala[2].y= 360;
        estanteSala[2].numeroIdentificador= 3 ;
        estanteSala[2].interagiuComJogador= 0;
        
        
          for(int i=0;i<3;i++){
            
            if(objetoDeSalaSorteado == estanteSala[i].numeroIdentificador){
                
                estanteSala[i].possuiItem=1;
                   
            }else estanteSala[i].possuiItem=0;
                  
        }
        
        
    
    //Fim iniciandoobjetos da sala
    
    
    
    
    
    //INICIANDO O JOGADOR
    
    Jogador jogador;
    jogador.animar = 0;
    jogador.contador = 0;
    jogador.item = 0;
    int contador[3];
    contador[0] = 0;
    contador[1] = 0;
    contador[2] = 0;
    jogador.posicao_quadrado.x =550;
    jogador.posicao_quadrado.y = 680;
    jogador.char_walk = LoadTexture("img/prisioneiro_pose02.png");

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
    
    
    //FIM INICIANDO O JOGADOR
    
    
    //INICIANDO COLISAO com o cenario
    
    Colisao_cenario colisao_cenario;
    
        colisao_cenario.colisao[0].height = 40;
        colisao_cenario.colisao[0].width = 414;
        colisao_cenario.colisao[0].x = 104;
        colisao_cenario.colisao[0].y = 635;
        colisao_cenario.colisao[1].height = 565;
        colisao_cenario.colisao[1].width = 40;
        colisao_cenario.colisao[1].x = 104;
        colisao_cenario.colisao[1].y = 110;
        colisao_cenario.colisao[2].height = 40;
        colisao_cenario.colisao[2].width = 414;
        colisao_cenario.colisao[2].x = 104;
        colisao_cenario.colisao[2].y = 110;
        colisao_cenario.colisao[3].height = 40;
        colisao_cenario.colisao[3].width = 673;
        colisao_cenario.colisao[3].x = 575;
        colisao_cenario.colisao[3].y = 112;
        colisao_cenario.colisao[4].height = 40;
        colisao_cenario.colisao[4].width = 673;
        colisao_cenario.colisao[4].x = 577;
        colisao_cenario.colisao[4].y = 635;
        colisao_cenario.colisao[5].height = 565;
        colisao_cenario.colisao[5].width = 40;
        colisao_cenario.colisao[5].x = 1210;
        colisao_cenario.colisao[5].y = 110;
        
        
        colisao_cenario.colisao[6].height = 92;
        colisao_cenario.colisao[6].width = 40;
        colisao_cenario.colisao[6].x = 478;
        colisao_cenario.colisao[6].y = 675;
        
        colisao_cenario.colisao[7].height = 92;
        colisao_cenario.colisao[7].width = 40;
        colisao_cenario.colisao[7].x = 576;
        colisao_cenario.colisao[7].y = 675;
        
        
        colisao_cenario.colisao[8].height = 52;
        colisao_cenario.colisao[8].width = 80;
        colisao_cenario.colisao[8].x = 506;
        colisao_cenario.colisao[8].y = 720;
        colisao_cenario.colisao[9].height = 150;
        colisao_cenario.colisao[9].width = 40;
        colisao_cenario.colisao[9].x = 478;
        colisao_cenario.colisao[9].y = 0;
        colisao_cenario.colisao[10].height = 150;
        colisao_cenario.colisao[10].width = 40;
        colisao_cenario.colisao[10].x = 576;
        colisao_cenario.colisao[10].y = 0;
        colisao_cenario.colisao[11].height = 52;
        colisao_cenario.colisao[11].width = 80;
        colisao_cenario.colisao[11].x = 506;
        colisao_cenario.colisao[11].y = 0;
        colisao_cenario.colisao[12].height = 190;
        colisao_cenario.colisao[12].width = 40;
        colisao_cenario.colisao[12].x = 374;
        colisao_cenario.colisao[12].y = 150;
        colisao_cenario.colisao[13].height = 210;
        colisao_cenario.colisao[13].width = 40;
        colisao_cenario.colisao[13].x = 374;
        colisao_cenario.colisao[13].y = 433;
        colisao_cenario.colisao[14].height = 40;
        colisao_cenario.colisao[14].width = 127;
        colisao_cenario.colisao[14].x = 245;
        colisao_cenario.colisao[14].y = 433;
        colisao_cenario.colisao[15].height = 40;
        colisao_cenario.colisao[15].width = 127;
        colisao_cenario.colisao[15].x = 245;
        colisao_cenario.colisao[15].y = 299;
        colisao_cenario.colisao[16].height = 40;
        colisao_cenario.colisao[16].width = 74;
        colisao_cenario.colisao[16].x = 123;
        colisao_cenario.colisao[16].y = 299;
        colisao_cenario.colisao[17].height = 40;
        colisao_cenario.colisao[17].width = 74;
        colisao_cenario.colisao[17].x = 123;
        colisao_cenario.colisao[17].y = 433;
        colisao_cenario.colisao[18].height = 60;
        colisao_cenario.colisao[18].width = 40;
        colisao_cenario.colisao[18].x = 146;
        colisao_cenario.colisao[18].y = 150;
        colisao_cenario.colisao[19].height = 60;
        colisao_cenario.colisao[19].width = 40;
        colisao_cenario.colisao[19].x = 146;
        colisao_cenario.colisao[19].y = 470;
        colisao_cenario.colisao[20].height = 60;
        colisao_cenario.colisao[20].width = 47;
        colisao_cenario.colisao[20].x = 326;
        colisao_cenario.colisao[20].y = 470;
        colisao_cenario.colisao[21].height = 60;
        colisao_cenario.colisao[21].width = 47;
        colisao_cenario.colisao[21].x = 326;
        colisao_cenario.colisao[21].y = 150;
        colisao_cenario.colisao[22].height = 80;
        colisao_cenario.colisao[22].width = 327;
        colisao_cenario.colisao[22].x = 883;
        colisao_cenario.colisao[22].y = 270;
        colisao_cenario.colisao[23].height = 40;
        colisao_cenario.colisao[23].width = 327;
        colisao_cenario.colisao[23].x = 883;
        colisao_cenario.colisao[23].y = 475;
        colisao_cenario.colisao[24].height = 50;
        colisao_cenario.colisao[24].width = 40;
        colisao_cenario.colisao[24].x = 883;
        colisao_cenario.colisao[24].y = 432;
        colisao_cenario.colisao[25].height = 50;
        colisao_cenario.colisao[25].width = 40;
        colisao_cenario.colisao[25].x = 883;
        colisao_cenario.colisao[25].y = 316;
        colisao_cenario.colisao[26].height = 58;
        colisao_cenario.colisao[26].width = 500;
        colisao_cenario.colisao[26].x = 713;
        colisao_cenario.colisao[26].y = 227;
        colisao_cenario.colisao[27].height = 58;
        colisao_cenario.colisao[27].width = 331;
        colisao_cenario.colisao[27].x = 885;
        colisao_cenario.colisao[27].y = 500;
        colisao_cenario.colisao[28].height = 58;
        colisao_cenario.colisao[28].width = 18;
        colisao_cenario.colisao[28].x = 713;
        colisao_cenario.colisao[28].y = 500;
        colisao_cenario.colisao[29].height = 58;
        colisao_cenario.colisao[29].width = 18;
        colisao_cenario.colisao[29].x = 713;
        colisao_cenario.colisao[29].y = 355;
        
        
        // arame vertical de cima
        colisao_cenario.colisao[30].x=710;
        colisao_cenario.colisao[30].y=284;
        colisao_cenario.colisao[30].width=5;
        colisao_cenario.colisao[30].height=308-284;
        
        //arame vertoaç de baixo
        colisao_cenario.colisao[31].x=710;
        colisao_cenario.colisao[31].y=414;
        colisao_cenario.colisao[31].width=5;
        colisao_cenario.colisao[31].height=480-414;
        
        //arame horiozntal
        colisao_cenario.colisao[32].x=732;
        colisao_cenario.colisao[32].y=540;
        colisao_cenario.colisao[32].width=860-732;
        colisao_cenario.colisao[32].height=6;
        
        //Colisao PortaSAida
        colisao_cenario.colisao[33].x=520;
        colisao_cenario.colisao[33].y=160;
        colisao_cenario.colisao[33].width=imagemPortaFinal.width;
        colisao_cenario.colisao[33].height=0;
                    
    
    //FIM INICIANDO COLISAO com o cenario
    
    
    //INICIANDO Guarda 1
    Guardas guarda1;
        
    guarda1.x=440;
    guarda1.y=590;
    guarda1.imagem = (Rectangle) {0.0f,0.0f,imagemGuarda.width/3,imagemGuarda.height/4};
    guarda1.movimento = 5;
    guarda1.sentidoCampoDeVisao=1;
    guarda1.campoDeVisao=100;
    guarda1.imagem.y= imagemGuarda.height/4;
    //FIM INICIANDO GUARDA 1;
    
    
    //INICIANDO Guarda 2
    Guardas guarda2;
        
    guarda2.x=650;
    guarda2.y=150;
    
    guarda2.imagem = (Rectangle) {0.0f,0.0f,imagemGuarda.width/3,imagemGuarda.height/4};
    guarda2.movimento = -5;
    guarda2.sentidoCampoDeVisao=-1;
    guarda2.campoDeVisao=100;
    guarda2.imagem.y= 4*imagemGuarda.height/4;
    //FIM INICIANDO GUARDA 2
     
    int tempoDoFrame=0;
    int frameAtual=0;

      

        while(*estadoFaseDois==0){
          
       //Atualização da fase 2
       

       
        //Atualização jogador 
        personagem_movimentacao(&jogador,&colisao_cenario,contador,NULL,2);
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
        
        
        //Fim atualização jogador
        
        //Atualização guardas 
        
        tempoDoFrame++;
        
        if(tempoDoFrame >= 10){
            
            tempoDoFrame=0;
            
            frameAtual++;
            
            if(frameAtual > 3){
                frameAtual=0;
            }
            
            guarda1.imagem.x=(float) frameAtual*imagemGuarda.width/3;
            guarda2.imagem.x=(float) frameAtual*imagemGuarda.width/3;

        }
        
            moverGuardas(&imagemGuarda,&guarda1,"vertical",150,590+imagemGuarda.height/4);
            moverGuardas(&imagemGuarda,&guarda2,"vertical",150,590+imagemGuarda.height/4);        
            
        //Fim atualização guardas 
        
        
        
        
       //Fim Atualização da fase 2
          
          ClearBackground(RAYWHITE);
          BeginDrawing();
       //Desenha o cenario
        DrawTextureRec(campo,(Rectangle){0.0f,0.0f,campo.width,campo.height},(Vector2){0,0},WHITE);
        DrawTextureRec(cela1,(Rectangle){0.0f,0.0f,cela1.width,cela1.height},(Vector2){0,0},WHITE);//desenha a porta da cela de baixo
        DrawTextureRec(cela2,(Rectangle){0.0f,0.0f,cela2.width,cela2.height},(Vector2){0,0},WHITE);//desenha a porta da cela de Cima
        
        desenharPortaCela(&portaFinal,imagemPortaFinal); 

       //Fim do cenario        

         
         //Desenha os personagens
         
        draw_jogador(&jogador);   //desenha o jogador
        
        desenharGuardas(&imagemGuarda,&guarda1);
       
        
        desenharGuardas(&imagemGuarda,&guarda2);
       
        
        //Fim desenahr os personagens
          
        //verifica se encontro os alicates nos objetos das celas  
        
        if(!pegouAlicate){
        
        if(IsKeyDown(KEY_E)  && achouObjeto==1 ){
        
           if(estanteCelas[0].interagiuComJogador==1){
            
                procurarItem(estanteCelas[0],procurando,&jogador,jogador.posicao_quadrado.x,jogador.posicao_quadrado.y,&pegouAlicate);
                
                
           }else
             if(estanteCelas[1].interagiuComJogador==1){
            
                procurarItem(estanteCelas[1],procurando,&jogador,jogador.posicao_quadrado.x,jogador.posicao_quadrado.y,&pegouAlicate);
                
                 
            }else
             if(camaCelas[0].interagiuComJogador==1){
            
                procurarItem(camaCelas[0],procurando,&jogador,jogador.posicao_quadrado.x,jogador.posicao_quadrado.y,&pegouAlicate);
                
            }else
             if(camaCelas[1].interagiuComJogador==1){
            
                procurarItem(camaCelas[1],procurando,&jogador,jogador.posicao_quadrado.x,jogador.posicao_quadrado.y,&pegouAlicate);
                 
            }
            
     
         //esntate da cela 1
         }else if(jogador.posicao_quadrado.x>=estanteCelas[0].x && jogador.posicao_quadrado.x<estanteCelas[0].x+estanteImagem.width && jogador.posicao_quadrado.y>estanteCelas[0].y && jogador.posicao_quadrado.y<estanteCelas[0].y+12){
                    
             DrawTextureRec(mensagemProcurar,(Rectangle) {0.0f,0.0f,mensagemProcurar.width,mensagemProcurar.height},(Vector2){jogador.posicao_quadrado.x,jogador.posicao_quadrado.y-mensagemProcurar.height},WHITE);
             achouObjeto=1;
             estanteCelas[0].interagiuComJogador=1;  
        
         //esntate da cela 2                   
           }else if(jogador.posicao_quadrado.x>=estanteCelas[1].x && jogador.posicao_quadrado.x<estanteCelas[1].x+estanteImagem.width && jogador.posicao_quadrado.y>estanteCelas[1].y && jogador.posicao_quadrado.y<estanteCelas[1].y+8){
               
             DrawTextureRec(mensagemProcurar,(Rectangle) {0.0f,0.0f,mensagemProcurar.width,mensagemProcurar.height},(Vector2){jogador.posicao_quadrado.x,jogador.posicao_quadrado.y-mensagemProcurar.height},WHITE);
             achouObjeto=1;
             estanteCelas[1].interagiuComJogador=1;               
             
             //cama cela 1
           }else if(jogador.posicao_quadrado.x>=camaCelas[0].x && jogador.posicao_quadrado.x<camaCelas[0].x+imagemCama.width && jogador.posicao_quadrado.y>camaCelas[0].y-12 && jogador.posicao_quadrado.y<camaCelas[0].y+imagemCama.height){
           
             DrawTextureRec(mensagemProcurar,(Rectangle) {0.0f,0.0f,mensagemProcurar.width,mensagemProcurar.height},(Vector2){jogador.posicao_quadrado.x,jogador.posicao_quadrado.y-mensagemProcurar.height},WHITE);
             achouObjeto=1;
             camaCelas[0].interagiuComJogador=1;
           
           //cama Cela 2
           }else if(jogador.posicao_quadrado.x>=camaCelas[1].x && jogador.posicao_quadrado.x<camaCelas[1].x+imagemCama.width && jogador.posicao_quadrado.y>camaCelas[1].y-12 && jogador.posicao_quadrado.y<camaCelas[1].y+imagemCama.height){
               
                DrawTextureRec(mensagemProcurar,(Rectangle) {0.0f,0.0f,mensagemProcurar.width,mensagemProcurar.height},(Vector2){jogador.posicao_quadrado.x,jogador.posicao_quadrado.y-mensagemProcurar.height},WHITE);
                achouObjeto=1;
                camaCelas[1].interagiuComJogador=1;
                
           }else{

                
              
               
             achouObjeto=0; 
             estanteCelas[0].interagiuComJogador=0;
             estanteCelas[1].interagiuComJogador=0;
             camaCelas[0].interagiuComJogador=0;
             camaCelas[1].interagiuComJogador=0;
             
        }
        }
        
       //Fim Verificar se encontrou o alicate nos objetos
    

        if(!pegouChave){
        
        if(IsKeyDown(KEY_E)  && achouObjeto==1 ){
        
            
           if(estanteSala[0].interagiuComJogador==1){
            
                procurarItem(estanteSala[0],procurando,&jogador,jogador.posicao_quadrado.x,jogador.posicao_quadrado.y,&pegouChave);
                
                
           }else
             if(estanteSala[1].interagiuComJogador==1){
            
                procurarItem(estanteSala[1],procurando,&jogador,jogador.posicao_quadrado.x,jogador.posicao_quadrado.y,&pegouChave);
                
                 
            }else
             if(estanteSala[2].interagiuComJogador==1){
            
                procurarItem(estanteSala[2],procurando,&jogador,jogador.posicao_quadrado.x,jogador.posicao_quadrado.y,&pegouChave);
                
           
             }
     
         //estante sala 1
         }else if(jogador.posicao_quadrado.x>=estanteSala[0].x && jogador.posicao_quadrado.x<estanteSala[0].x+estanteImagem.width && jogador.posicao_quadrado.y>estanteSala[0].y && jogador.posicao_quadrado.y<estanteSala[0].y+10){
                    
             DrawTextureRec(mensagemProcurar,(Rectangle) {0.0f,0.0f,mensagemProcurar.width,mensagemProcurar.height},(Vector2){jogador.posicao_quadrado.x,jogador.posicao_quadrado.y-mensagemProcurar.height},WHITE);
             achouObjeto=1;
             estanteSala[0].interagiuComJogador=1;  
        
         //estante sala 2                   
           }else if(jogador.posicao_quadrado.x>=estanteSala[1].x && jogador.posicao_quadrado.x<estanteSala[1].x+estanteImagem.width && jogador.posicao_quadrado.y>estanteSala[1].y && jogador.posicao_quadrado.y<estanteSala[1].y+10){
               
             DrawTextureRec(mensagemProcurar,(Rectangle) {0.0f,0.0f,mensagemProcurar.width,mensagemProcurar.height},(Vector2){jogador.posicao_quadrado.x,jogador.posicao_quadrado.y-mensagemProcurar.height},WHITE);
             achouObjeto=1;
             estanteSala[1].interagiuComJogador=1;               
             
             //estante sala 3
           }else if(jogador.posicao_quadrado.x>=estanteSala[2].x && jogador.posicao_quadrado.x<estanteSala[2].x+estanteImagem.width && jogador.posicao_quadrado.y>estanteSala[2].y-12 && jogador.posicao_quadrado.y<estanteSala[2].y+estanteImagem.height){
           
             DrawTextureRec(mensagemProcurar,(Rectangle) {0.0f,0.0f,mensagemProcurar.width,mensagemProcurar.height},(Vector2){jogador.posicao_quadrado.x,jogador.posicao_quadrado.y-mensagemProcurar.height},WHITE);
             achouObjeto=1;
             estanteSala[2].interagiuComJogador=1;
           
          
                
           }else{

             achouObjeto=0; 
             estanteSala[0].interagiuComJogador=0;
             estanteSala[1].interagiuComJogador=0;
             estanteSala[2].interagiuComJogador=0;
            
        }
        }
        

          
            if(jogador.item==1 && pegouAlicate){
                
                DrawTextureRec(alicate,(Rectangle) {0.0f,0.0f,alicate.width,alicate.height}, (Vector2) {1300,700},WHITE );
                
            }
            
             if(jogador.item==1 && pegouChave){
                
               DrawTextureRec(chave,(Rectangle) {0.0f,0.0f,chave.width,chave.height}, (Vector2) {1300,700},WHITE );
                
            }
            
            DrawText(FormatText("%f %f",jogador.posicao_quadrado.x,jogador.posicao_quadrado.y),1200,900,50,BLUE);
            
             //MENSAGEM de cortar Arame PARA O USUARIO 
             
             
             if(pegouAlicate && jogador.posicao_quadrado.x+jogador.char_walk.width/2 >= 686 && jogador.posicao_quadrado.y > 284 &&  jogador.posicao_quadrado.y < 308){
                               
                 DrawTextEx(fonte,"Aperte E para cortar",(Vector2){jogador.posicao_quadrado.x,jogador.posicao_quadrado.y-22},22,1,BLACK);
                 
                 if(IsKeyDown(KEY_E)){
                     
                    cortarArame(&jogador,1,&campo,&podePassarPeloArame[0]);
                    
                    colisao_cenario.colisao[30].x=0;
                    colisao_cenario.colisao[30].y=0;
                    colisao_cenario.colisao[30].width=0;
                    colisao_cenario.colisao[30].height=0;
                    pegouAlicate=0;
                     
                 }

                
            }
        
               if( pegouAlicate && jogador.posicao_quadrado.x >= 686 && jogador.posicao_quadrado.y > 414 &&  jogador.posicao_quadrado.y < 480 ){
            
                     DrawTextEx(fonte,"Aperte E para cortar",(Vector2){jogador.posicao_quadrado.x,jogador.posicao_quadrado.y-22},22,1,BLACK);
                     
                    if(IsKeyDown(KEY_E)){
                     
                     cortarArame(&jogador,2,&campo,&podePassarPeloArame[1]);
                     colisao_cenario.colisao[31].x=0;
                     colisao_cenario.colisao[31].y=0;
                     colisao_cenario.colisao[31].width=0;
                     colisao_cenario.colisao[31].height=0;
                     pegouAlicate=0;
                      
                 }
                
                }
              
               if(pegouAlicate &&jogador.posicao_quadrado.x >740  && jogador.posicao_quadrado.x <860 && jogador.posicao_quadrado.y<=550 ){
                   
                    DrawTextEx(fonte,"Aperte E para cortar",(Vector2){jogador.posicao_quadrado.x,jogador.posicao_quadrado.y-22},22,1,BLACK);
                 
                    if(IsKeyDown(KEY_E)){
                     
                     cortarArame(&jogador,3,&campo,&podePassarPeloArame[2]);
                     colisao_cenario.colisao[32].x=0;
                     colisao_cenario.colisao[32].y=0;
                     colisao_cenario.colisao[32].width=0;
                     colisao_cenario.colisao[32].height=0;
                     pegouAlicate=0;
                     
                 }
                   
                   
               }
                
                
         //Fim de MENSAGEM de cortar Arame PARA O USUARIO 
             
             
                    
       
           if( pegouChave && jogador.posicao_quadrado.x > 530 && jogador.posicao_quadrado.x < 530+imagemPortaFinal.width && jogador.posicao_quadrado.y <= 170 ){
               
               DrawTextEx(fonte,"Aperte E para abrir a porta!",(Vector2){portaFinal.x/2-22,portaFinal.y-22},22,1,BLACK);
               
               if(IsKeyPressed(KEY_E)){
                   
                   mudarEstadoPorta(&portaFinal);
                   colisao_cenario.colisao[33].x=0;
                   colisao_cenario.colisao[33].y=0;
                   colisao_cenario.colisao[33].width=0;
                   colisao_cenario.colisao[33].height=0;
                   pegouChave=0;
                   
                   
               }
               
           }
       
      jogador.contador = 0;
                    
            
EndDrawing();
    
    
    
    
    
    
        //Verifica Estado da fase

            passouFaseDois(&jogador,estadoFaseDois);
        
            seEntrouNoCampoDeVisao(&guarda1,&imagemGuarda,"vertical",jogador.posicao_quadrado.x,jogador.posicao_quadrado.y,jogador.char_walk,estadoFaseDois);
            //Guarda 1
            
            seEntrouNoCampoDeVisao(&guarda2,&imagemGuarda,"vertical",jogador.posicao_quadrado.x,jogador.posicao_quadrado.y,jogador.char_walk,estadoFaseDois);
            
            //Guarda 2
            
        //Fim da vericaçao
            
            
        }//FIM 
        
   
   
   
    UnloadTexture(campo);
    UnloadTexture(imagemGuarda);
    UnloadTexture(procurando);
    UnloadTexture(mensagemProcurar);
    UnloadTexture(cela1);
    UnloadTexture(cela2);
    UnloadTexture(alicate);
    UnloadTexture(imagemCama);
    UnloadTexture(estanteImagem);
    UnloadTexture(chave);        
        
        
  
    
    
}
