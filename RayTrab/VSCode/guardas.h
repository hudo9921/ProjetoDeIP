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
             
        if(guarda->y+imagem->height/4 == fimTela){
            
            guarda->movimento=-guarda->movimento;
            guarda->imagem.y=imagem->height/4;
            guarda->sentidoCampoDeVisao= -guarda->sentidoCampoDeVisao;
            
        }else if (guarda->y == comecoTela){
            
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
        
        DrawRectangle(guarda->x+(guarda->sentidoCampoDeVisao*imagem->width/3),guarda->y,guarda->campoDeVisao,imagem->height/4,BLANK);	
        
        }else{
            
            DrawRectangle(guarda->x+(guarda->sentidoCampoDeVisao*guarda->campoDeVisao),guarda->y,guarda->campoDeVisao,imagem->height/4,BLANK);	
        }
        
}else{
    if(guarda->sentidoCampoDeVisao > 0 ){
        
        DrawRectangle(guarda->x-imagem->width/9,guarda->y+(guarda->sentidoCampoDeVisao*imagem->height/4),imagem->height/4,guarda->campoDeVisao,GREEN);
          
    }else{
                       
        DrawRectangle(guarda->x-imagem->width/9,guarda->y+(guarda->sentidoCampoDeVisao*guarda->campoDeVisao
        ),imagem->height/4,guarda->campoDeVisao,GREEN);
                    
        }
   }

    }


void seEntrouNoCampoDeVisao(Guardas* guarda,Texture2D* imagem,char direcao[12],int xJogador,int yJogador, Texture2D imagemJogador,int* estadoFase){
    
      if(strcmp(direcao,"horizontal")==0){
      
        if(guarda->sentidoCampoDeVisao > 0){
       
           
            if(  xJogador + imagemJogador.width/2 >= guarda->x && xJogador - imagemJogador.width/2 < guarda->x + guarda->campoDeVisao && yJogador + imagemJogador.height >= guarda->y && yJogador < guarda->y + imagem->height/4 ){
          
        
                *estadoFase=-1;
            
            }
       
        }else {
            
            if(xJogador + imagemJogador.width/2 >= guarda->x-guarda->campoDeVisao  && xJogador < guarda->x+imagem->width/3 && yJogador + imagemJogador.height >= guarda->y && yJogador < guarda->y+imagem->height/4){
           
        
                
            *estadoFase=-1;
            
       }
       
}
}else if(strcmp(direcao,"vertical")==0){
    
    
    if(guarda-> sentidoCampoDeVisao > 0){
        
        if(yJogador+imagemJogador.width/2 >= guarda->y && yJogador - imagemJogador.width/2 < guarda->y + guarda->campoDeVisao && xJogador + imagemJogador.width/2 >= guarda->x && xJogador < guarda->x + imagem->width/3 ){
            
        *estadoFase=-1;

          DrawText("qweqweqw",  300,300,50,BLACK);
        }
        
        
    }else{
       
        if(yJogador + imagemJogador.width/2 >= guarda->y-guarda->campoDeVisao  && yJogador < guarda->y+imagem->height/4 && xJogador + imagemJogador.width/2 >= guarda->x && xJogador < guarda->x+imagem->width/3){
           
          *estadoFase=-1;
          DrawText("qweqweqw",  300,300,50,BLACK);
                
            
       }
        
    }
    
    
}else{   

    
  *estadoFase=0;


 } 

}



