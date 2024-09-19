/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-09-17 23:24:41
 * @LastEditTime : 2024-09-19 17:10:30
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : BuyItem.h
 * @     © 2024 FeiYehua
 */
#ifndef __BuyItem_h__
#define __BuyItem_h__
struct addedItem{
    char name;
    int place,quan;
};
int buyItem(int*,int);
int undoBuy(int*,struct addedItem*,int*);
#endif