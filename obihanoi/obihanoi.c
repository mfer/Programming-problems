#include <stdio.h>
#include <stdlib.h>

int dois[31];

int main(){
	
	int i = 0, k = 1;
	
	dois[0] = 1;
	
	for(i = 1; i <= 30; i++)
		dois[i] = dois[i - 1] * 2;
	
	while(1){
		scanf("%d", &i);
		
		if(!i)
			break;
		
		printf("Teste %d\n%d\n\n", k++, dois[i] - 1);
	}

	return 0;
}
