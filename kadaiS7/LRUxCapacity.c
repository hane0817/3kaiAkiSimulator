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
    double bunbo = 0;
    double bunsi[1000] = {0};
    double zipf[1000] = {0}; // zipfの確率を格納
    double randomNum = 0.0;  // ランダムな値を生成する

    double cacheCapaKakuritu[6] = {0}; // cacheCapacityごとに確率を代入

    int cacheCapacity[6] = {10, 20, 40, 80, 160, 320}; // キャッシュ容量

    int bingoCash[6] = {0}; // キャッシュがヒットした数

    double theta = 0.8;

    bunsi[0] = 1.0 / pow(1.0, theta);

    for (int j = 1; j < 1000; j++) // zipfの分子を計算
    {
        bunsi[j] = bunsi[j - 1] + 1.0 / pow(j + 1, theta); // 二番目のものについて計算するので1番目の確率+2番目の確立，2番目の確立を求めるにはi+1をpow
    }

    for (int j = 1; j <= 1000; j++) // 分母の計算
    {
        bunbo += 1 / pow(j, theta);
    }

    for (int j = 0; j < 1000; j++)
    {
        zipf[j] = bunsi[j] / bunbo;
    }

    for (int i = 0; i < 6; i++)
    {
        cash *dummy = malloc(1 * sizeof(cash)); // dummyの作成
        cash *head = dummy;
        cash *tail = dummy;
        dummy->prev = dummy->next = dummy;

        int count = 0; // キャッシュの数を数える

        count = 0;
        while (count != cacheCapacity[i]) // キャッシュをためる
        {
            cash *x = malloc(1 * sizeof(cash));
            randomNum = genrand_real2();

            for (int k = 0; k < 1000; k++) // コンテンツIDをzipfに従って代入
            {

                if (randomNum < zipf[k])
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
        } // キャッシュためる終了
        for (int k = 0; k < 10000; k++)
        {
            cash *x = malloc(1 * sizeof(cash));
            randomNum = genrand_real2();

            for (int k = 0; k < 1000; k++) // コンテンツIDをzipfに従って代入
            {

                if (randomNum < zipf[k])
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
                    count--; // キャッシュが被った場合キャッシュ数に変動がないのでマイナス
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
    FILE *fout;
    fout = fopen("out/xCacheCapacity.dat", "w");
    for (int i = 0; i < 6; i++)
    {
        cacheCapaKakuritu[i] = bingoCash[i] / soukaisu;
        fprintf(fout, "%d %lf\n", cacheCapacity[i], cacheCapaKakuritu[i]);
    }
}