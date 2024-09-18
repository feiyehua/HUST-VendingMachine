/*
 * @Author       : FeiYehua
 * @Date         : 2024-09-17 23:49:04
 * @LastEditTime : 2024-09-18 20:30:07
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : Pay.c
 *      © 2024 FeiYehua
 */
#include"Pay.h"
#include<stdio.h>
int lastLoc[4]={0,3,1,2};
int nextLoc[4]={0,2,3,1};
int curPay[4];//存储最近三个付款信息
int payItem(int price,int cfg)
{
    int total=0;
    while(total<price)
    {
        int n=0;
        scanf("%d",&n);
        if(n!=1&&n!=2&&n!=5)
        {
            printf("投入金额错误!\n");
            return -1;
        }
        total+=n;
    }
    printf("完成投币，开始找零 %d元\n",total-price);
    return 0;
}
int undoPay(int *cur,int *curTotal)
{
    if(curPay[*cur]==0)
    {
        printf("没有可以回退的操作！");
        return -1;
    }
    *curTotal-=curPay[*cur];
    curPay[*cur]=0;
    *cur=lastLoc[*cur];
    return 0;
}