/**********************************************************************************************************************
 * \file Cpu0_Main.c
 * \copyright Copyright (C) Infineon Technologies AG 2019
 * 
 * Use of this file is subject to the terms of use agreed between (i) you or the company in which ordinary course of 
 * business you are acting and (ii) Infineon Technologies AG or its licensees. If and as long as no such terms of use
 * are agreed, use of this file is subject to following:
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization obtaining a copy of the software and 
 * accompanying documentation covered by this license (the "Software") to use, reproduce, display, distribute, execute,
 * and transmit the Software, and to prepare derivative works of the Software, and to permit third-parties to whom the
 * Software is furnished to do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including the above license grant, this restriction
 * and the following disclaimer, must be included in all copies of the Software, in whole or in part, and all 
 * derivative works of the Software, unless such copies or derivative works are solely in the form of 
 * machine-executable object code generated by a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE 
 * COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN 
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS 
 * IN THE SOFTWARE.
 *********************************************************************************************************************/
 /*\title External interrupt generation
 * \abstract The ERU is used to generate an interrupt on each rising and falling edge at an input pin.
 * \description The code example uses the External Request Unit (ERU) to generate an interrupt for each
 *              falling and rising edge at an input pin. The falling and rising edges are generated
 *              with the pin P00.7 connected to the board�s button. If an interrupt occurs, an LED will be toggled.
 *
 * \name ERU_Interrupt_1_KIT_TC275_LK
 * \version V1.0.0
 * \board AURIX TC275 lite Kit, KIT_AURIX_TC275_LITE, TC27xTP_D-Step
 * \keywords AURIX, ERU, ERU_Interrupt_1, external request, interrupt
 * \documents https://www.infineon.com/aurix-expert-training/Infineon-AURIX_ERU_Interrupt_1_KIT_TC275_LK-TR-v01_00_00-EN.pdf
 * \documents https://www.infineon.com/aurix-expert-training/TC27D_iLLD_UM_1_0_1_12_0.chm
 * \lastUpdated 2021-06-29
 *********************************************************************************************************************/
#include "Ifx_Types.h"
#include "IfxCpu.h"
#include "IfxScuWdt.h"
#include "ERU_Interrupt.h"
#include "Motor_control_pwm.h"
extern long encoderPos;
IfxCpu_syncEvent g_cpuSyncEvent = 0;
int core0_main(void)
{
    IfxCpu_enableInterrupts();

    /* !!WATCHDOG0 AND SAFETY WATCHDOG ARE DISABLED HERE!!
     * Enable the watchdogs and service them periodically if it is required
     */
    IfxScuWdt_disableCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());
    IfxScuWdt_disableSafetyWatchdog(IfxScuWdt_getSafetyWatchdogPassword());

    /* Wait for CPU sync event */
    IfxCpu_emitEvent(&g_cpuSyncEvent);
    IfxCpu_waitEvent(&g_cpuSyncEvent, 1);

    /* Initialize ERU module and peripherals for ERU_Interrupt example */
    initPeripheralsAndERU();
    init_PWM_signal_generation();

    while(1)
    {

    }
    return (1);
}

