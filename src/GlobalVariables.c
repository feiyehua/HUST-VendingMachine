/*
 * @Author       : FeiYehua
 * @Date         : 2024-09-19 16:56:04
 * @LastEditTime : 2024-09-19 16:59:36
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : GlobalVariables.c
 *      © 2024 FeiYehua
 */
#include"GlobalVariables.h"
int lastLoc[4]={0,3,1,2};
int nextLoc[4]={1,2,3,1};
struct itemInfo vendingMachineItem[30];//使用一个结构体存储售货机的物品数量,数组下标为位置