
#ifndef SOUND_H    /* Guard against multiple inclusion */
#define SOUND_H

#include<stdint.h>

/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif

    
struct sound {
    int16_t current_freq;
    int16_t freq_step;
    int16_t max_freq;
    int16_t min_freq;
};

void set_frequency(uint16_t);
uint8_t mpu_read_motion(void);
void sound_init(void);
void sine_wave(uint8_t);
void sine_wave2(uint16_t);
    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */
