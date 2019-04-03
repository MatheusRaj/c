/*
	Versao do programa que implementa a lista linear de
	alunos por ENCADEAMENTO.
	Utiliza descritor de lista estruturado e subrotinas.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

struct regLista {char RA[14], discip[7];
				 float nota;
				 int faltas;
				 struct regLista *prox;
				};
typedef struct regLista TNo;

typedef struct {TNo *inicio, *final;
				int qtde;
				} TDescr;

void InicializaLista(TDescr *);
int IncluiAluno(TDescr *, TNo);
void ImprimeLista(TDescr *, char *);

int main()
{	TNo vInfo, *aux, *ant;
	TDescr lista;
	char apagou;

	InicializaLista(&lista);
	
	while (1)
	{	printf("\nInforme o RA: ");
		scanf("%13s", vInfo.RA);
		
		if (strcmp(vInfo.RA, "-1") == 0)
			break;
		
		printf("\nInforme a disciplina: ");
		scanf("%6s", vInfo.discip);
		
		printf("\nInforme a nota final: ");
		scanf("%f", &vInfo.nota);
		
		printf("\nInforme o total de faltas: ");
		scanf("%d", &vInfo.faltas);

		if (IncluiAluno(&lista, vInfo) == 2)
		{	puts("Memoria insuficiente para esta operacao.");
			return 2;
		}
	}
	
	ImprimeLista(&lista, "Lista de alunos");

	while (1)
	{	printf("Informe a disciplina: ");
		scanf("%6s", vInfo.discip);
	
		if (strcmp(vInfo.discip, "-1") == 0)
			break;
		
		apagou = 0;
		aux = lista.inicio;
		ant = NULL;
		while (aux != NULL)
		{	if (strcmp(aux->discip, vInfo.discip) == 0)
			{	if (ant == NULL)
					lista.inicio = aux->prox;
				else
					ant->prox = aux->prox;
		
				if (aux->prox == NULL)
					lista.final = ant;
				
				free(aux);
			
				if (ant == NULL)
					aux = lista.inicio;
				else
					aux = ant->prox;
			
				apagou = 1;
				lista.qtde = lista.qtde - 1;
			}
			else
			{	ant = aux;
				aux = aux->prox;
			}
		}
	
		if (!apagou)
			puts("Disciplina nao encontrada");
		else
			ImprimeLista(&lista, "Nova lista de alunos");
	}
	
	return 0;
}

void InicializaLista(TDescr *lista)
{	lista->inicio = NULL;
	lista->final = NULL;
	lista->qtde = 0;
}

int IncluiAluno(TDescr *lista, TNo pInfo)
{	TNo *aux;

	aux = (TNo *) malloc(sizeof(TNo));
	if (aux == NULL)
		return 2;

	strcpy(aux->RA, pInfo.RA);
	strcpy(aux->discip, pInfo.discip);
	aux->nota = pInfo.nota;
	aux->faltas = pInfo.faltas;
	aux->prox = NULL;
		
	if (lista->inicio == NULL)
		lista->inicio = aux;
	else
		lista->final->prox = aux;
		
	lista->final = aux;
	lista->qtde = lista->qtde + 1;
	
	return 0;
}

void ImprimeLista(TDescr *lista, char *cabec)
{	TNo *aux;
	int TotAprov;
	
	if (lista->inicio == NULL)
		puts("Lista vazia");
	else
	{	TotAprov = 0;
	
		printf("\n%s\n\n", cabec);
		aux = lista->inicio;
		while (aux != NULL)
		{	printf("%s %s %6.2f %3d\n", aux->RA, aux->discip,
					aux->nota, aux->faltas);
				
			if (aux->nota >= 6 && aux->faltas <= 20)
				TotAprov = TotAprov + 1;
		
			aux = aux->prox;
		}
		printf("\n%d alunos, %d aprovados\n", lista->qtde, TotAprov);
	}
}