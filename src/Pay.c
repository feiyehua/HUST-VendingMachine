/*
 * @Author       : FeiYehua
 * @Date         : 2024-09-17 23:49:04
 * @LastEditTime : 2024-09-17 23:52:40
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : Pay.c
 *      © 2024 FeiYehua
 */
#include"Pay.h"
#include<stdio.h>
int payItem(int price,int* total)
{
    while(*total<price)
    {
        int n=0;
        scanf("%d",&n);
        if(n!=1&&n!=2&&n!=5)
        {
            printf("投入金额错误");
            return -1;
        }
        *total+=n;
    }
    return 0;
}