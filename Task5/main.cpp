#include "../lib/uopmsb/uop_msb_2_0_0.h"
using namespace uop_msb_200;

// You are to use these ojects to read the switch inputs
DigitalIn SW1(USER_BUTTON);
DigitalIn SW2(BTN1_PIN);
DigitalIn SW3(BTN2_PIN);
DigitalInOut SW4(BTN3_PIN,PIN_INPUT,PullDown,0);
DigitalInOut SW5(BTN4_PIN,PIN_INPUT,PullDown,0);

// You are to use this object to control the LEDs
BusOut leds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN);

//Use this to sound an error
Buzzer alarm;

void flashlights ();        //Initialised function. The function itself is seen at the bottom of the code

int main()
{
    while (true)
    {
        leds = 0;

        //Beep
        alarm.playTone("A", uop_msb_200::Buzzer::HIGHER_OCTAVE);
        wait_us(250000);
        alarm.rest();

        //Wait for the blue button
        while (SW1==0);

        
        // For full marks, debounce the switches with suitable delays

        // This is a "combination lock" activity. Write some code to detect the following sequence of press-and-release inputs
        // SW2, SW5, SW5, SW2, SW3
        // If the full sequence is entered, correctly, the green LED should flash 3 times
        // If a sequence of 5 switch inputs is entered incorrectly, the red LED should light and the buzzer should sound for 5 seconds
        // For full marks, use flow control structures and arrays to avoid deep nesting of code

        // ***** MODIFY THE CODE BELOW HERE *****


        int correctCombination[5] = {2, 5, 5, 2, 3};        //Array of correct numbers, to be compared to with the userInput array.
        int userInput[5] = {};      //User registered button presses to be stored in this array.

        enum states {NOT_PRESSED = 0, PRESSED, DEBOUNCED, BUTTON_RELEASED};     //Simple way to give names to integer values, used in the cases below.

        int pressCount = 0;     //Simply increments the number of button presses that have occured.
        int buttonState = NOT_PRESSED;      //The buttonState to determine the case that the switch function will go to.
        int currentButton = 0;      //Determines what button (A, B, C or D) is pressed. Explained further down.
        
        while (1) {     //Constant checking for switch cases

            switch (buttonState) {      //The buttonState will determine what case the code will run, and the cases affect the button state if certain criteria are met.

                case NOT_PRESSED:       //The button isn't pressed.

                    if ((SW2) || (SW3) || (SW4) || (SW5)) {     //If buttons A, B, C or D are == 1, the buttonState is changed to PRESSED.

                        buttonState = PRESSED;

                    } else {        //The default 'standby' part of the code will run here. As no buttons are pressed, the code loops to NOT_PRESSED case.

                        buttonState = NOT_PRESSED;
                        
                    }       //End of case NOT_PRESSED: 'if' statement.

                    break;

                case PRESSED:       //The previous 'if' statement detects an input, and switches the case through buttonState.
                    
                    wait_us(10000);     //Debounce delay.

                    if ((SW2) || (SW3) || (SW4) || (SW5)) {     //If buttons A, B, C or D are == 1, the buttonState is changed to DEBOUNCED.

                        buttonState = DEBOUNCED;

                    } else {        //If the PRESSED case occured from 'static' and the buttons are off, the case will reset to NOT_PRESSED.

                        buttonState = NOT_PRESSED;
                        
                    }       //End of case PRESSED: 'if' statement.

                    break;

                case DEBOUNCED:     //If the button press in both NOT_PRESSED and PRESSED case are determined to be true, this case will run.

                    if (SW2) {      //If statement to determine the button pressed.

                        currentButton = 2;      //SW2 == 2 == A.

                    } else if (SW3) {

                        currentButton = 3;      //SW3 == 3 == B.
                        
                    } else if (SW4) {

                        currentButton = 4;      //SW4 == 4 == C.

                    } else if (SW5) {

                        currentButton = 5;      //SW5 == 5 == D.

                    } else {

                        buttonState = BUTTON_RELEASED;      //Switches case to BUTTON_RELEASED.

                    }       //End of case DEBOUNCED: 'if' statement.

                    break;

                case BUTTON_RELEASED:       //Case to determine the result of the end of the button press.

                    wait_us(10000);     //Debounce delay

                    if (!(SW2 || SW3 || SW4 || SW5)) {      //Testing if buttons are still released after wait.

                        userInput[pressCount] = currentButton;      //Inputs values for the second array, equal to currentButton (the button pressed).
                        
                        pressCount++;       //Increments pressCount so that another value in the input array can be put.

                        buttonState = NOT_PRESSED;      //Resets the code to look for another button press.

                    } else {

                        buttonState = DEBOUNCED;        //Debounce failsafe to ensure that 'static' didn't cause the BUTTON_RELEASED case to activate. If it did, this would run and send you back to the DEBOUNCED case.

                    }       //End of 'if' statement.
                    
                    if (pressCount >= 5) {      //If statement to determine the cuttoff for the number of inputs (pressCounts). Greater than is used here as a failsafe.

                        bool correctInput = true;       //Simple bool expression to be used below. True for correct code entered, false for incorrect code entered.

                        for (int arrayIndex = 0; arrayIndex < 5; arrayIndex++) {        //Increments from 0 to 4, in order to test the values of the array below.

                            if (userInput[arrayIndex] == correctCombination[arrayIndex]) {      //Sets the bool expression to 'true' (1) if equal to the first combination array.

                                correctInput = true;

                            } else {        //If the 2 arrays dont equal each other, this will run and set the bool to 'false'.

                                correctInput = false;
                                
                                break;      //Breaks out of loop when combination doesn't match.

                            }       //End of 'if' statement.

                        }       //End of 'for' loop.

                        if (correctInput) {     //Checks if the bool expression is true

                        flashlights();      //Void loop 'flashlights' is to run (seen below, and initialised at the top of the code).

                        } else {        //If the bool is anything other than 'true' (false), then this code will run.

                            alarm.playTone("A", uop_msb_200::Buzzer::HIGHER_OCTAVE);        //The alarm will turn on, at note 'A'.
                            wait_us(5000000);       //3 second delay.
                            alarm.rest();       //Alarm will rest (stop).

                        }       //End of 'if' statement.

                        pressCount = 0;     //Resets the pressCount
                        currentButton = 0;      //Resets the currentButton

                        //The above resets allow for the code to run indefinitely as long as you wait for either the green LEDS to stop flashing, or to wait until the buzzer stops. Then another attempt can occur.

                    }       //End of the pressCount >=5 'if' statement.

                    break;

            }       //End of the switch (buttonState) function.

        }       //End of the while (1) loop.


        // ***** MODIFY THE CODE ABOVE HERE *****
    }

}

void flashlights () {       //Void function used to make the previous code easier to read.

    for (int flashCount = 0; flashCount < 6; flashCount++) {        //Increments on and off function of the LED 6 times (3 on phases) before turning off.

        leds[2] = !leds[2];     //Toggles the LED from off to on and vice versa.
        wait_us(250000);        //Waits for 0.25 seconds.

    }       //End of the 'for' loop

}       //End of the 'flashlights' function.
