/*
 * @Author       : FeiYehua
 * @Date         : 2024-09-19 23:26:14
 * @LastEditTime : 2024-09-19 23:27:16
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : CheckIfEmpty.c
 *      © 2024 FeiYehua
 */
#include"CheckIfEmpty.h"
#include"GlobalVariables.h"
int checkIfEmpty()
{
    for(int i=1;i<=5;i++)
    {
        if(vendingMachineItem[i].quan!=0)
        {
            return 1;
        }
    }
    return 0;
}