/*
 * @Author       : FeiYehua
 * @Date         : 2024-09-17 12:53:01
 * @LastEditTime : 2024-09-18 20:17:33
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : AddItem.c
 *      © 2024 FeiYehua
 */
#include<stdio.h>
#include"AddItem.h"
#include"ItemInfo.h"
#include<string.h>
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
int addItem(int cfg)//cfg为1时，只需输入一次，cfg为2时，需要输入多次
{
    //getchar();
    printf("请依次输入货物的名称、位置、单价、数量，每行输入一种商品的信息\n");
    while(cfg!=0)
    {
        char inputCache[100];
        memset(inputCache,0,sizeof(inputCache));
        fgets(inputCache,100,stdin);
        if(strcmp(inputCache,"END\n")==0)//当检测到输入为END时，跳出循环
        {
            cfg=0;
            continue;
        }
        char name=0;
        int place=0,quan=0,price=0;
        sscanf(inputCache," %c %d %d %d",&name,&place,&price,&quan);
        if(checkItemInfo(name,place,price,quan)==-1)
        {
            return -1;
        }
        vendingMachineItem[place].name=name;
        vendingMachineItem[place].price=price;
        vendingMachineItem[place].quan=quan;
        if(cfg==1)
        {
            cfg-=1;
        }
    }
    return 0;
}