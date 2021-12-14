/*
*********************************************************************************************************
*                                            EXAMPLE CODE
*
*               This file is provided as an example on how to use Micrium products.
*
*               Please feel free to use any application code labeled as 'EXAMPLE CODE' in
*               your application products.  Example code may be used as is, in whole or in
*               part, or may be used as a reference only. This file can be modified as
*               required to meet the end-product requirements.
*
*               Please help us continue to provide the Embedded community with the finest
*               software available.  Your honesty is greatly appreciated.
*
*               You can find our product's user manual, API reference, release notes and
*               more information at https://doc.micrium.com.
*               You can contact us at www.micrium.com.
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*
*                                              uC/OS-II
*                                            EXAMPLE CODE
*
* Filename : main.c
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                            INCLUDE FILES
*********************************************************************************************************
*/

#include    <stdio.h>
#include    <string.h>
#include    <ctype.h>
#include    <stdlib.h>
#include    <app_cfg.h>
#include    <ucos_ii.h>
#include <lib_def.h>

/*
*********************************************************************************************************
*                                            LOCAL DEFINES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                   VARIABLES and CONSTANTS
*********************************************************************************************************
*/

#define  TASK_STK_SIZE    128
#define  TASK_START_PRIO    5
#define  COMPTIME_1    (INT16U)1 
#define  DEADLINE_1    (INT16U)4 
#define  COMPTIME_2    (INT16U)2
#define  DEADLINE_2    (INT16U)5
#define  COMPTIME_3    (INT16U)2
#define  DEADLINE_3    (INT16U)10
#define  DATA_SHARE    1  /*是否运行在共享数据模式*/

OS_STK        AppStartTaskStk[TASK_STK_SIZE];
OS_STK		  MyTaskStks[3][TASK_STK_SIZE];
static OS_EVENT* sem;


/*
*********************************************************************************************************
*                                         FUNCTION PROTOTYPES
*********************************************************************************************************
*/


void Task1(void* p_arg);
void Task2(void* p_arg);
void Task3(void* p_arg);


/*
*********************************************************************************************************
*                                                main()
*
* Description : This is the standard entry point for C code.  It is assumed that your code will call
*               main() once you have performed all necessary initialization.
*
* Arguments   : none
*
* Returns     : none
*
* Notes       : none
*********************************************************************************************************
*/

int  main (void)
{
#if OS_TASK_NAME_EN > 0u
    CPU_INT08U  os_err;
#endif


    CPU_IntInit();

    //Mem_Init();                                                 /* Initialize Memory Managment Module                   */
    CPU_IntDis();                                               /* Disable all Interrupts                               */
   // CPU_Init();                                                 /* Initialize the uC/CPU services                       */

    OSInit();                                                   /* Initialize uC/OS-II                                  */

    MyOSTaskCreate(Task1, (void*)0, (OS_STK*)&MyTaskStks[0][TASK_STK_SIZE - 1], 1, COMPTIME_1,DEADLINE_1);
    MyOSTaskCreate(Task2, (void*)0, (OS_STK*)&MyTaskStks[1][TASK_STK_SIZE - 1], 2, COMPTIME_2, DEADLINE_2);
    MyOSTaskCreate(Task3, (void*)0, (OS_STK*)&MyTaskStks[2][TASK_STK_SIZE - 1], 3, COMPTIME_3, DEADLINE_3);


#if OS_TASK_NAME_EN > 0u
    OSTaskNameSet(         APP_CFG_STARTUP_TASK_PRIO,
                  (INT8U *)"Startup Task",
                           &os_err);
#endif

    OSStart();                                                  /* Start multitasking (i.e. give control to uC/OS-II)   */

    while (DEF_ON) {                                            /* Should Never Get Here.                               */
        ;
    }
}


/*
*********************************************************************************************************
*                                            STARTUP TASK
*
* Description : This is an example of a startup task.  As mentioned in the book's text, you MUST
*               initialize the ticker only once multitasking has started.
*
* Arguments   : p_arg   is the argument passed to 'StartupTask()' by 'OSTaskCreate()'.
*
* Returns     : none
*
* Notes       : 1) The first line of code is used to prevent a compiler warning because 'p_arg' is not
*                  used.  The compiler should not generate any code for this statement.
*********************************************************************************************************
*/

void Task1(void* p_arg) {
    int start = 0;
    int end;
    int toDelay;

    while (1) {
        while (OSTCBCur->CompTime > 0) {

        }
        end = OSTimeGet();
        toDelay = DEADLINE_1 - (end - start);
        start += DEADLINE_1;
        OSTCBCur->CompTime = COMPTIME_1;
        OSTimeDly(toDelay);
    }
    
}

void Task2(void* p_arg) {
    int start = 0;
    int end;
    int toDelay;

    while (1) {





        while (OSTCBCur->CompTime > 0) {

        }
        end = OSTimeGet();
        toDelay = DEADLINE_2 - (end - start);
        start += DEADLINE_2;
        OSTCBCur->CompTime = COMPTIME_2;
        OSTimeDly(toDelay);
    }

}

void Task3(void* p_arg) {
    int start = 0;
    int end;
    int toDelay;

    while (1) {





        while (OSTCBCur->CompTime > 0) {

        }
        end = OSTimeGet();
        toDelay = DEADLINE_3 - (end - start);
        start += DEADLINE_3;
        OSTCBCur->CompTime = COMPTIME_3;
        OSTimeDly(toDelay);
    }

}

