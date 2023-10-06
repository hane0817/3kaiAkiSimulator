#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    int sugaku;
    int eigo;
    int buturi;
} result;

double get_average(result *seito, int ninzu, double *sugakuHeikin, double *eigoHeikin, double *buturiHeikin)
{
    double sugakuSum = 0;
    double eigoSum = 0;
    double buturiSum = 0;

    for (int i = 0; i < ninzu; i++)
    {
        sugakuSum += seito[i].sugaku;
        eigoSum += seito[i].eigo;
        buturiSum += seito[i].buturi;
    }

    *sugakuHeikin = sugakuSum / (double)ninzu;
    *eigoHeikin = eigoSum / (double)ninzu;
    *buturiHeikin = buturiSum / (double)ninzu;
}

double get_std(result *seito, int ninzu, double *sugakuHeikin, double *sugakuHyojunhensa, double *eigoHeikin, double *eigoHyojunhensa, double *buturiHeikin, double *buturiHyojunhensa)
{
    double sugakuSum = 0;
    double eigoSum = 0;
    double buturiSum = 0;
    double sugakuNijouSum = 0;
    double eigoNijouSum = 0;
    double buturiNijouSum = 0;
    double sugakuNijouHeikin = 0;
    double eigoNijouHeikin = 0;
    double buturiNijouHeikin = 0;
    double sugakuBunsan = 0;
    double eigoBunsan = 0;
    double buturiBunsan = 0;

    for (int i = 0; i < ninzu; i++)
    {
        sugakuSum += seito[i].sugaku;
        sugakuNijouSum += pow(seito[i].sugaku, 2);
        eigoSum += seito[i].eigo;
        eigoNijouSum += pow(seito[i].eigo, 2);
        buturiSum += seito[i].buturi;
        buturiNijouSum += pow(seito[i].buturi, 2);
    }

    sugakuNijouHeikin = sugakuNijouSum / ninzu;
    eigoNijouHeikin = eigoNijouSum / ninzu;
    buturiNijouHeikin = buturiNijouSum / ninzu;

    sugakuBunsan = sugakuNijouHeikin - pow(*sugakuHeikin, 2);
    eigoBunsan = eigoNijouHeikin - pow(*eigoHeikin, 2);
    buturiBunsan = buturiNijouHeikin - pow(*buturiHeikin, 2);

    *sugakuHyojunhensa = sqrt(sugakuBunsan);
    *eigoHyojunhensa = sqrt(eigoBunsan);
    *buturiHyojunhensa = sqrt(buturiBunsan);
}

int main(void)
{
    FILE *fin;
    FILE *fout;

    result *seito;
    int ninzu = 5;

    seito = (result *)calloc(ninzu, sizeof(result));
    double sugakuHeikin = 0;
    double eigoHeikin = 0;
    double buturiHeikin = 0;
    double sugakuHyojunhensa = 0;
    double eigoHyojunhensa = 0;
    double buturiHyojunhensa = 0;

    fin = fopen("in/exam08.dat", "r");

    for (int i = 0; i < ninzu; i++)
    {
        fscanf(fin, "%d", &seito[i].sugaku);
        fscanf(fin, "%d", &seito[i].eigo);
        fscanf(fin, "%d", &seito[i].buturi);
    }

    get_average(seito, ninzu, &sugakuHeikin, &eigoHeikin, &buturiHeikin);

    get_std(seito, ninzu, &sugakuHeikin, &sugakuHyojunhensa, &eigoHeikin, &eigoHyojunhensa, &buturiHeikin, &buturiHyojunhensa);

    fout = fopen("out/exam08.dat", "w");

    fprintf(fout, "数学:平均=%lf,標準偏差=%lf\n", sugakuHeikin, sugakuHyojunhensa);
    fprintf(fout, "英語:平均=%lf,標準偏差=%lf\n", eigoHeikin, eigoHyojunhensa);
    fprintf(fout, "数学:平均=%lf,標準偏差=%lf\n", buturiHeikin, buturiHyojunhensa);

    free(seito);
}