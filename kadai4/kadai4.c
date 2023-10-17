#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    FILE *fin;
    FILE *fout;
    int x[3][5] = {0}; // 生徒の点数 左の添え字は科目，右は点数
    int sum[3] = {0};  // 合計
    int sum2[3] = {0}; // 二乗の合計
    char s[3][20];     // 左の添え字は科目番号 科目名を入れる
    double suugakuHeikin = 0;
    double eigoHeikin = 0;
    double buturiHeikin = 0;

    double suugakuNijouHeikin = 0;
    double eigoNijouHeikin = 0;
    double buturiNijouHeikin = 0;

    double suugakuBunsan = 0;
    double eigoBunsan = 0;
    double buturiBunsan = 0;

    double suugakuHyojunhensa = 0;
    double eigoHyojunhensa = 0;
    double buturiHyojunhensa = 0;

    fin = fopen("in/exam04.dat", "r");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            fscanf(fin, "%d", &x[i][j]);

            // 下は合計を計算
            if (i == 0)
            {
                sum[0] += x[0][j];
                sum2[0] += pow(x[0][j], 2);
            }
            else if (i == 1)
            {
                sum[1] += x[1][j];
                sum2[1] += pow(x[1][j], 2);
            }
            else
            {
                sum[2] += x[2][j];
                sum2[2] += pow(x[2][j], 2);
            }
        }
    }

    suugakuHeikin = sum[0] / 5.0;
    eigoHeikin = sum[1] / 5.0;
    buturiHeikin = sum[2] / 5.0;

    suugakuNijouHeikin = sum2[0] / 5.0;
    eigoNijouHeikin = sum2[1] / 5.0;
    buturiNijouHeikin = sum2[2] / 5.0;

    suugakuBunsan = suugakuNijouHeikin - pow(suugakuHeikin, 2);
    eigoBunsan = eigoNijouHeikin - pow(eigoHeikin, 2);
    buturiBunsan = buturiNijouHeikin - pow(buturiHeikin, 2);

    suugakuHyojunhensa = sqrt(suugakuBunsan);
    eigoHyojunhensa = sqrt(eigoBunsan);
    buturiHyojunhensa = sqrt(buturiBunsan);

    sprintf(s[0], "数学");
    sprintf(s[1], "英語");
    sprintf(s[2], "物理");

    fout = fopen("out/exam04.dat", "w");

    fprintf(fout, "%s:点数=%d,%d,%d,%d,%d,\n平均=%lf,標準偏差=%lf\n\n", s[0], x[0][0], x[0][1], x[0][2], x[0][3], x[0][4], suugakuHeikin, suugakuHyojunhensa);
    fprintf(fout, "%s:点数=%d,%d,%d,%d,%d,\n平均=%lf,標準偏差=%lf\n\n", s[1], x[1][0], x[1][1], x[1][2], x[1][3], x[1][4], eigoHeikin, eigoHyojunhensa);
    fprintf(fout, "%s:点数=%d,%d,%d,%d,%d,\n平均=%lf,標準偏差=%lf\n\n", s[2], x[2][0], x[2][1], x[2][2], x[2][3], x[2][4], buturiHeikin, buturiHyojunhensa);

    fclose(fin);
    fclose(fout);
}