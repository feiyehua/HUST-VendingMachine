/*
 * @Author       : FeiYehua
 * @Date         : 2024-09-17 12:40:09
 * @LastEditTime : 2024-09-23 16:20:33
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : VendingMachineLevel1-2.c
 *      © 2024 FeiYehua
 */
#include<stdio.h>
#include"Pay.h"
#ifdef _WIN32
#include<windows.h>
#endif
int price;
int main()
{
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif
    printf("请输入总价\n");
    while(scanf("%d",&price)!=1)
    {
        printf("请输入一个数字！\n");
        while(getchar()!='\n');
    }
    while(getchar()!='\n');
    if(payItem(price,1)!=0)
    {
        return -1;
    }
    return 0;
}