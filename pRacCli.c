/*
	Arquivo cliente para a manipulacao de numeros racionais via TDA.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "TRac.h"

int main()
{	TRac X, Y, R, b;

	printf("Informe X: ");
	scanf("%d/%d", &X.num, &X.den);
	
	printf("Informe Y: ");
	scanf("%d/%d", &Y.num, &Y.den);
	
	R = SomaRac(X, Y);	
	printf("\n%d/%d + %d/%d = %d/%d\n", X.num, X.den,
										Y.num, Y.den,
										R.num, R.den);
	R = SubtraiRac(X, Y);	
	printf("\n%d/%d - %d/%d = %d/%d\n", X.num, X.den,
										Y.num, Y.den,
										R.num, R.den);
	R = MultRac(X, Y);	
	printf("\n%d/%d * %d/%d = %d/%d\n", X.num, X.den,
										Y.num, Y.den,
										R.num, R.den);
	R = DivRac(X, Y);	
	printf("\n%d/%d / %d/%d = %d/%d\n", X.num, X.den,
										Y.num, Y.den,
										R.num, R.den);
	b = R;
	R = SimplRac(b);
	printf("\n%d/%d = %d/%d\n", b.num, b.den,
								R.num, R.den);
								
	return 0;
}
