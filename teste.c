#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>                               
#include <stdlib.h>
#include <string.h>

#include "lista.h"

int compara_int(void*, void*);
int compara_int_decresc(void* a, void* b);
int lista_item(void* item);

void teste_0();
void teste_1();
void teste_2();
void teste_3();
void teste_4();
void teste_5();
void teste_6();
void teste_7();

int main(int argc, char** argv)
{
	unsigned n = 0;
	int res = 0;

	teste_0();
	teste_1();
	teste_2();
	teste_3();
	teste_4();
	teste_5();
	teste_6();
	teste_7();
	return 0;
};  // main()

int compara_int(void* a, void* b)
{
	int primeiro = *(int*)a;
	int segundo = *(int*)b;
	if (primeiro == segundo) return 0;
	if (primeiro < segundo) return -1;
	return 1;
};  // compara_int()

int compara_int_decresc(void* a, void* b)
{
	int primeiro = *(int*)a;
	int segundo = *(int*)b;
	if (primeiro == segundo) return 0;
	if (primeiro > segundo) return -1;
	return 1;
};  // compara_int()

int lista_item(void* item)
{
	/*
	isso aqui e so para ilustrar. Esse item poderia ser um 
	registro complexo de cadastro com varios itens para 
	ajustar na tela. Fazendo assim so precisa pasar a funcao
	e se muda o layout e so mudar a funcao...
	*/
	int e = *(int*)item;
	printf("    [ %8d ]\n", e);
	return 0;
};  // listar()

void teste_0()
{
	unsigned n = 0;
	int res = 0;
	Lista* teste = criar("Primeira Lista");
	res = listar(teste);
	printf("listar() retornou %d\n", res);
};

void teste_1()
{
	int n = 0;
	int res = 0;
	Lista* teste = criar("Primeira Lista");

	res = listar(teste);
	printf("listar() retornou %d\n", res);

	n = 100;
	res = define_maximo(teste, n);
	printf("define_maximo(%d) retornou %d\n", n, res);

	res = listar(teste);
	printf("listar() retornou %d\n", res);

	res = tamanho(teste);
	printf("tamanho() retornou %d\n", res);

	if (vazia(teste))
	{
		printf("Lista '%s' vazia\n", teste->nome);
	}
	else
	{
		printf("Lista '%s' Nao esta vazia\n", teste->nome);
	};  // if()

};  // teste_1()

void teste_2()
{
	//
	// agora vamos criar uma lista de int
	// e inserir no inicio
	//
	unsigned n = 0;
	int res = 0;
	Lista* teste = criar("Primeira Lista");
	int* novo;
	for (int i = 0; i < 10; i += 1)
	{
		novo = (int*)malloc(sizeof(int));
		*novo = i;
		inserir_no_inicio((void*)novo, teste);
		printf("inserido %d no inicio\n", *novo);
	};  // for()

	res = tamanho(teste);
	printf("tamanho() retornou %d\n", res);

	listar(teste);

	//
	// agora vamos criar outros int 
	// e inserir no final
	//
	for (int i = 10; i < 20; i += 1)
	{
		novo = (int*)malloc(sizeof(int));
		*novo = i;
		inserir_no_final((void*)novo, teste);
		printf("inserido %d no final\n", *novo);
	};  // for()

	res = tamanho(teste);
	printf("tamanho() retornou %d\n", res);

	listar(teste);
	// agora apaga de vez a lista
	teste = apagar(teste);
	listar(teste);

};  // teste_2()

void teste_3()
{
	unsigned n = 0;
	int res = 0;
	Lista* teste = criar("Primeira Lista");
	int* novo;

	//
	// insere primeiro no fim depois no inicio
	// agora cria de novo a lista
	//

	teste = criar("Outra lista");
	res = listar(teste);
	printf("listar() retornou %d\n", res);

	n = 100;
	res = define_maximo(teste, n);
	printf("define_maximo(%d) retornou %d\n", n, res);

	res = listar(teste);
	printf("listar() retornou %d\n", res);

	res = tamanho(teste);
	printf("tamanho() retornou %d\n", res);

	if (vazia(teste))
	{
		printf("Lista '%s' vazia\n", teste->nome);
	}
	else
	{
		printf("Lista '%s' Nao esta vazia\n", teste->nome);
	}

	for (int i = 10; i < 20; i += 1)
	{
		novo = (int*)malloc(sizeof(int));
		*novo = i;
		teste = inserir_no_final((void*)novo, teste);
		printf("inserido %d no final\n", *novo);
	};  // for()

	res = tamanho(teste);
	printf("tamanho() retornou %d\n", res);

	listar(teste);
	for (int i = 0; i < 10; i += 1)
	{
		novo = (int*)malloc(sizeof(int));
		*novo = i;
		teste = inserir_no_inicio((void*)novo, teste);
		printf("inserido %d no inicio\n", *novo);
	};  // for()

	res = tamanho(teste);
	printf("tamanho() retornou %d\n", res);

	printf("\n\n\n************\n\nAntes de teste: na ordem\n");
	listar(teste);
	teste = apagar(teste);
};  // teste_3()

void teste_4()
{
	unsigned n = 0;
	int res = 0;
	int* novo;
	Lista* teste = criar("Testando na ordem");
	listar(teste);

	// a ideia aqui: inserir 
	// uns pares de 2 a 24 no final. entao vao ficar na ordem
	// depois vamos inserir os impares de 1 a 31
	// na ordem para ver se fica tudo intercalado

	for (int i = 2; i < 25; i += 2)
	{
		novo = (int*)malloc(sizeof(int));
		*novo = i;
		inserir_no_final((void*)novo, teste);
	};  // for()
	listar(teste);
	printf("Na ordem de 1 a 31 impares\n");
	for (int i = 1; i < 32; i += 2)
	{
		novo = (int*)malloc(sizeof(int));
		*novo = i;
		// mandamos inserir usando a funcao que escrevemos
		// para comparar
		teste = inserir_na_ordem((void*)novo, teste, compara_int);
	};	// for()
	listar(teste);
	teste = apagar(teste);
};  // teste_4()

void teste_5()
{
	unsigned n = 0;
	int res = 0;
	int* novo;
	Lista* teste = criar("Testando na ordem");
	listar(teste);

	/*
		aqui uma situacao particular: inserir na ordem
		quando vai mudar o primeiro elemento. tem que
		acertar varios detalhes
	*/

	int i = 2;
	novo = (int*)malloc(sizeof(int));
	*novo = i;
	inserir_no_final((void*)novo, teste);
	listar(teste);

	i = 1;
	novo = (int*)malloc(sizeof(int));
	*novo = i;

	teste = inserir_na_ordem((void*)novo, teste, compara_int);
	listar(teste);
	teste = apagar(teste);
	return;

};  // teste_5()

void teste_6()
{
	unsigned n = 0;
	int res = 0;
	int* novo;
	Lista* teste = criar("Testando na ordem");
	listar(teste);

	/*
		aqui uma situacao particular: inserir na ordem
		quando vai mudar o ultimo elemento. tem que
		acertar varios detalhes
	*/

	int i = 1;
	novo = (int*)malloc(sizeof(int));
	*novo = i;
	inserir_no_final((void*)novo, teste);
	listar(teste);

	i = 2;
	novo = (int*)malloc(sizeof(int));
	*novo = i;

	teste = inserir_na_ordem((void*)novo, teste, compara_int);
	listar(teste);
	teste = apagar(teste);
	return;

};  // teste_6()

void teste_7()
{
	//
	// aqui vaos cahamr a listar() certa, a que nao 
	// assume nada sobre o conteudo de item. 
	// Seria como um map de javascript ou C++ ou java
	//
		unsigned n = 0;
	int res = 0;
	Lista* teste = criar("Nova Lista");
	int* novo;
	for (int i = 0; i < 10; i += 1)
	{
		novo = (int*)malloc(sizeof(int));
		*novo = i;
		teste = inserir_no_inicio((void*)novo, teste);
		printf("inserido %d no inicio\n", *novo);
	};  // for()

	res = tamanho(teste);
	printf("tamanho() retornou %d\n", res);

	//listar(teste);
	listar_do_seu_jeito(teste, lista_item);

	Node* prim = primeiro(teste);
	printf("primeiro() retornou %d\n", *(int*)prim->item);

	Node* ult = ultimo(teste);
	printf("ultimo() retornou %d\n", *(int*)ult->item);

	teste = apagar(teste);
};  // teste_7() 
