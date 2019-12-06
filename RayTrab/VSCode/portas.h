#include "raylib.h"

#ifndef PORTAS_H
#define PORTAS_H

typedef struct{
    
    int x;
    int y;
    int estadoDaPorta; //1=fechada, -1=aberta
    Rectangle imagem;
    
}Portas;

#endif

void mudarEstadoPorta( Portas* porta ){
    
    porta->estadoDaPorta = -porta->estadoDaPorta;
      
}

void desenharPorta(Portas* porta,Texture2D imagemPorta){
    
    if(porta->estadoDaPorta > 0){
        
            porta->imagem.y = 0;
            DrawTextureRec(imagemPorta,porta->imagem,(Vector2){ porta->x , porta->y },WHITE);
            
    }else{
        
            porta->imagem.y = imagemPorta.height/2;
            DrawTextureRec(imagemPorta,porta->imagem,(Vector2){ porta->x , porta->y },WHITE);
            
    }
    
}