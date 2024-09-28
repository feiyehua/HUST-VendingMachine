/*
 * @Author       : FeiYehua
 * @Date         : 2024-09-16 23:16:13
 * @LastEditTime : 2024-09-28 22:17:46
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : VendingMachineLevel1-1.c
 *      © 2024 FeiYehua
 */
#include<stdio.h>
#include"AddItem.h"
#include"GlobalVariables.h"
#include"ShowItem.h"
#ifdef _WIN32
#include<windows.h>
#endif
int main()
{
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif
    if(addItem(1)!=0)
    {
        printf("输入内容错误！\n");
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