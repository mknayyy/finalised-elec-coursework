#include "../lib/uopmsb/uop_msb_2_0_0.h"
using namespace uop_msb_200;

// You are to use these ojects to read the switch inputs
DigitalIn sw1(BTN1_PIN);
DigitalIn sw2(BTN2_PIN);


// You are to use this object to control the LEDs
BusOut leds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN);

int main()
{
    while (true)
    {
    // ***** MODIFY THE CODE BELOW HERE *****
    // For full marks, debounce the switches with suitable delays

    // 1. Wait for sw1 to be pressed and released


    if ((sw1 == 1) && (sw2 == 0)) {

        wait_us(50000);     //Debounce delay

    } 


    // 2. Wait for sw2 to be pressed and released


    else if ((sw1 == 0) && (sw2 == 1)) {

        wait_us(50000);     //Debounce delay

    }


    // 3. Wait for sw1 and sw2 to be pressed


    else if ((sw1 == 1) && (sw2 == 1)) {

        wait_us(50000);     //Debounce delay

    }


    // 4. Wait for either sw1 or sw2 to be released


    else if ((sw1 == 0) || (sw2 == 0)) {

        wait_us(50000);     //Debounce delay

    }


    // 5. Turn on all LEDs
    // 6. Wait for 1s
    // 7. Turn off all LEDs

    //^^^THE ABOVE ARE ALL ANSWERED WITH THE CODE BELOW^^^


    if ((sw1 == 0) && (sw2 == 0)) {
        
        wait_us(50000);     //Debounce delay
        leds = 0b111;
        wait_us(1000000);
        leds = 0b000;
    
    }


    // ***** MODIFY THE CODE ABOVE HERE *****
    }
}


