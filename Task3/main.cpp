#include "../lib/uopmsb/uop_msb_2_0_0.h"
using namespace uop_msb_200;

// You are to use this object to control the LEDs
BusOut leds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN);

int main()
{

    // ***** MODIFY THE CODE BELOW HERE *****

    //1. Turn only the yellow LED ON


    leds[1] = 1;


    //2. Pause for 1s


    wait_us(1000000);


    //3. Turn only the red LED ON


    leds[0] = 1;
    leds[1] = 0;


    //4. Pause for 1s


    wait_us(1000000);


    //5. Turn only the green LED ON


    leds = 0;
    leds[2] = 1;


    //6. Pause for 1s


    wait_us(1000000);


    //7. Using a while-loop, flash the yellow LED on and off 5 times. Each flash should last 0.25s. 


    int t_0 = 0;

    while (t_0 < 10) {      //10 is used as each iteration of the while loop turns it off/on, whereas a flash is usually defined as a pair of off and on.

        leds[1] = !leds[1];
        wait_us(250000);
        t_0++;

    }


    //8. Using a do-while-loop, flash the green LED on and off 5 times. Each flash should last 0.25s. 


    int t_1 = 0;

    do {

        leds[2] = !leds[2];
        wait_us(250000);
        t_1++;

    } while (t_1 < 11);     //As the code never asked for the green led to be turned off, it's on by default. as a result, 11 is used in order to make it off at the final phase.


    //9. Using a for-loop, flash the red LED on and off 5 times. Each flash should last 0.25s. 


    for (int t_2 = 0; t_2 < 10; t_2++) {

        leds[0] = !leds[0];
        wait_us(250000);

    }


    //10. Turn off all the LEDs


    leds = 0;       //This is uneccesary, as the code is developed to have this be the default, however i've included it for completionist sake.


    // ***** MODIFY THE CODE ABOVE HERE *****

    while (true) {

    }
}


