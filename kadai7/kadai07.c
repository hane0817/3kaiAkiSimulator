#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double get_average(int *sujiHairetu, int sujiKosu)
{
    double sum = 0;
    double heikin = 0;
    for (int i = 0; i < sujiKosu; i++)
    {
        sum += sujiHairetu[i];
        printf("%d", sujiHairetu[i]);
    }

    heikin = sum / sujiKosu;

    return heikin;
}

double get_std(int *sujiHairetu, int sujiKosu)
{
    double sum = 0;
    double nijouSum = 0;
    double heikin = 0;
    double nijouHeikin = 0;
    double bunsan = 0;
    double hyojunhensa = 0;

    for (int i = 0; i < sujiKosu; i++)
    {
        sum += sujiHairetu[i];
        nijouSum += pow(sujiHairetu[i], 2);
    }

    heikin = sum / sujiKosu;
    nijouHeikin = nijouSum / sujiKosu;

    bunsan = nijouHeikin - pow(heikin, 2);
    hyojunhensa = sqrt(bunsan);

    return hyojunhensa;
}

int main(void)
{
    int sujiKosu = 0;
    double heikin = 0;
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
        sujiHairetu[i] = value;
    }

    heikin = get_average(sujiHairetu, sujiKosu);
    hyojunhensa = get_std(sujiHairetu, sujiKosu);

    printf("平均値は%lfで，標準偏差は%lfです．\n", heikin, hyojunhensa);
    free(sujiHairetu);
}