#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    FILE *fin;
    int x[3][5] = {0}; // 生徒の点数 左の添え字は科目，右は点数
    int idx[5] = {0};  // 各生徒の最大得点の科目番号

    fin = fopen("in/exam04.dat", "r");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            fscanf(fin, "%d", &x[i][j]);
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (idx[i] < x[j][i])
            {
                idx[i] = x[j][i];
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        printf("生徒%dの最大得点は%d\n", i, idx[i]);
    }
}