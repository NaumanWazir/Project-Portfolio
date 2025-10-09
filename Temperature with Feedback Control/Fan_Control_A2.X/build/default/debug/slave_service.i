# 1 "slave_service.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Program Files/Microchip/MPLABX/v5.45/packs/Microchip/PIC16F1xxxx_DFP/1.5.133/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "slave_service.c" 2
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\stdint.h" 1 3



# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\musl_xc8.h" 1 3
# 4 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\stdint.h" 2 3
# 22 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\stdint.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\bits/alltypes.h" 1 3
# 127 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned long uintptr_t;
# 142 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long intptr_t;
# 158 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\bits/alltypes.h" 3
typedef signed char int8_t;




typedef short int16_t;




typedef __int24 int24_t;




typedef long int32_t;





typedef long long int64_t;
# 188 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long long intmax_t;





typedef unsigned char uint8_t;




typedef unsigned short uint16_t;




typedef __uint24 uint24_t;




typedef unsigned long uint32_t;





typedef unsigned long long uint64_t;
# 229 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned long long uintmax_t;
# 22 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\stdint.h" 2 3


typedef int8_t int_fast8_t;

typedef int64_t int_fast64_t;


typedef int8_t int_least8_t;
typedef int16_t int_least16_t;

typedef int24_t int_least24_t;
typedef int24_t int_fast24_t;

typedef int32_t int_least32_t;

typedef int64_t int_least64_t;


typedef uint8_t uint_fast8_t;

typedef uint64_t uint_fast64_t;


typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;

typedef uint24_t uint_least24_t;
typedef uint24_t uint_fast24_t;

typedef uint32_t uint_least32_t;

typedef uint64_t uint_least64_t;
# 144 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\stdint.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\bits/stdint.h" 1 3
typedef int16_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef uint16_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
# 144 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\stdint.h" 2 3
# 1 "slave_service.c" 2

# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\stdbool.h" 1 3
# 2 "slave_service.c" 2


# 1 "./slave_service.h" 1
# 46 "./slave_service.h"
void update_slave_reg(void);
void update_offset_n_offFan_value(void);
# 4 "slave_service.c" 2

# 1 "./pid.h" 1
# 18 "./pid.h"
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\stdlib.h" 1 3
# 10 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\stdlib.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\features.h" 1 3
# 10 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\stdlib.h" 2 3
# 21 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\stdlib.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\bits/alltypes.h" 1 3
# 18 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long int wchar_t;
# 122 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned size_t;
# 21 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\stdlib.h" 2 3


int atoi (const char *);
long atol (const char *);
long long atoll (const char *);
double atof (const char *);

float strtof (const char *restrict, char **restrict);
double strtod (const char *restrict, char **restrict);
long double strtold (const char *restrict, char **restrict);



long strtol (const char *restrict, char **restrict, int);
unsigned long strtoul (const char *restrict, char **restrict, int);
long long strtoll (const char *restrict, char **restrict, int);
unsigned long long strtoull (const char *restrict, char **restrict, int);

int rand (void);
void srand (unsigned);

          void abort (void);
int atexit (void (*) (void));
          void exit (int);
          void _Exit (int);

void *bsearch (const void *, const void *, size_t, size_t, int (*)(const void *, const void *));

__attribute__((nonreentrant)) void qsort (void *, size_t, size_t, int (*)(const void *, const void *));

int abs (int);
long labs (long);
long long llabs (long long);

typedef struct { int quot, rem; } div_t;
typedef struct { long quot, rem; } ldiv_t;
typedef struct { long long quot, rem; } lldiv_t;

div_t div (int, int);
ldiv_t ldiv (long, long);
lldiv_t lldiv (long long, long long);

typedef struct { unsigned int quot, rem; } udiv_t;
typedef struct { unsigned long quot, rem; } uldiv_t;
udiv_t udiv (unsigned int, unsigned int);
uldiv_t uldiv (unsigned long, unsigned long);





size_t __ctype_get_mb_cur_max(void);
# 18 "./pid.h" 2

# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\math.h" 1 3
# 15 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\math.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\bits/alltypes.h" 1 3
# 33 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\bits/alltypes.h" 3
typedef float float_t;




typedef double double_t;
# 15 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\math.h" 2 3
# 42 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\math.h" 3
int __fpclassifyf(float);







int __signbitf(float);
# 59 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\math.h" 3
double acos(double);
float acosf(float);
long double acosl(long double);



double acosh(double);
float acoshf(float);
long double acoshl(long double);



double asin(double);
float asinf(float);
long double asinl(long double);



double asinh(double);
float asinhf(float);
long double asinhl(long double);



double atan(double);
float atanf(float);
long double atanl(long double);



double atan2(double, double);
float atan2f(float, float);
long double atan2l(long double, long double);



double atanh(double);
float atanhf(float);
long double atanhl(long double);



double cbrt(double);
float cbrtf(float);
long double cbrtl(long double);



double ceil(double);
float ceilf(float);
long double ceill(long double);



double copysign(double, double);
float copysignf(float, float);
long double copysignl(long double, long double);



double cos(double);
float cosf(float);
long double cosl(long double);



double cosh(double);
float coshf(float);
long double coshl(long double);



double erf(double);
float erff(float);
long double erfl(long double);



double erfc(double);
float erfcf(float);
long double erfcl(long double);



double exp(double);
float expf(float);
long double expl(long double);



double exp2(double);
float exp2f(float);
long double exp2l(long double);



double expm1(double);
float expm1f(float);
long double expm1l(long double);



double fabs(double);
float fabsf(float);
long double fabsl(long double);



double fdim(double, double);
float fdimf(float, float);
long double fdiml(long double, long double);



double floor(double);
float floorf(float);
long double floorl(long double);



double fma(double, double, double);
float fmaf(float, float, float);
long double fmal(long double, long double, long double);



double fmax(double, double);
float fmaxf(float, float);
long double fmaxl(long double, long double);



double fmin(double, double);
float fminf(float, float);
long double fminl(long double, long double);



double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);



double frexp(double, int *);
float frexpf(float, int *);
long double frexpl(long double, int *);



double hypot(double, double);
float hypotf(float, float);
long double hypotl(long double, long double);



int ilogb(double);
int ilogbf(float);
int ilogbl(long double);



double ldexp(double, int);
float ldexpf(float, int);
long double ldexpl(long double, int);



double lgamma(double);
float lgammaf(float);
long double lgammal(long double);



long long llrint(double);
long long llrintf(float);
long long llrintl(long double);



long long llround(double);
long long llroundf(float);
long long llroundl(long double);



double log(double);
float logf(float);
long double logl(long double);



double log10(double);
float log10f(float);
long double log10l(long double);



double log1p(double);
float log1pf(float);
long double log1pl(long double);



double log2(double);
float log2f(float);
long double log2l(long double);



double logb(double);
float logbf(float);
long double logbl(long double);



long lrint(double);
long lrintf(float);
long lrintl(long double);



long lround(double);
long lroundf(float);
long lroundl(long double);



double modf(double, double *);
float modff(float, float *);
long double modfl(long double, long double *);



double nan(const char *);
float nanf(const char *);
long double nanl(const char *);



double nearbyint(double);
float nearbyintf(float);
long double nearbyintl(long double);



double nextafter(double, double);
float nextafterf(float, float);
long double nextafterl(long double, long double);



double nexttoward(double, long double);
float nexttowardf(float, long double);
long double nexttowardl(long double, long double);




double pow(double, double);
__attribute__((nonreentrant)) float powf(float, float);
long double powl(long double, long double);



double remainder(double, double);
float remainderf(float, float);
long double remainderl(long double, long double);



double remquo(double, double, int *);
float remquof(float, float, int *);
long double remquol(long double, long double, int *);



double rint(double);
float rintf(float);
long double rintl(long double);



double round(double);
float roundf(float);
long double roundl(long double);



double scalbln(double, long);
float scalblnf(float, long);
long double scalblnl(long double, long);



double scalbn(double, int);
float scalbnf(float, int);
long double scalbnl(long double, int);



double sin(double);
float sinf(float);
long double sinl(long double);



double sinh(double);
float sinhf(float);
long double sinhl(long double);



double sqrt(double);
float sqrtf(float);
long double sqrtl(long double);



double tan(double);
float tanf(float);
long double tanl(long double);



double tanh(double);
float tanhf(float);
long double tanhl(long double);



double tgamma(double);
float tgammaf(float);
long double tgammal(long double);



double trunc(double);
float truncf(float);
long double truncl(long double);
# 423 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\math.h" 3
extern int signgam;

double j0(double);
double j1(double);
double jn(int, double);

double y0(double);
double y1(double);
double yn(int, double);
# 19 "./pid.h" 2






typedef struct
{
    float setpoint;
 float proportiongain;
 float integralgain;
 float derivativegain;
 float lasterror;
 float result;
 float integral;
 float errorabsmax;
 float errorabsmin;
}POSPID;


typedef struct
{
 float setpoint;
 float proportiongain;
    float integralgain;
 float derivativegain;
 float lasterror;
    float preerror;
 float deadband;
    float result;
 float errorabsmax;
 float errorabsmin;
}INCPID;

extern float VariableIntergralCoefficient(float error,float absmax,float absmin);
extern void pos_PIDRegulation(POSPID *vPID,float processValue);
extern void inc_PIDRegulation(INCPID *vPID, float processValue);
extern void init_pid(void);
extern void dinit_pid(void);
extern void set_pid_target(float);
# 5 "slave_service.c" 2





uint8_t slave_reg[17 + 1] = {0};

extern uint8_t temp_data[2];
extern uint16_t speed;
extern float temperature;
extern uint8_t rxBuf[13 + 1];
float offset_temp,offFan_temp;

extern float Tol_max;
extern float Tol_min;
extern float Tol_1;
extern float Tol_2;
extern float percent;

extern uint8_t MaxFanSpeed;
float SetTemp = 70;


void update_slave_reg(void)
{
    float temp;
    int temp_storage;
    int temp_storage1;

    if(temperature < Tol_min)
    {speed = 0;}


    temp_storage =(int)temperature;
    slave_reg[0]= (uint8_t)(temp_storage/16);
    temp_storage1= temp_storage%16;
    slave_reg[1]= (uint8_t)((temperature-temp_storage+temp_storage1)*16);


    slave_reg[2]= (speed&0xFF00)>>8;
    slave_reg[3]= speed&0x00FF;


    temp_storage =(int)offset_temp;
    slave_reg[4]= (uint8_t)(temp_storage/16);
    temp_storage1= temp_storage%16;
    slave_reg[5]= (uint8_t)((offset_temp-temp_storage+temp_storage1)*16);


    temp_storage =(int)offFan_temp;
    slave_reg[6]= (uint8_t)(temp_storage/16);
    temp_storage1= temp_storage%16;
    slave_reg[7]= (uint8_t)((offFan_temp-temp_storage+temp_storage1)*16);


    temp_storage =(int)SetTemp;
    slave_reg[8]= (uint8_t)(temp_storage/16);
    temp_storage1= temp_storage%16;
    slave_reg[9]= (uint8_t)((SetTemp-temp_storage+temp_storage1)*16);


    temp_storage =(int)Tol_1;
    slave_reg[10]= (uint8_t)(temp_storage/16);
    temp_storage1= temp_storage%16;
    slave_reg[11]= (uint8_t)((Tol_1-temp_storage+temp_storage1)*16);

    temp = Tol_2;
    if(temp < 0.0) temp = -Tol_2;

    temp_storage =(int)temp;
    slave_reg[12]= (uint8_t)(temp_storage/16);
    temp_storage1= temp_storage%16;
    slave_reg[13]= (uint8_t)((temp-temp_storage+temp_storage1)*16);


    slave_reg[14] = MaxFanSpeed;
# 101 "slave_service.c"
    slave_reg[15]= 0x00;
    slave_reg[16]= slave_reg[0]^slave_reg[1]^slave_reg[2]^slave_reg[3]^slave_reg[4]^slave_reg[5]^slave_reg[6]^slave_reg[7]^slave_reg[8]^slave_reg[9]^slave_reg[10]^slave_reg[11]^slave_reg[12]^slave_reg[13]^slave_reg[14];
}


void update_offset_n_offFan_value(void)
{
    uint8_t temp = rxBuf[0]^rxBuf[1]^rxBuf[2]^rxBuf[3]^rxBuf[4]^rxBuf[5]^rxBuf[6]^rxBuf[7]^rxBuf[8]^rxBuf[9]^rxBuf[10];

    if((temp == rxBuf[12]) &&(rxBuf[11] == 0))
    {

        if((rxBuf[0]&0x10)==0x10)
        {
            temp=rxBuf[0]&0x0F;
            offset_temp = 256-(temp*16+((float)(rxBuf[1])/16));
        }
        else{
            temp=rxBuf[0]&0x0F;
            offset_temp = temp*16+((float)(rxBuf[1])/16);
        }




        if((rxBuf[2]&0x10)==0x10)
        {
            temp=rxBuf[2]&0x0F;
            offFan_temp = 256-(temp*16+((float)(rxBuf[3])/16));
        }
        else{
            temp=rxBuf[2]&0x0F;
            offFan_temp = temp*16+((float)(rxBuf[3])/16);
        }


        if((rxBuf[4]&0x10)==0x10)
        {
            temp=rxBuf[4]&0x0F;
            SetTemp = 256-(temp*16+((float)(rxBuf[5])/16));
        }
        else{
            temp=rxBuf[4]&0x0F;
            SetTemp = temp*16+((float)(rxBuf[5])/16);
        }

        Tol_1 = (float)(rxBuf[6]*16)+((float)(rxBuf[7])/16);
        Tol_2 = (float)(rxBuf[8]*16)+((float)(rxBuf[9])/16);

        Tol_2 = -Tol_2;
        Tol_max = SetTemp + Tol_1;
        Tol_min = SetTemp + Tol_2;

        MaxFanSpeed = rxBuf[10];
        percent = ((float)MaxFanSpeed/(float)100.0);

        set_pid_target(SetTemp);
    }
    update_slave_reg();
}
