#include <stdio.h>
#include <stdlib.h>

inline char close(char a){
	if(a == ')')
		return '(';
	
	if(a == '}')
		return '{';
	
	return '[';
}

int main(){
	
	int i = 0, T = 0, top = 0, R = 0;
	char c, str[100002], stack[100002];
	
	scanf("%d", &T);
	
	while(T--){
		
		scanf("%s", str);
		
		i = 0;
		top = 0;
		R = 0;
		
		while(c = str[i]){
			if(c == '(' || c == '{' || c == '[')
				stack[top++] = c;
			else{
				if(!top || stack[top - 1] != close(c)){
					R = 1;
					break;
				}
				
				top--;
			}
			
			i++;
		}
		
		if(top > 0 || R)
			printf("N\n");
		else
			printf("S\n");
		
	}

	return 0;
}
