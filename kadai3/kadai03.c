#include <stdio.h>
#include <math.h>

int main(void)
{
    FILE *fin;
    FILE *fout;
    int x[10] = {0};
    double sum = 0;
    double nijousum = 0;
    double heikin = 0;
    double nijouheikin = 0;
    double bunsan = 0;
    double hyoujunhensa = 0;
    fin = fopen("in/exam03.dat", "r");
    for (int i = 1; i < 11; i++)
    {
        fscanf(fin, "%d", &x[i]);
    }
    for (int i = 1; i < 11; i++)
    {
        sum += x[i];
        nijousum += pow(x[i], 2);
    }
    heikin = sum / 10;
    nijouheikin = nijousum / 10;
    bunsan = nijouheikin - pow(heikin, 2);
    hyoujunhensa = sqrt(bunsan);
    fout = fopen("out/exam03.dat", "w"); // fopenの位置をfprintfの上に書くとエラー解決
    for (int i = 1; i < 11; i++)
    {
        fprintf(fout, "%d ", x[i]);
    }
    fprintf(fout, "%lf %lf", heikin, hyoujunhensa);
    fclose(fin);
    fclose(fout);
}