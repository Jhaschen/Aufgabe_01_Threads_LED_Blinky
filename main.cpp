/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include <cstdint>


// Blinking rate in milliseconds
#define BLINKING_RATE     200ms




void led2_thread()
{
    
    DigitalOut led2(D2);
    while (true) {
        led2 = !led2;
        ThisThread::sleep_for(250ms);
    }
  
  
  
  }
void led3_thread()
{
   
    DigitalOut led3(D3);
    while (true) {
        led3 = !led3;
        ThisThread::sleep_for(1000ms);
    }
    
}



int main()
{
    // Initialise the digital pin LED1 as an output
    DigitalOut led1(LED1);

    Thread thread_led2(osPriorityNormal,OS_STACK_SIZE,NULL,"LED2_THREAD");
    Thread thread_led3(osPriorityNormal,OS_STACK_SIZE,NULL,"LED3_THREAD");
    thread_led2.start(led2_thread);
    thread_led3.start(led3_thread);




    while (true) {
        led1 = !led1;
        
        ThisThread::sleep_for(BLINKING_RATE);

        
    }
}
