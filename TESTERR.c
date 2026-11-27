#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h>
#include <ctype.h>
#include<windows.h>
#include<math.h>
#include "ArvoreBinaria.h"
#include "TabelaHash.h"
#include "Extra.h"

int main(){
    SetConsoleOutputCP(CP_UTF8);

    printf("\n\nARQUIVO DE TESTES\n\n");

    Equipamento *Hash[47] = {NULL};
    Arv* Arvoreee = CriaArv();

    DadosEqui a = {1011, "PC", NULL};
    DadosEqui b = {1100, "Monitor", NULL};
    DadosEqui c = {3456, "Mouse", NULL};
    DadosEqui d = {1456, "Teclado", NULL};

    inserirEqui(Hash, CalculaChave(1011), a);
    inserirEqui(Hash, CalculaChave(1100), b);
    inserirEqui(Hash, CalculaChave(3456), c);
    inserirEqui(Hash, CalculaChave(1456), d);

    printf("%d\n", RemoveEqui(Hash, 1100));
    printf("%d\n", RemoveEqui(Hash, 1011));
    printf("%d\n", RemoveEqui(Hash, 1456));
    printf("%d\n", RemoveEqui(Hash, 1100));
    printf("%d\n", RemoveEqui(Hash, 3456));
    printf("%d\n", Hash[0] == NULL);
    liberaTabela(Hash);


    int extra, chave;

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

    printf("\nChegou no final do teste, agora insira o incidente");

    Incidente inci;

    inci.CodEqui = VerificaID();
    printf("\nInsira o código");
    inci.Grave = VerificaGrav();
    inci.NumIden = VerificaNumIdem();
    printf("\nbotou os valores");
    InsereInci(Arvoreee, inci);


    ImprimirArv(Arvoreee->raiz);

    Arvoreee = RemovInci(Arvoreee, inci.NumIden);

   printf("\nFinalizando Programa");
    liberaTabela(Hash);

return 0;
}
