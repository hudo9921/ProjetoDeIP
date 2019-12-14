#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "guardas.h"
#include "portas.h"
#include "jogador.h"
#include "cronometro.h"
#include "fase2.h"

#include "fase3.h"

int main()
{
    int largura = GetScreenWidth();
    int altura =GetScreenHeight();
    int estadofasetres=0;
    InitWindow(largura,altura,"Jogo");
    SetTargetFPS(60);
    comecarFaseTres(&estadofasetres,1);
    CloseWindow();


    return 0;
}