#include <stdio.h>
 
#define MAX 1001
#define ELEMENTOS 40
 
int vetor[ELEMENTOS*MAX], elementos[ELEMENTOS], N, F;
 
void solve(int notToSolve) {
  int i;
  for (i = 0 ; i < MAX *  N ; i++)
    vetor[i] = 0;
  
  vetor[0] = 1;
  int j;
  for (i = 0 ; i < N ; i++) {
    if (i == notToSolve)
      continue;
    for (j = MAX*N - 1 ; j >= 0 ; j--) {
      if (vetor[j] == 1) {
        vetor[j + elementos[i] ] = 1;
      }
    }
  }
}
 
 
int returnTotal(int notToSolve) {
  int soma = 0;
  int i;
  for (i = 0 ; i < N ; i++)
    if (i != notToSolve)
      soma += elementos[i];
  
  return soma;
}
 
int main() {
  while (scanf("%d %d",&N,&F) && N) {
    int i, rv;
    for (i = 0 ; i < N ; i++)
      rv = scanf("%d",&elementos[i]);
    solve(-1);
 
    int total = returnTotal(-1);
 
    if (total < F || (total - F)%2 == 1 || vetor[(total-F)/2] == 0) 
      printf("*\n");
    else {
      for (i = 0 ; i < N ; i++) {
        solve(i);
        total = returnTotal(i);
        int seraPositivo = 0;
        int seraNegativo = 0;
        
        int newF1 = total - (F + elementos[i]);
        int newF2 = total - (F - elementos[i]);
        
        if (newF1 >= 0 && newF1%2 == 0 && vetor[newF1/2])
          seraNegativo = 1;
        if (newF2 >= 0 && newF2%2 == 0 && vetor[newF2/2])
          seraPositivo = 1;
        if (seraPositivo && seraNegativo)
          printf("?");
        else if (seraPositivo)
          printf("+");
        else
          printf("-");
      }
      printf("\n");
    }
  }
 
  return 0;
}
