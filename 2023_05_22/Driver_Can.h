#ifndef DRIVER_CAN
#define DRIVER_CAN

/***********************************************************************/
/*Include*/ 
/***********************************************************************/
#include "Ifx_Types.h"
#include "IfxCpu.h"
#include "IfxMultican_Can.h"
#include "IfxPort.h"
#include "Bsp.h"


/***********************************************************************/
/*Define*/ 
/***********************************************************************/

#define STB         &MODULE_P20,6                               //STB Pin Settings (Set LOW to Run)

#define TX_INTERRUPT_SRC_ID         IfxMultican_SrcId_0         /* Transmit interrupt service request ID             */
#define ISR_PRIORITY_CAN_TX         2                           /* Define the CAN TX interrupt priority              */
#define PIN5                        5                           /* LED1 used in TX ISR is connected to this pin      */
#define PIN6                        6                           /* LED2 used in RX ISR is connected to this pin      */


#define WAIT_TIME_1ms               1                           // Wait 1 milliseconds
#define WAIT_TIME_5ms               5                           // Wait 5 milliseconds
#define WAIT_TIME_10ms              10                          // Wait 10 milliseconds
#define WAIT_TIME_20ms              20                          // Wait 20 milliseconds
#define WAIT_TIME_50ms              50                          // Wait 50 milliseconds
#define WAIT_TIME_100ms             100                         // Wait 100 milliseconds

#define LED1         &MODULE_P00,5                              //LED1 Settings
#define LED2         &MODULE_P00,6                              //LED2 Settings
/***********************************************************************/
/*Typedef*/ 
/***********************************************************************/
typedef struct
{
    struct
    {
        IfxMultican_Can        can;          /**< \brief CAN driver handle */
        IfxMultican_Can_Node   canSrcNode;   /**< \brief CAN Source Node */
        IfxMultican_Can_MsgObj canSrcMsgObj; /**< \brief CAN Source Message object */
    }drivers;
} App_MulticanBasic;


typedef struct
{
    unsigned long ID;                      // CAN Message ID
    unsigned char IDE;                     // CAN Message IDE
    unsigned char DLC;                     // CAN Data Length
    unsigned char Data[8];                 // CAN Data
} CanRxMsg;

typedef struct
{
    IfxPort_Pin_Config              led1;                  /* LED1 configuration structure                           */
    IfxPort_Pin_Config              led2;                  /* LED2 configuration structure                           */
} AppLedType;


/***********************************************************************/
/*External Variable*/ 
/***********************************************************************/
IFX_EXTERN App_MulticanBasic g_MulticanBasic;


/***********************************************************************/
/*Global Function Prototype*/ 
/***********************************************************************/
extern void Driver_Can_Init(void);                         // Driver_Can_Init function
extern void Driver_Can_TxTest(void);                       // Driver_Can_TxTest function
extern void CAN_send(CanRxMsg *message);                   // CAN_send function
extern void CAN_TEST(void);                                // CAN_TEST function
void initLed(void);                                        // initLed function
void blinkLED1(void);                                      // blinkLED1 function
void blinkLED2(void);                                      // blinkLED2 function
#endif /* DRIVER_STM */
