/*
 * @Author       : FeiYehua
 * @Date         : 2024-09-17 22:58:44
 * @LastEditTime : 2024-09-18 11:53:08
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : VendingMachineLevel1-3.c
 *      © 2024 FeiYehua
 */
#include<stdio.h>
#include"AddItem.h"
#include"ItemInfo.h"
#include"BuyItem.h"
#include"Pay.h"
typedef enum {
    ERROR,
    SELL,
    BUY,
    ADD
} VendingMachineState;
VendingMachineState nextState(VendingMachineState currentState)
{
    switch(currentState)
    {
        case ERROR:
        {
            printf("发生错误！\n");
            return SELL;
        }
        case SELL:
        {
            printf("请选择要进行的操作\n");
            printf("1.摆放\n");
            printf("2.购买\n");
            int ope=0;
            scanf("%d",&ope);
            switch(ope)
            {
                case 1:
                    return ADD;
                case 2:
                    return BUY;
                default:
                    return ERROR;
            }
        }
        case ADD:
        {
            addItem(1);
            return SELL;
        }
        case BUY:
        {
            int totalPrice=0;
            if(buyItem(&totalPrice)!=0)
            {
                return ERROR;
            }
            if(payItem(totalPrice)!=0)
            {
                return ERROR;
            }
            return SELL;
        }
    }
}
int main()
{
    VendingMachineState state = SELL;
    while(state!=ERROR)
    {
        state=nextState(state);
    }
    return 1;
}