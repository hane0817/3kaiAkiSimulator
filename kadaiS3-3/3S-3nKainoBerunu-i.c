#include <stdio.h>
#include <math.h>
#include "MT.h"

int main(void)
{
    int n = 20;  // nは事象の数かつ試行回数
    int N1 = 10; // Nは実験を何セットやるか
    int N2 = 1000;
    int N3 = 100000;
    double p;

    printf("pの値を入力してください\n");
    printf("p:");
    scanf("%lf", &p);

    FILE *fout;

    int kaisu[3][n + 1];       // 事象が起こった実験の数を入れる 例：kaisu[1]は実験をNセット行なって表が一回しか出なかった実験の数 n+1は0から最後の数まで何個あるか
    double kakuritu[3][n + 1]; // 起こった回数ごとに確立を求める
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            kaisu[i][j] = 0;
            kakuritu[i][j] = 0;
        }
    }

    init_genrand(10);

    // N=10の時

    for (int i = 0; i < N1; i++) // 実験をNセット行う
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
                kaisu[0][j]++;
            }
        }
    }

    // N=1000の時

    for (int i = 0; i < N2; i++) // 実験をNセット行う
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
                kaisu[1][j]++;
            }
        }
    }

    // N=100000の時

    for (int i = 0; i < N3; i++) // 実験をNセット行う
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
                kaisu[2][j]++;
            }
        }
    }

    fout = fopen("out/N=10.dat", "w");

    for (int i = 0; i < n + 1; i++)
    {
        kakuritu[0][i] = (double)kaisu[0][i] / N1; // 確立を求める kaisuは事象ごとに分けた実験の数なので割る数はN

        fprintf(fout, "%2d %lf\n", i, kakuritu[0][i]);
    }

    fout = fopen("out/N=1000.dat", "w");

    for (int i = 0; i < n + 1; i++)
    {
        kakuritu[1][i] = (double)kaisu[1][i] / N2;

        fprintf(fout, "%2d %lf\n", i, kakuritu[1][i]);
    }

    fout = fopen("out/N=100000.dat", "w");

    for (int i = 0; i < n + 1; i++)
    {
        kakuritu[2][i] = (double)kaisu[2][i] / N3;

        fprintf(fout, "%2d %lf\n", i, kakuritu[2][i]);
    }
}