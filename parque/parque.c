/*
 * Alexandre Martins
 * SPOJBR 1356 - Parque Jurassico
 * http://alemart.users.sourceforge.net/progchallenges.html
 */
#include <stdio.h>
#include <string.h>
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAXN 105

/* sequencias */
char s[MAXN], t[MAXN];

/* matriz da programacao dinamica */
int m[MAXN][MAXN];

/* direcao para reconstruir o caminho */
char d[MAXN][MAXN];

/*
 * programacao dinamica
 * ----------------------
 * m[i,j] := tamanho da menor supersequencia de s[1..i] e t[1..j]
 *
 * m[0,j] = j para qualquer j (e' o tamanho da sequencia t[1..j], pois s[1..0] e' vazio!)
 * m[i,0] = i para qualquer i (e' o tamanho da sequencia s[1..i], pois t[1..0] e' vazio!)
 *
 *          {
 * m[i,j] = {   m[i-1,j-1] + 1                 , se s[i] == t[j]
 *          {   min( m[i-1,j] , m[i,j-1] ) + 1 , se s[i] != t[j]
 *          }
 *
 * Por que?! Olhe as duas ultimas letras de s[1..i] e t[1..j]:
 *
 * a) sao iguais?
 *
 * 1    ...    i     j
 * (~~~ s ~~~) A
 * (~~~~~~ t ~~~~~~) A
 *
 * neste caso, A vai para a supersequencia (somo +1) e devemos
 * calcular o tamanho supersequencia minima de s[1..i-1] e t[1..j-1]
 *
 * b) sao diferentes?
 *
 * 1    ...    i     j
 * (~~~ s ~~~) A
 * (~~~~~~ t ~~~~~~) C
 *
 * neste caso, ou A ou C vai para a supersequencia - qual deles nao sei.
 * Para descobrir qual a melhor opcao, verifico qual das supersequencias e'
 * a menor:
 * i)  a gerada por s[1..i-1] e t[1..j] (escolhi A)
 * ii) ou a gerada por s[1..i] e t[1..j-1] (escolhi C)
 * Ou escolhi A, ou escolhi C - por isso somo +1.
 */

/*
 * algoritmo exponencial
 * ------------------------
 * int tamanho(int i, int j)
 * {
 *     if(i == 0) return j;
 *     if(j == 0) return i;
 * 
 *     if(s[i] == t[j])
 *         return tamanho(i-1,j-1) + 1;
 *     else
 *         return MIN( tamanho(i-1,j) , tamanho(i,j-1) ) + 1;
 * }
 */


void pd()
{
    int i, j;

    /* base da recursao */
    for(i=0; i<MAXN; i++) m[i][0] = i;
    for(j=0; j<MAXN; j++) m[0][j] = j;

    /* programacao dinamica */
    for(i=1; i<MAXN; i++) {
        for(j=1; j<MAXN; j++) {
            if(s[i] == t[j]) {
                m[i][j] = m[i-1][j-1] + 1;
                d[i][j] = 'D'; /* diagonal */
            }
            else {
                if(m[i-1][j] <= m[i][j-1]) {
                    m[i][j] = m[i-1][j] + 1;
                    d[i][j] = 'U'; /* cima (up) */
                }
                else {
                    m[i][j] = m[i][j-1] + 1;
                    d[i][j] = 'L'; /* esquerda (left) */
                }
            }
        }
    }
}


void reconstruct_path(int i, int j)
{
    int k;

    if(i == 0) {
        for(k=1; k<=j; k++)
            putchar(t[k]);
        return;
    }

    if(j == 0) {
        for(k=1; k<=i; k++)
            putchar(s[k]);
        return;
    }
    
    switch(d[i][j]) {
        case 'U':
            reconstruct_path(i-1, j);
            putchar(s[i]);
            break;

        case 'L':
            reconstruct_path(i, j-1);
            putchar(t[j]);
            break;

        case 'D':
            reconstruct_path(i-1, j-1);
            putchar(s[i]); /* ou t[j], tanto faz */
            break;
    }
}


int main()
{
    int i, x = 0, n0, n1;
    char line[2][MAXN];

    while(1) {
        /* input */
        gets(line[0]);
        if(line[0][0] == '#') break;
        gets(line[1]);
        n0 = strlen( line[0] );
        n1 = strlen( line[1] );

        /* pre-processamento */
        for(i=0; i<MAXN; i++)
            s[i] = t[i] = 0;

        for(i=1; i<=n0; i++)
            s[i] = line[0][i-1];

        for(i=1; i<=n1; i++)
            t[i] = line[1][i-1];

        /* processamento */
        pd();

        /* output */
        printf("Teste %d\n", ++x);
        reconstruct_path(n0, n1);
        printf("\n\n");
    }

    return 0;
}
