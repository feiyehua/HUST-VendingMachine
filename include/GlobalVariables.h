/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-09-17 18:02:05
 * @LastEditTime : 2024-09-22 08:07:30
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : GlobalVariables.h
 * @     © 2024 FeiYehua
 */
#ifndef __GlobalVariables_h__
#define __GlobalVariables_h__
struct itemInfo{
    char name;//货物的名称
    int price;
    int quan;//货物的价格和数量
};
extern struct itemInfo vendingMachineItem[10];
extern int lastLoc[4];
extern int nextLoc[4];
#endif