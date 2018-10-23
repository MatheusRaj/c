/*This code will return the frequency of characters of a string */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAMANHO 203


int main (){

  int count, i, j, k, l, aux = 0;
  char linha[TAMANHO], result[123];

  scanf("%d",&count);
  getc(stdin);

  //Recebe a linha
  for(i=0;i<count;i++){
    memset(result,0,sizeof(result));
    fgets(linha,TAMANHO,stdin);
    k=strlen(linha);
    for(j=0;j<k;j++) linha[j] = tolower(linha[j]);

    //O for para contar a frequencia
    for(j=0;j<k;j++){
      l = linha[j];
      result[l] += 1;
    }

    //O for para ver a maior frequencia
    for(aux=0,j='a';j<='z';j++) if(aux < result[j]) aux = result[j];

    //O for para imprimir as letras com mais frequencia
    for (j='a';j<='z';j++) if (aux == result[j]) printf("%c",j);

    printf("\n");

  }
  return 0;
}
