#include "../lib/uopmsb/uop_msb_2_0_0.h"
using namespace uop_msb_200;

BusOut leds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN);

int main()
{
    leds = 0;
    // ***** MODIFY THE CODE BELOW HERE *****

    // 1. Write a for-loop to count from 5 to 100 in steps of 5 - print the results to the serial terminal


    for (int i = 5; i < 105; i = i + 5) {

        printf("i = %d\n\n", i);

    }


    // 2. Write a for-loop to count from 100 down to 10 in steps of 10 - print the results to the serial terminal


    for (int x = 100; x > 0; x = x - 10 ) {

        printf("x = %d\n\n", x);

    }


    // 3. Write some code to demonstrate nested for-loops (one loop within another)


    //First nest
    
    for (int y = 0; y < 11; y++) {

        printf("This is the first instance of a nested loop: y=%d\n\n", y); 


        //Second nest
        
        for (int z = 10; z > 0; z--) {

            printf("This is the (nested) second instance of a nested loop: z=%d\n\n", z); 

        }

    }


    // ***** MODIFY THE CODE ABOVE HERE *****
    leds = 7;

    while (true) {

    }
}

