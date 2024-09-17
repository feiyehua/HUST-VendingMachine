/*
 * @Author       : FeiYehua
 * @Date         : 2024-09-17 18:02:05
 * @LastEditTime : 2024-09-17 18:02:06
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : ItemInfo.h
 *      © 2024 FeiYehua
 */
#ifndef __ItemInfo_h__
#define __ItemInfo_h__
struct itemInfo{
    char name;//货物的名称
    int price;
    int quan;//货物的价格和数量
}vendingMachineItem[30];//使用一个结构体存储售货机的物品数量,数组下标为位置
#endif