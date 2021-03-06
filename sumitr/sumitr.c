#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int K = 0, M[MAX][MAX];

inline int max(int a, int b){
	return a > b ? a : b;
}

int main(){
	
	int i = 0, j = 0, n = 0;
	
	for(i = 0; i < MAX; i++)
		for(j = 0; j < MAX; j++)
			M[i][j] = 0;
	
	scanf("%d", &n);
	
	while(n--){
		scanf("%d", &K);
		
		for(i = 1; i <= K; i++)
			for(j = 0; j < i; j++)
				scanf("%d", &M[i - 1][j]);
		
		for(i = K - 2; i >= 0; i--)
			for(j = 0; j <= i; j++)
				M[i][j] += max(M[i + 1][j], M[i + 1][j + 1]);
				
		printf("%d\n", M[0][0]);
	}

	return 0;
}

/*
Recursivo

int getMax(int i, int j){
	
	int p1 = 0, p2 = 0;
	
	if(i >= K)
		return 0;
	
	p1 = getMax(i + 1, j); // embaixo
	p2 = getMax(i + 1, j + 1); // embaixo p/ direita
	
	return max(p1, p2) + M[i][j];
}
*/

/*
Solucao enviada C++

#include<iostream>
#define for(a,b,c) for(a=b;a<=c;a++)
using namespace std;
int main(){int i=0,j=0,n=0,K=0,m=0,M[101][101]={0};cin>>n;while(n--){cin>>K;for(i,1,K)for(j,1,i){cin>>M[i][j];m=max((M[i][j]+=max(M[i-1][j],M[i-1][j-1])),m);}cout<<m<<endl;m=0;}}
*/
