#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <bitset>
 
using namespace std;
 
#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define forall(i,c) for(typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define dforn(i,n) for(int i=((int)(n)-1);i>=0;i--)
#define dforsn(i,s,n) for(int i=((int)(n)-1);i>=(int)(n);i--)
#define esta(i,c) ((c).find(i) != (c).end())
#define dbg(x) cerr << #x << " = " << x << endl;
#define raya cerr << string(80,'=') << endl;
 
typedef long long tint;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
 
int n, nrows, ncols, m[9][9];
int zr[81],zc[81],z;
int inRow[9][10],inBlock[9][10],inCol[9][10];
 
bool solFound = false;
 
bool checkSudoku(){
        forn(i,nrows) forsn(j,1,nrows+1)
                if(inRow[i][j] != 1 || inCol[i][j] != 1 || inBlock[i][j] != 1) return false;
        return true;
}
 
void backtrack(int cz){
        if(checkSudoku()){
                solFound = true;
        }else{
                if(cz == z) return;
                int nr = zr[cz], nc = zc[cz];
 
                forsn(i,1,n*n+1){
                        if(!inRow[nr][i] && !inCol[nc][i] && !inBlock[n*(nr/n)+nc/n][i]){
                                m[nr][nc] = i;
                                inRow[nr][i] = inCol[nc][i] = inBlock[n*(nr/n)+nc/n][i] = 1;
                                backtrack(cz+1);
                               
                                if(solFound) return;
                                inRow[nr][i] = inCol[nc][i] = inBlock[n*(nr/n)+nc/n][i] = 0;
                        }
                }
               
                m[nr][nc] = 0;
        }
}
 
int main(){
        #ifdef JUAMPI
                freopen("989.in","r",stdin);
        #endif
 
        bool flag = true;
        while(scanf("%d",&n) == 1){
                if(flag) flag = false; else putchar('\n');
                nrows = ncols = n*n;
               
                z = 0;
               
                memset(inRow,0,sizeof(inRow));
                memset(inCol,0,sizeof(inCol));
                memset(inBlock,0,sizeof(inBlock));             
       
                forn(i,nrows)
                forn(j,ncols){
                        scanf("%d",&m[i][j]);
                        int v = m[i][j];
                        if(v==0){
                                zr[z] = i; zc[z] = j; z++;
                        }else{
                                inRow[i][v]++; inCol[j][v]++; inBlock[n*(i/n)+j/n][v]++;
                        }
                }
       
                int nzr[81],nzc[81],nz=0;
               
                forn(i,nrows)
                forn(j,ncols){
                        forsn(k,1,nrows+1){
                                if(inRow[i][k] > 1 || inCol[j][k] > 1 || inBlock[n*(i/n)+j/n][k] > 1){
                                        solFound = false;
                                        goto found;
                                }
                        }
                }
 
                forn(i,z){
                        int r = zr[i], c = zc[i];
                       
                        int pos = 0, num=-1;
                        forsn(k,1,nrows+1){
                                if(!inRow[r][k] && !inCol[c][k] && !inBlock[n*(r/n)+c/n][k]){
                                        pos++; num = k;
                                }
                        }
 
                        if(pos == 1){
                                inRow[r][num]++; inCol[c][num]++; inBlock[n*(r/n)+c/n][num]++;
                                m[r][c] = num;
                                zr[i] = zc[i] = -1;
                        }
                }
                forn(i,z){
                        if(zr[i] >= 0 && zc[i] >= 0){
                                nzr[nz] = zr[i]; nzc[nz] = zc[i]; nz++;
                        }
                }
                z = nz;
                forn(i,z){
                        zr[i] = nzr[i]; zc[i] = nzc[i];
                }
               
                solFound = false;
                backtrack(0);
 
found:
                if(solFound){
                        forn(i,nrows){
                                forn(j,ncols){
                                        putchar(m[i][j]+'0');
                                        if(j < n*n-1) putchar(' ');
                                }
                                putchar('\n');
                        }
                }else{
                        printf("NO SOLUTION\n");
                }
        }
 
        return 0;
}
