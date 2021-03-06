#include <stdio.h>
#include <string.h>
#define MAX 1001

typedef struct {
	char nome[20];
	int pts, pos;
} Jogador;

Jogador p[MAX];

int cmp(const void *a, const void *b){
	Jogador *ja = (Jogador*)a, *jb = (Jogador*)b;
	
	int dif = jb->pts - ja->pts;
	
	if(dif != 0)
		return dif;
		
	return strcmp(ja->nome, jb->nome);
}

int main(){
	int i = 0, j = 0, n = 0, r = 0, min = 0, max = 0, tot = 0, k = 1, pos = 0;
	
	while(1){
		scanf("%d", &n);

		if(!n)
			break;
			
		pos = 1;

		for(i = 0; i < n; i++){
			scanf("%s", p[i].nome);
			getchar();
		
			scanf("%d", &r);
			getchar();
		
			min = r;
			max = r;
			tot = r;
		
			for(j = 1; j < 12; j++){
				scanf("%d", &r);
				getchar();
			
				tot += r;
			
				if(r > max)
					max = r;
				else if(r < min)
					min = r;
			}
		
			p[i].pts = tot - max - min;		
		}
	
		printf("Teste %d\n", k++);
		qsort(p, n, sizeof(Jogador), cmp);
	
		for(i = 0; i < n; i++){
			if(i - 1 >= 0 && p[i - 1].pts == p[i].pts)
				pos = p[i - 1].pos;
			else
				pos = i + 1;
		
			p[i].pos = pos;
		
			printf("%d %d %s\n", pos, p[i].pts, p[i].nome);
		}
		
		printf("\n");
	}

	return 0;
}
