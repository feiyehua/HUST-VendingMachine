/*
 * @Author       : FeiYehua
 * @Date         : 2024-09-17 23:49:04
 * @LastEditTime : 2024-09-18 11:41:48
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : Pay.c
 *      © 2024 FeiYehua
 */
#include"Pay.h"
#include<stdio.h>
int payItem(int price)
{
    int total=0;
    while(total<price)
    {
        int n=0;
        scanf("%d",&n);
        if(n!=1&&n!=2&&n!=5)
        {
            printf("投入金额错误!\n");
            return -1;
        }
        total+=n;
    }
    printf("完成投币，开始找零 %d元\n",total-price);
    return 0;
}