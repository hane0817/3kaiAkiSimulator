#include <stdio.h>
#include <math.h>
#include "MT.h"

int main(void)
{
    int N = 100000; // 実験のセット数
    int detameGoukei[N];
    int goukei = 0;
    int ikkaime = 0;
    int nikaime = 0;

    for (int k = 0; k < N; k++)
    {
        detameGoukei[k] = 0;
    }

    init_genrand(10);

    for (int k = 0; k < N; k++) // 実際に実験し合計を代入
    {
        ikkaime = (int)(genrand_real2() * 6.0) + 1;
        nikaime = (int)(genrand_real2() * 6.0) + 1;
        detameGoukei[k] = ikkaime + nikaime;
    }

    int kaisuDetameGoukei[14];
    for (int k = 0; k < 14; k++)
    {
        kaisuDetameGoukei[k] = 0;
    }

    for (int k = 0; k < N; k++)
    {
        switch (detameGoukei[k])
        {
        case 0:
            kaisuDetameGoukei[0]++;
            break;
        case 1:
            kaisuDetameGoukei[1]++;
            break;
        case 2:
            kaisuDetameGoukei[2]++;
            break;
        case 3:
            kaisuDetameGoukei[3]++;
            break;
        case 4:
            kaisuDetameGoukei[4]++;
            break;
        case 5:
            kaisuDetameGoukei[5]++;
            break;
        case 6:
            kaisuDetameGoukei[6]++;
            break;
        case 7:
            kaisuDetameGoukei[7]++;
            break;
        case 8:
            kaisuDetameGoukei[8]++;
            break;
        case 9:
            kaisuDetameGoukei[9]++;
            break;
        case 10:
            kaisuDetameGoukei[10]++;
            break;
        case 11:
            kaisuDetameGoukei[11]++;
            break;
        case 12:
            kaisuDetameGoukei[12]++;
            break;
        }
    }

    double kakuritu[13];      // 出た目の合計の回数と100000を割って確率を出す
    double kakurituBunpu[13]; // 出た目の合計の回数と100000を割って確率を出す
    double kakurituTemp = 0;  // 累積分布関数を求めるために一時的に合計をだすところ
    for (int i = 0; i < 13; i++)
    {
        kakuritu[i] = 0;
        kakurituBunpu[i] = 0;
    }

    for (int i = 2; i < 13; i++)
    {
        kakuritu[i] = (double)kaisuDetameGoukei[i] / N; // 質量確立
    }

    for (int i = 12; i > 1; i--) // 累積確立を計算
    {
        for (int k = i; k > 1; k--)
        {
            kakurituTemp += kakuritu[k];
        }
        kakurituBunpu[i] = kakurituTemp;
        kakurituTemp = 0;
    }

    FILE *fout;
    fout = fopen("out/situryou.dat", "w");
    for (int i = 0; i < 13; i++)
    {
        fprintf(fout, "%d %lf\n", i, kakuritu[i]);
    }

    fout = fopen("out/bunpu.dat", "w");
    for (int i = 0; i < 13; i++)
    {
        fprintf(fout, "%d %lf\n", i, kakurituBunpu[i]);
    }
}