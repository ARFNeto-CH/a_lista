#pragma once
#define _CRT_SECURE_NO_WARNINGS

struct no
{
    void*      item;
    struct no* proxima;
    struct no* anterior;
};  // no
typedef struct no Node;

struct a_propria_lista
{
    char*     nome;
    unsigned  quantos;
    unsigned  maximo;
    Node*     inicio;
    Node*     fim;
};
typedef struct a_propria_lista Lista;

Lista*      apagar(Lista*);
Lista*      criar(const char*);
int         define_maximo(Lista* l, const unsigned);
Lista*      inserir_na_ordem(void*, Lista*, int(*)(void*, void*));
Lista*      inserir_no_inicio(void*, Lista*);
Lista*      inserir_no_final(void*, Lista*);
int         listar(Lista*);
int         listar_do_seu_jeito(Lista*, int(*)(void*));
int         maximo(Lista*);
Node*       primeiro(Lista*);
Lista*      remover(void*, Lista*);
int         tamanho(Lista*);
Node*       ultimo(Lista*);
int         vazia(Lista*);

//fim