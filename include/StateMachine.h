/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-09-18 12:43:31
 * @LastEditTime : 2024-09-18 12:45:15
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : StateMachine.h
 * @     © 2024 FeiYehua
 */
#ifndef __StateMachine_h__
#define __StateMachine_h__
typedef enum {
    ERROR,
    SELL,
    BUY,
    ADD,
    END
} VendingMachineState;
VendingMachineState nextState(VendingMachineState);
#endif