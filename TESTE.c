#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h>
#include <ctype.h>
#include<windows.h>
#include<math.h>
//#include "Lista.h"
//#include "ArvoreBinaria.h"
#include "TabelaHash.h"
#include "Extra.h"

int main(){
    SetConsoleOutputCP(CP_UTF8);

    printf("\n\nARQUIVO DE TESTES\n\n");

    int extra, chave;
    Equipamento *Hash[47] = {NULL};
    //limpando_buffer();

        extra = VerificaID();
        chave = CalculaChave(extra);

    printf("\nA chave foi: %d\n ", chave);

    inserirEqui(Hash, chave, extra);
    ImprimeEqui(Hash[chave]->dados);

    printf("\nFez isso??\n");

    int chave2;
        extra = VerificaID();
        chave2 = CalculaChave(extra);
        printf("\nFez nova chave?? %d", chave2);


    liberaTabela(Hash);

return 0;
}
