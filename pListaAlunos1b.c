/*
	Versao inicial do programa que implementa a lista
	linear de alunos por CONTIGUIDADE.
	Faz apenas a inclusão e a impressão dos dados.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define FALSE 0
#define TRUE  1

#define QTDE_ELEMS		500

struct regLista {char RA[14], discip[7];
				 float nota;
				 int faltas;
				};
typedef struct regLista TNo;

TNo alunos[QTDE_ELEMS];

void ImprimeLista(TNo *, int, char *);

int main()
{	TNo vInfo;
	int qtde, i, x;
	char apagou;

	qtde = 0;
	while (1)
	{	printf("\nInforme o RA: ");
		scanf("%13s", vInfo.RA);
		
		if (strcmp(vInfo.RA, "-1") == 0)
			break;
		
		if (qtde == QTDE_ELEMS)
		{	puts("Memoria insuficiente para esta operacao.");
			return 2;
		}
		printf("\nInforme a disciplina: ");
		scanf("%6s", vInfo.discip);
		
		printf("\nInforme a nota final: ");
		scanf("%f", &vInfo.nota);
		
		printf("\nInforme o total de faltas: ");
		scanf("%d", &vInfo.faltas);
		
		alunos[qtde] = vInfo;
		qtde = qtde + 1;
	}
	
	ImprimeLista(alunos, qtde, "Lista de alunos");

	while (TRUE)
	{	printf("Informe a disciplina: ");
		scanf("%6s", vInfo.discip);
		
		if (strcmp(vInfo.discip, "-1") == 0)
			break;
	
		apagou = FALSE;
		i = 0;
		while (i < qtde)
		{	if (strcmp(alunos[i].discip, vInfo.discip) == 0)
			{	x = i;
				while (x < qtde - 1)
				{	alunos[x] = alunos[x + 1];
					x = x + 1;
				}
		
				qtde = qtde - 1;
				apagou = TRUE;
			}
			else
				i = i + 1;
		}
	
		if (apagou == FALSE)
			puts("Disciplina nao encontrada");
		else
			ImprimeLista(alunos, qtde, "Nova lista de alunos");
	}
	
	return 0;
}

void ImprimeLista(TNo *alunos, int qtde, char *cabec)
{	int TotAprov, i;

	if (qtde == 0)
		puts("Lista vazia");
	else
	{	TotAprov = 0;
	
		printf("\n%s\n\n", cabec);
		i = 0;
		while (i < qtde)
		{	printf("%s %s %6.2f %3d\n", alunos[i].RA, alunos[i].discip,
					alunos[i].nota, alunos[i].faltas);
				
			if (alunos[i].nota >= 6 && alunos[i].faltas <= 20)
				TotAprov = TotAprov + 1;
		
			i = i + 1;
		}
		printf("\n%d alunos, %d aprovados\n", qtde, TotAprov);
	}
}
