#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    int sugaku;
    int eigo;
    int buturi;
} result;

double get_average(result *seito[], int ninzu, double *sugakuHeikin, double *eigoHeikin, double *buturiHeikin)
{
    double sugakuSum = 0;
    double eigoSum = 0;
    double buturiSum = 0;

    for (int i = 0; i < ninzu; i++)
    {
        sugakuSum += seito[i]->sugaku;
        eigoSum += seito[i]->eigo;
        buturiSum += seito[i]->buturi;
    }

    *sugakuHeikin = sugakuSum / ninzu;
    *eigoHeikin = eigoSum / ninzu;
    *buturiHeikin = buturiSum / ninzu;
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
    FILE *fin;
    FILE *fout;

    result seito[5];
    double *sugakuHeikin = 0;
    double *eigoHeikin = 0;
    double *buturiHeikin = 0;
    double *sugakuHyojunhensa = 0;
    double *eigoHyojunhensa = 0;
    double *buturiHyojunhensa = 0;

    int ninzu = 5;

    fin = fopen("in/exam08.dat", "r");

    for (int i = 0; i < ninzu; i++)
    {
        fscanf(fin, "%d", &seito[i].sugaku);
        fscanf(fin, "%d", &seito[i].eigo);
        fscanf(fin, "%d", &seito[i].buturi);
    }

    get_average(seito, ninzu, sugakuHeikin, eigoHeikin, buturiHeikin);

        fout = fopen("out/exam08.dat", "w");

    for (int i = 0; i < ninzu; i++)
    {
        fprintf(fout, "数学:平均=%d,標準偏差=", sugakuHeikin);
    }
}