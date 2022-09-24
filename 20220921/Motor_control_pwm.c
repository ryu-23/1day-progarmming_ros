/*
 * Motor_control_pwm.c
 *
 *  Created on: 2022. 8. 4.
 *      Author: user
 */

#include "IfxPort.h"
#include "Bsp.h"
#include "ADC_Single_Channel.h"
#include "Motor_control_pwm.h"

#define L298_IN1         &MODULE_P00, 0
#define L298_IN2         &MODULE_P00, 1

void L298_Pin_init(void)
{
    IfxPort_setPinModeOutput(L298_IN1, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
    IfxPort_setPinLow(L298_IN1);

    IfxPort_setPinModeOutput(L298_IN2, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
    IfxPort_setPinLow(L298_IN2);
}

void motor_control(int pwm)
{
    if(pwm<0)  //fwd or reverse
    {
        //IN1 high   IN2 low
        IfxPort_setPinHigh(L298_IN1);
        IfxPort_setPinLow(L298_IN2);
    }
    else if(pwm>0)     //fwd or reverse
    {
        //IN1 low   IN2 high
        IfxPort_setPinLow(L298_IN1);
        IfxPort_setPinHigh(L298_IN2);
    }
    else      //stop
    {
        //IN1 low   IN2 low
        IfxPort_setPinLow(L298_IN1);
        IfxPort_setPinLow(L298_IN2);
    }
}



