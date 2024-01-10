#include <stdio.h>
#include <math.h>
#include "MT.h"

typedef struct
{
    int contentsID;
    int elapsedTime;
} cash;

int main(void)
{
    double soukaisu = 10000;
    double bunbo[17] = {0};         // zipfの分母 thetaごとに分ける
    double bunsi[17][1000] = {0.0}; // zipfの分子 thetaごとに分けて分子を1000こ求める
    double zipf[17][1000] = {0.0};  // 左がジャンル 右が何番目か zipfの確率を格納
    double randomNum = 0.0;         // ランダムな値を代入する

    double theta[17] = {0}; // シータ 左はシータの数，右はシータの値 0.4などをいれる

    cash cashCapacity[17][100] = {0}; // キャッシュ容量

    for (int i = 0; i < 17; i++)
    {
        theta[i] = 0.4 + i * 0.05;
    }

    double count[17][1000] = {0}; // 左はシータの数 右はコンテンツの数

    for (int i = 0; i < 17; i++) // 分子の始めを0で初期化
    {
        bunsi[i][0] = 1.0 / pow(1.0, theta[i]);
    }

    for (int i = 0; i < 17; i++)
    {
        for (int j = 1; j < 1000; j++) // zipfの分子を計算
        {
            bunsi[i][j] = bunsi[i][j - 1] + 1.0 / pow(j + 1, theta[i]); // 二番目のものについて計算するので1番目の確率+2番目の確立，2番目の確立を求めるにはi+1をpow
        }
    }

    for (int i = 0; i < 17; i++) // 分母の計算
    {
        for (int j = 1; j <= 1000; j++)
        {
            bunbo[i] += 1 / pow(j, theta[i]);
        }
    }

    for (int j = 0; j < 1000; j++)
    {
        for (int i = 0; i < 17; i++) // zipfを求める
        {
            zipf[i][j] = bunsi[i][j] / bunbo[i];
        }
    }

    for (int i = 0; i < 10000; i++)
    {
        randomNum = genrand_real2();
        cash cash;
        cash.contentsID = randomNum;
        cash.elapsedTime = 0;
        for (int j = 0; j < 17; j++)
        {
            for (int k = 0; k < 1000; k++)
            {
                if (cash.contentsID < zipf[j][k])
                {
                    count[j][k]++;
                    break;
                }
            }
        }
    }
}