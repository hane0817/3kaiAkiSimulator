#include <stdio.h>
#include <math.h>
int main(void)
{
    FILE *fin;
    FILE *fout;
    int x1 = 0;
    int x2 = 0;
    int x3 = 0;
    int x4 = 0;
    int x5 = 0;

    double sum = 0;  // 入力値の総和
    double sum2 = 0; // 入力値の2乗の総和
    double bunsan = 0;
    double hyoujunhensa = 0;
    double heikin = 0;  // 平均
    double heikin2 = 0; // 2乗の平均
    fin = fopen("in/exam02.dat", "r");
    fscanf(fin, "%d%d%d%d%d", &x1, &x2, &x3, &x4, &x5);
    sum = x1 + x2 + x3 + x4 + x5;
    sum2 = pow(x1, 2) + pow(x2, 2) + pow(x3, 2) + pow(x4, 2) + pow(x5, 2);
    heikin = sum / 5;
    heikin2 = sum2 / 5;
    printf("x1:%d x2:%d x3:%d x4:%d x5:%d\n", x1, x2, x3, x4, x5);
    printf("sum:%lf,sum2:%lf\n", sum, sum2);
    printf("x1~x5の平均は%lfだよ\n", heikin);
    bunsan = heikin2 - pow(heikin, 2);
    printf("分散は%lfだよ\n", bunsan);
    hyoujunhensa = sqrt(bunsan);
    printf("標準偏差は%lfだよ\n", hyoujunhensa);

    fout = fopen("out/exam02.dat", "w");
    fprintf(fout, "%lf %lf", heikin, hyoujunhensa);
    fclose(fin);
    fclose(fout);
}