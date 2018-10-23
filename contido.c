/*This program will define if a point is contained or not*/
#include <stdio.h>

typedef struct {int x, y;} Tponto;

int contido(Tponto e, Tponto d, Tponto p);

int main(){
  Tponto esq, dir, point;
  int n;
  scanf("%d", &n);
  while (n--){
    scanf("%f %f %f %f %f %f", &esq.x, &esq.y, &dir.x, &dir.y, &point.x, &point.y);
    printf("%s\n", contido(esq, dir, point) ? "Contido" : "Nao-Contido");
  }
  return 0;
}

int contido(Tponto e, Tponto d, Tponto p){
  return p.x >= e.x && p.x <= d.x && p.y >= e.y && p.y <= d.y ? 1 : 0;
}
