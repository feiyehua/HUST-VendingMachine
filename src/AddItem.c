/*
 * @Author       : FeiYehua
 * @Date         : 2024-09-17 12:53:01
 * @LastEditTime : 2024-09-28 18:28:10
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
struct itemInfo curAdd[4];//存储最近三个摆放信息
int addedItemPlace[4];
int checkItemInfo(char name,int place,int price,int quan)//这里检查了用户输入是否正确
{
    if(name>'Z'||name<'A')
    {
        printf("输入的物品名称错误！\n");
        return -1;
    }
    if(place<=0||place>=6)
    {
        printf("输入的位置错误！\n");
        return -1;
    }
    if(price>=10)
    {
        printf("输入的价格过高！\n");
        return -1;
    }
    if(quan>=50)
    {
        printf("物品数量过多！\n");
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
            return 0;
        }
        if(strcmp(inputCache,"BACK\n")==0&&cfg==3)//当检测到输入为END时，跳出循环，此功能只在cfg为2或3时可用
        {
            undoAdd(&cur);
            continue;
        }
        char name=0;
        int place=0,quan=0,price=0;
        if(sscanf(inputCache," %c %d %d %d",&name,&place,&price,&quan)!=4)
        {
            printf("输入内容错误！\n");
            continue;
        }
        if(checkItemInfo(name,place,price,quan)==-1)
        {
            printf("输入内容错误！\n");
            continue;
        }
        /*if(vendingMachineItem[place].quan!=0)
        {
            printf("所选货架上已经有货！\n");
            continue;
        }*/
        cur=nextLoc[cur];
        curAdd[cur].name=vendingMachineItem[place].name;
        curAdd[cur].price=vendingMachineItem[place].price;
        curAdd[cur].quan=vendingMachineItem[place].quan;//存储在上货之前货架上的物品信息
        vendingMachineItem[place].name=name;
        vendingMachineItem[place].price=price;
        vendingMachineItem[place].quan=quan;
        addedItemPlace[cur]=place;
        if(cfg==1)
        {
            return 0;
        }
    }
    return 0;
}
int undoAdd(int *cur)//这个是Level2-2中的撤销函数
{
    if(addedItemPlace[*cur]==0)
    {
        printf("没有可以回退的操作！\n");
        return -1;
    }
    vendingMachineItem[addedItemPlace[*cur]].name=curAdd[*cur].name;
    vendingMachineItem[addedItemPlace[*cur]].price=curAdd[*cur].price;
    vendingMachineItem[addedItemPlace[*cur]].quan=curAdd[*cur].quan;
    curAdd[*cur].name=0;
    curAdd[*cur].price=0;
    curAdd[*cur].quan=0;//删除掉撤销成功的操作信息
    addedItemPlace[*cur]=0;
    *cur=lastLoc[*cur];
    return 0;
}