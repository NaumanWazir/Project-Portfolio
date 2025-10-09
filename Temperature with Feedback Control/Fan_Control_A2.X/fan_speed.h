/* 
 * File:   fan_speed.h
 * Author: yangxiao
 *
 * Created on September 22, 2021, 7:25 AM
 */

#ifndef FAN_SPEED_H
#define	FAN_SPEED_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "mcc_generated_files/ccp1.h"
#include "stdlib.h"

void cal_speed(uint16_t capture);

#ifdef	__cplusplus
}
#endif

#endif	/* FAN_SPEED_H */

