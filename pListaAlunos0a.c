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

int main()
{	TNo vInfo, *inicio, *aux, *ant;
	int TotAlunos, TotAprov;

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
	
	TotAlunos = 0;
	TotAprov = 0;
	
	printf("\nLista de alunos\n\n");
	aux = inicio;
	while (aux != NULL)
	{	printf("%s %s %6.2f %3d\n", aux->RA, aux->discip,
				aux->nota, aux->faltas);
				
		TotAlunos = TotAlunos + 1;
		if (aux->nota >= 6 && aux->faltas <= 20)
			TotAprov = TotAprov + 1;
		
		aux = aux->prox;
	}
	printf("\n%d alunos, %d aprovados\n", TotAlunos,
			TotAprov);
	
	return 0;
}
