/*
 * File:   external_switch.c
 * Author: Shahzad Anwar Khan
 *
 * Created on February 4, 2024, 7:18 PM
 */


#include "external_switch.h"
#include<stdio.h>
//#include<stdbool.h>
bool switch_pressed = false;

void switch_press_handler(void) {
    printf("4.custom interrpt handler called \n\r");
    switch_pressed = true;
}
/*
 The below function is used to read if switch was pressed since the last call
 * to this function. The call to this function resets the switch status.
 */

bool check_if_switch_pressed(void) {
    // read the switch status recorded so far
    bool resp = switch_pressed;
    // reset the switch satus once we read it
    switch_pressed = false;
    // return the switch status
    return resp;
}