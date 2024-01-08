#include <stdio.h>
#include <math.h>
#include "MT.h"

int main(void)
{
    int n = 20;   // nは事象の数かつ試行回数
    int N = 1000; // Nは実験を何セットやるか
    double p;
    FILE *fout;

    printf("pの値を入力してください．\n");
    printf("p:");
    scanf("%lf", &p);

    int kaisu[n + 1];       // 事象が起こった実験の数を入れる 例：kaisu[1]は実験をNセット行なって表が一回しか出なかった実験の数 n+1は0から最後の数まで何個あるか
    double kakuritu[n + 1]; // 起こった回数ごとに確立を求める
    for (int i = 0; i < n + 1; i++)
    {
        kaisu[i] = 0;
        kakuritu[i] = 0;
    }

    init_genrand(10);

    for (int i = 0; i < N; i++) // 実験をNセット行う
    {
        int count = 0;
        for (int k = 0; k < n; k++) // 1回実験を行う
        {

            if (genrand_real2() < p)
            {
                count++;
            }
        }

        for (int j = 0; j < n + 1; j++) // 1回の実験で表が出た回数を集計
        {
            if (count == j)
            {
                kaisu[j]++;
            }
        }
    }

    fout = fopen("out/out.dat", "w");
    for (int i = 0; i < n + 1; i++)
    {
        kakuritu[i] = (double)kaisu[i] / N; // 確立を求める kaisuは事象ごとに分けた実験の数なので割る数はN
        fprintf(fout, "%lf\n", i, kakuritu[i]);
    }
}