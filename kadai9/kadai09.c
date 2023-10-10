#include <stdio.h>
#include <stdlib.h>

int kosuu = 10;

int tansaku(int x[], int left, int right)
{
    int p, i, j;
    p = x[(left + right) / 2];
    i = left;
    j = right;

    while (1)
    {
        while (x[i] < p)
        {
            i++;
        }

        while (p < x[j])
        {
            j--;
        }

        if (i >= j)
        {
            break;
        }

        int tmp = 0;
        tmp = x[i];
        x[i] = x[j];
        x[j] = tmp;

        i++;
        j--;
    }

    if (left < i - 1)
    {
        tansaku(x, left, i - 1);
    }
    if (j + 1 < right)
    {
        tansaku(x, j + 1, right);
    }
}

int main(void)
{
    FILE *fin;
    int x[10] = {0};
    fin = fopen("in/exam09.dat", "r");
    for (int itr = 0; itr < kosuu; itr++)
    {
        fscanf(fin, "%d", &x[itr]);
    }

    tansaku(x, 0, 9);

    for (int itr = 0; itr < kosuu; itr++)
    {
        printf("%d ", x[itr]);
    }
}