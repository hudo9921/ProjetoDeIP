#include "raylib.h"
#ifndef FASE2_H
#define FASE2_H
#endif


void passouFaseTres(){
    
    
    
    
}

void tirarObstaculo(Jogador* jogador,int* podePassarPeloObstaculo){
    
    *podePassarPeloObstaculo=1;
    
    jogador->item=0;

}
    


void comecarFaseTres(int* estadoFaseTres){
    
    srand(time(NULL));
    
    Font fonte =LoadFont("fonte.otf");
    
    Texture2D campo= LoadTexture("img/fase03.png");
    Texture2D alicate = LoadTexture("img/alicate.png");
    Texture2D obstaculo = LoadTexture("img/vasos_fase03.png");
    Texture2D arame = LoadTexture("img/arame_fase03.png");
    Texture2D imagemGuardas = LoadTexture("img/guardas.png");
    Texture2D estanteImagem = LoadTexture("img/estante.png");
    Texture2D procurando = LoadTexture("img/procurando.png");
    Texture2D mensagemProcurar = LoadTexture("img/Mensagem_procurar.png");
    Texture2D martelo= LoadTexture("img/martelo.png");
    
    
    int objetoDeSalaSorteado= (rand()%2)+1;
    int cortouArame=0;
    int pegouAlicate=0;
    int pegouMartelo=0;
    int achouObjeto=0;
    int quebrouvaso=0;
    
    //Iniciando Guardas
    Guardas guarda[6];
    
    for(int i=0;i<6;i++){
        
        guarda[i].imagem=(Rectangle){0.0f,0.0f,imagemGuardas.width/3,imagemGuardas.height/4};
        guarda[i].campoDeVisao = 100; 
        
        if(i%2!=0){
        
            guarda[i].movimento=5+0.5;
            guarda[i].sentidoCampoDeVisao=1;
        
        }else{
            
            guarda[i].movimento=-5 + 0.5;
            guarda[i].sentidoCampoDeVisao=-1;
        
        }
    }

    //GuARDA 1
    
    guarda[0].x=240;// 240 //550
    guarda[0].y=155;
    guarda[0].imagem.y = 2*imagemGuardas.height/4 ;
    //
    
    //Guarda 2
    guarda[1].x=550;// 240 //550
    guarda[1].y=275;
    guarda[1].imagem.y = 3*imagemGuardas.height/4 ;
   
    //
    
    //Guarda 3
    guarda[2].x=240;// 240 //550
    guarda[2].y=430;
    guarda[2].imagem.y = 2*imagemGuardas.height/4 ;
    //
    
    //Guarda 4
    guarda[3].x=550;// 240 //550
    guarda[3].y=600;
    guarda[3].imagem.y = 3*imagemGuardas.height/4 ;
    //
    
    //Guarda 5
    guarda[4].x=700;
    guarda[4].y=0;
    guarda[4].imagem.y = 4*imagemGuardas.height/4 ;
    //
    
    //Guarda 6
    guarda[5].x=850;
    guarda[5].y=320;
    guarda[5].imagem.y = imagemGuardas.height/4 ;
    guarda[5].movimento=-5;
    guarda[5].sentidoCampoDeVisao=-1;
    //
    
    //FIm iniciando Guardas
    
    Objetos estanteSala1[2];
        
        estanteSala1[0].x=852;
        estanteSala1[0].y= 100-estanteImagem.height;
        estanteSala1[0].numeroIdentificador=1;
        
        
        estanteSala1[1].x=898 ;
        estanteSala1[1].y=100-estanteImagem.height;
        estanteSala1[1].numeroIdentificador=2;
        
        
        for(int i=0;i<2;i++){
            
            if(objetoDeSalaSorteado == estanteSala1[i].numeroIdentificador){
                
                estanteSala1[i].possuiItem=1;
                   
            }else estanteSala1[i].possuiItem=0;
                  
        }
    
    
    Objetos estanteSala2[2];
        
        estanteSala2[0].x=246;
        estanteSala2[0].y=100 -estanteImagem.height;
        estanteSala2[0].numeroIdentificador=1;
        
        
        estanteSala2[1].x= 286;
        estanteSala2[1].y=100-estanteImagem.height;
        estanteSala2[1].numeroIdentificador=2;
        
        objetoDeSalaSorteado = (rand()%2)+1;
        
        for(int i=0;i<2;i++){
            
            if(objetoDeSalaSorteado == estanteSala2[i].numeroIdentificador){
                
                estanteSala2[i].possuiItem=1;
                   
            }else estanteSala2[i].possuiItem=0;
                  
        }
    
    
    
    
   //Iniciando Jogador
    
        
    Jogador jogador;
    jogador.animar = 0;
    jogador.contador = 0;
    jogador.item = 0;
    int contador[3];
    contador[0] = 0;
    contador[1] = 0;
    contador[2] = 0;
    jogador.posicao_quadrado.x =930;
    jogador.posicao_quadrado.y = 500;
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
        
    
    
    //fim iniciando jogador
    
    //INICIADNO COLISOES COM o CENARFIO
   Colisao_cenario colisao;
   colisao.colisao[0].height = 768;
   colisao.colisao[0].width = 40;
   colisao.colisao[0].x = 200;
   colisao.colisao[0].y = 1;
   colisao.colisao[1].height = 321;
   colisao.colisao[1].width = 40;
   colisao.colisao[1].x = 577;
   colisao.colisao[1].y = 1;
   colisao.colisao[2].height = 359;
   colisao.colisao[2].width = 40;
   colisao.colisao[2].x = 577;
   colisao.colisao[2].y = 409;
   colisao.colisao[3].height = 40;
   colisao.colisao[3].width = 337;
   colisao.colisao[3].x = 240;
   colisao.colisao[3].y = 1;
   colisao.colisao[4].height = 40;
   colisao.colisao[4].width = 126;
   colisao.colisao[4].x = 240;
   colisao.colisao[4].y = 222;
   colisao.colisao[5].height = 40;
   colisao.colisao[5].width = 133;
   colisao.colisao[5].x = 240 + 126 + 80;
   colisao.colisao[5].y = 222;
   colisao.colisao[6].height = 40;
   colisao.colisao[6].width = 133;
   colisao.colisao[6].x = 240 + 126 + 80;
   colisao.colisao[6].y = 485;
   colisao.colisao[7].height = 40;
   colisao.colisao[7].width = 126;
   colisao.colisao[7].x = 240;
   colisao.colisao[7].y = 485;
   colisao.colisao[8].height = 40;
   colisao.colisao[8].width = 126;
   colisao.colisao[8].x = 240;
   colisao.colisao[8].y = 725;
   colisao.colisao[9].height = 40;
   colisao.colisao[9].width = 133;
   colisao.colisao[9].x = 240 + 126 + 80;
   colisao.colisao[9].y = 725;
   colisao.colisao[10].height = 40;
   colisao.colisao[10].width = 480;
   colisao.colisao[10].x = 620;
   colisao.colisao[10].y = 1;
   colisao.colisao[11].height = 12;
   colisao.colisao[11].width = 482;
   colisao.colisao[11].x = 618;
   colisao.colisao[11].y = 757;
   colisao.colisao[12].height = 766;
   colisao.colisao[12].width = 21;
   colisao.colisao[12].x = 1082;
   colisao.colisao[12].y = 1;
   colisao.colisao[13].height = 295;
   colisao.colisao[13].width = 40;
   colisao.colisao[13].x = 813;
   colisao.colisao[13].y = 40;
   colisao.colisao[14].height = 295;
   colisao.colisao[14].width = 40;
   colisao.colisao[14].x = 813 + 247;
   colisao.colisao[14].y = 40;
   colisao.colisao[15].height = 40;
   colisao.colisao[15].width = 70;
   colisao.colisao[15].x = 850;
   colisao.colisao[15].y = 293;
   colisao.colisao[16].height = 40;
   colisao.colisao[16].width = 90;
   colisao.colisao[16].x = 850 + 60 + 65;
   colisao.colisao[16].y = 293;
   colisao.colisao[17].height = 60;
   colisao.colisao[17].width = 84;
   colisao.colisao[17].x = 850;
   colisao.colisao[17].y = 160;
   colisao.colisao[18].height = 60;
   colisao.colisao[18].width = 84;
   colisao.colisao[18].x = 850 + 8;
   colisao.colisao[18].y = 35;
   colisao.colisao[19].height = 60;
   colisao.colisao[19].width = 50;
   colisao.colisao[19].x = 850 + 170;
   colisao.colisao[19].y = 35;
   colisao.colisao[20].height = 60;
   colisao.colisao[20].width = 50;
   colisao.colisao[20].x = 850 + 174;
   colisao.colisao[20].y = 158;
   colisao.colisao[21].height = 60;
   colisao.colisao[21].width = 88;
   colisao.colisao[21].x = 240;
   colisao.colisao[21].y = 34;
   colisao.colisao[22].height = 60;
   colisao.colisao[22].width = 37;
   colisao.colisao[22].x = 240 + 148;
   colisao.colisao[22].y = 34;
   colisao.colisao[23].height = 60;
   colisao.colisao[23].width = 80;
   colisao.colisao[23].x = 240 + 257;
   colisao.colisao[23].y = 34;
   colisao.colisao[24].height = 60;
   colisao.colisao[24].width = 100;
   colisao.colisao[24].x = 240 + 10;
   colisao.colisao[24].y = 515;
   colisao.colisao[25].height = 54;
   colisao.colisao[25].width = 40;
   colisao.colisao[25].x = 240 + 637;
   colisao.colisao[25].y = 714;
   colisao.colisao[26].height = 54;
   colisao.colisao[26].width = 40;
   colisao.colisao[26].x = 240 + 637 + 100;
   colisao.colisao[26].y = 714;
   
   
   //Arame 
   colisao.colisao[28].x= 624 ;
   colisao.colisao[28].y= 326;
   colisao.colisao[28].width=5;
   colisao.colisao[28].height=45;
  
  
  
   colisao.colisao[27].x= 0 ;
   colisao.colisao[27].y= 0;
   colisao.colisao[27].width= 0;
   colisao.colisao[27].height=0;
   
   //
   //Arame 
   colisao.colisao[29].x= 394 ;
   colisao.colisao[29].y= 440;
   colisao.colisao[29].width= obstaculo.width;
   colisao.colisao[29].height=obstaculo.height;
   //
   //Arame 
   colisao.colisao[30].x= 0 ;
   colisao.colisao[30].y= 0;
   colisao.colisao[30].width= 0;
   colisao.colisao[30].height=0;
   //
   //Arame 
   colisao.colisao[31].x= 0 ;
   colisao.colisao[31].y= 0;
   colisao.colisao[31].width= 0;
   colisao.colisao[31].height=0;
   //
   //Arame 
   colisao.colisao[32].x= 0 ;
   colisao.colisao[32].y= 0;
   colisao.colisao[32].width= 0;
   colisao.colisao[32].height=0;
   //
   ////Arame 
   colisao.colisao[32].x= 0 ;
   colisao.colisao[32].y= 0;
   colisao.colisao[32].width= 0;
   colisao.colisao[32].height=0;
   //
   
   
    //Fim DAS COLISOES
    
    int tempoDoFrame=0;
    int frameAtual=0;
    
    while(*estadoFaseTres==0){
        //Atualização guardas 
        
        tempoDoFrame++;
        
        if(tempoDoFrame >= 10){
            
            tempoDoFrame=0;
            
            frameAtual++;
            
            if(frameAtual > 3){
                frameAtual=0;
            }
            
             for(int i=0;i<6;i++){
                
                guarda[i].imagem.x=(float) frameAtual*imagemGuardas.width/3;

             }    
        }
        
        for(int i=0;i<6;i++){
             
            if( i==5 ) moverGuardas(&imagemGuardas,&guarda[5],"vertical",320,700);
            else  if(i==4) moverGuardas(&imagemGuardas,&guarda[4],"vertical",0,700);  
            else moverGuardas(&imagemGuardas,&guarda[i],"horizontal",240,550+imagemGuardas.width/3);
             
         } //Fim atualização guardas
        
         //Atualização jogador 
          
        personagem_movimentacao(&jogador,&colisao,contador,NULL);
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
        
        ClearBackground(RAYWHITE);
        BeginDrawing();
        
        
        
            
            
        
        
         DrawTextureRec(campo,(Rectangle) {0.0f,0.0f,campo.width,campo.height},(Vector2) {0.0f,0.0f},WHITE );
         
         if(!cortouArame) DrawTextureRec(arame,(Rectangle){0.0f,0.0f,arame.width,arame.height},(Vector2){ 0.0f,0.0f },WHITE);
         
         DrawText(FormatText("%f||%f",jogador.posicao_quadrado.x,jogador.posicao_quadrado.y),100,800,50,RED);
         
         draw_jogador(&jogador);
         
         for(int i=0;i<6;i++){
             
               desenharGuardas(&imagemGuardas,&guarda[i]);
               
         }
         
         for(int i=0;i<6;i++){
             
             if(i == 4 || i==5 ) desenharCampoDeVisao(&guarda[i],"vertical",&imagemGuardas);
             else                desenharCampoDeVisao(&guarda[i],"horizontal",&imagemGuardas);
             
             
         }
        
        
         if(IsKeyDown(KEY_E)  && achouObjeto==1 ){
        
           if(estanteSala1[0].interagiuComJogador==1){
            
                procurarItem(estanteSala1[0],procurando,&jogador,jogador.posicao_quadrado.x,jogador.posicao_quadrado.y,&pegouAlicate);
                
                
           }else
             if(estanteSala1[1].interagiuComJogador==1){
            
                procurarItem(estanteSala1[1],procurando,&jogador,jogador.posicao_quadrado.x,jogador.posicao_quadrado.y,&pegouAlicate);
                 
             }else if(estanteSala2[0].interagiuComJogador==1){
                 
                procurarItem(estanteSala2[0],procurando,&jogador,jogador.posicao_quadrado.x,jogador.posicao_quadrado.y,&pegouMartelo);
                 
             }else if(estanteSala2[1].interagiuComJogador==1){
                 
                procurarItem(estanteSala2[1],procurando,&jogador,jogador.posicao_quadrado.x,jogador.posicao_quadrado.y,&pegouMartelo);
                 
             }
            
     
         //esntate da sala 1
         }else if( jogador.posicao_quadrado.x >= estanteSala1[0].x &&jogador.posicao_quadrado.x <= estanteSala1[0].x+30 && jogador.posicao_quadrado.y>=estanteSala1[0].y && jogador.posicao_quadrado.y<=estanteSala1[0].y+estanteImagem.height+10 ){
             
             DrawText("sjlifs",0,700,30,RED);
             
             DrawTextureRec(mensagemProcurar,(Rectangle) {0.0f,0.0f,mensagemProcurar.width,mensagemProcurar.height},(Vector2){jogador.posicao_quadrado.x,jogador.posicao_quadrado.y-mensagemProcurar.height},WHITE);
             achouObjeto=1;
             estanteSala1[0].interagiuComJogador=1;  
        
         //esntate da sala 2                   
           }else if(jogador.posicao_quadrado.x >= estanteSala1[1].x &&jogador.posicao_quadrado.x <= estanteSala1[1].x+30 && jogador.posicao_quadrado.y>=estanteSala1[1].y && jogador.posicao_quadrado.y<=estanteSala1[1].y+estanteImagem.height+10){
               
             DrawTextureRec(mensagemProcurar,(Rectangle) {0.0f,0.0f,mensagemProcurar.width,mensagemProcurar.height},(Vector2){jogador.posicao_quadrado.x,jogador.posicao_quadrado.y-mensagemProcurar.height},WHITE);
             achouObjeto=1;
           estanteSala1[1].interagiuComJogador=1;
           
           }else if(jogador.posicao_quadrado.x >= estanteSala2[0].x &&jogador.posicao_quadrado.x <= estanteSala2[0].x+30 && jogador.posicao_quadrado.y>=estanteSala2[0].y && jogador.posicao_quadrado.y<=estanteSala2[0].y+estanteImagem.height+10){
               
             DrawTextureRec(mensagemProcurar,(Rectangle) {0.0f,0.0f,mensagemProcurar.width,mensagemProcurar.height},(Vector2){jogador.posicao_quadrado.x,jogador.posicao_quadrado.y-mensagemProcurar.height},WHITE);
             achouObjeto=1;
           estanteSala2[0].interagiuComJogador=1;
           
           } else if(jogador.posicao_quadrado.x >= estanteSala2[1].x &&jogador.posicao_quadrado.x <= estanteSala2[1].x+30 && jogador.posicao_quadrado.y>=estanteSala2[1].y && jogador.posicao_quadrado.y<=estanteSala2[1].y+estanteImagem.height+10){
               
             DrawTextureRec(mensagemProcurar,(Rectangle) {0.0f,0.0f,mensagemProcurar.width,mensagemProcurar.height},(Vector2){jogador.posicao_quadrado.x,jogador.posicao_quadrado.y-mensagemProcurar.height},WHITE);
             achouObjeto=1;
           estanteSala2[1].interagiuComJogador=1;
          
          }else{
               
             achouObjeto=0; 
             estanteSala1[0].interagiuComJogador=0;
             estanteSala1[1].interagiuComJogador=0;
             estanteSala2[0].interagiuComJogador=0;
             estanteSala2[1].interagiuComJogador=0;
            
          }
               if(pegouAlicate && jogador.posicao_quadrado.x>= 618 && jogador.posicao_quadrado.x< 635    && jogador.posicao_quadrado.y > 326 &&  jogador.posicao_quadrado.y < 326+45){
                               
                 DrawTextEx(fonte,"Aperte E para cortar",(Vector2){jogador.posicao_quadrado.x,jogador.posicao_quadrado.y-22},22,1,BLACK);
                 
                 if(IsKeyDown(KEY_E)){
                     
                  tirarObstaculo(&jogador,&cortouArame);
                    
                    colisao.colisao[28].x=0;
                    colisao.colisao[28].y=0;
                    colisao.colisao[28].width=0;
                    colisao.colisao[28].height=0;
                    pegouAlicate=0;
                     
                 } 
            }  
            
             if(pegouMartelo && jogador.posicao_quadrado.x>= 394 && jogador.posicao_quadrado.x< 635    && jogador.posicao_quadrado.y > 326 &&  jogador.posicao_quadrado.y < 326+45){
                               
                 DrawTextEx(fonte,"Aperte E para cortar",(Vector2){jogador.posicao_quadrado.x,jogador.posicao_quadrado.y-22},22,1,BLACK);
                 
                 if(IsKeyDown(KEY_E)){
                     
                  tirarObstaculo(&jogador,&quebrouVaso);
                    
                    colisao.colisao[29].x=0;
                    colisao.colisao[29].y=0;
                    colisao.colisao[29].width=0;
                    colisao.colisao[29].height=0;
                    pegouMartelo=0;
                     
                 } 
            }  
                
                
           
          if(jogador.item==1 && pegouAlicate){
                
                DrawTextureRec(alicate,(Rectangle) {0.0f,0.0f,alicate.width,alicate.height}, (Vector2) {1300,700},WHITE );
                
    
    }
    
        if(pegouMartelo){
            
                DrawTextureRec(martelo,(Rectangle) {0.0f,0.0f,martelo.width,martelo.height}, (Vector2) {1300,700},WHITE );
            
            
        }
                
            
        
        
        
        EndDrawing();
        
            jogador.contador = 0;
        
    }//fim while
    
    UnloadTexture(campo);
    UnloadTexture(alicate);
    
}