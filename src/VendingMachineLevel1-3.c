/*
 * @Author       : FeiYehua
 * @Date         : 2024-09-17 22:58:44
 * @LastEditTime : 2024-09-18 12:37:45
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
    ADD,
    END
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
            printf("0.退出\n");
            int ope=0;
            scanf("%d",&ope);
            switch(ope)
            {
                case 0:
                    return END;
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
        case END:
            return END;
    }
}
int main()
{
    VendingMachineState state = SELL;
    while(state!=END)
    {
        state=nextState(state);
    }
    return 1;
}