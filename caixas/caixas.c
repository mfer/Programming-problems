#include <stdio.h>

inline int min(int a, int b){
	return a < b ? a : b;
}

int main(){
	
	int i = 0, j = 0, n = 0, p = 0, fila[1001], read = 0, L = 0, C = 0, topo = 0, esq = 0, dir = 0;
	
	while(1){
		
		scanf("%d %d", &n, &p);
		
		if(!n && !p)break;
		
		for(i = 0; i < p; i++){
			scanf("%d", &fila[i]);
			
			for(j = 0; j < fila[i]; j++){
				scanf("%d", &read);
				getchar();
				
				if(read == 1){
					C = i;
					L = j + 1;
				}
			}
		}
		
		topo = fila[C] - L;
		esq = topo;
		dir = topo;
		
		for(i = C - 1; i >= 0 && fila[i] >= L; i--)
			esq += fila[i] - L + 1;
		
		for(i = C + 1; i < p && fila[i] >= L; i++)
			dir += fila[i] - L + 1;
			
		printf("%d\n", min(dir, esq));
	}

	return 0;
}
