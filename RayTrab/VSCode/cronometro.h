#ifndef CRONOMETRO_H
#define CRONOMETRO_H

typedef struct{

    
int tempo;
int minutos;
int segundos;



}Cronometro; 

#endif


void contarTempo(Cronometro* cronometro){

    
      if(cronometro->tempo%60==0)
        {
            cronometro->tempo=0;
            cronometro->segundos++; 
        }




}