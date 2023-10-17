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
    int kazuSeisuList = 0;
    int itiSeisu = 1;

    while (1)
    {
        int menyu = 0;
        int nyuryokuSeisu = 0;
        printf("[メニュー] 0:入力, 1:削除, 2:表示, 3:終了：");
        scanf("%d", &menyu);

        if (menyu == 0 && head == 0x0)
        {
            printf("初めて入力するのですね！整数を入力してください：");
            scanf("%d", &nyuryokuSeisu);
            if (x == 0x0)
            {
                x = malloc(1 * sizeof(seisuList));
            }
            x->seisu = nyuryokuSeisu;
            head = x;
            tail = head;

            nyuryokuHajimete = 0;
            kazuSeisuList++;
            itiSeisu++;

            seisuList *y = malloc(1 * sizeof(seisuList));

            y = head;
            int itr = 1;
            printf("格納された整数を表示します\n");

            while (y != NULL)
            {

                printf("%d番目：%d\n", itr, y->seisu);

                y = y->next;
                itr++;
            }

            continue;
        }
        else if (menyu == 0)
        {
            printf("入力が選ばれました！整数を入力してください：");
            scanf("%d", &nyuryokuSeisu);
            x = malloc(1 * sizeof(seisuList));
            x->seisu = nyuryokuSeisu;

            x->next = NULL;
            tail->next = x;
            tail = tail->next;

            kazuSeisuList++;
            itiSeisu++;

            x = head;
            int itr = 1;
            while (x != NULL)
            {
                if (tail->seisu < x->seisu)
                {
                    int tmp;
                    tmp = tail->seisu;
                    tail->seisu = x->seisu;
                    x->seisu = tmp;
                    printf("入れ替えました\n");
                }
                x = x->next;
                itr++;
            }

            seisuList *y = malloc(1 * sizeof(seisuList));

            y = head;
            itr = 1;
            printf("格納された整数を表示します\n");

            while (y != NULL)
            {

                printf("%d番目：%d\n", itr, y->seisu);

                y = y->next;
                itr++;
            }
        }
        else if (menyu == 1)
        {
            printf("削除が選ばれました！削除する整数を入力してください：");
            scanf("%d", &nyuryokuSeisu);

            x = head;
            seisuList *sakujopointer = x->next;
            while (x != NULL)
            {

                printf("%dのデータを削除します\n", nyuryokuSeisu);
                if (x == head && x->seisu == nyuryokuSeisu)
                {
                    x = x->next;
                    if (sakujopointer != 0x0)
                    {
                        sakujopointer = sakujopointer->next;
                    }
                    head = x;
                    printf("先頭のノードを削除しました.\n");

                    seisuList *y = malloc(1 * sizeof(seisuList));

                    y = head;
                    int itr = 1;
                    printf("格納された整数を表示します\n");

                    while (y != NULL)
                    {

                        printf("%d番目：%d\n", itr, y->seisu);

                        y = y->next;
                        itr++;
                    }

                    continue;
                }
                else if (sakujopointer != 0x0 && sakujopointer->seisu == nyuryokuSeisu)
                {

                    x->next = sakujopointer->next;
                    free(sakujopointer);
                    printf("途中のノードを削除しました.\n");

                    seisuList *y = malloc(1 * sizeof(seisuList));

                    y = head;
                    int itr = 1;
                    printf("格納された整数を表示します\n");

                    while (y != NULL)
                    {

                        printf("%d番目：%d\n", itr, y->seisu);

                        y = y->next;
                        itr++;
                    }
                    continue;
                }
                else
                {
                    printf("目的のノードを削除しました\n");
                    break;
                }

                if (x == 0x0)
                {
                    printf("全てのノードを削除しました\n");
                    break;
                }

                x = x->next;
                sakujopointer = sakujopointer->next;
            }
        }
        else if (menyu == 2)
        {
            int hyoujiBasho = 0;
            printf("表示が選ばれました！表示する位置を入力してください：");
            scanf("%d", &hyoujiBasho);

            if (hyoujiBasho > kazuSeisuList)
            {
                printf("格納されている数よりも大きい整数を入力したので表示できません\n");
                continue;
            }
            else
            {
                seisuList *y = malloc(1 * sizeof(seisuList));

                y = head;
                int itr = 1;
                printf("格納された整数を表示します\n");

                while (y != NULL)
                {

                    printf("%d番目：%d\n", itr, y->seisu);

                    y = y->next;
                    itr++;
                }
            }
        }
        else if (menyu == 3)
        {
            break;
        }
    }
    return 0;
}