#include <stdio.h>

typedef struct {
	int placa, ant, prox;
} Vaga;

int main(){
	Vaga estac[1001];
	
	int c = 0, n = 0, i = 0, j = 0, p = 0, q = 0, queued = 0, tot = 0;
	char l;
	
	while(scanf("%d %d", &c, &n) != EOF){
		
		for(i = 0; i < c; i++){
			estac[i].placa = 0;
			estac[i].prox = 0;
			estac[i].ant = 0;
		}
		
		estac[0].prox = n - 1;
		estac[n - 1].ant = 0;
			
		queued = 0;
		tot = 0;
		
		for(i = 0; i < n; i++){
			scanf("%c %d %d", &l, &p, &q);
			
			if(l == 'C'){
				if(queued < q)
					continue;
				
				for(j = 0; j < c; j++){
					if(!estac[j].placa && estac[j].prox - j + 1 >= q){
						estac[j].placa = p;
						estac[j].prox = j + q;
						
					}else
						j = estac[j].prox;
				}
						
			}else{
				
			}
			
		}
	}

	return 0;
}
