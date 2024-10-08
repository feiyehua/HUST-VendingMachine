/*
 * @Author       : FeiYehua
 * @Date         : 2024-09-17 23:49:04
 * @LastEditTime : 2024-09-23 16:22:27
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : Pay.c
 *      © 2024 FeiYehua
 */
#include"Pay.h"
#include<stdio.h>
#include<string.h>
//这个文件中存储了支付的核心函数。
extern int lastLoc[4];
extern int nextLoc[4];
int curPay[4];//存储最近三个付款信息
int payItem(int price,int cfg)//这是付款操作
{
    int total=0;
    int cur=0;
    int flag=1;
    printf("总价为%d元，开始投币！\n",price);
    while(total<price)
    {
        char name=0;
        int place=0,quan=0;
        char inputCache[100];
        memset(inputCache,0,sizeof(inputCache));
        fgets(inputCache,100,stdin);
        if(strcmp(inputCache,"BUY\n")==0&&flag==1)
        {
            return 1;//如果用户希望返回购买货物的状态，则返回1
        }
        flag=0;//返回购买货物仅在第一次询问投币时有效
        if(cfg==3&&strcmp(inputCache,"BACK\n")==0)
        {
            undoPay(&cur,&total);
            continue;
        }
        else
        {
            int n=0;
            sscanf(inputCache,"%d",&n);
            if(n!=1&&n!=2&&n!=5)//直接在此检测用户输入是否合法
            {   
                printf("投入金额错误，将忽略本次输入!\n");
                continue;
                //return -1;
            }
            cur=nextLoc[cur];
            curPay[cur]=n;
            total+=n;
        } 
        
    }
    printf("完成投币，开始找零 %d元\n",total-price);
    return 0;
}
int undoPay(int *cur,int *curTotal)//Level2-2中撤销函数
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