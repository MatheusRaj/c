#include <stdio.h>
#include <math.h>

float media(float *p, int n);

float variancia(float *p, float m, int n);

int main(){

  int n, i;
  float vetor[100];

  scanf("%d",&n);

  for(i=0;i<n;i++) scanf("%f",&vetor[i]);

  float m = media(vetor, n);

  float v = variancia(vetor, m, n);

  printf("Media: %.4f Variancia: %.4f\n",m,v);

  return 0;
}

float media(float *p, int n){

  int i;
  float m=0, o = n;
  for(i=0;i<n;i++) m += p[i];
  return m/o;
}

float variancia(float *p, float m, int n){

  int i;
  float x=0, o = n;
  for(i=0;i<n;i++) {
    x += pow(p[i] - m,2);
  }
  return x/o;
}
