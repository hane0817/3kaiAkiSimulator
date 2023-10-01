#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int sujiKosu = 0;
    int sum = 0;
    int nijouSum = 0;
    double heikin = 0;
    double nijouHeikin = 0;
    double bunsan = 0;
    double hyojunhensa = 0;

    printf("最初に投入する数字の個数を入力してください\n");
    scanf("%d", &sujiKosu);
    printf("投入する数字の個数は%dですね\n", sujiKosu);
    printf("数字を入力してください\n");

    int *sujiHairetu;
    sujiHairetu = (int *)calloc(sujiKosu, sizeof(int));

    if (sujiHairetu == NULL)
    {
        printf("メモリが確保できません\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < sujiKosu; i++)
    {
        int value = 0;

        scanf("%d", &value);
        if (value >= 1000)
        {
            printf("数字は1000未満を入力してください\n");
            return 0;
        }
        sum += value;
        nijouSum += pow(value, 2);
        sujiHairetu[i] = value;
    }

    heikin = sum / sujiKosu;
    nijouHeikin = nijouSum / (double)sujiKosu;
    bunsan = nijouHeikin - pow(heikin, 2);
    hyojunhensa = sqrt(bunsan);

    printf("入力された数字はそれぞれ");
    for (int i = 0; i < sujiKosu; i++)
    {
        printf(" %d", sujiHairetu[i]);
    }

    printf("\n平均値は%lf,標準偏差は%lfです\n", heikin, hyojunhensa);

    free(sujiHairetu);
}