#include <stdio.h>
struct regLista {int valor;
				 struct regLista *prox;
				};

int main()
{	printf("%d\n",sizeof(struct regLista));

	return 0;
}
