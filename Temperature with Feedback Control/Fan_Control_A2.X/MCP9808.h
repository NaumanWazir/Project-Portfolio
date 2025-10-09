/* 
 * File:   MCP9808.h
 * Author: yangxiao
 *
 * Created on September 18, 2021, 2:20 PM
 */

#ifndef MCP9808_H
#define	MCP9808_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "iic1_master.h"
#include "mssp1_host.h"

    
  //  extern uint8_t temp_data[2];
    
    
    void MCP9808_init(void);
    void Read_temp_MCP(void);
    float cal_temp(void);

#ifdef	__cplusplus
}
#endif

#endif	/* MCP9808_H */

