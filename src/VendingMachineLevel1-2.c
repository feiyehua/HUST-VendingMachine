/*
 * @Author       : FeiYehua
 * @Date         : 2024-09-17 12:40:09
 * @LastEditTime : 2024-09-17 23:51:14
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : VendingMachineLevel1-2.c
 *      © 2024 FeiYehua
 */
#include<stdio.h>
#include"Pay.h"
int price,total;
int main()
{
    printf("请输入总价\n");
    scanf("%d",&price);
    if(payItem(price,&total)!=0)
    {
        return -1;
    }
    printf("完成投币，开始找零\n%d",total-price);
    return 0;
}