#include <stdio.h>
#include <math.h>
#include "MT.h"
int main(void)
{
    int n;
    int N = 1000;
    double p;
    double kakuritu;
    FILE *fout;

    printf("nとpの値を入力してください．\n");
    printf("n:");
    scanf("%d", &n);
    printf("p:");
    scanf("%lf", &p);

    int i = 0;
    int count = 0;
    for (i = 0; i < n; i++)
    {
        init_genrand(i);
        if (genrand_real2() < p)
        {
            count++;
        }
    }
    fout = fopen("out/out.dat", "w");
    fprintf(fout, "%d %d\n", n, count);
}