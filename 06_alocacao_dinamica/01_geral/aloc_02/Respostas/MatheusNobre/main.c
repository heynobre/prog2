#include <stdio.h>
#include "utils.h"

int main()
{
    int n,m;
    scanf("%d %d", &n, &m);
    int **ma = CriaMatriz(n,m);

    LeMatriz(ma,n,m);
    
    ImprimeMatrizTransposta(ma,n,m);

    LiberaMatriz(ma,n);
    

    return 0;
}