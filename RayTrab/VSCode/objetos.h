#ifndef OBJETOS_H
#define OBJETOS_H

typedef struct{


    int x;
    int y;
    int possuiItem;
    int numeroIdentificador;
    int interagiuComJogador;
    Texture2D imagem;
    


}Objetos;


#endif

void procurarItem(Objetos objeto,Texture2D imagem,Jogador* jogador,int xJogador,int yJogador,int* pegouItem){
   
        
       DrawTextureRec(imagem,(Rectangle){0.0f,imagem.height,imagem.width,imagem.height},(Vector2){ xJogador,yJogador},WHITE);
       
       
       
       if(objeto.possuiItem==1){
           
           jogador->item=1;    
           *pegouItem=1;
           
       }else{
           
           
       }
    
        
    
}
