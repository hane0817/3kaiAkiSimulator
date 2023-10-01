#include <stdio.h>
#include "MT.h"
#include <time.h>
int main(void)
{
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        init_genrand(i);
        printf("%lf\n", genrand_real2()); // genrand_real2は0から1までの浮動小数点数を生成する %ldはダメ doubleは64ビット
    }
}