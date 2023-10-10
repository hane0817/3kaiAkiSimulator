#include <stdio.h>
#include <stdlib.h>

typedef struct __seisuList
{
    int seisu;
    struct __seisuList *next;
} seisuList;

int main(void)
{
    seisuList *head = NULL;
    seisuList *tail = NULL;

    seisuList *x = malloc(1 * sizeof(seisuList));
    int nyuryokuHajimete = 1;
    while (1)
    {
        int menyu = 0;
        int nyuryokuSeisu = 0;
        printf("[メニュー] 0:入力, 1:削除, 2:表示, 3:終了：");
        scanf("%d", &menyu);

        if (menyu == 0 && nyuryokuHajimete == 1)
        {
            printf("初めて入力するのですね！整数を入力してください：");
            scanf("%d", nyuryokuSeisu);

            x->seisu = nyuryokuSeisu;
            head = x;
            tail = head;

            nyuryokuHajimete = 0;
        }
        else if (menyu == 0)
        {
            printf("入力が選ばれました！整数を入力してください：");
            scanf("%d", nyuryokuSeisu);
            x->seisu = nyuryokuSeisu;
        }
        else if (menyu == 1)
        {
            printf("削除が選ばれました！削除する整数を入力してください：");
            scanf("%d", nyuryokuSeisu);
        }
        else if (menyu == 2)
        {
            printf("表示が選ばれました！表示する位置を入力してください：");
            scanf("%d", nyuryokuSeisu);
        }
        else if (menyu == 3)
        {
            break;
        }
    }
    return 0;
}