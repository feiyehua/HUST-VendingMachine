/*
 * @Author       : FeiYehua
 * @Date         : 2024-09-22 07:19:05
 * @LastEditTime : 2024-09-22 07:19:07
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : ShowItem.c
 *      © 2024 FeiYehua
 */
#include"ShowItem.h"
#include"GlobalVariables.h"
#include"stdio.h"
int showItem()
{
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