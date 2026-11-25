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

    DadosEqui teste;
    teste.CodEqui = extra;
    teste.IL =NULL;
    teste.NomeEqui[0] = '\0';

    inserirEqui(Hash, chave, teste);
    ImprimeEqui(Hash[chave]->dados);

    printf("\nFez isso??\n");

    int chave2;
    do{
        extra = VerificaID();
       chave2 = CalculaChave(extra);
    }while(!Existe(Hash, chave2, extra));

    printf("\nA chave foi: %d\n ", chave);

    DadosEqui teste2;
    teste2.CodEqui = extra;
    teste2.IL =NULL;
    teste2.NomeEqui[0] = '\0';
        printf("\nFez nova chave?? %d", chave2);

    inserirEqui(Hash, chave2, teste2);
    ImprimeEqui(Hash[chave2]->dados);


    printf("\nChegou no final do teste 2");

    extra = VerificaID();
    chave2 = CalculaChave(extra);

    teste2.CodEqui = extra;
    teste2.IL =NULL;
    teste2.NomeEqui[0] = '\0';
        printf("\nFez nova chave?? %d", chave2);

    inserirEqui(Hash, chave2, teste2);
    ImprimeEqui(Hash[chave2]->dados);


    printf("\nChegou no final do teste 3");
    liberaTabela(Hash);

return 0;
}
