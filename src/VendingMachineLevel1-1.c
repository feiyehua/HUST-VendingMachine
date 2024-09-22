/*
 * @Author       : FeiYehua
 * @Date         : 2024-09-16 23:16:13
 * @LastEditTime : 2024-09-22 08:02:51
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : VendingMachineLevel1-1.c
 *      © 2024 FeiYehua
 */
#include<stdio.h>
#include"AddItem.h"
#include"GlobalVariables.h"
#include"ShowItem.h"
int main()
{
    if(addItem(1)!=0)
    {
        printf("输入内容错误！");
        return -1;
    }
    showItem();
    return 0;
}
/*
A 3 5 7
B 2 4 6
a 1 2 4
F 5 6 7 
T 11 9 10
*/