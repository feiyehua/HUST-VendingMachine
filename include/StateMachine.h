/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-09-18 12:43:31
 * @LastEditTime : 2024-09-19 17:52:56
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : StateMachine.h
 * @     © 2024 FeiYehua
 */
#ifndef __StateMachine_h__
#define __StateMachine_h__
typedef enum {
    BUY,
    ADD,
    END
} VendingMachineState;
VendingMachineState nextState(VendingMachineState,int);
#endif