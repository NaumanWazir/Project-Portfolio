
#include "mpu6050.h"
#include<stdio.h>

uint8_t buffer_2_byte[2];

bool mpu6050_init() {
    mpu_write_reg(CONFIG, 0x00);
    mpu_write_reg(GYRO_CONFIG, 0x00);
    mpu_write_reg(ACCEL_CONFIG, 0x00);
    mpu_write_reg(FIFO_EN, 0x00);
    mpu_write_reg(I2C_MST_CTRL, 0x00);
    mpu_write_reg(INT_PIN_CFG, 0x10);
    mpu_write_reg(INT_ENABLE, 0x00);
    mpu_write_reg(USER_CTRL, 0x00);
    mpu_write_reg(PWR_MGMT_1, 0x00);
    mpu_write_reg(PWR_MGMT_2, 0x00);
    uint8_t id = 0;
    bool resp = false;
    if (mpu_read_single_reg(WHO_AM_I, &id)) {
        if (id == MPU6050_ID) {
            resp = true;
            printf("+++ mpu6050 detected +++\n\r");
        } else {
            printf("!!! mpu6050 not detected !!!\n\r");
        }
    } else {
        printf("+++ i2c failed during init +++\n\r");
    }
    return resp;
}

uint8_t mpu6050_get_id() {
    uint8_t id = 0;
    mpu_read_single_reg(WHO_AM_I, &id);
    return id;
}

float get_mpu_temperature() {
    uint8_t temp_H_byte = 0;
    uint8_t temp_L_byte = 0;
    mpu_read_single_reg(temp_H, &temp_H_byte);
    mpu_read_single_reg(temp_L, &temp_L_byte);
    int16_t raw_value = (temp_H_byte << 8) | temp_L_byte;
    //temp_out= 16_bit_sgnd_value/340 + 36.53
    float temp = (raw_value / 340.0) + 36.53;
    return temp;
}

int16_t mpu_get_acceleration(uint8_t axis) {
    uint8_t start_add = ax_x_H;
    switch (axis) {
        case X_AXIS:
        {
            start_add = ax_x_H;
            break;
        }
        case Y_AXIS:
        {
            start_add = ax_y_H;
            break;
        }
        case Z_AXIS:
        {
            start_add = ax_z_H;
            break;
        }
        default:
        {
            start_add = ax_x_H;
        }
    }
    mpu_read_multi_reg(start_add, buffer_2_byte, 2);
    int16_t acc = (buffer_2_byte[0] << 8) | buffer_2_byte[1];
    return acc;
}

int16_t mpu_get_rotation(uint8_t axis) {
    uint8_t start_add = gs_x_H;
    switch (axis) {
        case X_AXIS:
        {
            start_add = gs_x_H;
            break;
        }
        case Y_AXIS:
        {
            start_add = gs_y_H;
            break;
        }
        case Z_AXIS:
        {
            start_add = gs_z_H;
            break;
        }
        default:
        {
            start_add = gs_x_H;
        }
    }
    mpu_read_multi_reg(start_add, buffer_2_byte, 2);
    int16_t rot = (buffer_2_byte[0] << 8) | buffer_2_byte[1];
    return rot;
}

bool mpu_write_reg(uint8_t reg_to_write, uint8_t data) {
    uint8_t buffer[] = {reg_to_write, data};
    uint16_t count = I2C_Multi_Write(MPU6050_ADDRESS, buffer, 2);
    if (count == 2) {
        return true;
    } else {
        return false;
    }
}

bool mpu_read_single_reg(uint8_t reg_to_read, uint8_t *data) {
    bool resp = false;
    resp = I2C_Single_Write(MPU6050_ADDRESS, reg_to_read);
    *data = I2C_Single_Read(MPU6050_ADDRESS);
    //    printf("single value register 0x%x read: 0x%x \n\r", reg_to_read, *data);
    return resp;
}

uint16_t mpu_read_multi_reg(uint8_t start_address, uint8_t *data, uint8_t len) {
    if (I2C_Single_Write(MPU6050_ADDRESS, start_address)) {
        uint16_t count = 0;
        count = I2C_Multi_Read(MPU6050_ADDRESS, data, len);
        return count;
    } else {
        return 0;
    }
}

/* *****************************************************************************
 End of File
 */
