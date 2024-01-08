#include <stdio.h>
#include <math.h>
double comb(int n, int k)
{
    int i;
    double f;
    f = 1.0;
    for (i = 1; i <= k; i++) // 二項係数の計算
    {
        f = f * (double)(n - i + 1) / (double)i;
    }
    return f;
}

int main(void)
{
    int n;
    double p;
    double kakuritu;
    FILE *fout;

    printf("nとpの値を入力してください．\n");
    printf("n:");
    scanf("%d", &n);
    printf("p:");
    scanf("%lf", &p);
    fout = fopen("out/out.dat", "w");

    for (int k = 0; k <= n; k++)
    {
        double nikokeisu = 1;

        nikokeisu = comb(n, k);

        kakuritu = nikokeisu * pow(p, k) * pow((1 - p), (n - k));

        fprintf(fout, "%d %lf\n", k, kakuritu);
    }
    return 0;
}