#include <stdio.h>

char c[3][3];
int ret[2] = {0, 0};

void wins(){
	
	int i = 0, j = 0, cx = 0, co = 0;
	
	// diagonal principal
	
	for(i = 0; i < 3; i++){
		if(c[i][i] == 'X')
			cx++;
		else if(c[i][i] == 'O')
			co++;
	}
	
	if(cx == 3)
		ret[0]++;
	if(co == 3)
		ret[1]++;
		
	cx = 0;
	co = 0;
	
	
	// diagonal secundaria
	
	for(i = 0; i < 3; i++){
		if(c[i][2 - i] == 'X')
			cx++;
		else if(c[i][2 - i] == 'O')
			co++;
	}
	
	if(cx == 3)
		ret[0]++;
	if(co == 3)
		ret[1]++;
		
	cx = 0;
	co = 0;
	

	for(i = 0; i < 3; i++){
		
		// Linha
		
		for(j = 0; j < 3; j++){
			if(c[i][j] == 'X')
				cx++;
			else if(c[i][j] == 'O')
				co++;
		}

		if(cx == 3)
			ret[0]++;
		if(co == 3)
			ret[1]++;
	
		cx = 0;
		co = 0;
		
		// Coluna
		
		for(j = 0; j < 3; j++){
			if(c[j][i] == 'X')
				cx++;
			else if(c[j][i] == 'O')
				co++;
		}

		if(cx == 3)
			ret[0]++;
		if(co == 3)
			ret[1]++;
	
		cx = 0;
		co = 0;	
	}
}

int main(){
	
	int n = 0, i = 0, x = 0, o = 0;
	char r;
	
	scanf("%d", &n);
	getchar();
	
	while(n--){
		
		x = 0;
		o = 0;
		
		ret[0] = 0;
		ret[1] = 0;
	
		for(i = 0; i < 9; i++){
			r = getchar();
			
			if(r == '\n')
				i--;
			else
				c[i / 3][i % 3] = r;
			
			if(r == 'X')
				x++;
			else if(r == 'O')
				o++;
		}
		
		wins();
		
		if((ret[0] && ret[1]) || (o > x) || (x > o + 1) || (ret[0] && x != o + 1) || (ret[1] && o != x))
			printf("no\n");
		else
			printf("yes\n");
		
		getchar();
	}

	return 0;
}
