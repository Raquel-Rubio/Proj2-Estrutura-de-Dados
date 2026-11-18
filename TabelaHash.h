#ifndef TABELAHASH_H_INCLUDED
#define TABELAHASH_H_INCLUDED

#define A (0,618)

typedef struct noLista{
    int ID;
    struct noLista *prox;
}NoLista;

typedef struct lista{
    NoLista *inicio;
}Lista;

typedef struct dadosEqui{
    int CodEqui;
    char NomeEqui[11];
    Lista *incidentesLista;
}DadosEqui;

typedef struct equipamento{
    DadosEqui dados;
    struct equipamento *prox;
}Equipamento;


void CalculaChave (int nome){
    printf("RECEBIDO: %d\n", nome);
    float roberto = (float) nome;
    printf("ROBERTO = %.2f\n", roberto);
    float outronome = (roberto*0,618555555);
    printf("TESTANDO0: %.2f\n", outronome);
    outronome = fmodf(outronome, 1);
    printf("TESTANDO1: %.2f\n", outronome);
    outronome = outronome * 47;
    printf("TESTANDO2: %.2f\n", outronome);


}
//Função Hash - MULTIPLICAÇÃO

//   47*((codEqui * 0,618)%1) -> achar o menor inteiro do valor obtido

/*
Lista* CriaLista(void){
     Lista *l;
     l=(Lista*)malloc(sizeof(Lista));
     l->inicio = NULL;
   return l;
}

Lista* liberaLista (Lista* l)
{
    No *aux;
    while(l->inicio!=NULL){
        aux = l->inicio;
        l->inicio = l->inicio->prox;
        free(aux);
    }
    free(l);
    return NULL;
}

void inserir (Lista *L, int num){
    NoLista *novo = (NoLista*)malloc(sizeof(NoLista));
    novo->ID = num;
    novo->prox = NULL;

    NoLista *aux;
    NoLista *aux2=NULL;
    aux = L ->inicio;
    while(aux!=NULL){
        aux2 = aux;
        aux = aux->prox;
    }

    novo->prox = aux;
    if(aux2 == NULL){
        L->inicio = novo;
    }
    else{
        aux2->prox = novo;
    }
}

void inserirEqui (Equipamento *tabela[], int codigo, dadosEqui infos){
    equipamento *novo = (equipamento*)malloc(sizeof(equipamento));
    novo->dados = infos;
    novo->prox = NULL;

    equipamento *aux;
    equipamento *aux2=NULL;

    if (tabela[codigo] == NULL){
        //coloca

    }

    aux = E ->inicio;
    while(aux!=NULL){
        aux2 = aux;
        aux = aux->prox;
    }

    novo->prox = aux;
    if(aux2 == NULL){
        E->inicio = novo;
    }
    else{
        aux2->prox = novo;
    }
}
*/


#endif // TABELAHASH_H_INCLUDED
