#include <stdio.h>
#include <math.h>
#include "MT.h"

int main(void)
{

    double soukaisu = 1000000;

    double bunbo = 0;          // zipfの分母
    double bunsi[100] = {0.0}; // zipfの分子
    double zipf[100] = {0.0};  // ジャンルごとのzipfの確率を格納
    double randomNum = 0.0;    // ランダムな値を代入する

    double theta1 = 0.4;
    double theta2 = 0.6;
    double theta3 = 0.8;
    double theta4 = 1.0;
    double theta5 = 1.2;

    double count1[100] = {0};
    double count2[100] = {0};
    double count3[100] = {0};
    double count4[100] = {0};
    double count5[100] = {0};

    double kakuritu1[100] = {0};
    double kakuritu2[100] = {0};
    double kakuritu3[100] = {0};
    double kakuritu4[100] = {0};
    double kakuritu5[100] = {0};

    // thetaが0.4の時
    bunsi[0] = 1.0 / pow(1.0, theta1);
    bunbo = 0;

    for (int i = 1; i < 100; i++) // zipfの分子を計算
    {
        bunsi[i] = bunsi[i - 1] + 1.0 / pow(i + 1, theta1); // 二番目のものについてけいさんするので1番目の確率+2番目の確立，2番目の確立を求めるにはi+1をpow
    }

    for (int k = 1; k <= 100; k++) // zipfの分母を計算
    {
        bunbo += 1 / pow(k, theta1);
    }

    for (int i = 0; i < 100; i++)
    {
        zipf[i] = bunsi[i] / bunbo;
    }

    for (int i = 0; i < soukaisu; i++) // 実験しカウントする
    {
        randomNum = genrand_real2();
        for (int k = 0; k < 100; k++)
        {
            if (randomNum < zipf[k])
            {
                count1[k]++;
                break;
            }
        }
    }

    // thetaが0.6の時
    bunsi[0] = 1.0 / pow(1.0, theta2);
    bunbo = 0;

    for (int i = 1; i < 100; i++) // zipfの分子を計算
    {
        bunsi[i] = bunsi[i - 1] + 1.0 / pow(i + 1, theta2);
    }

    for (int k = 1; k <= 100; k++) // zipfの分母を計算
    {
        bunbo += 1 / pow(k, theta2);
    }

    for (int i = 0; i < 100; i++)
    {
        zipf[i] = bunsi[i] / bunbo;
    }

    for (int i = 0; i < soukaisu; i++) // 実験しカウントする
    {
        randomNum = genrand_real2();
        for (int k = 0; k < 100; k++)
        {
            if (randomNum < zipf[k])
            {
                count2[k]++;
                break;
            }
        }
    }

    // thetaが0.8の時
    bunsi[0] = 1.0 / pow(1.0, theta3);
    bunbo = 0;
    for (int i = 1; i <= 100; i++) // zipfの分子を計算
    {
        bunsi[i] = bunsi[i - 1] + 1.0 / pow(i + 1, theta3);
    }

    for (int k = 1; k <= 100; k++) // zipfの分母を計算
    {
        bunbo += 1 / pow((double)k, theta3);
    }

    for (int i = 0; i < 100; i++)
    {
        zipf[i] = bunsi[i] / bunbo;
    }

    for (int i = 0; i < soukaisu; i++) // 実験しカウントする
    {
        randomNum = genrand_real2();
        for (int k = 0; k < 100; k++)
        {
            if (randomNum < zipf[k])
            {
                count3[k]++;
                break;
            }
        }
    }

    // thetaが1.0の時
    bunsi[0] = 1.0 / pow(1.0, theta4);
    bunbo = 0;

    for (int i = 1; i <= 100; i++) // zipfの分子を計算
    {
        bunsi[i] = bunsi[i - 1] + 1.0 / pow(i + 1, theta4);
    }

    for (int k = 1; k <= 100; k++) // zipfの分母を計算
    {
        bunbo += 1 / pow(k, theta4);
    }

    for (int i = 0; i < 100; i++)
    {
        zipf[i] = bunsi[i] / bunbo;
    }

    for (int i = 0; i < soukaisu; i++) // 実験しカウントする
    {
        randomNum = genrand_real2();
        for (int k = 0; k < 100; k++)
        {
            if (randomNum < zipf[k])
            {
                count4[k]++;
                break;
            }
        }
    }

    // thetaが1.2の時
    bunsi[0] = 1.0 / pow(1.0, theta5);
    bunbo = 0;

    for (int i = 1; i <= 100; i++) // zipfの分子を計算
    {
        bunsi[i] = bunsi[i - 1] + 1.0 / pow(i + 1, theta5);
    }

    for (int k = 1; k <= 100; k++) // zipfの分母を計算
    {
        bunbo += 1 / pow(k, theta5);
    }

    for (int i = 0; i < 100; i++)
    {
        zipf[i] = bunsi[i] / bunbo;
    }

    for (int i = 0; i < soukaisu; i++) // 実験しカウントする
    {
        randomNum = genrand_real2();
        for (int k = 0; k < 100; k++)
        {
            if (randomNum < zipf[k])
            {
                count5[k]++;
                break;
            }
        }
    }

    for (int i = 0; i < 100; i++) // それぞれの確立を計算し格納
    {
        kakuritu1[i] = count1[i] / soukaisu;
        kakuritu2[i] = count2[i] / soukaisu;
        kakuritu3[i] = count3[i] / soukaisu;
        kakuritu4[i] = count4[i] / soukaisu;
        kakuritu5[i] = count5[i] / soukaisu;
    }
    FILE *fout;
    fout = fopen("out/count1.dat", "w");
    for (int i = 0; i < 100; i++)
    {
        fprintf(fout, "%d %lf\n", i, kakuritu1[i]);
    }
    fout = fopen("out/count2.dat", "w");
    for (int i = 0; i < 100; i++)
    {
        fprintf(fout, "%d %lf\n", i, kakuritu2[i]);
    }
    fout = fopen("out/count3.dat", "w");
    for (int i = 0; i < 100; i++)
    {
        fprintf(fout, "%d %lf\n", i, kakuritu3[i]);
    }
    fout = fopen("out/count4.dat", "w");
    for (int i = 0; i < 100; i++)
    {
        fprintf(fout, "%d %lf\n", i, kakuritu4[i]);
    }
    fout = fopen("out/count5.dat", "w");
    for (int i = 0; i < 100; i++)
    {
        fprintf(fout, "%d %lf\n", i, kakuritu5[i]);
    }
}