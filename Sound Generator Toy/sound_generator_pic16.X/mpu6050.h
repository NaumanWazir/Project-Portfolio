/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef _MPU6050_H    /* Guard against multiple inclusion */
#define _MPU6050_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */
#include "i2c.h"
#include<stdint.h>
/* This section lists the other files that are included in this file.
 */

/* TODO:  Include other files here if needed. */


/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif


    /* ************************************************************************** */
    /* ************************************************************************** */
    /* Section: Constants                                                         */
    /* ************************************************************************** */
    /* ************************************************************************** */

    /*  A brief description of a section can be given directly below the section
        banner.
     */


    /* ************************************************************************** */
    /** Descriptive Constant Name

      @Summary
        Brief one-line summary of the constant.
    
      @Description
        Full description, explaining the purpose and usage of the constant.
        <p>
        Additional description in consecutive paragraphs separated by HTML 
        paragraph breaks, as necessary.
        <p>
        Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.
    
      @Remarks
        Any additional remarks
     */
#define EXAMPLE_CONSTANT 0
#define MPU6050_ADDRESS 0x68
#define MPU6050_ID 0x68
#define CONFIG 0x1A //--> 0x00
#define GYRO_CONFIG 0x1B //--> 0x00, 250dps
#define ACCEL_CONFIG 0x1C// --> 0x00,2g
#define FIFO_EN 0x23//--> 0x00, keep fifo dsbld
#define I2C_MST_CTRL 0x24// --> 0x00, keep aux i2c dsbld
#define INT_PIN_CFG 0x37// --> 0x10, any read clears interrupts
#define INT_ENABLE 0x38// --> 0x00 all intrpts dsbld
#define INT_STATUS 0x3A// --> intrpts status, read to clear intrpts
#define USER_CTRL 0x6A// --> 0x00 user control reg, 
#define PWR_MGMT_1 0x6B //--> 0x00
#define PWR_MGMT_2 0x6c// --> 0x00
#define WHO_AM_I 0x75// --> should always return 0x68 when read
//ODR defined by register (25)d, use burst reads
#define X_AXIS 0
#define Y_AXIS 1
#define Z_AXIS 2
#define ax_x_H 0x3B
#define ax_x_L 0x3C

#define ax_y_H 0x3D
#define ax_y_L 0x3E

#define ax_z_H 0x3F
#define ax_z_L 0x40

#define temp_H 0x41
#define temp_L 0x42

#define gs_x_H 0x43
#define gx_x_L 0x44

#define gs_y_H 0x45
#define gx_y_L 0x46

#define gs_z_H 0x47
#define gx_z_L 0x48

    // *****************************************************************************
    // *****************************************************************************
    // Section: Data Types
    // *****************************************************************************
    // *****************************************************************************

    /*  A brief description of a section can be given directly below the section
        banner.
     */


    // *****************************************************************************

    /** Descriptive Data Type Name

      @Summary
        Brief one-line summary of the data type.
    
      @Description
        Full description, explaining the purpose and usage of the data type.
        <p>
        Additional description in consecutive paragraphs separated by HTML 
        paragraph breaks, as necessary.
        <p>
        Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.

      @Remarks
        Any additional remarks
        <p>
        Describe enumeration elements and structure and union members above each 
        element or member.
     */
    typedef struct _example_struct_t {
        /* Describe structure member. */
        int some_number;

        /* Describe structure member. */
        bool some_flag;

    } example_struct_t;


    // *****************************************************************************
    // *****************************************************************************
    // Section: Interface Functions
    // *****************************************************************************
    // *****************************************************************************

    /*  A brief description of a section can be given directly below the section
        banner.
     */

    // *****************************************************************************
    /**
      @Function
        int ExampleFunctionName ( int param1, int param2 ) 

      @Summary
        Brief one-line description of the function.

      @Description
        Full description, explaining the purpose and usage of the function.
        <p>
        Additional description in consecutive paragraphs separated by HTML 
        paragraph breaks, as necessary.
        <p>
        Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.

      @Precondition
        List and describe any required preconditions. If there are no preconditions,
        enter "None."

      @Parameters
        @param param1 Describe the first parameter to the function.
    
        @param param2 Describe the second parameter to the function.

      @Returns
        List (if feasible) and describe the return values of the function.
        <ul>
          <li>1   Indicates an error occurred
          <li>0   Indicates an error did not occur
        </ul>

      @Remarks
        Describe any special behavior not described above.
        <p>
        Any additional remarks.

      @Example
        @code
        if(ExampleFunctionName(1, 2) == 0)
        {
            return 3;
        }
     */

    int ExampleFunction(int param1, int param2);
    bool mpu6050_init(void);
    uint8_t mpu6050_get_id(void);
    float get_mpu_temperature(void);
    bool mpu_write_reg(uint8_t, uint8_t);
    bool mpu_write_reg(uint8_t, uint8_t);
    bool mpu_read_single_reg(uint8_t, uint8_t *);
    uint16_t mpu_read_multi_reg(uint8_t, uint8_t *, uint8_t);
    int16_t mpu_get_acceleration(uint8_t);
    int16_t mpu_get_rotation(uint8_t);
    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
