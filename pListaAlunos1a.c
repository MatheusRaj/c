/*
	Versao inicial do programa que implementa a lista
	linear de alunos por ENCADEAMENTO.
	Faz apenas a inclusão e a impressão dos dados.
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

void ImprimeLista(TNo *, char *);

int main()
{	TNo vInfo, *inicio, *aux, *ant;
	char apagou;
	
	inicio = NULL;
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
		
		aux = (TNo *) malloc(sizeof(TNo));
		if (aux == NULL)
		{	puts("Memoria insuficiente para esta operacao.");
			return 2;
		}

		strcpy(aux->RA, vInfo.RA);
		strcpy(aux->discip, vInfo.discip);
		aux->nota = vInfo.nota;
		aux->faltas = vInfo.faltas;
		aux->prox = NULL;
		
		if (inicio == NULL)
			inicio = aux;
		else
			ant->prox = aux;
		
		ant = aux;
	}
	
	ImprimeLista(inicio, "Lista de alunos");

	while (1)
	{	printf("Informe a disciplina: ");
		scanf("%6s", vInfo.discip);
	
		if (strcmp(vInfo.discip, "-1") == 0)
			break;
		
		apagou = 0;
		aux = inicio;
		ant = NULL;
		while (aux != NULL)
		{	if (strcmp(aux->discip, vInfo.discip) == 0)
			{	if (ant == NULL)
					inicio = aux->prox;
				else
					ant->prox = aux->prox;
		
				free(aux);
			
				if (ant == NULL)
					aux = inicio;
				else
					aux = ant->prox;
			
				apagou = 1;
			}
			else
			{	ant = aux;
				aux = aux->prox;
			}
		}
	
		if (!apagou)
			puts("Disciplina nao encontrada");
		else
			ImprimeLista(inicio, "Nova lista de alunos");
	}
	
	return 0;
}

void ImprimeLista(TNo *i, char *cabec)
{	TNo *aux;
	int TotAlunos, TotAprov;
	
	if (i == NULL)
		puts("Lista vazia");
	else
	{	TotAlunos = 0;
		TotAprov = 0;
	
		printf("\n%s\n\n", cabec);
		aux = i;
		while (aux != NULL)
		{	printf("%s %s %6.2f %3d\n", aux->RA, aux->discip,
					aux->nota, aux->faltas);
				
			TotAlunos = TotAlunos + 1;
			if (aux->nota >= 6 && aux->faltas <= 20)
				TotAprov = TotAprov + 1;
		
			aux = aux->prox;
		}
		printf("\n%d alunos, %d aprovados\n", TotAlunos, TotAprov);
	}
}
