#include <stdio.h>
#include <stdlib.h>
#define M 1005

int p[M], v[M], T[M][M];

inline int max(int a, int b){
	return a > b ? a : b;
}

int main(){
	
	int W = 0, n = 0, i = 0, j = 0, k = 1;
	
	while(1){
		scanf("%d %d", &W, &n);
		
		if(!W && !n)
			break;

		for(i = 0; i <= W; i++)
			T[0][i] = 0;
			
		for(i = 0; i <= n; i++)
			T[i][0] = 0;

		for(i = 1; i <= n; i++)
			scanf("%d %d", &p[i], &v[i]);

		for(i = 1; i <= n; i++){
			for(j = 1; j <= W; j++){
				if(p[i] <= j)
					T[i][j] = max(T[i - 1][j], T[i - 1][j - p[i]] + v[i]);
				else
					T[i][j] = T[i - 1][j];
			}
		}

		printf("Teste %d\n%d\n\n", k++, T[n][W]);
	}
	
	return 0;
}
