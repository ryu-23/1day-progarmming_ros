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

#define STB                         &MODULE_P20,6

#define TX_INTERRUPT_SRC_ID         IfxMultican_SrcId_0         /* Transmit interrupt service request ID             */
#define ISR_PRIORITY_CAN_TX         2                           /* Define the CAN TX interrupt priority              */

#define RX_INTERRUPT_SRC_ID         IfxMultican_SrcId_1         /* Receive interrupt service request ID              */
#define ISR_PRIORITY_CAN_RX         1                           /* Define the CAN RX interrupt priority              */

#define PIN5                        5                           /* LED1 used in TX ISR is connected to this pin      */
#define PIN6                        6                           /* LED2 used in RX ISR is connected to this pin      */


#define WAIT_TIME_1ms               1
#define WAIT_TIME_5ms               5
#define WAIT_TIME_10ms              10
#define WAIT_TIME_20ms              20
#define WAIT_TIME_50ms              50
#define WAIT_TIME_100ms             100

#define LED1                        &MODULE_P00,5
#define LED2                        &MODULE_P00,6
#define INT_RX_OUT                  &MODULE_P00,7

/***********************************************************************/
/*Typedef*/ 
/***********************************************************************/
typedef struct
{
    struct
    {

        IfxMultican_Can                 can;                   /* CAN module handle to HW module SFR set                 */
        IfxMultican_Can_Config          canConfig;             /* CAN module configuration structure                     */
        IfxMultican_Can_Node            canSrcNode;            /* CAN source node handle data structure                  */
        IfxMultican_Can_Node            canDstNode;            /* CAN destination node handle data structure             */
        IfxMultican_Can_NodeConfig      canNodeConfig;         /* CAN node configuration structure                       */
        IfxMultican_Can_MsgObj          canSrcMsgObj;          /* CAN source message object handle data structure        */
        IfxMultican_Can_MsgObj          canDstMsgObj;          /* CAN destination message object handle data structure   */
        IfxMultican_Can_MsgObjConfig    canMsgObjConfig;       /* CAN message object configuration structure             */
        IfxMultican_Message             txMsg;                 /* Transmitted CAN message structure                      */
        IfxMultican_Message             rxMsg;                 /* Received CAN message structure                         */

    }drivers;
} App_MulticanBasic;

typedef struct
{
    unsigned long ID;
    unsigned char IDE;
    unsigned char DLC;
    unsigned char Data[8];
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
extern void Driver_Can_Init(void);
extern void Driver_Can_TxTest(void);
extern void CAN_send(CanRxMsg *message);
extern void CAN_TEST(void);

void canIsrTxHandler(void);
void canIsrRxHandler(void);


void initLed(void);
void blinkLED1(void);
void blinkLED2(void);
#endif /* DRIVER_STM */
