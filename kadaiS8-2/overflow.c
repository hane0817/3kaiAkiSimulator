#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "MT.h"

int main(void)
{
    init_genrand(10);
    int q = 0;              // 待ち行列長
    int total_q = 0;        // 待ち行列長の合計
    int t = 0;              // 時刻
    int sim_len = 1000000;  // シミュレートする制限時間
    int K = 10;             // 待ち行列長の限界
    int overflow_count = 0; // 客がサービスをあきらめた回数

    double p1[26] = {0}; // TS内で客が一人到着する確率
    for (int i = 0; i <= 25; i++)
    {
        p1[i] = 0.1 + i * 0.01;
    }
    double p2 = 0.35; // TS内でサービス中の客のサービスが完了する確率

    double ave_q[26] = {0}; // 待ち行列長の平均

    double overflow_probability[26] = {0}; // 客がサービスをあきらめた確率(溢れ率)
    for (int i = 0; i <= 25; i++)
    {
        while (t < sim_len)
        {
            if (q > 0) // 客を処理
            {
                if (genrand_real2() < p2)
                {
                    q--;
                }
            }

            if (q > K) // 客の人数がKを超えている場合
            {
                t++;
                total_q += q;
                overflow_count++;
                continue;
            }

            if (genrand_real2() < p1[i]) // 客が到着
            {
                q++;
            }
            t++;
            total_q += q;
        }
        ave_q[i] = (double)total_q / (double)t;
        overflow_probability[i] = (double)overflow_count / (double)t;
        t = 0; // 初期化
        q = 0;
        total_q = 0;
        overflow_count = 0;
    }

    printf("Average queue length = %lf\nGive up ratio = %lf\n", ave_q, overflow_probability);
}