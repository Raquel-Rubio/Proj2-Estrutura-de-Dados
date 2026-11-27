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
//Funções do MAIN do proj 1

int VerificaPeriodo(int priori){
    int verif;
    if(priori==3){
        do{
            printf("\nPor favor insira o Período (1 a 20):   ");
            verif = PegarInteiros();
        }while(verif < 1 || verif > 20);

        return verif;

    }else{
        if(priori==2){
            do{
                printf("\nPor favor insira o Período (1 a 15):   ");
                verif = PegarInteiros();
            }while(verif < 1 || verif > 15);

            return verif;

        }else{
            do{
                printf("\nPor favor insira o Período (1 a 7):   ");
                verif = PegarInteiros();
            }while(verif < 1 || verif > 7);

          return verif;

        }
    }
}

int VPInterno(int priori, int perio){
    if(priori==3){
        if(perio < 1 || perio > 20){
            printf("\nNova prioridade não condiz com periodo já existente\n");
            return 0;
        }
        return 1;
    }else{
        if(priori==2){
            if(perio < 1 || perio > 15){
                printf("\nNova prioridade não condiz com periodo já existente\n");
                return 0;
            }
            return 1;
        }else{
            if(perio < 1 || perio > 7){
                printf("\nNova prioridade não condiz com periodo já existente\n");
                return 0;
            }
            return 1;
        }
    }
}

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
    teste.IL = NULL;
    teste.NomeEqui[0] = '\0';

    inserirEqui(Hash, chave, teste);
    ImprimeEqui(Hash, chave, teste.CodEqui);

    printf("\nFez isso??\n");

    int chave2;
    do{
        extra = VerificaID();
       chave2 = CalculaChave(extra);
    }while(!ExisteEqui(Hash, chave2, extra));

    printf("\nA chave foi: %d\n ", chave);

    DadosEqui teste2;
    teste2.CodEqui = extra;
    teste2.IL =NULL;
    teste2.NomeEqui[0] = '\0';
        printf("\nFez nova chave?? %d", chave2);

    inserirEqui(Hash, chave2, teste2);
    ImprimeEqui(Hash, chave2, teste2.CodEqui);


    printf("\nChegou no final do teste 2");

    extra = VerificaID();
    chave2 = CalculaChave(extra);

    teste2.CodEqui = extra;
    teste2.IL =NULL;
    teste2.NomeEqui[0] = '\0';
        printf("\nFez nova chave?? %d", chave2);

    inserirEqui(Hash, chave2, teste2);
    ImprimeEqui(Hash, chave2, teste2.CodEqui);


    printf("\nChegou no final do teste 3");
    liberaTabela(Hash);

return 0;
}
