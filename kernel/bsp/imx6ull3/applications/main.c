/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2020/10/7      bernard      the first version
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <rtthread.h>
// #include <tc_comm.h>
#define THREAD_STACK_SIZE    512
#define THREAD_TIMESLICE    5
#define THREAD_PRIORITY        6
#define THREAD_PRIORITY_1 1
#define THREAD_PRIORITY_2 2
void thread_entry1(void *parameter)
{
    while (1)
    {
        rt_kprintf("111Hello RT-Thread!\n");
        rt_thread_mdelay(1000); 
    }
}
void thread_entry2(void *parameter)
{
    while (1)
    {
        rt_kprintf("222Hello RT-Thread!\n");
        rt_thread_mdelay(1000); 
    }
}

int main(void)
{
    rt_thread_t tid1; // 线程控制块
    rt_thread_t tid2; // 线程控制块
    tid1 = rt_thread_create("print_thread1",  
                           thread_entry1,  
                           RT_NULL,        
                           THREAD_STACK_SIZE,
                           THREAD_PRIORITY,
                           THREAD_TIMESLICE);

      tid2 = rt_thread_create("print_thread2",  
                           thread_entry2,  
                           RT_NULL,        
                           THREAD_STACK_SIZE,
                           THREAD_PRIORITY,
                           THREAD_TIMESLICE);                        

    if (tid1 != RT_NULL)
    {
        rt_thread_startup(tid1); // 启动线程
    }
if (tid2 != RT_NULL)
    {
        rt_thread_startup(tid2); // 启动线程
    }
    return 0;
    rt_system_scheduler_init();
    rt_system_scheduler_start();
}

//single
// void thread_entry(void *parameter)
// {
//     while (1)
//     {
//         rt_kprintf("Hello RT-Thread!\n");
//         rt_thread_mdelay(1000); 
//     }
// }

// int main(void)
// {
//     rt_thread_t tid; // 线程控制块

//     tid = rt_thread_create("print_thread",  
//                            thread_entry,  
//                            RT_NULL,        
//                            THREAD_STACK_SIZE,
//                            THREAD_PRIORITY,
//                            THREAD_TIMESLICE);

//     if (tid != RT_NULL)
//     {
//         rt_thread_startup(tid); // 启动线程
//     }

//     return 0;
// }


//muti
// static struct rt_thread thread1;
// static struct rt_thread thread2;

// ALIGN(RT_ALIGN_SIZE)
// static rt_uint8_t thread1_stack[THREAD_STACK_SIZE];
// static rt_uint8_t thread2_stack[THREAD_STACK_SIZE];

// void thread_entry1(void *parameter)
// {
//     while (1)
//     {
//         rt_kprintf("Thread 1 is running\n");
//         rt_thread_mdelay(1000); 
//     }
// }

// void thread_entry2(void *parameter)
// {
//     while (1)
//     {
//         rt_kprintf("Thread 2 is running\n");
//         rt_thread_mdelay(1000); 
//     }
// }

// int _rt_application_init(void)
// {
//     rt_err_t result;

//     /* 初始化线程1 */
//     result = rt_thread_init(&thread1,
//                             "thread1",
//                             thread_entry1,
//                             RT_NULL,
//                             &thread1_stack[0],
//                             sizeof(thread1_stack),
//                             THREAD_PRIORITY_1,
//                             THREAD_TIMESLICE);
//     if (result == RT_EOK)
//     {
//         rt_thread_startup(&thread1);
//     }

//     /* 初始化线程2 */
//     result = rt_thread_init(&thread2,
//                             "thread2",
//                             thread_entry2,
//                             RT_NULL,
//                             &thread2_stack[0],
//                             sizeof(thread2_stack),
//                             THREAD_PRIORITY_2,
//                             THREAD_TIMESLICE);
//     if (result == RT_EOK)
//     {
//         rt_thread_startup(&thread2);
//     }

//     return 0;
// }

// int main(void)
// {   
//     rt_system_scheduler_init();
//     _rt_application_init();

    
//     rt_system_scheduler_start();

//     return 0;
// }
