/*
 * @Author       : FeiYehua
 * @Date         : 2024-09-17 23:25:09
 * @LastEditTime : 2024-09-18 22:15:57
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : BuyItem.c
 *      © 2024 FeiYehua
 */
#include<stdio.h>
#include"ItemInfo.h"
#include"BuyItem.h"
#include<string.h>
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
    printf("请输入购买货物的名称，货物位置，购买数量！\n");
    while(cfg!=0)
    {
        char name=0;
        int place=0,quan=0;
        char inputCache[100];
        memset(inputCache,0,sizeof(inputCache));
        fgets(inputCache,100,stdin);
        if(strcmp(inputCache,"END\n")==0)//输入为END时停止输入
        {
            cfg=0;
            continue;
        }
        sscanf(inputCache," %c %d %d",&name,&place,&quan);
        if(checkItemAvailability(name,place,quan)==0)
        {
            *totalPrice+=vendingMachineItem[place].price;
        }
        else
        {
            return -1;
        }
        //printf("该商品已经添加到购物车！需要继续添加，请输入0；结算，请输入1");
        //printf("\n");
        //scanf("%d",&state);
        if(cfg==1)
        {
            cfg-=1;
        }
    }
    printf("总价为%d元！\n",*totalPrice);
    return 0;
}