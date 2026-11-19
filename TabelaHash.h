#ifndef TABELAHASH_H_INCLUDED
#define TABELAHASH_H_INCLUDED

#define A (0.618)
#define M 47

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

//Função Hash - MULTIPLICAÇÃO

//   47*((codEqui * 0,618)%1) -> achar o menor inteiro do valor obtido
int CalculaChave (int nome){

    float outronome = (nome*0.618);
    outronome = fmodf(outronome, 1);
    outronome = outronome * 47;

    return (int)outronome;
}

Equipamento* CriaTabela(){
    Equipamento *E = (Equipamento*)malloc(M * sizeof(Equipamento));
    for(int i=0; i<M; i++){
        E[i].dados.CodEqui=0;
        E[i].dados.incidentesLista = NULL;
        E[i].dados.NomeEqui= '\0';


        E[i].prox = NULL;
    }
    return E;
}

Lista* CriaLista(void){
     Lista *l;
     l=(Lista*)malloc(sizeof(Lista));
     l->inicio = NULL;
   return l;
}

Lista* liberaLista (Lista* l)
{
    NoLista *aux;
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

void inserirEqui (Equipamento *tabela[], int codigo, DadosEqui infos){
    Equipamento *novo = (Equipamento*)malloc(sizeof(Equipamento));
    novo->dados = infos;
    novo->prox = NULL;

    Equipamento *aux = tabela[codigo];
    Equipamento *aux2=NULL;

    while(aux != NULL){ //nao tenho certeza sobre ess comparação, tem que ver se isso realmente funciona
        aux2 = aux;
        aux = aux->prox;
    }

    novo->prox = aux;
    if(aux2 == NULL){
        tabela[codigo] = novo;
    }
    else{
        aux2->prox = novo;
    }
}



int DisponivelCod(Equipamento *E[], int codigo, int chave){

    Equipamento *aux = E[chave];
    while(aux != NULL){
        if(aux->dados.CodEqui == codigo){
            printf("\nEsse código de equipamento ja está em uso\n");
            return 0;
        }
        aux = aux->prox;
    }
    return 1;
}

#endif // TABELAHASH_H_INCLUDED
