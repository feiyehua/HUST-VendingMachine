/*
 * @Author       : FeiYehua
 * @Date         : 2024-09-17 23:25:09
 * @LastEditTime : 2024-09-19 17:29:41
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : BuyItem.c
 *      © 2024 FeiYehua
 */
#include<stdio.h>
#include"GlobalVariables.h"
#include"BuyItem.h"
#include<string.h>
struct addedItem addedItemLog[4];
int checkItemAvailability(char name,int place,int quan)
{
    if(place>5)
    {
        printf("没有这个通道！\n");
        return -2;
    }
    if(vendingMachineItem[place].name!=name)
    {
        printf("输入的货物与该通道上的货物不匹配！\n");
        return -1;
    }
    if(vendingMachineItem[place].quan<quan)
    {
        printf("货物数量不足！\n");
        return -3;
    }
    vendingMachineItem[place].quan-=quan;
    return 0;
}
int buyItem(int* totalPrice,int cfg)
{
    int cur=0;
    printf("请输入购买货物的名称，货物位置，购买数量！\n");
    while(cfg!=0)
    {
        char name=0;
        int place=0,quan=0;
        char inputCache[100];
        memset(inputCache,0,sizeof(inputCache));
        fgets(inputCache,100,stdin);
        if(strcmp(inputCache,"END\n")==0&&cfg!=1)//输入为END时停止输入
        {
            cfg=0;
            continue;
        }
        if(strcmp(inputCache,"BACK\n")==0&&cfg==3)
        {
            undoBuy(&cur,&addedItemLog[cur],totalPrice);
            continue;
        }
        sscanf(inputCache," %c %d %d",&name,&place,&quan);
        if(checkItemAvailability(name,place,quan)==0)
        {
            *totalPrice+=vendingMachineItem[place].price*quan;
        }
        else
        {
            continue;
        }
        if(cfg==1)
        {
            cfg-=1;
        }
        cur=nextLoc[cur];
        addedItemLog[cur].name=name;
        addedItemLog[cur].place=place;
        addedItemLog[cur].quan=quan;
    }
    printf("总价为%d元！\n",*totalPrice);
    return 0;
}
int undoBuy(int* cur,struct addedItem* curItem,int* curTotal)
{
    if((*curItem).name==0)
    {
        printf("没有可以回退的操作！\n");
        return -1;
    }
    *curTotal-=vendingMachineItem[(*curItem).place].price*(*curItem).quan;
    vendingMachineItem[(*curItem).place].quan+=(*curItem).quan;
    (*curItem).name=0,(*curItem).quan=0,(*curItem).place=0;
    *cur=lastLoc[*cur];
    return 0;
}