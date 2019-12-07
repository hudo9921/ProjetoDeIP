#include "raylib.h"
#include <string.h>
#ifndef GUARDAS_H
#define GUARDAS_H


typedef struct
{
   int x;
   int y;
   Rectangle imagem;
   int campoDeVisao;
   int movimento;
   int sentidoCampoDeVisao;
   
}Guardas;



#endif



void moverGuardas(Texture2D* imagem,Guardas* guarda,char direcao[12],int comecoTela,int fimTela){
    
    if(strcmp(direcao,"horizontal")==0){
        
       if(guarda->x+imagem->width/3 == fimTela ){
            
            guarda->movimento=-guarda->movimento;
            guarda->imagem.y=3*imagem->height/4;
            guarda->sentidoCampoDeVisao= -guarda->sentidoCampoDeVisao;
            
        }else if (guarda->x == comecoTela){
            
            guarda->imagem.y=2*imagem->height/4;   
            guarda->movimento=-guarda->movimento;
            guarda->sentidoCampoDeVisao= -guarda->sentidoCampoDeVisao;
            
        }
            
            guarda->x+=guarda->movimento;
        
        
    }else{
             
        if(guarda->y+imagem->height/4 == 0){
            
            guarda->movimento=-guarda->movimento;
            guarda->imagem.y=imagem->height/4;
            guarda->sentidoCampoDeVisao= -guarda->sentidoCampoDeVisao;
            
        }else if (guarda->y == 0){
            
            guarda->imagem.y=4*imagem->height/4;   
            guarda->movimento=-guarda->movimento;
            guarda->sentidoCampoDeVisao= -guarda->sentidoCampoDeVisao;
            
        }
            
            guarda->y+=guarda->movimento;
      
    }
       
}

void desenharGuardas(Texture2D* imagem,Guardas* guarda){
    
    DrawTextureRec(*imagem,guarda->imagem,(Vector2){ guarda->x,guarda->y},WHITE);
    
}

void desenharCampoDeVisao(Guardas* guarda,char direcao[12],Texture2D* imagem){

    if(strcmp(direcao,"horizontal")==0){
        if(guarda->sentidoCampoDeVisao>0){
        
        DrawRectangle(guarda->x+(guarda->sentidoCampoDeVisao*imagem->width/3),guarda->y,guarda->campoDeVisao,imagem->height/4,RED);	
        
        }else{
            
            DrawRectangle(guarda->x+(guarda->sentidoCampoDeVisao*guarda->campoDeVisao),guarda->y,guarda->campoDeVisao,imagem->height/4,RED);	
        }
        
}else{
    
     DrawRectangle(guarda->x,guarda->y+(guarda->sentidoCampoDeVisao*imagem->height/4),imagem->height/4,guarda->campoDeVisao,RED);
}

    }


void seEntrouNoCampoDeVisao(Guardas* guarda,Texture2D* imagem,char direcao[12],int xJogador,int yJogador, Texture2D imagemJogador,int* estadoFase){
    
      if(strcmp(direcao,"horizontal")==0){
      
        if(guarda->sentidoCampoDeVisao > 0){
       
           
            if(  xJogador + imagemJogador.width/2 >= guarda->x && xJogador - imagemJogador.width/2 < guarda->x + guarda->campoDeVisao && yJogador + imagemJogador.height >= guarda->y && yJogador < guarda->y + imagem->height/4 ){
          
          DrawText("Perdeu",600,600,50,WHITE);
                *estadoFase=-10;
            
            }
       
        }else {
            
            if(xJogador + imagemJogador.width/2 >= guarda->x-guarda->campoDeVisao  && xJogador < guarda->x+imagem->width/3 && yJogador + imagemJogador.height >= guarda->y && yJogador < guarda->y+imagem->height/4){
           
           DrawText("Perdeu",600,600,50,WHITE);
                
            *estadoFase=-10;
            
       }
       
}
}else if(strcmp(direcao,"vertical")){
    
    
}else{   

    
  *estadoFase=0;


 } 

}



