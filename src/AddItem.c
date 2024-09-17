/*
 * @Author       : FeiYehua
 * @Date         : 2024-09-17 12:53:01
 * @LastEditTime : 2024-09-17 23:33:42
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : AddItem.c
 *      © 2024 FeiYehua
 */
#include<stdio.h>
#include"AddItem.h"
#include"ItemInfo.h"
int checkItemInfo(char name,int place,int price,int quan)
{
    if(name>'Z'||name<'A')
    {
        return -1;
    }
    if(place<=0||place>=6)
    {
        return -1;
    }
    return 0;
}
int addItem(int n)
{
    //getchar();
    printf("请依次输入货物的名称、位置、单价、数量，每行输入一种商品的信息\n");
    for(int i=1;i<=n;i++)
    {
        char name=0;
        int place,quan,price;
        scanf(" %c%d%d%d",&name,&place,&price,&quan);
        if(checkItemInfo(name,place,price,quan)==-1)
        {
            return -1;
        }
        vendingMachineItem[place].name=name;
        vendingMachineItem[place].price=price;
        vendingMachineItem[place].quan=quan;
    }
    return 0;
}