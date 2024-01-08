#include <stdio.h>
#include <math.h>
#include "MT.h"

int main(void)
{
    int hani[100];
    for (int i = 0; i < 100; i++) // シグマが1で100個の区間を作成
    {
        hani[i] = 0;
    }

    init_genrand(10);

    double soukaisu = 1000000;

    double hasseikaisu1 = 1;
    double hasseikaisu2 = 0.2;
    double hasseikaisu3 = 0.1;
    double hasseikaisu4 = 0.05;
    double hasseikaisu5 = 0.02;

    int sampleCount1[100];
    int sampleCount2[100];
    int sampleCount3[100];
    int sampleCount4[100];
    int sampleCount5[100];

    double kakuritu1[100];
    double kakuritu2[100];
    double kakuritu3[100];
    double kakuritu4[100];
    double kakuritu5[100];

    for (int i = 0; i < 100; i++)
    {
        sampleCount1[i] = 0;
        sampleCount2[i] = 0;
        sampleCount3[i] = 0;
        sampleCount4[i] = 0;
        sampleCount5[i] = 0;
    }

    for (int i = 0; i < 1000000; i++) // hasseikaisuが1の場合
    {
        double x1 = -1 * log(1 - genrand_real2()) / hasseikaisu1;

        for (int k = 0; k < 100; k++)
        {
            if (x1 > 100)
            {
                sampleCount1[99]++;
                break;
            }
            else if (k < x1 && x1 < k + 1)
            {
                sampleCount1[k]++;
                break;
            }
        }
    }

    for (int i = 0; i < 1000000; i++) // hasseikaisuが2の場合
    {
        double x2 = -1 * log(1 - genrand_real2()) / hasseikaisu2;
        for (int k = 0; k < 100; k++)
        {
            if (x2 > 100)
            {
                sampleCount2[99]++;
                break;
            }
            else if (k < x2 && x2 < k + 1)
            {
                sampleCount2[k]++;
                break;
            }
        }
    }

    for (int i = 0; i < 1000000; i++) // hasseikaisuが3の場合
    {
        double x3 = -1 * log(1 - genrand_real2()) / hasseikaisu3;
        for (int k = 0; k < 100; k++)
        {
            if (x3 > 100)
            {
                sampleCount3[99]++;
                break;
            }
            else if (k < x3 && x3 < k + 1)
            {
                sampleCount3[k]++;
                break;
            }
        }
    }

    for (int i = 0; i < 1000000; i++) // hasseikaisuが4の場合
    {
        double x4 = -1 * log(1 - genrand_real2()) / hasseikaisu4;
        for (int k = 0; k < 100; k++)
        {
            if (x4 > 100)
            {
                sampleCount4[99]++;
                break;
            }
            else if (k < x4 && x4 < k + 1)
            {
                sampleCount4[k]++;
                break;
            }
        }
    }

    for (int i = 0; i < 1000000; i++) // hasseikaisuが5の場合
    {
        double x5 = -1 * log(1 - genrand_real2()) / hasseikaisu5;
        for (int k = 0; k < 100; k++)
        {
            if (x5 > 100)
            {
                sampleCount5[99]++;
                break;
            }
            else if (k < x5 && x5 < k + 1)
            {
                sampleCount5[k]++;
                break;
            }
        }
    }

    for (int i = 0; i < 100; i++)
    {
        kakuritu1[i] = sampleCount1[i] / soukaisu;
        kakuritu2[i] = sampleCount2[i] / soukaisu;
        kakuritu3[i] = sampleCount3[i] / soukaisu;
        kakuritu4[i] = sampleCount4[i] / soukaisu;
        kakuritu5[i] = sampleCount5[i] / soukaisu;
    }

    FILE *fout;
    fout = fopen("out/lamda1.dat", "w");
    for (int i = 0; i < 100; i++)
    {
        fprintf(fout, "%d %lf\n", i, kakuritu1[i]);
    }

    fout = fopen("out/lamda5.dat", "w");
    for (int i = 0; i < 100; i++)
    {
        fprintf(fout, "%d %lf\n", i, kakuritu2[i]);
    }

    fout = fopen("out/lamda10.dat", "w");
    for (int i = 0; i < 100; i++)
    {
        fprintf(fout, "%d %lf\n", i, kakuritu3[i]);
    }

    fout = fopen("out/lamda20.dat", "w");
    for (int i = 0; i < 100; i++)
    {
        fprintf(fout, "%d %lf\n", i, kakuritu4[i]);
    }

    fout = fopen("out/lamda50.dat", "w");
    for (int i = 0; i < 100; i++)
    {
        fprintf(fout, "%d %lf\n", i, kakuritu5[i]);
    }
}