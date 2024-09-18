/*
 * @Author       : FeiYehua
 * @Date         : 2024-09-17 23:49:04
 * @LastEditTime : 2024-09-18 23:22:02
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : Pay.c
 *      © 2024 FeiYehua
 */
#include"Pay.h"
#include<stdio.h>
#include<string.h>
int lastLoc[4]={0,3,1,2};
int nextLoc[4]={1,2,3,1};
int curPay[4];//存储最近三个付款信息
int payItem(int price,int cfg)
{
    int total=0;
    int cur=0;
    while(total<price)
    {
        char name=0;
        int place=0,quan=0;
        char inputCache[100];
        memset(inputCache,0,sizeof(inputCache));
        fgets(inputCache,100,stdin);
        if(cfg==3&&strcmp(inputCache,"BACK\n")==0)
        {
            undoPay(&cur,&total);
            continue;
        }
        else
        {
            int n=0;
            sscanf(inputCache,"%d",&n);
            if(n!=1&&n!=2&&n!=5)
            {   
                printf("投入金额错误!\n");
                return -1;
            }
            cur=nextLoc[cur];
            curPay[cur]=n;
            total+=n;
        } 
        
    }
    printf("完成投币，开始找零 %d元\n",total-price);
    return 0;
}
int undoPay(int *cur,int *curTotal)
{
    if(curPay[*cur]==0)
    {
        printf("没有可以回退的操作！\n");
        return -1;
    }
    *curTotal-=curPay[*cur];
    curPay[*cur]=0;
    *cur=lastLoc[*cur];
    return 0;
}