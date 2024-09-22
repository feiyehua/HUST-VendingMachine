/*
 * @Author       : FeiYehua
 * @Date         : 2024-09-17 12:53:01
 * @LastEditTime : 2024-09-22 08:04:00
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : AddItem.c
 *      © 2024 FeiYehua
 */
//这里存放了摆放操作的核心函数。
#include<stdio.h>
#include"AddItem.h"
#include"GlobalVariables.h"
#include<string.h>
#include"ShowItem.h"
struct itemInfo curAdd[4];//存储最近三个付款信息
int checkItemInfo(char name,int place,int price,int quan)//这里检查了用户输入是否正确
{
    if(name>'Z'||name<'A')
    {
        return -1;
    }
    if(place<=0||place>=6)
    {
        return -1;
    }
    if(price>=10||quan>=50)
    {
        return -1;
    }
    return 0;
}
int addItem(int cfg)//cfg为1时，只需输入一次，cfg为2时，需要输入多次
//这是摆放货物的核心函数
{
    int cur=0;
    printf("请依次输入货物的名称、位置、单价、数量，每行输入一种商品的信息\n");
    while(cfg!=0)
    {
#ifdef _DEBUG_
        printf("\033[0m\033[1;31mThis is a debug message!\033[0m\n");
        showItem();
#endif
        char inputCache[100];
        memset(inputCache,0,sizeof(inputCache));
        fgets(inputCache,100,stdin);
        if(strcmp(inputCache,"END\n")==0&&cfg!=1)//当检测到输入为END时，跳出循环，此功能只在cfg为2或3时可用
        {
            cfg=0;
            continue;
        }
        if(strcmp(inputCache,"BACK\n")==0&&cfg==3)//当检测到输入为END时，跳出循环，此功能只在cfg为2或3时可用
        {
            undoAdd(&cur,&curAdd[cur]);
            continue;
        }
        char name=0;
        int place=0,quan=0,price=0;
        if(sscanf(inputCache," %c %d %d %d",&name,&place,&price,&quan)!=4){
            return -1;
        }
        if(checkItemInfo(name,place,price,quan)==-1)
        {
            return -1;
        }
        vendingMachineItem[place].name=name;
        vendingMachineItem[place].price=price;
        vendingMachineItem[place].quan=quan;
        cur=nextLoc[cur];
        curAdd[cur].name=name;
        curAdd[cur].price=price;
        curAdd[cur].quan=quan;
        if(cfg==1)
        {
            cfg-=1;
        }
    }
    return 0;
}
int undoAdd(int *cur,struct itemInfo *item)//这个是Level2-2中的撤销函数
{
    if((*item).name==0)
    {
        printf("没有可以回退的操作！\n");
        return -1;
    }
    (*item).name=0;
    (*item).price=0;
    (*item).quan=0;//删除掉撤销成功的操作信息
    *cur=lastLoc[*cur];
    return 0;
}