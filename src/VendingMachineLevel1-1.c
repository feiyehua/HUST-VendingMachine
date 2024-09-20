/*
 * @Author       : FeiYehua
 * @Date         : 2024-09-16 23:16:13
 * @LastEditTime : 2024-09-20 17:34:08
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : VendingMachineLevel1-1.c
 *      © 2024 FeiYehua
 */
#include<stdio.h>
#include"AddItem.h"
#include"GlobalVariables.h"
int main()
{
    for(int i=1;i<=29;i++)
    {
        vendingMachineItem[i].quan=0;
    }
    int n=1;//n表示物品的种类种数
    if(addItem(n)!=0)
    {
        printf("输入内容错误！");
        return -1;
    }
    for(int i=1;i<=5;i++)
    {
        if(vendingMachineItem[i].quan==0)//如果货架上无货，则不输出
        {
            continue;
        }
        else{//输出货架上的货物信息
            printf("%d: ",i);
            for(int j=1;j<=vendingMachineItem[i].quan;j++)
            {
                printf("%c",vendingMachineItem[i].name);
            }
            printf(" %d\n",vendingMachineItem[i].price);
        }
    }
    return 0;
}
/*
A 3 5 7
B 2 4 6
a 1 2 4
F 5 6 7 
T 11 9 10
*/