/*
	Arquivo fonte do programa inicial que opera sobre numeros racionais,
	com as definicoes de tipo de dados e subrotinas.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {int num, den;} TRac;

TRac SomaRac(TRac, TRac);
TRac SubtraiRac(TRac, TRac);
TRac MultRac(TRac, TRac);
TRac DivRac(TRac, TRac);
TRac SimplRac(TRac);
int mdc(int, int);

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

TRac SomaRac(TRac n1, TRac n2)
{	TRac res;

	res.num = n1.num * n2.den + n2.num * n1.den;
	res.den = n1.den * n2.den;
	
	return res;
}

TRac SubtraiRac(TRac n1, TRac n2)
{	TRac res;

	res.num = n1.num * n2.den - n2.num * n1.den;
	res.den = n1.den * n2.den;
	
	return res;
}

TRac MultRac(TRac n1, TRac n2)
{	TRac res;

	res.num = n1.num * n2.num;
	res.den = n1.den * n2.den;
	
	return res;
}

TRac DivRac(TRac n1, TRac n2)
{	TRac res;

	res.num = n1.num * n2.den;
	res.den = n2.num * n1.den;
	
	return res;
}

TRac SimplRac(TRac n1)
{	TRac res;

	res.num = n1.num / mdc(n1.num, n1.den);
	res.den = n1.den / mdc(n1.num, n1.den);
	
	return res;
}

int mdc(int m, int n)
{	if (m < 0) m = -m;
	if (n < 0) n = -n;

	if (m % n == 0)
		return n;
	else
		return mdc(n, m % n);
}
