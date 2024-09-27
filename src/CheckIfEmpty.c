/*
 * @Author       : FeiYehua
 * @Date         : 2024-09-19 23:26:14
 * @LastEditTime : 2024-09-27 18:04:46
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : CheckIfEmpty.c
 *      © 2024 FeiYehua
 */
#include"CheckIfEmpty.h"
#include"GlobalVariables.h"
#include<stdio.h>
int checkIfEmpty()
{
    for(int i=1;i<=5;i++)
    {
        if(vendingMachineItem[i].quan!=0)
        {
            return 1;
        }
    }
    printf("货物已售空，欢迎下次再来！\n");
    return 0;
}