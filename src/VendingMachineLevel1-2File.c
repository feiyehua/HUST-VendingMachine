/*
 * @Author       : FeiYehua
 * @Date         : 2024-09-17 12:44:51
 * @LastEditTime : 2024-09-18 11:44:51
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : VendingMachineLevel1-2File.c
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
    freopen("Level1-2.in","r",stdin);
    freopen("Level1-2.out","w",stdout);
    printf("请输入总价\n");
    scanf("%d",&price);
    if(payItem(price,1)!=0)
    {
        return -1;
    }
    return 0;
}