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

    double theta[17] = {0}; // シータ 左はシータの数，右はシータの値 0.4などをいれる

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

    for (int j = 0; j < 1000; j++) // zipfを求める
    {
        for (int i = 0; i < 17; i++)
        {
            zipf[i][j] = bunsi[i][j] / bunbo[i];
        }
    }

    cash *cashFirst = malloc(1 * sizeof(cash)); // キャッシュ容量の一つ目を作成
    randomNum = genrand_real2();

    for (int i = 0; i < 1000; i++)
    {
        if (randomNum < zipf[0][i])
        {
            cashFirst->contentsID = i;
            break;
        }
    }

    cash *head = cashFirst;
    cash *tail = cashFirst;
    cashFirst->prev = cashFirst->next = cashFirst;

    for (int i = 0; i < 999; i++) // 1000個キャッシュが入ったキャッシュ容量の作成
    {
        cash *x = malloc(1 * sizeof(cash));

        randomNum = genrand_real2();

        for (int i = 0; i < 1000; i++) // contentsIDの決定
        {
            if (randomNum < zipf[0][i])
            {
                x->contentsID = i;
                break;
            }
        }

        x->next = tail->next; /** (1) **/
        x->prev = tail;       /** (2) **/
        tail->next->prev = x; /** (3) **/
        tail->next = x;       /** (4) **/
        tail = tail->next;    /** (5) **/
    }

    int bingoCash[17] = {0}; // キャッシュがヒットした数

    for (int i = 0; i < soukaisu; i++) // 実験開始
    {
        cash *generatedCash = malloc(1 * sizeof(cash)); // 要求キャッシュ

        randomNum = genrand_real2();

        for (int i = 0; i < 1000; i++) // コンテンツIDの決定
        {
            if (randomNum < zipf[0][i])
            {
                generatedCash->contentsID = i;
                break;
            }
        }

        cash *ptr = malloc(1 * sizeof(cash)); // 調べる用のポインター
        ptr = head;
        int counter = 0;
        while (1)
        {
            if (generatedCash->contentsID == head->contentsID) // headでヒット
            {
                ptr->next = head;
                tail = tail->next;
                bingoCash[0]++;
                counter++;
                break;
            }
            else if (generatedCash->contentsID == ptr->contentsID) // headとtailの間でヒット
            {
                ptr->prev->next = ptr->next; // 1
                ptr->next->prev = ptr->prev; // 2
                tail->next = ptr;            // 3
                ptr->prev = tail;            // 4
                ptr->next = head;            // 5
                ptr = head;                  // 6
                bingoCash[0]++;
                counter++;

                break;
            }
            else if (generatedCash->contentsID == tail->contentsID) // tailでヒット
            {
                bingoCash[0]++;
                counter++;

                break;
            }
            else if (ptr == tail && generatedCash->contentsID != tail->contentsID)
            {
                // ヒットせず

                tail->next = generatedCash;
                generatedCash->prev = tail;
                generatedCash->next = head->next;
                head = head->next;
                tail = tail->next;
                head->prev = tail;
                counter++;
                break;
            }
            ptr = ptr->next;
            counter++;
        }
    }
}