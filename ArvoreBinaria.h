#ifndef ARVOREBINARIA_H_INCLUDED
#define ARVOREBINARIA_H_INCLUDED

typedef struct incidente{
    int NIdem;
    int CodEqui;
    int Grav;
}incidente;

typedef struct NoArvore{
    Dados info;
    NoArv *esq;
    NoArv *dir;
}NoArv;

typedef struct Arvore{
    NoArv *raiz;
}Arv;

Arv *CriaArv(){
    Arv *aux;
    aux = (Arv*)malloc(sizeof(Arv));
    aux->raiz = NULL;
    return aux;
}

NoArv *criar_no_abb (incidente dados);

NoArv *inserir_abb(NoArv *raiz, incidente dados);

NoArv *pesquisar_abb(NoArv *raiz, int id_incidente);

void listar_in_order(NoArv *raiz);

NoArv *remover_abb(NoArv *raiz, int id_incidente);

void liberar_arvore(NoArv *raiz);



#endif // ARVOREBINARIA_H_INCLUDED
