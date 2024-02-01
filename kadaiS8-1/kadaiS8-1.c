#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "MT.h"

int main(void)
{
    init_genrand(10);
    int q = 0;          // 待ち行列長
    int total_q = 0;    // 待ち行列長の合計
    int t = 0;          // 時刻
    int sim_len = 1000; // シミュレートする制限時間

    double p1 = 0.3;  // TS内で客が一人到着する確率
    double p2 = 0.35; // TS内でサービス中の客のサービスが完了する確率

    double ave_q = 0; // 待ち行列長の平均

    while (t < sim_len)
    {
        if (q < 0)
        {
            if (genrand_real2() < p2)
            {
                q--;
            }
        }
        if (genrand_real2() < p1)
        {
            q++;
        }
        t++;
        total_q += q;
    }
    ave_q = (double)total_q / (double)t;
    printf("Average queue length = %lf\n", ave_q);
}