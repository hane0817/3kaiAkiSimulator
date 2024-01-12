#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "MT.h"

typedef struct __cash // 経過時間は昇順でキャッシュ容量であるリスト構造に入れるので必要なし
{
    int contentsID;
    struct __cash *next;
    struct __cash *prev;
} cash;

int main(void)
{
    double soukaisu = 10000;
    double bunbo[17] = {0};         // zipfの分母 thetaごとに分ける
    double bunsi[17][1000] = {0.0}; // zipfの分子 thetaごとに分けて分子を1000こ求める
    double zipf[17][1000] = {0.0};  // 左がジャンル 右が何番目か zipfの確率を格納
    double randomNum = 0.0;         // ランダムな値を生成する

    double thetaKakuritu[17] = {0}; // thetaごとに確率を代入

    double theta[17] = {0}; // シータ 左はシータの数，右はシータの値 0.4などをいれる

    for (int i = 0; i < 17; i++)
    {
        theta[i] = 0.4 + i * 0.05;
    }

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

    for (int i = 0; i < 1000; i++) // zipfを求める
    {
        for (int j = 0; j < 17; j++)
        {
            zipf[j][i] = bunsi[j][i] / bunbo[j];
        }
    }

    int bingoCash[17] = {0}; // キャッシュがヒットした数

    cash *dummy = malloc(1 * sizeof(cash)); // dummyの作成
    cash *head = dummy;
    cash *tail = dummy;
    dummy->prev = dummy->next = dummy;

    int count = 0; // キャッシュの数を数える

    for (int i = 0; i < 17; i++)
    {
        while (count != 100) // キャッシュを100こためる
        {
            cash *x = malloc(1 * sizeof(cash));
            randomNum = genrand_real2();

            for (int k = 0; k < 1000; k++) // コンテンツIDをzipfに従って代入
            {

                if (randomNum < zipf[i][k])
                {
                    x->contentsID = k;
                    break;
                }
            }

            count++;

            x->next = tail->next; /** (1) **/
            x->prev = tail;       /** (2) **/
            tail->next->prev = x; /** (3) **/
            tail->next = x;       /** (4) **/
            tail = tail->next;    /** (5) **/

            cash *ptr = malloc(1 * sizeof(cash)); // 調べる用のポインター
            ptr = head->next;
            while (ptr != tail)
            {
                if (ptr->contentsID == x->contentsID) // ヒット
                {
                    ptr->prev->next = ptr->next;
                    ptr->next->prev = ptr->prev;
                    count--; // キャッシュが被った場合キャッシュ数に変動がないのでマイナス
                }
                ptr = ptr->next;
            }
        }

        for (int j = 0; j < 10000; j++)
        {
            cash *x = malloc(1 * sizeof(cash));
            randomNum = genrand_real2();

            for (int k = 0; k < 1000; k++) // コンテンツIDをzipfに従って代入
            {

                if (randomNum < zipf[i][k])
                {
                    x->contentsID = k;
                    break;
                }
            }

            x->next = tail->next; /** (1) **/
            x->prev = tail;       /** (2) **/
            tail->next->prev = x; /** (3) **/
            tail->next = x;       /** (4) **/
            tail = tail->next;    /** (5) **/

            cash *ptr = malloc(1 * sizeof(cash)); // 調べる用のポインター
            ptr = head->next;
            while (ptr != tail)
            {
                if (ptr->contentsID == x->contentsID) // ヒット
                {
                    ptr->prev->next = ptr->next;
                    ptr->next->prev = ptr->prev;
                    bingoCash[i]++;
                    break;
                }
                else if (ptr == tail->prev && tail->prev->contentsID != x->contentsID)
                {
                    head->next = head->next->next;
                    head->next->prev = head;
                    break;
                }
                ptr = ptr->next;
            }
        }
    }

    for (int i = 0; i < 17; i++)
    {
        thetaKakuritu[i] = bingoCash[i] / soukaisu;
    }

    FILE *fout;
    fout = fopen("out/xZipf.dat", "w");
    for (int i = 0; i < 17; i++)
    {
        fprintf(fout, "%lf %lf\n", theta[i], thetaKakuritu[i]);
    }
}