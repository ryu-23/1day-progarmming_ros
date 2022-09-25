#include "GPT12_PWM_Generation.h"
#include "Ifx_Types.h"
#include "IfxGpt12.h"
#include "IfxPort.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
#define ISR_PRIORITY_GPT12_TIMER    6                       /* Define the GPT12 Timer interrupt priority            */
#define ISR_PROVIDER_GPT12_TIMER    IfxSrc_Tos_cpu0         /* Interrupt provider                                   */
#define PWM_FREQUENCY               486.44f                    /* Frequency of the PWM signal in Hz                    */
#define PWM_DUTY_CYCLE              30                      /* Duty cycle of the PWM signal in percentage           */
#define LED                         &MODULE_P00, 5          /* LED which toggles in the Interrupt Service Routine   */
#define GPT1_BLOCK_PRESCALER        32                      /* GPT1 block prescaler value                           */
#define TIMER_T3_INPUT_PRESCALER    32                      /* Timer input prescaler value                          */
#define TEST_PIN1                   &MODULE_P02, 0

/*********************************************************************************************************************/
/*--------------------------------------------Function Implementations-----------------------------------------------*/
/*********************************************************************************************************************/
/* Macro to define Interrupt Service Routine */
IFX_INTERRUPT(interruptGpt12, 0, ISR_PRIORITY_GPT12_TIMER);
extern float32 test_value;
float32 fTimer;

/* Interrupt Service Routine of the GPT12 */
void interruptGpt12(void)
{
    /* Toggle the state of the LED */
    IfxPort_togglePin(LED);
    IfxPort_togglePin(TEST_PIN1);
}

/* Function to initialize the GPT12 module and the LED */
void initGpt12PWM(void)
{
    /* Enable the GPT12 module */
    IfxGpt12_enableModule(&MODULE_GPT120);
    /* Set GPT1 block prescaler to divide the module frequency */
    IfxGpt12_setGpt1BlockPrescaler(&MODULE_GPT120, IfxGpt12_Gpt1BlockPrescaler_32);
    /* Set the GPT12 timer T3 in timer mode */
    IfxGpt12_T3_setMode(&MODULE_GPT120, IfxGpt12_Mode_timer);
    /* Set the Timer T3 direction   */
    IfxGpt12_T3_setTimerDirection(&MODULE_GPT120, IfxGpt12_TimerDirection_down);
    /* Set timer T3 input prescaler to divide the timer frequency */
    IfxGpt12_T3_setTimerPrescaler(&MODULE_GPT120, IfxGpt12_TimerInputPrescaler_32);

    /* Calculate dutyUpTime and dutyDownTime for reloading timer T3 */
    float32 moduleFreq = IfxGpt12_getModuleFrequency(&MODULE_GPT120);
    fTimer = (moduleFreq / (GPT1_BLOCK_PRESCALER * TIMER_T3_INPUT_PRESCALER));

    test_value = fTimer;

    uint16 dutyUpTime = (fTimer * (PWM_DUTY_CYCLE / 100.0f)) / PWM_FREQUENCY;
    uint16 dutyDownTime = (fTimer * (1 - (PWM_DUTY_CYCLE / 100.0f))) / PWM_FREQUENCY;

    /* Set timer T3 value */
    IfxGpt12_T3_setTimerValue(&MODULE_GPT120, dutyDownTime);

    /* Timer T2: reloads the value dutyDownTime in timer T3 */
    /* Set the timer T2 in reload mode */
    IfxGpt12_T2_setMode(&MODULE_GPT120, IfxGpt12_Mode_reload);
    /* Set the T2 input parameter: Negative transition (falling edge) of T3 toggle latch T3OTL */
    IfxGpt12_T2_setReloadInputMode(&MODULE_GPT120, IfxGpt12_ReloadInputMode_fallingEdgeTxOTL);
    /* Set timer T2 value (the value that is reloaded in T3 on negative transition) */
    IfxGpt12_T2_setTimerValue(&MODULE_GPT120, dutyDownTime);

    /* Timer T4: reloads the value dutyUpTime in timer T3 */
    /* Set timer T4 in reload mode */
    IfxGpt12_T4_setMode(&MODULE_GPT120, IfxGpt12_Mode_reload);
    /* Set the T4 input parameter: Positive transition (rising edge) of T3 toggle latch T3OTL */
    IfxGpt12_T4_setReloadInputMode(&MODULE_GPT120, IfxGpt12_ReloadInputMode_risingEdgeTxOTL);
    /* Set timer T4 value (the value that is reloaded in T3 on positive transition) */
    IfxGpt12_T4_setTimerValue(&MODULE_GPT120, dutyUpTime);

    /* Configure the GPT12 interrupt */
    volatile Ifx_SRC_SRCR *src = IfxGpt12_T3_getSrc(&MODULE_GPT120);            /* Get interrupt address            */
    IfxSrc_init(src, ISR_PROVIDER_GPT12_TIMER, ISR_PRIORITY_GPT12_TIMER);       /* Initialize the service request   */
    IfxSrc_enable(src);                                                         /* Enable GPT12 interrupt           */

    /* Initialize the LED */
    IfxPort_setPinModeOutput(LED, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
    IfxPort_setPinModeOutput(TEST_PIN1, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
}

/* Function to start the GPT12 timer */
void runGpt12PWM(void)
{
    IfxGpt12_T3_run(&MODULE_GPT120, IfxGpt12_TimerRun_start);                   /* Start the timer T3               */
}

void Set_GptPWM_Duty(uint8 pmw_duty)
{
    uint16 dutyUpTime   = (fTimer * (pmw_duty / 100.0f)) / PWM_FREQUENCY;
    uint16 dutyDownTime = (fTimer * (1 - (pmw_duty / 100.0f))) / PWM_FREQUENCY;
    IfxGpt12_T2_setTimerValue(&MODULE_GPT120, dutyDownTime);
    IfxGpt12_T4_setTimerValue(&MODULE_GPT120, dutyUpTime);
}
