#include <stdio.h>
#include "utils.h"

int main()
{
    int n;
    scanf("%d", &n);
    int *v = CriaVetor(n);

    LeVetor(v, n);
    
    printf("%.2f\n", CalculaMedia(v,n));

    LiberaVetor(v);
    

    return 0;
}