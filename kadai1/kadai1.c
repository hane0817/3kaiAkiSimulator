#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int i = 0;
    int x = 0;
    int sum = 0;
    int max = 0;
    int min = 1000;

    printf("好きな値を5回入力してね！\n");

    for (i = 0; i < 5; i++)
    {
        printf("入力欄:");
        scanf("%d", &x);
        if (x >= 1000)
        {
            printf("入力値が1000以上やからエラーやで\n");
            exit(2);
        }
        sum += x;
        if (x > max)
        {
            max = x;
        }
        if (x < min)
        {
            min = x;
        }
    }
    printf("平均値:%f,max:%d,min:%d\n", (float)sum / 5, max, min);
}