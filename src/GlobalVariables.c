/*
 * @Author       : FeiYehua
 * @Date         : 2024-09-19 16:56:04
 * @LastEditTime : 2024-09-19 16:59:36
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : GlobalVariables.c
 *      © 2024 FeiYehua
 */
//在这里存储了项目用到的全局变量。
//lastLoc和nextLoc用来存储一个类似链表的结构，使记录历史操作时有更优的空间复杂度。
//vendingMachineItem数组存储了已经放入售货机的物品信息
#include"GlobalVariables.h"
int lastLoc[4]={0,3,1,2};
int nextLoc[4]={1,2,3,1};
struct itemInfo vendingMachineItem[30];//使用一个结构体存储售货机的物品数量,数组下标为位置