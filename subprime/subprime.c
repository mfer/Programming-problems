#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int i = 0, b = 0, n = 0, bancos[21], r = 0, d = 0, c = 0, v = 0;
	
	while(1){
		
		scanf("%d %d", &b, &n);
		
		if(!b && !n)
			break;
		
		for(i = 0; i < b; i++){
			scanf("%d", &r);
			getchar();
			bancos[i] = r;
		}
		
		for(i = 0; i < n; i++){
			scanf("%d %d %d", &d, &c, &v);
			bancos[d - 1] -= v;
			bancos[c - 1] += v;
		}
		
		for(i = 0; i < b && bancos[i] >= 0; i++);
		
		printf((i == b) ? "S\n" : "N\n");
		
	}

	return 0;
}
