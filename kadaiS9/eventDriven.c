#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "MT.h"

#define TR_SIZE 10

struct transaction
{
    double event_time;        /*Time the event occurs*/
    int event_type;           /*Type of event*/
    int works1;               /*Working area 1*/
    int works2;               /*Working area 2*/
    int works3;               /*Working area 3*/
    struct transaction *pre;  /*Pointer to previous element*/
    struct transaction *next; /*Pointer to next element*/
};

struct transaction tr_tab[TR_SIZE]; /*Transaction table*/
struct transaction *tr_tab_top;     /*Pointer to the top element*/

double now_time = 0;
int gwork1 = 0;
int gwork2 = 0;
int gwork3 = 0;
int n_trans = 0;
int n_blk = 0;
int q_len = 0;
double lmd1 = 0.3;
double lmd2 = 0.29;
int d_q_len[TR_SIZE] = {0};
int n_arr = 0;
int f_serv = 0;
int cap = TR_SIZE;

int get_trans()
{
    int i;
    struct transaction *p;

    now_time = tr_tab_top->event_time;
    i = tr_tab_top->event_type;
    gwork1 = tr_tab_top->works1;
    gwork2 = tr_tab_top->works2;
    gwork3 = tr_tab_top->works3;
    if (tr_tab_top->pre != 0)
        errprt(101);
    n_trans--;
    if (n_trans > 0)
    {
        p = tr_tab_top;
        tr_tab_top = tr_tab_top->next;
        tr_tab_top->pre = 0;
        if (p != &tr_tab[n_trans])
        {
            p->event_time = tr_tab[n_trans].event_time;
            p->event_type = tr_tab[n_trans].event_type;
            p->works1 = tr_tab[n_trans].works1;
            p->works2 = tr_tab[n_trans].works2;
            p->works3 = tr_tab[n_trans].works3;
            p->pre = tr_tab[n_trans].pre;
            p->next = tr_tab[n_trans].next;
            if (p->pre != 0)
                (p->pre)->next = p;
            else
                tr_tab_top = p;
            if (p->next != 0)
                (p->next)->pre = p;
        }
    }
    /*out_trtab();*/
    return (i);
}

void insert_trans(ev_time, ev_type, w1, w2, w3) double ev_time;
int ev_type;
int w1;
int w2;
int w3;
{
    int flg;
    struct transaction *p;

    if (n_trans == TR_SIZE)
        errprt(100);

    tr_tab[n_trans].event_time = ev_time;
    tr_tab[n_trans].event_type = ev_type;
    tr_tab[n_trans].works1 = w1;
    tr_tab[n_trans].works2 = w2;
    tr_tab[n_trans].works3 = w3;
    if (n_trans == 0)
    {
        tr_tab[n_trans].pre = 0;
        tr_tab[n_trans].next = 0;
        tr_tab_top = &tr_tab[n_trans];
    }
    else
    {
        p = tr_tab_top;
        flg = 0;
        while (p->event_time < ev_time)
        {
            if (p->next == 0)
            { /* New event is inserted into the last element. */
                tr_tab[n_trans].pre = p;
                tr_tab[n_trans].next = 0;
                p->next = &tr_tab[n_trans];
                flg = 1;
                break;
            }
            p = p->next;
        }
        if ((p == tr_tab_top) && (flg == 0))
        { /* New event is inserted into the top element. */
            tr_tab[n_trans].pre = 0;
            tr_tab[n_trans].next = p;
            tr_tab_top = &tr_tab[n_trans];
            p->pre = &tr_tab[n_trans];
        }
        else
        { /* Others */
            if (flg == 0)
            {
                tr_tab[n_trans].pre = p->pre;
                tr_tab[n_trans].next = p;
                (p->pre)->next = &tr_tab[n_trans];
                p->pre = &tr_tab[n_trans];
            }
        }
    }
    n_trans++;
    // out_trtab();
}

void arrival()
{
    insert_trans(now_time + exp_rand(lmd1), 0);
    d_q_len[q_len]++;
    n_arr++;
    if (f_serv == 0)
    {
        insert_trans(now_time + exp_rand(lmd2), 1);
        f_serv = 1;
    }
    else
    {
        if (q_len == cap)
            n_blk++;
        else
            q_len++;
    }
}

void service_cmp()
{
    f_serv = 0;
    if (q_len > 0)
    {
        insert_trans(now_time + exp_rand(lmd2), 1);
        q_len--;
        f_serv = 1;
    }
}

double exp_rand(x)
{
    double x;
    return (-log(1.0 - genrand_real2()) / x);
}

int main(void)
{
    int sim_time = 1000;
    while (now_time < sim_time)
    {
        switch (get_trans())
        {
        case 0:
        {
            req_generated();
            break;
        }
        default:
            break;
        }
    }
}
