# 1 "main.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "main.c" 2







# 1 "./device_config.h" 1
# 8 "main.c" 2

# 1 "./pin_manager.h" 1
# 10 "./pin_manager.h"
# 1 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\xc.h" 1 3
# 18 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\xc.h" 3
extern const char __xc8_OPTIM_SPEED;

extern double __fpnormalize(double);



# 1 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\xc8debug.h" 1 3



# 1 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\stdlib.h" 1 3



# 1 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\musl_xc8.h" 1 3
# 4 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\stdlib.h" 2 3






# 1 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\features.h" 1 3
# 10 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\stdlib.h" 2 3
# 21 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\stdlib.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\bits/alltypes.h" 1 3
# 18 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long int wchar_t;
# 122 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned size_t;
# 168 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\bits/alltypes.h" 3
typedef __int24 int24_t;
# 204 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\bits/alltypes.h" 3
typedef __uint24 uint24_t;
# 21 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\stdlib.h" 2 3


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

void *malloc (size_t);
void *calloc (size_t, size_t);
void *realloc (void *, size_t);
void free (void *);

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
# 4 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\xc8debug.h" 2 3








#pragma intrinsic(__builtin_software_breakpoint)
extern void __builtin_software_breakpoint(void);
# 24 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\xc.h" 2 3
# 1 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\builtins.h" 1 3



# 1 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\stdint.h" 1 3
# 22 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\stdint.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\bits/alltypes.h" 1 3
# 127 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned long uintptr_t;
# 142 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long intptr_t;
# 158 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\bits/alltypes.h" 3
typedef signed char int8_t;




typedef short int16_t;
# 173 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long int32_t;





typedef long long int64_t;
# 188 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long long intmax_t;





typedef unsigned char uint8_t;




typedef unsigned short uint16_t;
# 209 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned long uint32_t;





typedef unsigned long long uint64_t;
# 229 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned long long uintmax_t;
# 22 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\stdint.h" 2 3


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
# 144 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\stdint.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\bits/stdint.h" 1 3
typedef int16_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef uint16_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
# 144 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\stdint.h" 2 3
# 5 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\builtins.h" 2 3


#pragma intrinsic(__nop)
extern void __nop(void);


#pragma intrinsic(_delay)
extern __attribute__((nonreentrant)) void _delay(uint32_t);
#pragma intrinsic(_delaywdt)
extern __attribute__((nonreentrant)) void _delaywdt(uint32_t);

#pragma intrinsic(_delay3)
extern __attribute__((nonreentrant)) void _delay3(uint8_t);
# 25 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\xc.h" 2 3








# 1 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\pic18.h" 1 3




# 1 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\htc.h" 1 3



# 1 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\xc.h" 1 3
# 5 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\htc.h" 2 3
# 6 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\pic18.h" 2 3


# 1 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\pic18_chip_select.h" 1 3
# 320 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\pic18_chip_select.h" 3
# 1 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 1 3
# 45 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
# 1 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\__at.h" 1 3
# 46 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 2 3







extern volatile unsigned char PORTA __attribute__((address(0xF80)));

__asm("PORTA equ 0F80h");


typedef union {
    struct {
        unsigned RA0 :1;
        unsigned RA1 :1;
        unsigned RA2 :1;
        unsigned RA3 :1;
        unsigned RA4 :1;
        unsigned RA5 :1;
        unsigned RA6 :1;
        unsigned RA7 :1;
    };
    struct {
        unsigned AN0 :1;
        unsigned AN1 :1;
        unsigned AN2 :1;
        unsigned AN3 :1;
        unsigned T0CKI :1;
        unsigned AN4 :1;
        unsigned OSC2 :1;
        unsigned OSC1 :1;
    };
    struct {
        unsigned :2;
        unsigned VREFN :1;
        unsigned VREFP :1;
        unsigned :1;
        unsigned SS :1;
        unsigned CLKO :1;
        unsigned CLKI :1;
    };
    struct {
        unsigned :5;
        unsigned NOT_SS :1;
    };
    struct {
        unsigned :2;
        unsigned CVREF :1;
        unsigned :2;
        unsigned nSS :1;
    };
    struct {
        unsigned :5;
        unsigned LVDIN :1;
    };
    struct {
        unsigned :5;
        unsigned HLVDIN :1;
    };
    struct {
        unsigned :4;
        unsigned C1OUT :1;
        unsigned C2OUT :1;
    };
    struct {
        unsigned ULPWUIN :1;
        unsigned :6;
        unsigned RJPU :1;
    };
} PORTAbits_t;
extern volatile PORTAbits_t PORTAbits __attribute__((address(0xF80)));
# 272 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned char PORTB __attribute__((address(0xF81)));

__asm("PORTB equ 0F81h");


typedef union {
    struct {
        unsigned RB0 :1;
        unsigned RB1 :1;
        unsigned RB2 :1;
        unsigned RB3 :1;
        unsigned RB4 :1;
        unsigned RB5 :1;
        unsigned RB6 :1;
        unsigned RB7 :1;
    };
    struct {
        unsigned INT0 :1;
        unsigned INT1 :1;
        unsigned INT2 :1;
        unsigned CCP2 :1;
        unsigned KBI0 :1;
        unsigned KBI1 :1;
        unsigned KBI2 :1;
        unsigned KBI3 :1;
    };
    struct {
        unsigned AN12 :1;
        unsigned AN10 :1;
        unsigned AN8 :1;
        unsigned AN9 :1;
        unsigned AN11 :1;
        unsigned PGM :1;
        unsigned PGC :1;
        unsigned PGD :1;
    };
    struct {
        unsigned FLT0 :1;
    };
    struct {
        unsigned :3;
        unsigned CCP2_PA2 :1;
    };
} PORTBbits_t;
extern volatile PORTBbits_t PORTBbits __attribute__((address(0xF81)));
# 451 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned char PORTC __attribute__((address(0xF82)));

__asm("PORTC equ 0F82h");


typedef union {
    struct {
        unsigned RC0 :1;
        unsigned RC1 :1;
        unsigned RC2 :1;
        unsigned RC3 :1;
        unsigned RC4 :1;
        unsigned RC5 :1;
        unsigned RC6 :1;
        unsigned RC7 :1;
    };
    struct {
        unsigned T1OSO :1;
        unsigned T1OSI :1;
        unsigned CCP1 :1;
        unsigned SCK :1;
        unsigned SDI :1;
        unsigned SDO :1;
        unsigned TX :1;
        unsigned RX :1;
    };
    struct {
        unsigned T13CKI :1;
        unsigned CCP2 :1;
        unsigned :1;
        unsigned SCL :1;
        unsigned SDA :1;
        unsigned :1;
        unsigned CK :1;
        unsigned DT :1;
    };
    struct {
        unsigned T1CKI :1;
        unsigned :1;
        unsigned P1A :1;
    };
    struct {
        unsigned :1;
        unsigned PA2 :1;
        unsigned PA1 :1;
    };
} PORTCbits_t;
extern volatile PORTCbits_t PORTCbits __attribute__((address(0xF82)));
# 633 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned char PORTD __attribute__((address(0xF83)));

__asm("PORTD equ 0F83h");


typedef union {
    struct {
        unsigned RD0 :1;
        unsigned RD1 :1;
        unsigned RD2 :1;
        unsigned RD3 :1;
        unsigned RD4 :1;
        unsigned RD5 :1;
        unsigned RD6 :1;
        unsigned RD7 :1;
    };
    struct {
        unsigned PSP0 :1;
        unsigned PSP1 :1;
        unsigned PSP2 :1;
        unsigned PSP3 :1;
        unsigned PSP4 :1;
        unsigned PSP5 :1;
        unsigned PSP6 :1;
        unsigned PSP7 :1;
    };
    struct {
        unsigned :5;
        unsigned P1B :1;
        unsigned P1C :1;
        unsigned P1D :1;
    };
    struct {
        unsigned :7;
        unsigned SS2 :1;
    };
} PORTDbits_t;
extern volatile PORTDbits_t PORTDbits __attribute__((address(0xF83)));
# 775 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned char PORTE __attribute__((address(0xF84)));

__asm("PORTE equ 0F84h");


typedef union {
    struct {
        unsigned RE0 :1;
        unsigned RE1 :1;
        unsigned RE2 :1;
        unsigned RE3 :1;
    };
    struct {
        unsigned RD :1;
        unsigned WR :1;
        unsigned CS :1;
        unsigned MCLR :1;
    };
    struct {
        unsigned NOT_RD :1;
    };
    struct {
        unsigned :1;
        unsigned NOT_WR :1;
    };
    struct {
        unsigned :2;
        unsigned NOT_CS :1;
    };
    struct {
        unsigned :3;
        unsigned NOT_MCLR :1;
    };
    struct {
        unsigned nRD :1;
        unsigned nWR :1;
        unsigned nCS :1;
        unsigned nMCLR :1;
    };
    struct {
        unsigned AN5 :1;
        unsigned AN6 :1;
        unsigned AN7 :1;
        unsigned VPP :1;
    };
    struct {
        unsigned PD2 :1;
        unsigned PC2 :1;
        unsigned CCP10 :1;
        unsigned CCP9E :1;
    };
    struct {
        unsigned RDE :1;
        unsigned WRE :1;
        unsigned PB2 :1;
        unsigned PC3E :1;
    };
} PORTEbits_t;
extern volatile PORTEbits_t PORTEbits __attribute__((address(0xF84)));
# 978 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned char LATA __attribute__((address(0xF89)));

__asm("LATA equ 0F89h");


typedef union {
    struct {
        unsigned LATA0 :1;
        unsigned LATA1 :1;
        unsigned LATA2 :1;
        unsigned LATA3 :1;
        unsigned LATA4 :1;
        unsigned LATA5 :1;
        unsigned LATA6 :1;
        unsigned LATA7 :1;
    };
    struct {
        unsigned LA0 :1;
        unsigned LA1 :1;
        unsigned LA2 :1;
        unsigned LA3 :1;
        unsigned LA4 :1;
        unsigned LA5 :1;
        unsigned LA6 :1;
        unsigned LA7 :1;
    };
} LATAbits_t;
extern volatile LATAbits_t LATAbits __attribute__((address(0xF89)));
# 1090 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned char LATB __attribute__((address(0xF8A)));

__asm("LATB equ 0F8Ah");


typedef union {
    struct {
        unsigned LATB0 :1;
        unsigned LATB1 :1;
        unsigned LATB2 :1;
        unsigned LATB3 :1;
        unsigned LATB4 :1;
        unsigned LATB5 :1;
        unsigned LATB6 :1;
        unsigned LATB7 :1;
    };
    struct {
        unsigned LB0 :1;
        unsigned LB1 :1;
        unsigned LB2 :1;
        unsigned LB3 :1;
        unsigned LB4 :1;
        unsigned LB5 :1;
        unsigned LB6 :1;
        unsigned LB7 :1;
    };
} LATBbits_t;
extern volatile LATBbits_t LATBbits __attribute__((address(0xF8A)));
# 1202 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned char LATC __attribute__((address(0xF8B)));

__asm("LATC equ 0F8Bh");


typedef union {
    struct {
        unsigned LATC0 :1;
        unsigned LATC1 :1;
        unsigned LATC2 :1;
        unsigned LATC3 :1;
        unsigned LATC4 :1;
        unsigned LATC5 :1;
        unsigned LATC6 :1;
        unsigned LATC7 :1;
    };
    struct {
        unsigned LC0 :1;
        unsigned LC1 :1;
        unsigned LC2 :1;
        unsigned LC3 :1;
        unsigned LC4 :1;
        unsigned LC5 :1;
        unsigned LC6 :1;
        unsigned LC7 :1;
    };
} LATCbits_t;
extern volatile LATCbits_t LATCbits __attribute__((address(0xF8B)));
# 1314 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned char LATD __attribute__((address(0xF8C)));

__asm("LATD equ 0F8Ch");


typedef union {
    struct {
        unsigned LATD0 :1;
        unsigned LATD1 :1;
        unsigned LATD2 :1;
        unsigned LATD3 :1;
        unsigned LATD4 :1;
        unsigned LATD5 :1;
        unsigned LATD6 :1;
        unsigned LATD7 :1;
    };
    struct {
        unsigned LD0 :1;
        unsigned LD1 :1;
        unsigned LD2 :1;
        unsigned LD3 :1;
        unsigned LD4 :1;
        unsigned LD5 :1;
        unsigned LD6 :1;
        unsigned LD7 :1;
    };
} LATDbits_t;
extern volatile LATDbits_t LATDbits __attribute__((address(0xF8C)));
# 1426 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned char LATE __attribute__((address(0xF8D)));

__asm("LATE equ 0F8Dh");


typedef union {
    struct {
        unsigned LATE0 :1;
        unsigned LATE1 :1;
        unsigned LATE2 :1;
    };
    struct {
        unsigned LE0 :1;
        unsigned LE1 :1;
        unsigned LE2 :1;
    };
} LATEbits_t;
extern volatile LATEbits_t LATEbits __attribute__((address(0xF8D)));
# 1478 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned char TRISA __attribute__((address(0xF92)));

__asm("TRISA equ 0F92h");


extern volatile unsigned char DDRA __attribute__((address(0xF92)));

__asm("DDRA equ 0F92h");


typedef union {
    struct {
        unsigned TRISA0 :1;
        unsigned TRISA1 :1;
        unsigned TRISA2 :1;
        unsigned TRISA3 :1;
        unsigned TRISA4 :1;
        unsigned TRISA5 :1;
        unsigned TRISA6 :1;
        unsigned TRISA7 :1;
    };
    struct {
        unsigned RA0 :1;
        unsigned RA1 :1;
        unsigned RA2 :1;
        unsigned RA3 :1;
        unsigned RA4 :1;
        unsigned RA5 :1;
        unsigned RA6 :1;
        unsigned RA7 :1;
    };
} TRISAbits_t;
extern volatile TRISAbits_t TRISAbits __attribute__((address(0xF92)));
# 1593 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
typedef union {
    struct {
        unsigned TRISA0 :1;
        unsigned TRISA1 :1;
        unsigned TRISA2 :1;
        unsigned TRISA3 :1;
        unsigned TRISA4 :1;
        unsigned TRISA5 :1;
        unsigned TRISA6 :1;
        unsigned TRISA7 :1;
    };
    struct {
        unsigned RA0 :1;
        unsigned RA1 :1;
        unsigned RA2 :1;
        unsigned RA3 :1;
        unsigned RA4 :1;
        unsigned RA5 :1;
        unsigned RA6 :1;
        unsigned RA7 :1;
    };
} DDRAbits_t;
extern volatile DDRAbits_t DDRAbits __attribute__((address(0xF92)));
# 1700 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned char TRISB __attribute__((address(0xF93)));

__asm("TRISB equ 0F93h");


extern volatile unsigned char DDRB __attribute__((address(0xF93)));

__asm("DDRB equ 0F93h");


typedef union {
    struct {
        unsigned TRISB0 :1;
        unsigned TRISB1 :1;
        unsigned TRISB2 :1;
        unsigned TRISB3 :1;
        unsigned TRISB4 :1;
        unsigned TRISB5 :1;
        unsigned TRISB6 :1;
        unsigned TRISB7 :1;
    };
    struct {
        unsigned RB0 :1;
        unsigned RB1 :1;
        unsigned RB2 :1;
        unsigned RB3 :1;
        unsigned RB4 :1;
        unsigned RB5 :1;
        unsigned RB6 :1;
        unsigned RB7 :1;
    };
} TRISBbits_t;
extern volatile TRISBbits_t TRISBbits __attribute__((address(0xF93)));
# 1815 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
typedef union {
    struct {
        unsigned TRISB0 :1;
        unsigned TRISB1 :1;
        unsigned TRISB2 :1;
        unsigned TRISB3 :1;
        unsigned TRISB4 :1;
        unsigned TRISB5 :1;
        unsigned TRISB6 :1;
        unsigned TRISB7 :1;
    };
    struct {
        unsigned RB0 :1;
        unsigned RB1 :1;
        unsigned RB2 :1;
        unsigned RB3 :1;
        unsigned RB4 :1;
        unsigned RB5 :1;
        unsigned RB6 :1;
        unsigned RB7 :1;
    };
} DDRBbits_t;
extern volatile DDRBbits_t DDRBbits __attribute__((address(0xF93)));
# 1922 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned char TRISC __attribute__((address(0xF94)));

__asm("TRISC equ 0F94h");


extern volatile unsigned char DDRC __attribute__((address(0xF94)));

__asm("DDRC equ 0F94h");


typedef union {
    struct {
        unsigned TRISC0 :1;
        unsigned TRISC1 :1;
        unsigned TRISC2 :1;
        unsigned TRISC3 :1;
        unsigned TRISC4 :1;
        unsigned TRISC5 :1;
        unsigned TRISC6 :1;
        unsigned TRISC7 :1;
    };
    struct {
        unsigned RC0 :1;
        unsigned RC1 :1;
        unsigned RC2 :1;
        unsigned RC3 :1;
        unsigned RC4 :1;
        unsigned RC5 :1;
        unsigned RC6 :1;
        unsigned RC7 :1;
    };
} TRISCbits_t;
extern volatile TRISCbits_t TRISCbits __attribute__((address(0xF94)));
# 2037 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
typedef union {
    struct {
        unsigned TRISC0 :1;
        unsigned TRISC1 :1;
        unsigned TRISC2 :1;
        unsigned TRISC3 :1;
        unsigned TRISC4 :1;
        unsigned TRISC5 :1;
        unsigned TRISC6 :1;
        unsigned TRISC7 :1;
    };
    struct {
        unsigned RC0 :1;
        unsigned RC1 :1;
        unsigned RC2 :1;
        unsigned RC3 :1;
        unsigned RC4 :1;
        unsigned RC5 :1;
        unsigned RC6 :1;
        unsigned RC7 :1;
    };
} DDRCbits_t;
extern volatile DDRCbits_t DDRCbits __attribute__((address(0xF94)));
# 2144 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned char TRISD __attribute__((address(0xF95)));

__asm("TRISD equ 0F95h");


extern volatile unsigned char DDRD __attribute__((address(0xF95)));

__asm("DDRD equ 0F95h");


typedef union {
    struct {
        unsigned TRISD0 :1;
        unsigned TRISD1 :1;
        unsigned TRISD2 :1;
        unsigned TRISD3 :1;
        unsigned TRISD4 :1;
        unsigned TRISD5 :1;
        unsigned TRISD6 :1;
        unsigned TRISD7 :1;
    };
    struct {
        unsigned RD0 :1;
        unsigned RD1 :1;
        unsigned RD2 :1;
        unsigned RD3 :1;
        unsigned RD4 :1;
        unsigned RD5 :1;
        unsigned RD6 :1;
        unsigned RD7 :1;
    };
} TRISDbits_t;
extern volatile TRISDbits_t TRISDbits __attribute__((address(0xF95)));
# 2259 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
typedef union {
    struct {
        unsigned TRISD0 :1;
        unsigned TRISD1 :1;
        unsigned TRISD2 :1;
        unsigned TRISD3 :1;
        unsigned TRISD4 :1;
        unsigned TRISD5 :1;
        unsigned TRISD6 :1;
        unsigned TRISD7 :1;
    };
    struct {
        unsigned RD0 :1;
        unsigned RD1 :1;
        unsigned RD2 :1;
        unsigned RD3 :1;
        unsigned RD4 :1;
        unsigned RD5 :1;
        unsigned RD6 :1;
        unsigned RD7 :1;
    };
} DDRDbits_t;
extern volatile DDRDbits_t DDRDbits __attribute__((address(0xF95)));
# 2366 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned char TRISE __attribute__((address(0xF96)));

__asm("TRISE equ 0F96h");


extern volatile unsigned char DDRE __attribute__((address(0xF96)));

__asm("DDRE equ 0F96h");


typedef union {
    struct {
        unsigned TRISE0 :1;
        unsigned TRISE1 :1;
        unsigned TRISE2 :1;
        unsigned :1;
        unsigned PSPMODE :1;
        unsigned IBOV :1;
        unsigned OBF :1;
        unsigned IBF :1;
    };
    struct {
        unsigned RE0 :1;
        unsigned RE1 :1;
        unsigned RE2 :1;
        unsigned RE3 :1;
    };
} TRISEbits_t;
extern volatile TRISEbits_t TRISEbits __attribute__((address(0xF96)));
# 2452 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
typedef union {
    struct {
        unsigned TRISE0 :1;
        unsigned TRISE1 :1;
        unsigned TRISE2 :1;
        unsigned :1;
        unsigned PSPMODE :1;
        unsigned IBOV :1;
        unsigned OBF :1;
        unsigned IBF :1;
    };
    struct {
        unsigned RE0 :1;
        unsigned RE1 :1;
        unsigned RE2 :1;
        unsigned RE3 :1;
    };
} DDREbits_t;
extern volatile DDREbits_t DDREbits __attribute__((address(0xF96)));
# 2530 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned char OSCTUNE __attribute__((address(0xF9B)));

__asm("OSCTUNE equ 0F9Bh");


typedef union {
    struct {
        unsigned TUN :5;
        unsigned :1;
        unsigned PLLEN :1;
        unsigned INTSRC :1;
    };
    struct {
        unsigned TUN0 :1;
        unsigned TUN1 :1;
        unsigned TUN2 :1;
        unsigned TUN3 :1;
        unsigned TUN4 :1;
    };
} OSCTUNEbits_t;
extern volatile OSCTUNEbits_t OSCTUNEbits __attribute__((address(0xF9B)));
# 2595 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned char PIE1 __attribute__((address(0xF9D)));

__asm("PIE1 equ 0F9Dh");


typedef union {
    struct {
        unsigned TMR1IE :1;
        unsigned TMR2IE :1;
        unsigned CCP1IE :1;
        unsigned SSPIE :1;
        unsigned TXIE :1;
        unsigned RCIE :1;
        unsigned ADIE :1;
        unsigned PSPIE :1;
    };
    struct {
        unsigned :4;
        unsigned TX1IE :1;
        unsigned RC1IE :1;
    };
} PIE1bits_t;
extern volatile PIE1bits_t PIE1bits __attribute__((address(0xF9D)));
# 2672 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned char PIR1 __attribute__((address(0xF9E)));

__asm("PIR1 equ 0F9Eh");


typedef union {
    struct {
        unsigned TMR1IF :1;
        unsigned TMR2IF :1;
        unsigned CCP1IF :1;
        unsigned SSPIF :1;
        unsigned TXIF :1;
        unsigned RCIF :1;
        unsigned ADIF :1;
        unsigned PSPIF :1;
    };
    struct {
        unsigned :4;
        unsigned TX1IF :1;
        unsigned RC1IF :1;
    };
} PIR1bits_t;
extern volatile PIR1bits_t PIR1bits __attribute__((address(0xF9E)));
# 2749 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned char IPR1 __attribute__((address(0xF9F)));

__asm("IPR1 equ 0F9Fh");


typedef union {
    struct {
        unsigned TMR1IP :1;
        unsigned TMR2IP :1;
        unsigned CCP1IP :1;
        unsigned SSPIP :1;
        unsigned TXIP :1;
        unsigned RCIP :1;
        unsigned ADIP :1;
        unsigned PSPIP :1;
    };
    struct {
        unsigned :4;
        unsigned TX1IP :1;
        unsigned RC1IP :1;
    };
} IPR1bits_t;
extern volatile IPR1bits_t IPR1bits __attribute__((address(0xF9F)));
# 2826 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned char PIE2 __attribute__((address(0xFA0)));

__asm("PIE2 equ 0FA0h");


typedef union {
    struct {
        unsigned CCP2IE :1;
        unsigned TMR3IE :1;
        unsigned HLVDIE :1;
        unsigned BCLIE :1;
        unsigned EEIE :1;
        unsigned :1;
        unsigned CMIE :1;
        unsigned OSCFIE :1;
    };
    struct {
        unsigned :2;
        unsigned LVDIE :1;
    };
} PIE2bits_t;
extern volatile PIE2bits_t PIE2bits __attribute__((address(0xFA0)));
# 2892 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned char PIR2 __attribute__((address(0xFA1)));

__asm("PIR2 equ 0FA1h");


typedef union {
    struct {
        unsigned CCP2IF :1;
        unsigned TMR3IF :1;
        unsigned HLVDIF :1;
        unsigned BCLIF :1;
        unsigned EEIF :1;
        unsigned :1;
        unsigned CMIF :1;
        unsigned OSCFIF :1;
    };
    struct {
        unsigned :2;
        unsigned LVDIF :1;
    };
} PIR2bits_t;
extern volatile PIR2bits_t PIR2bits __attribute__((address(0xFA1)));
# 2958 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned char IPR2 __attribute__((address(0xFA2)));

__asm("IPR2 equ 0FA2h");


typedef union {
    struct {
        unsigned CCP2IP :1;
        unsigned TMR3IP :1;
        unsigned HLVDIP :1;
        unsigned BCLIP :1;
        unsigned EEIP :1;
        unsigned :1;
        unsigned CMIP :1;
        unsigned OSCFIP :1;
    };
    struct {
        unsigned :2;
        unsigned LVDIP :1;
    };
} IPR2bits_t;
extern volatile IPR2bits_t IPR2bits __attribute__((address(0xFA2)));
# 3024 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned char EECON1 __attribute__((address(0xFA6)));

__asm("EECON1 equ 0FA6h");


typedef union {
    struct {
        unsigned RD :1;
        unsigned WR :1;
        unsigned WREN :1;
        unsigned WRERR :1;
        unsigned FREE :1;
        unsigned :1;
        unsigned CFGS :1;
        unsigned EEPGD :1;
    };
    struct {
        unsigned :6;
        unsigned EEFS :1;
    };
} EECON1bits_t;
extern volatile EECON1bits_t EECON1bits __attribute__((address(0xFA6)));
# 3090 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned char EECON2 __attribute__((address(0xFA7)));

__asm("EECON2 equ 0FA7h");




extern volatile unsigned char EEDATA __attribute__((address(0xFA8)));

__asm("EEDATA equ 0FA8h");




extern volatile unsigned char EEADR __attribute__((address(0xFA9)));

__asm("EEADR equ 0FA9h");




extern volatile unsigned char RCSTA __attribute__((address(0xFAB)));

__asm("RCSTA equ 0FABh");


extern volatile unsigned char RCSTA1 __attribute__((address(0xFAB)));

__asm("RCSTA1 equ 0FABh");


typedef union {
    struct {
        unsigned RX9D :1;
        unsigned OERR :1;
        unsigned FERR :1;
        unsigned ADDEN :1;
        unsigned CREN :1;
        unsigned SREN :1;
        unsigned RX9 :1;
        unsigned SPEN :1;
    };
    struct {
        unsigned :3;
        unsigned ADEN :1;
    };
    struct {
        unsigned :5;
        unsigned SRENA :1;
    };
    struct {
        unsigned :6;
        unsigned RC8_9 :1;
    };
    struct {
        unsigned :6;
        unsigned RC9 :1;
    };
    struct {
        unsigned RCD8 :1;
    };
} RCSTAbits_t;
extern volatile RCSTAbits_t RCSTAbits __attribute__((address(0xFAB)));
# 3220 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
typedef union {
    struct {
        unsigned RX9D :1;
        unsigned OERR :1;
        unsigned FERR :1;
        unsigned ADDEN :1;
        unsigned CREN :1;
        unsigned SREN :1;
        unsigned RX9 :1;
        unsigned SPEN :1;
    };
    struct {
        unsigned :3;
        unsigned ADEN :1;
    };
    struct {
        unsigned :5;
        unsigned SRENA :1;
    };
    struct {
        unsigned :6;
        unsigned RC8_9 :1;
    };
    struct {
        unsigned :6;
        unsigned RC9 :1;
    };
    struct {
        unsigned RCD8 :1;
    };
} RCSTA1bits_t;
extern volatile RCSTA1bits_t RCSTA1bits __attribute__((address(0xFAB)));
# 3321 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned char TXSTA __attribute__((address(0xFAC)));

__asm("TXSTA equ 0FACh");


extern volatile unsigned char TXSTA1 __attribute__((address(0xFAC)));

__asm("TXSTA1 equ 0FACh");


typedef union {
    struct {
        unsigned TX9D :1;
        unsigned TRMT :1;
        unsigned BRGH :1;
        unsigned SENDB :1;
        unsigned SYNC :1;
        unsigned TXEN :1;
        unsigned TX9 :1;
        unsigned CSRC :1;
    };
    struct {
        unsigned TX9D1 :1;
        unsigned TRMT1 :1;
        unsigned BRGH1 :1;
        unsigned SENDB1 :1;
        unsigned SYNC1 :1;
        unsigned TXEN1 :1;
        unsigned TX91 :1;
        unsigned CSRC1 :1;
    };
    struct {
        unsigned :6;
        unsigned TX8_9 :1;
    };
    struct {
        unsigned TXD8 :1;
    };
} TXSTAbits_t;
extern volatile TXSTAbits_t TXSTAbits __attribute__((address(0xFAC)));
# 3453 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
typedef union {
    struct {
        unsigned TX9D :1;
        unsigned TRMT :1;
        unsigned BRGH :1;
        unsigned SENDB :1;
        unsigned SYNC :1;
        unsigned TXEN :1;
        unsigned TX9 :1;
        unsigned CSRC :1;
    };
    struct {
        unsigned TX9D1 :1;
        unsigned TRMT1 :1;
        unsigned BRGH1 :1;
        unsigned SENDB1 :1;
        unsigned SYNC1 :1;
        unsigned TXEN1 :1;
        unsigned TX91 :1;
        unsigned CSRC1 :1;
    };
    struct {
        unsigned :6;
        unsigned TX8_9 :1;
    };
    struct {
        unsigned TXD8 :1;
    };
} TXSTA1bits_t;
extern volatile TXSTA1bits_t TXSTA1bits __attribute__((address(0xFAC)));
# 3577 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned char TXREG __attribute__((address(0xFAD)));

__asm("TXREG equ 0FADh");


extern volatile unsigned char TXREG1 __attribute__((address(0xFAD)));

__asm("TXREG1 equ 0FADh");




extern volatile unsigned char RCREG __attribute__((address(0xFAE)));

__asm("RCREG equ 0FAEh");


extern volatile unsigned char RCREG1 __attribute__((address(0xFAE)));

__asm("RCREG1 equ 0FAEh");




extern volatile unsigned char SPBRG __attribute__((address(0xFAF)));

__asm("SPBRG equ 0FAFh");


extern volatile unsigned char SPBRG1 __attribute__((address(0xFAF)));

__asm("SPBRG1 equ 0FAFh");




extern volatile unsigned char SPBRGH __attribute__((address(0xFB0)));

__asm("SPBRGH equ 0FB0h");




extern volatile unsigned char T3CON __attribute__((address(0xFB1)));

__asm("T3CON equ 0FB1h");


typedef union {
    struct {
        unsigned :2;
        unsigned NOT_T3SYNC :1;
    };
    struct {
        unsigned TMR3ON :1;
        unsigned TMR3CS :1;
        unsigned nT3SYNC :1;
        unsigned T3CCP1 :1;
        unsigned T3CKPS :2;
        unsigned T3CCP2 :1;
        unsigned RD16 :1;
    };
    struct {
        unsigned :2;
        unsigned T3SYNC :1;
        unsigned :1;
        unsigned T3CKPS0 :1;
        unsigned T3CKPS1 :1;
    };
    struct {
        unsigned :3;
        unsigned SOSCEN3 :1;
        unsigned :3;
        unsigned RD163 :1;
    };
    struct {
        unsigned :7;
        unsigned T3RD16 :1;
    };
} T3CONbits_t;
extern volatile T3CONbits_t T3CONbits __attribute__((address(0xFB1)));
# 3732 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned short TMR3 __attribute__((address(0xFB2)));

__asm("TMR3 equ 0FB2h");




extern volatile unsigned char TMR3L __attribute__((address(0xFB2)));

__asm("TMR3L equ 0FB2h");




extern volatile unsigned char TMR3H __attribute__((address(0xFB3)));

__asm("TMR3H equ 0FB3h");




extern volatile unsigned char CMCON __attribute__((address(0xFB4)));

__asm("CMCON equ 0FB4h");


typedef union {
    struct {
        unsigned CM :3;
        unsigned CIS :1;
        unsigned C1INV :1;
        unsigned C2INV :1;
        unsigned C1OUT :1;
        unsigned C2OUT :1;
    };
    struct {
        unsigned CM0 :1;
        unsigned CM1 :1;
        unsigned CM2 :1;
    };
    struct {
        unsigned CMEN0 :1;
        unsigned CMEN1 :1;
        unsigned CMEN2 :1;
    };
} CMCONbits_t;
extern volatile CMCONbits_t CMCONbits __attribute__((address(0xFB4)));
# 3843 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned char CVRCON __attribute__((address(0xFB5)));

__asm("CVRCON equ 0FB5h");


typedef union {
    struct {
        unsigned CVR :4;
        unsigned CVRSS :1;
        unsigned CVRR :1;
        unsigned CVROE :1;
        unsigned CVREN :1;
    };
    struct {
        unsigned CVR0 :1;
        unsigned CVR1 :1;
        unsigned CVR2 :1;
        unsigned CVR3 :1;
    };
    struct {
        unsigned :6;
        unsigned CVROEN :1;
    };
} CVRCONbits_t;
extern volatile CVRCONbits_t CVRCONbits __attribute__((address(0xFB5)));
# 3922 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned char ECCP1AS __attribute__((address(0xFB6)));

__asm("ECCP1AS equ 0FB6h");


extern volatile unsigned char ECCPAS __attribute__((address(0xFB6)));

__asm("ECCPAS equ 0FB6h");


typedef union {
    struct {
        unsigned PSSBD :2;
        unsigned PSSAC :2;
        unsigned ECCPAS :3;
        unsigned ECCPASE :1;
    };
    struct {
        unsigned PSSBD0 :1;
        unsigned PSSBD1 :1;
        unsigned PSSAC0 :1;
        unsigned PSSAC1 :1;
        unsigned ECCPAS0 :1;
        unsigned ECCPAS1 :1;
        unsigned ECCPAS2 :1;
    };
} ECCP1ASbits_t;
extern volatile ECCP1ASbits_t ECCP1ASbits __attribute__((address(0xFB6)));
# 4007 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
typedef union {
    struct {
        unsigned PSSBD :2;
        unsigned PSSAC :2;
        unsigned ECCPAS :3;
        unsigned ECCPASE :1;
    };
    struct {
        unsigned PSSBD0 :1;
        unsigned PSSBD1 :1;
        unsigned PSSAC0 :1;
        unsigned PSSAC1 :1;
        unsigned ECCPAS0 :1;
        unsigned ECCPAS1 :1;
        unsigned ECCPAS2 :1;
    };
} ECCPASbits_t;
extern volatile ECCPASbits_t ECCPASbits __attribute__((address(0xFB6)));
# 4084 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned char PWM1CON __attribute__((address(0xFB7)));

__asm("PWM1CON equ 0FB7h");


extern volatile unsigned char ECCP1DEL __attribute__((address(0xFB7)));

__asm("ECCP1DEL equ 0FB7h");


typedef union {
    struct {
        unsigned PDC :7;
        unsigned PRSEN :1;
    };
    struct {
        unsigned PDC0 :1;
        unsigned PDC1 :1;
        unsigned PDC2 :1;
        unsigned PDC3 :1;
        unsigned PDC4 :1;
        unsigned PDC5 :1;
        unsigned PDC6 :1;
    };
} PWM1CONbits_t;
extern volatile PWM1CONbits_t PWM1CONbits __attribute__((address(0xFB7)));
# 4157 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
typedef union {
    struct {
        unsigned PDC :7;
        unsigned PRSEN :1;
    };
    struct {
        unsigned PDC0 :1;
        unsigned PDC1 :1;
        unsigned PDC2 :1;
        unsigned PDC3 :1;
        unsigned PDC4 :1;
        unsigned PDC5 :1;
        unsigned PDC6 :1;
    };
} ECCP1DELbits_t;
extern volatile ECCP1DELbits_t ECCP1DELbits __attribute__((address(0xFB7)));
# 4222 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned char BAUDCON __attribute__((address(0xFB8)));

__asm("BAUDCON equ 0FB8h");


extern volatile unsigned char BAUDCTL __attribute__((address(0xFB8)));

__asm("BAUDCTL equ 0FB8h");


typedef union {
    struct {
        unsigned ABDEN :1;
        unsigned WUE :1;
        unsigned :1;
        unsigned BRG16 :1;
        unsigned TXCKP :1;
        unsigned RXDTP :1;
        unsigned RCIDL :1;
        unsigned ABDOVF :1;
    };
    struct {
        unsigned :4;
        unsigned SCKP :1;
        unsigned :1;
        unsigned RCMT :1;
    };
    struct {
        unsigned :5;
        unsigned RXCKP :1;
    };
    struct {
        unsigned :1;
        unsigned W4E :1;
    };
} BAUDCONbits_t;
extern volatile BAUDCONbits_t BAUDCONbits __attribute__((address(0xFB8)));
# 4316 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
typedef union {
    struct {
        unsigned ABDEN :1;
        unsigned WUE :1;
        unsigned :1;
        unsigned BRG16 :1;
        unsigned TXCKP :1;
        unsigned RXDTP :1;
        unsigned RCIDL :1;
        unsigned ABDOVF :1;
    };
    struct {
        unsigned :4;
        unsigned SCKP :1;
        unsigned :1;
        unsigned RCMT :1;
    };
    struct {
        unsigned :5;
        unsigned RXCKP :1;
    };
    struct {
        unsigned :1;
        unsigned W4E :1;
    };
} BAUDCTLbits_t;
extern volatile BAUDCTLbits_t BAUDCTLbits __attribute__((address(0xFB8)));
# 4402 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned char CCP2CON __attribute__((address(0xFBA)));

__asm("CCP2CON equ 0FBAh");


typedef union {
    struct {
        unsigned CCP2M :4;
        unsigned DC2B :2;
    };
    struct {
        unsigned CCP2M0 :1;
        unsigned CCP2M1 :1;
        unsigned CCP2M2 :1;
        unsigned CCP2M3 :1;
        unsigned CCP2Y :1;
        unsigned CCP2X :1;
    };
    struct {
        unsigned :4;
        unsigned DC2B0 :1;
        unsigned DC2B1 :1;
    };
} CCP2CONbits_t;
extern volatile CCP2CONbits_t CCP2CONbits __attribute__((address(0xFBA)));
# 4481 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned short CCPR2 __attribute__((address(0xFBB)));

__asm("CCPR2 equ 0FBBh");




extern volatile unsigned char CCPR2L __attribute__((address(0xFBB)));

__asm("CCPR2L equ 0FBBh");




extern volatile unsigned char CCPR2H __attribute__((address(0xFBC)));

__asm("CCPR2H equ 0FBCh");




extern volatile unsigned char CCP1CON __attribute__((address(0xFBD)));

__asm("CCP1CON equ 0FBDh");


typedef union {
    struct {
        unsigned CCP1M :4;
        unsigned DC1B :2;
        unsigned P1M :2;
    };
    struct {
        unsigned CCP1M0 :1;
        unsigned CCP1M1 :1;
        unsigned CCP1M2 :1;
        unsigned CCP1M3 :1;
        unsigned CCP1Y :1;
        unsigned CCP1X :1;
        unsigned P1M0 :1;
        unsigned P1M1 :1;
    };
    struct {
        unsigned :4;
        unsigned DC1B0 :1;
        unsigned DC1B1 :1;
    };
} CCP1CONbits_t;
extern volatile CCP1CONbits_t CCP1CONbits __attribute__((address(0xFBD)));
# 4599 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned short CCPR1 __attribute__((address(0xFBE)));

__asm("CCPR1 equ 0FBEh");




extern volatile unsigned char CCPR1L __attribute__((address(0xFBE)));

__asm("CCPR1L equ 0FBEh");




extern volatile unsigned char CCPR1H __attribute__((address(0xFBF)));

__asm("CCPR1H equ 0FBFh");




extern volatile unsigned char ADCON2 __attribute__((address(0xFC0)));

__asm("ADCON2 equ 0FC0h");


typedef union {
    struct {
        unsigned ADCS :3;
        unsigned ACQT :3;
        unsigned :1;
        unsigned ADFM :1;
    };
    struct {
        unsigned ADCS0 :1;
        unsigned ADCS1 :1;
        unsigned ADCS2 :1;
        unsigned ACQT0 :1;
        unsigned ACQT1 :1;
        unsigned ACQT2 :1;
    };
} ADCON2bits_t;
extern volatile ADCON2bits_t ADCON2bits __attribute__((address(0xFC0)));
# 4691 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned char ADCON1 __attribute__((address(0xFC1)));

__asm("ADCON1 equ 0FC1h");


typedef union {
    struct {
        unsigned PCFG :4;
        unsigned VCFG :2;
    };
    struct {
        unsigned PCFG0 :1;
        unsigned PCFG1 :1;
        unsigned PCFG2 :1;
        unsigned PCFG3 :1;
        unsigned VCFG0 :1;
        unsigned VCFG1 :1;
    };
    struct {
        unsigned :3;
        unsigned CHSN3 :1;
        unsigned VCFG01 :1;
        unsigned VCFG11 :1;
    };
} ADCON1bits_t;
extern volatile ADCON1bits_t ADCON1bits __attribute__((address(0xFC1)));
# 4776 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned char ADCON0 __attribute__((address(0xFC2)));

__asm("ADCON0 equ 0FC2h");


typedef union {
    struct {
        unsigned :1;
        unsigned GO_NOT_DONE :1;
    };
    struct {
        unsigned ADON :1;
        unsigned GO_nDONE :1;
        unsigned CHS :4;
    };
    struct {
        unsigned :1;
        unsigned GO :1;
        unsigned CHS0 :1;
        unsigned CHS1 :1;
        unsigned CHS2 :1;
        unsigned CHS3 :1;
    };
    struct {
        unsigned :1;
        unsigned DONE :1;
    };
    struct {
        unsigned :1;
        unsigned NOT_DONE :1;
    };
    struct {
        unsigned :1;
        unsigned nDONE :1;
    };
    struct {
        unsigned :1;
        unsigned GO_DONE :1;
    };
    struct {
        unsigned :1;
        unsigned GODONE :1;
    };
} ADCON0bits_t;
extern volatile ADCON0bits_t ADCON0bits __attribute__((address(0xFC2)));
# 4895 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned short ADRES __attribute__((address(0xFC3)));

__asm("ADRES equ 0FC3h");




extern volatile unsigned char ADRESL __attribute__((address(0xFC3)));

__asm("ADRESL equ 0FC3h");




extern volatile unsigned char ADRESH __attribute__((address(0xFC4)));

__asm("ADRESH equ 0FC4h");




extern volatile unsigned char SSPCON2 __attribute__((address(0xFC5)));

__asm("SSPCON2 equ 0FC5h");


typedef union {
    struct {
        unsigned SEN :1;
        unsigned RSEN :1;
        unsigned PEN :1;
        unsigned RCEN :1;
        unsigned ACKEN :1;
        unsigned ACKDT :1;
        unsigned ACKSTAT :1;
        unsigned GCEN :1;
    };
    struct {
        unsigned :1;
        unsigned ADMSK1 :1;
        unsigned ADMSK2 :1;
        unsigned ADMSK3 :1;
        unsigned ADMSK4 :1;
        unsigned ADMSK5 :1;
    };
} SSPCON2bits_t;
extern volatile SSPCON2bits_t SSPCON2bits __attribute__((address(0xFC5)));
# 5011 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned char SSPCON1 __attribute__((address(0xFC6)));

__asm("SSPCON1 equ 0FC6h");


typedef union {
    struct {
        unsigned SSPM :4;
        unsigned CKP :1;
        unsigned SSPEN :1;
        unsigned SSPOV :1;
        unsigned WCOL :1;
    };
    struct {
        unsigned SSPM0 :1;
        unsigned SSPM1 :1;
        unsigned SSPM2 :1;
        unsigned SSPM3 :1;
    };
} SSPCON1bits_t;
extern volatile SSPCON1bits_t SSPCON1bits __attribute__((address(0xFC6)));
# 5081 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned char SSPSTAT __attribute__((address(0xFC7)));

__asm("SSPSTAT equ 0FC7h");


typedef union {
    struct {
        unsigned :2;
        unsigned R_NOT_W :1;
    };
    struct {
        unsigned :5;
        unsigned D_NOT_A :1;
    };
    struct {
        unsigned BF :1;
        unsigned UA :1;
        unsigned R_nW :1;
        unsigned S :1;
        unsigned P :1;
        unsigned D_nA :1;
        unsigned CKE :1;
        unsigned SMP :1;
    };
    struct {
        unsigned :2;
        unsigned R :1;
        unsigned :2;
        unsigned D :1;
    };
    struct {
        unsigned :2;
        unsigned W :1;
        unsigned :2;
        unsigned A :1;
    };
    struct {
        unsigned :2;
        unsigned nW :1;
        unsigned :2;
        unsigned nA :1;
    };
    struct {
        unsigned :2;
        unsigned R_W :1;
        unsigned :2;
        unsigned D_A :1;
    };
    struct {
        unsigned :2;
        unsigned NOT_WRITE :1;
    };
    struct {
        unsigned :5;
        unsigned NOT_ADDRESS :1;
    };
    struct {
        unsigned :2;
        unsigned nWRITE :1;
        unsigned :2;
        unsigned nADDRESS :1;
    };
    struct {
        unsigned :2;
        unsigned RW :1;
        unsigned START :1;
        unsigned STOP :1;
        unsigned DA :1;
    };
    struct {
        unsigned :2;
        unsigned NOT_W :1;
        unsigned :2;
        unsigned NOT_A :1;
    };
} SSPSTATbits_t;
extern volatile SSPSTATbits_t SSPSTATbits __attribute__((address(0xFC7)));
# 5302 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned char SSPADD __attribute__((address(0xFC8)));

__asm("SSPADD equ 0FC8h");




extern volatile unsigned char SSPBUF __attribute__((address(0xFC9)));

__asm("SSPBUF equ 0FC9h");




extern volatile unsigned char T2CON __attribute__((address(0xFCA)));

__asm("T2CON equ 0FCAh");


typedef union {
    struct {
        unsigned T2CKPS :2;
        unsigned TMR2ON :1;
        unsigned T2OUTPS :4;
    };
    struct {
        unsigned T2CKPS0 :1;
        unsigned T2CKPS1 :1;
        unsigned :1;
        unsigned T2OUTPS0 :1;
        unsigned T2OUTPS1 :1;
        unsigned T2OUTPS2 :1;
        unsigned T2OUTPS3 :1;
    };
    struct {
        unsigned :3;
        unsigned TOUTPS0 :1;
        unsigned TOUTPS1 :1;
        unsigned TOUTPS2 :1;
        unsigned TOUTPS3 :1;
    };
} T2CONbits_t;
extern volatile T2CONbits_t T2CONbits __attribute__((address(0xFCA)));
# 5414 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned char PR2 __attribute__((address(0xFCB)));

__asm("PR2 equ 0FCBh");


extern volatile unsigned char MEMCON __attribute__((address(0xFCB)));

__asm("MEMCON equ 0FCBh");


typedef union {
    struct {
        unsigned :7;
        unsigned EBDIS :1;
    };
    struct {
        unsigned :4;
        unsigned WAIT0 :1;
    };
    struct {
        unsigned :5;
        unsigned WAIT1 :1;
    };
    struct {
        unsigned WM0 :1;
    };
    struct {
        unsigned :1;
        unsigned WM1 :1;
    };
} PR2bits_t;
extern volatile PR2bits_t PR2bits __attribute__((address(0xFCB)));
# 5473 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
typedef union {
    struct {
        unsigned :7;
        unsigned EBDIS :1;
    };
    struct {
        unsigned :4;
        unsigned WAIT0 :1;
    };
    struct {
        unsigned :5;
        unsigned WAIT1 :1;
    };
    struct {
        unsigned WM0 :1;
    };
    struct {
        unsigned :1;
        unsigned WM1 :1;
    };
} MEMCONbits_t;
extern volatile MEMCONbits_t MEMCONbits __attribute__((address(0xFCB)));
# 5524 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned char TMR2 __attribute__((address(0xFCC)));

__asm("TMR2 equ 0FCCh");




extern volatile unsigned char T1CON __attribute__((address(0xFCD)));

__asm("T1CON equ 0FCDh");


typedef union {
    struct {
        unsigned :2;
        unsigned NOT_T1SYNC :1;
    };
    struct {
        unsigned TMR1ON :1;
        unsigned TMR1CS :1;
        unsigned nT1SYNC :1;
        unsigned T1OSCEN :1;
        unsigned T1CKPS :2;
        unsigned T1RUN :1;
        unsigned RD16 :1;
    };
    struct {
        unsigned :2;
        unsigned T1SYNC :1;
        unsigned :1;
        unsigned T1CKPS0 :1;
        unsigned T1CKPS1 :1;
    };
    struct {
        unsigned :3;
        unsigned SOSCEN :1;
        unsigned :3;
        unsigned T1RD16 :1;
    };
} T1CONbits_t;
extern volatile T1CONbits_t T1CONbits __attribute__((address(0xFCD)));
# 5634 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned short TMR1 __attribute__((address(0xFCE)));

__asm("TMR1 equ 0FCEh");




extern volatile unsigned char TMR1L __attribute__((address(0xFCE)));

__asm("TMR1L equ 0FCEh");




extern volatile unsigned char TMR1H __attribute__((address(0xFCF)));

__asm("TMR1H equ 0FCFh");




extern volatile unsigned char RCON __attribute__((address(0xFD0)));

__asm("RCON equ 0FD0h");


typedef union {
    struct {
        unsigned NOT_BOR :1;
    };
    struct {
        unsigned :1;
        unsigned NOT_POR :1;
    };
    struct {
        unsigned :2;
        unsigned NOT_PD :1;
    };
    struct {
        unsigned :3;
        unsigned NOT_TO :1;
    };
    struct {
        unsigned :4;
        unsigned NOT_RI :1;
    };
    struct {
        unsigned nBOR :1;
        unsigned nPOR :1;
        unsigned nPD :1;
        unsigned nTO :1;
        unsigned nRI :1;
        unsigned :1;
        unsigned SBOREN :1;
        unsigned IPEN :1;
    };
    struct {
        unsigned BOR :1;
        unsigned POR :1;
        unsigned PD :1;
        unsigned TO :1;
        unsigned RI :1;
    };
} RCONbits_t;
extern volatile RCONbits_t RCONbits __attribute__((address(0xFD0)));
# 5788 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned char WDTCON __attribute__((address(0xFD1)));

__asm("WDTCON equ 0FD1h");


typedef union {
    struct {
        unsigned SWDTEN :1;
    };
    struct {
        unsigned SWDTE :1;
    };
} WDTCONbits_t;
extern volatile WDTCONbits_t WDTCONbits __attribute__((address(0xFD1)));
# 5816 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned char HLVDCON __attribute__((address(0xFD2)));

__asm("HLVDCON equ 0FD2h");


extern volatile unsigned char LVDCON __attribute__((address(0xFD2)));

__asm("LVDCON equ 0FD2h");


typedef union {
    struct {
        unsigned HLVDL :4;
        unsigned HLVDEN :1;
        unsigned IVRST :1;
        unsigned :1;
        unsigned VDIRMAG :1;
    };
    struct {
        unsigned HLVDL0 :1;
        unsigned HLVDL1 :1;
        unsigned HLVDL2 :1;
        unsigned HLVDL3 :1;
    };
    struct {
        unsigned LVDL0 :1;
        unsigned LVDL1 :1;
        unsigned LVDL2 :1;
        unsigned LVDL3 :1;
        unsigned LVDEN :1;
        unsigned IRVST :1;
    };
    struct {
        unsigned LVV0 :1;
        unsigned LVV1 :1;
        unsigned LVV2 :1;
        unsigned LVV3 :1;
        unsigned :1;
        unsigned BGST :1;
    };
} HLVDCONbits_t;
extern volatile HLVDCONbits_t HLVDCONbits __attribute__((address(0xFD2)));
# 5955 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
typedef union {
    struct {
        unsigned HLVDL :4;
        unsigned HLVDEN :1;
        unsigned IVRST :1;
        unsigned :1;
        unsigned VDIRMAG :1;
    };
    struct {
        unsigned HLVDL0 :1;
        unsigned HLVDL1 :1;
        unsigned HLVDL2 :1;
        unsigned HLVDL3 :1;
    };
    struct {
        unsigned LVDL0 :1;
        unsigned LVDL1 :1;
        unsigned LVDL2 :1;
        unsigned LVDL3 :1;
        unsigned LVDEN :1;
        unsigned IRVST :1;
    };
    struct {
        unsigned LVV0 :1;
        unsigned LVV1 :1;
        unsigned LVV2 :1;
        unsigned LVV3 :1;
        unsigned :1;
        unsigned BGST :1;
    };
} LVDCONbits_t;
extern volatile LVDCONbits_t LVDCONbits __attribute__((address(0xFD2)));
# 6086 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned char OSCCON __attribute__((address(0xFD3)));

__asm("OSCCON equ 0FD3h");


typedef union {
    struct {
        unsigned SCS :2;
        unsigned IOFS :1;
        unsigned OSTS :1;
        unsigned IRCF :3;
        unsigned IDLEN :1;
    };
    struct {
        unsigned SCS0 :1;
        unsigned SCS1 :1;
        unsigned FLTS :1;
        unsigned :1;
        unsigned IRCF0 :1;
        unsigned IRCF1 :1;
        unsigned IRCF2 :1;
    };
} OSCCONbits_t;
extern volatile OSCCONbits_t OSCCONbits __attribute__((address(0xFD3)));
# 6169 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned char T0CON __attribute__((address(0xFD5)));

__asm("T0CON equ 0FD5h");


typedef union {
    struct {
        unsigned T0PS :3;
        unsigned PSA :1;
        unsigned T0SE :1;
        unsigned T0CS :1;
        unsigned T08BIT :1;
        unsigned TMR0ON :1;
    };
    struct {
        unsigned T0PS0 :1;
        unsigned T0PS1 :1;
        unsigned T0PS2 :1;
        unsigned T0PS3 :1;
        unsigned :2;
        unsigned T016BIT :1;
    };
} T0CONbits_t;
extern volatile T0CONbits_t T0CONbits __attribute__((address(0xFD5)));
# 6252 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned short TMR0 __attribute__((address(0xFD6)));

__asm("TMR0 equ 0FD6h");




extern volatile unsigned char TMR0L __attribute__((address(0xFD6)));

__asm("TMR0L equ 0FD6h");




extern volatile unsigned char TMR0H __attribute__((address(0xFD7)));

__asm("TMR0H equ 0FD7h");




extern volatile unsigned char STATUS __attribute__((address(0xFD8)));

__asm("STATUS equ 0FD8h");


typedef union {
    struct {
        unsigned C :1;
        unsigned DC :1;
        unsigned Z :1;
        unsigned OV :1;
        unsigned N :1;
    };
    struct {
        unsigned CARRY :1;
        unsigned :1;
        unsigned ZERO :1;
        unsigned OVERFLOW :1;
        unsigned NEGATIVE :1;
    };
} STATUSbits_t;
extern volatile STATUSbits_t STATUSbits __attribute__((address(0xFD8)));
# 6344 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned short FSR2 __attribute__((address(0xFD9)));

__asm("FSR2 equ 0FD9h");




extern volatile unsigned char FSR2L __attribute__((address(0xFD9)));

__asm("FSR2L equ 0FD9h");




extern volatile unsigned char FSR2H __attribute__((address(0xFDA)));

__asm("FSR2H equ 0FDAh");




extern volatile unsigned char PLUSW2 __attribute__((address(0xFDB)));

__asm("PLUSW2 equ 0FDBh");




extern volatile unsigned char PREINC2 __attribute__((address(0xFDC)));

__asm("PREINC2 equ 0FDCh");




extern volatile unsigned char POSTDEC2 __attribute__((address(0xFDD)));

__asm("POSTDEC2 equ 0FDDh");




extern volatile unsigned char POSTINC2 __attribute__((address(0xFDE)));

__asm("POSTINC2 equ 0FDEh");




extern volatile unsigned char INDF2 __attribute__((address(0xFDF)));

__asm("INDF2 equ 0FDFh");




extern volatile unsigned char BSR __attribute__((address(0xFE0)));

__asm("BSR equ 0FE0h");




extern volatile unsigned short FSR1 __attribute__((address(0xFE1)));

__asm("FSR1 equ 0FE1h");




extern volatile unsigned char FSR1L __attribute__((address(0xFE1)));

__asm("FSR1L equ 0FE1h");




extern volatile unsigned char FSR1H __attribute__((address(0xFE2)));

__asm("FSR1H equ 0FE2h");




extern volatile unsigned char PLUSW1 __attribute__((address(0xFE3)));

__asm("PLUSW1 equ 0FE3h");




extern volatile unsigned char PREINC1 __attribute__((address(0xFE4)));

__asm("PREINC1 equ 0FE4h");




extern volatile unsigned char POSTDEC1 __attribute__((address(0xFE5)));

__asm("POSTDEC1 equ 0FE5h");




extern volatile unsigned char POSTINC1 __attribute__((address(0xFE6)));

__asm("POSTINC1 equ 0FE6h");




extern volatile unsigned char INDF1 __attribute__((address(0xFE7)));

__asm("INDF1 equ 0FE7h");




extern volatile unsigned char WREG __attribute__((address(0xFE8)));

__asm("WREG equ 0FE8h");
# 6475 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned short FSR0 __attribute__((address(0xFE9)));

__asm("FSR0 equ 0FE9h");




extern volatile unsigned char FSR0L __attribute__((address(0xFE9)));

__asm("FSR0L equ 0FE9h");




extern volatile unsigned char FSR0H __attribute__((address(0xFEA)));

__asm("FSR0H equ 0FEAh");




extern volatile unsigned char PLUSW0 __attribute__((address(0xFEB)));

__asm("PLUSW0 equ 0FEBh");




extern volatile unsigned char PREINC0 __attribute__((address(0xFEC)));

__asm("PREINC0 equ 0FECh");




extern volatile unsigned char POSTDEC0 __attribute__((address(0xFED)));

__asm("POSTDEC0 equ 0FEDh");




extern volatile unsigned char POSTINC0 __attribute__((address(0xFEE)));

__asm("POSTINC0 equ 0FEEh");




extern volatile unsigned char INDF0 __attribute__((address(0xFEF)));

__asm("INDF0 equ 0FEFh");




extern volatile unsigned char INTCON3 __attribute__((address(0xFF0)));

__asm("INTCON3 equ 0FF0h");


typedef union {
    struct {
        unsigned INT1IF :1;
        unsigned INT2IF :1;
        unsigned :1;
        unsigned INT1IE :1;
        unsigned INT2IE :1;
        unsigned :1;
        unsigned INT1IP :1;
        unsigned INT2IP :1;
    };
    struct {
        unsigned INT1F :1;
        unsigned INT2F :1;
        unsigned :1;
        unsigned INT1E :1;
        unsigned INT2E :1;
        unsigned :1;
        unsigned INT1P :1;
        unsigned INT2P :1;
    };
} INTCON3bits_t;
extern volatile INTCON3bits_t INTCON3bits __attribute__((address(0xFF0)));
# 6623 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned char INTCON2 __attribute__((address(0xFF1)));

__asm("INTCON2 equ 0FF1h");


typedef union {
    struct {
        unsigned :7;
        unsigned NOT_RBPU :1;
    };
    struct {
        unsigned RBIP :1;
        unsigned :1;
        unsigned TMR0IP :1;
        unsigned :1;
        unsigned INTEDG2 :1;
        unsigned INTEDG1 :1;
        unsigned INTEDG0 :1;
        unsigned nRBPU :1;
    };
    struct {
        unsigned :7;
        unsigned RBPU :1;
    };
} INTCON2bits_t;
extern volatile INTCON2bits_t INTCON2bits __attribute__((address(0xFF1)));
# 6693 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned char INTCON __attribute__((address(0xFF2)));

__asm("INTCON equ 0FF2h");


typedef union {
    struct {
        unsigned RBIF :1;
        unsigned INT0IF :1;
        unsigned TMR0IF :1;
        unsigned RBIE :1;
        unsigned INT0IE :1;
        unsigned TMR0IE :1;
        unsigned PEIE_GIEL :1;
        unsigned GIE_GIEH :1;
    };
    struct {
        unsigned :1;
        unsigned INT0F :1;
        unsigned T0IF :1;
        unsigned :1;
        unsigned INT0E :1;
        unsigned T0IE :1;
        unsigned PEIE :1;
        unsigned GIE :1;
    };
    struct {
        unsigned :6;
        unsigned GIEL :1;
        unsigned GIEH :1;
    };
} INTCONbits_t;
extern volatile INTCONbits_t INTCONbits __attribute__((address(0xFF2)));
# 6810 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile unsigned short PROD __attribute__((address(0xFF3)));

__asm("PROD equ 0FF3h");




extern volatile unsigned char PRODL __attribute__((address(0xFF3)));

__asm("PRODL equ 0FF3h");




extern volatile unsigned char PRODH __attribute__((address(0xFF4)));

__asm("PRODH equ 0FF4h");




extern volatile unsigned char TABLAT __attribute__((address(0xFF5)));

__asm("TABLAT equ 0FF5h");





extern volatile __uint24 TBLPTR __attribute__((address(0xFF6)));


__asm("TBLPTR equ 0FF6h");




extern volatile unsigned char TBLPTRL __attribute__((address(0xFF6)));

__asm("TBLPTRL equ 0FF6h");




extern volatile unsigned char TBLPTRH __attribute__((address(0xFF7)));

__asm("TBLPTRH equ 0FF7h");




extern volatile unsigned char TBLPTRU __attribute__((address(0xFF8)));

__asm("TBLPTRU equ 0FF8h");





extern volatile __uint24 PCLAT __attribute__((address(0xFF9)));


__asm("PCLAT equ 0FF9h");



extern volatile __uint24 PC __attribute__((address(0xFF9)));


__asm("PC equ 0FF9h");




extern volatile unsigned char PCL __attribute__((address(0xFF9)));

__asm("PCL equ 0FF9h");




extern volatile unsigned char PCLATH __attribute__((address(0xFFA)));

__asm("PCLATH equ 0FFAh");




extern volatile unsigned char PCLATU __attribute__((address(0xFFB)));

__asm("PCLATU equ 0FFBh");




extern volatile unsigned char STKPTR __attribute__((address(0xFFC)));

__asm("STKPTR equ 0FFCh");


typedef union {
    struct {
        unsigned STKPTR :5;
        unsigned :1;
        unsigned STKUNF :1;
        unsigned STKFUL :1;
    };
    struct {
        unsigned SP0 :1;
        unsigned SP1 :1;
        unsigned SP2 :1;
        unsigned SP3 :1;
        unsigned SP4 :1;
        unsigned :2;
        unsigned STKOVF :1;
    };
} STKPTRbits_t;
extern volatile STKPTRbits_t STKPTRbits __attribute__((address(0xFFC)));
# 6978 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile __uint24 TOS __attribute__((address(0xFFD)));


__asm("TOS equ 0FFDh");




extern volatile unsigned char TOSL __attribute__((address(0xFFD)));

__asm("TOSL equ 0FFDh");




extern volatile unsigned char TOSH __attribute__((address(0xFFE)));

__asm("TOSH equ 0FFEh");




extern volatile unsigned char TOSU __attribute__((address(0xFFF)));

__asm("TOSU equ 0FFFh");
# 7017 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\proc\\pic18f4520.h" 3
extern volatile __bit ABDEN __attribute__((address(0x7DC0)));


extern volatile __bit ABDOVF __attribute__((address(0x7DC7)));


extern volatile __bit ACKDT __attribute__((address(0x7E2D)));


extern volatile __bit ACKEN __attribute__((address(0x7E2C)));


extern volatile __bit ACKSTAT __attribute__((address(0x7E2E)));


extern volatile __bit ACQT0 __attribute__((address(0x7E03)));


extern volatile __bit ACQT1 __attribute__((address(0x7E04)));


extern volatile __bit ACQT2 __attribute__((address(0x7E05)));


extern volatile __bit ADCS0 __attribute__((address(0x7E00)));


extern volatile __bit ADCS1 __attribute__((address(0x7E01)));


extern volatile __bit ADCS2 __attribute__((address(0x7E02)));


extern volatile __bit ADDEN __attribute__((address(0x7D5B)));


extern volatile __bit ADEN __attribute__((address(0x7D5B)));


extern volatile __bit ADFM __attribute__((address(0x7E07)));


extern volatile __bit ADIE __attribute__((address(0x7CEE)));


extern volatile __bit ADIF __attribute__((address(0x7CF6)));


extern volatile __bit ADIP __attribute__((address(0x7CFE)));


extern volatile __bit ADMSK1 __attribute__((address(0x7E29)));


extern volatile __bit ADMSK2 __attribute__((address(0x7E2A)));


extern volatile __bit ADMSK3 __attribute__((address(0x7E2B)));


extern volatile __bit ADMSK4 __attribute__((address(0x7E2C)));


extern volatile __bit ADMSK5 __attribute__((address(0x7E2D)));


extern volatile __bit ADON __attribute__((address(0x7E10)));


extern volatile __bit AN0 __attribute__((address(0x7C00)));


extern volatile __bit AN1 __attribute__((address(0x7C01)));


extern volatile __bit AN10 __attribute__((address(0x7C09)));


extern volatile __bit AN11 __attribute__((address(0x7C0C)));


extern volatile __bit AN12 __attribute__((address(0x7C08)));


extern volatile __bit AN2 __attribute__((address(0x7C02)));


extern volatile __bit AN3 __attribute__((address(0x7C03)));


extern volatile __bit AN4 __attribute__((address(0x7C05)));


extern volatile __bit AN5 __attribute__((address(0x7C20)));


extern volatile __bit AN6 __attribute__((address(0x7C21)));


extern volatile __bit AN7 __attribute__((address(0x7C22)));


extern volatile __bit AN8 __attribute__((address(0x7C0A)));


extern volatile __bit AN9 __attribute__((address(0x7C0B)));


extern volatile __bit BCLIE __attribute__((address(0x7D03)));


extern volatile __bit BCLIF __attribute__((address(0x7D0B)));


extern volatile __bit BCLIP __attribute__((address(0x7D13)));


extern volatile __bit BF __attribute__((address(0x7E38)));


extern volatile __bit BGST __attribute__((address(0x7E95)));


extern volatile __bit BOR __attribute__((address(0x7E80)));


extern volatile __bit BRG16 __attribute__((address(0x7DC3)));


extern volatile __bit BRGH __attribute__((address(0x7D62)));


extern volatile __bit BRGH1 __attribute__((address(0x7D62)));


extern volatile __bit C1INV __attribute__((address(0x7DA4)));


extern volatile __bit __attribute__((__deprecated__)) C1OUT __attribute__((address(0x7DA6)));


extern volatile __bit C2INV __attribute__((address(0x7DA5)));


extern volatile __bit __attribute__((__deprecated__)) C2OUT __attribute__((address(0x7DA7)));


extern volatile __bit CARRY __attribute__((address(0x7EC0)));


extern volatile __bit CCP1 __attribute__((address(0x7C12)));


extern volatile __bit CCP10 __attribute__((address(0x7C22)));


extern volatile __bit CCP1IE __attribute__((address(0x7CEA)));


extern volatile __bit CCP1IF __attribute__((address(0x7CF2)));


extern volatile __bit CCP1IP __attribute__((address(0x7CFA)));


extern volatile __bit CCP1M0 __attribute__((address(0x7DE8)));


extern volatile __bit CCP1M1 __attribute__((address(0x7DE9)));


extern volatile __bit CCP1M2 __attribute__((address(0x7DEA)));


extern volatile __bit CCP1M3 __attribute__((address(0x7DEB)));


extern volatile __bit CCP1X __attribute__((address(0x7DED)));


extern volatile __bit CCP1Y __attribute__((address(0x7DEC)));


extern volatile __bit CCP2IE __attribute__((address(0x7D00)));


extern volatile __bit CCP2IF __attribute__((address(0x7D08)));


extern volatile __bit CCP2IP __attribute__((address(0x7D10)));


extern volatile __bit CCP2M0 __attribute__((address(0x7DD0)));


extern volatile __bit CCP2M1 __attribute__((address(0x7DD1)));


extern volatile __bit CCP2M2 __attribute__((address(0x7DD2)));


extern volatile __bit CCP2M3 __attribute__((address(0x7DD3)));


extern volatile __bit CCP2X __attribute__((address(0x7DD5)));


extern volatile __bit CCP2Y __attribute__((address(0x7DD4)));


extern volatile __bit CCP2_PA2 __attribute__((address(0x7C0B)));


extern volatile __bit CCP9E __attribute__((address(0x7C23)));


extern volatile __bit CFGS __attribute__((address(0x7D36)));


extern volatile __bit CHS0 __attribute__((address(0x7E12)));


extern volatile __bit CHS1 __attribute__((address(0x7E13)));


extern volatile __bit CHS2 __attribute__((address(0x7E14)));


extern volatile __bit CHS3 __attribute__((address(0x7E15)));


extern volatile __bit CHSN3 __attribute__((address(0x7E0B)));


extern volatile __bit CIS __attribute__((address(0x7DA3)));


extern volatile __bit CK __attribute__((address(0x7C16)));


extern volatile __bit CKE __attribute__((address(0x7E3E)));


extern volatile __bit CKP __attribute__((address(0x7E34)));


extern volatile __bit CLKI __attribute__((address(0x7C07)));


extern volatile __bit CLKO __attribute__((address(0x7C06)));


extern volatile __bit CM0 __attribute__((address(0x7DA0)));


extern volatile __bit CM1 __attribute__((address(0x7DA1)));


extern volatile __bit CM2 __attribute__((address(0x7DA2)));


extern volatile __bit CMEN0 __attribute__((address(0x7DA0)));


extern volatile __bit CMEN1 __attribute__((address(0x7DA1)));


extern volatile __bit CMEN2 __attribute__((address(0x7DA2)));


extern volatile __bit CMIE __attribute__((address(0x7D06)));


extern volatile __bit CMIF __attribute__((address(0x7D0E)));


extern volatile __bit CMIP __attribute__((address(0x7D16)));


extern volatile __bit CREN __attribute__((address(0x7D5C)));


extern volatile __bit CS __attribute__((address(0x7C22)));


extern volatile __bit CSRC __attribute__((address(0x7D67)));


extern volatile __bit CSRC1 __attribute__((address(0x7D67)));


extern volatile __bit CVR0 __attribute__((address(0x7DA8)));


extern volatile __bit CVR1 __attribute__((address(0x7DA9)));


extern volatile __bit CVR2 __attribute__((address(0x7DAA)));


extern volatile __bit CVR3 __attribute__((address(0x7DAB)));


extern volatile __bit CVREF __attribute__((address(0x7C02)));


extern volatile __bit CVREN __attribute__((address(0x7DAF)));


extern volatile __bit CVROE __attribute__((address(0x7DAE)));


extern volatile __bit CVROEN __attribute__((address(0x7DAE)));


extern volatile __bit CVRR __attribute__((address(0x7DAD)));


extern volatile __bit CVRSS __attribute__((address(0x7DAC)));


extern volatile __bit DA __attribute__((address(0x7E3D)));


extern volatile __bit DC __attribute__((address(0x7EC1)));


extern volatile __bit DC1B0 __attribute__((address(0x7DEC)));


extern volatile __bit DC1B1 __attribute__((address(0x7DED)));


extern volatile __bit DC2B0 __attribute__((address(0x7DD4)));


extern volatile __bit DC2B1 __attribute__((address(0x7DD5)));


extern volatile __bit DONE __attribute__((address(0x7E11)));


extern volatile __bit DT __attribute__((address(0x7C17)));


extern volatile __bit D_A __attribute__((address(0x7E3D)));


extern volatile __bit D_NOT_A __attribute__((address(0x7E3D)));


extern volatile __bit D_nA __attribute__((address(0x7E3D)));


extern volatile __bit EBDIS __attribute__((address(0x7E5F)));


extern volatile __bit ECCPAS0 __attribute__((address(0x7DB4)));


extern volatile __bit ECCPAS1 __attribute__((address(0x7DB5)));


extern volatile __bit ECCPAS2 __attribute__((address(0x7DB6)));


extern volatile __bit ECCPASE __attribute__((address(0x7DB7)));


extern volatile __bit EEFS __attribute__((address(0x7D36)));


extern volatile __bit EEIE __attribute__((address(0x7D04)));


extern volatile __bit EEIF __attribute__((address(0x7D0C)));


extern volatile __bit EEIP __attribute__((address(0x7D14)));


extern volatile __bit EEPGD __attribute__((address(0x7D37)));


extern volatile __bit FERR __attribute__((address(0x7D5A)));


extern volatile __bit FLT0 __attribute__((address(0x7C08)));


extern volatile __bit FLTS __attribute__((address(0x7E9A)));


extern volatile __bit FREE __attribute__((address(0x7D34)));


extern volatile __bit GCEN __attribute__((address(0x7E2F)));


extern volatile __bit GIE __attribute__((address(0x7F97)));


extern volatile __bit GIEH __attribute__((address(0x7F97)));


extern volatile __bit GIEL __attribute__((address(0x7F96)));


extern volatile __bit GIE_GIEH __attribute__((address(0x7F97)));


extern volatile __bit GO __attribute__((address(0x7E11)));


extern volatile __bit GODONE __attribute__((address(0x7E11)));


extern volatile __bit GO_DONE __attribute__((address(0x7E11)));


extern volatile __bit GO_NOT_DONE __attribute__((address(0x7E11)));


extern volatile __bit GO_nDONE __attribute__((address(0x7E11)));


extern volatile __bit HLVDEN __attribute__((address(0x7E94)));


extern volatile __bit HLVDIE __attribute__((address(0x7D02)));


extern volatile __bit HLVDIF __attribute__((address(0x7D0A)));


extern volatile __bit HLVDIN __attribute__((address(0x7C05)));


extern volatile __bit HLVDIP __attribute__((address(0x7D12)));


extern volatile __bit HLVDL0 __attribute__((address(0x7E90)));


extern volatile __bit HLVDL1 __attribute__((address(0x7E91)));


extern volatile __bit HLVDL2 __attribute__((address(0x7E92)));


extern volatile __bit HLVDL3 __attribute__((address(0x7E93)));


extern volatile __bit IBF __attribute__((address(0x7CB7)));


extern volatile __bit IBOV __attribute__((address(0x7CB5)));


extern volatile __bit IDLEN __attribute__((address(0x7E9F)));


extern volatile __bit INT0 __attribute__((address(0x7C08)));


extern volatile __bit INT0E __attribute__((address(0x7F94)));


extern volatile __bit INT0F __attribute__((address(0x7F91)));


extern volatile __bit INT0IE __attribute__((address(0x7F94)));


extern volatile __bit INT0IF __attribute__((address(0x7F91)));


extern volatile __bit INT1 __attribute__((address(0x7C09)));


extern volatile __bit INT1E __attribute__((address(0x7F83)));


extern volatile __bit INT1F __attribute__((address(0x7F80)));


extern volatile __bit INT1IE __attribute__((address(0x7F83)));


extern volatile __bit INT1IF __attribute__((address(0x7F80)));


extern volatile __bit INT1IP __attribute__((address(0x7F86)));


extern volatile __bit INT1P __attribute__((address(0x7F86)));


extern volatile __bit INT2 __attribute__((address(0x7C0A)));


extern volatile __bit INT2E __attribute__((address(0x7F84)));


extern volatile __bit INT2F __attribute__((address(0x7F81)));


extern volatile __bit INT2IE __attribute__((address(0x7F84)));


extern volatile __bit INT2IF __attribute__((address(0x7F81)));


extern volatile __bit INT2IP __attribute__((address(0x7F87)));


extern volatile __bit INT2P __attribute__((address(0x7F87)));


extern volatile __bit INTEDG0 __attribute__((address(0x7F8E)));


extern volatile __bit INTEDG1 __attribute__((address(0x7F8D)));


extern volatile __bit INTEDG2 __attribute__((address(0x7F8C)));


extern volatile __bit INTSRC __attribute__((address(0x7CDF)));


extern volatile __bit IOFS __attribute__((address(0x7E9A)));


extern volatile __bit IPEN __attribute__((address(0x7E87)));


extern volatile __bit IRCF0 __attribute__((address(0x7E9C)));


extern volatile __bit IRCF1 __attribute__((address(0x7E9D)));


extern volatile __bit IRCF2 __attribute__((address(0x7E9E)));


extern volatile __bit IRVST __attribute__((address(0x7E95)));


extern volatile __bit IVRST __attribute__((address(0x7E95)));


extern volatile __bit KBI0 __attribute__((address(0x7C0C)));


extern volatile __bit KBI1 __attribute__((address(0x7C0D)));


extern volatile __bit KBI2 __attribute__((address(0x7C0E)));


extern volatile __bit KBI3 __attribute__((address(0x7C0F)));


extern volatile __bit LA0 __attribute__((address(0x7C48)));


extern volatile __bit LA1 __attribute__((address(0x7C49)));


extern volatile __bit LA2 __attribute__((address(0x7C4A)));


extern volatile __bit LA3 __attribute__((address(0x7C4B)));


extern volatile __bit LA4 __attribute__((address(0x7C4C)));


extern volatile __bit LA5 __attribute__((address(0x7C4D)));


extern volatile __bit LA6 __attribute__((address(0x7C4E)));


extern volatile __bit LA7 __attribute__((address(0x7C4F)));


extern volatile __bit LATA0 __attribute__((address(0x7C48)));


extern volatile __bit LATA1 __attribute__((address(0x7C49)));


extern volatile __bit LATA2 __attribute__((address(0x7C4A)));


extern volatile __bit LATA3 __attribute__((address(0x7C4B)));


extern volatile __bit LATA4 __attribute__((address(0x7C4C)));


extern volatile __bit LATA5 __attribute__((address(0x7C4D)));


extern volatile __bit LATA6 __attribute__((address(0x7C4E)));


extern volatile __bit LATA7 __attribute__((address(0x7C4F)));


extern volatile __bit LATB0 __attribute__((address(0x7C50)));


extern volatile __bit LATB1 __attribute__((address(0x7C51)));


extern volatile __bit LATB2 __attribute__((address(0x7C52)));


extern volatile __bit LATB3 __attribute__((address(0x7C53)));


extern volatile __bit LATB4 __attribute__((address(0x7C54)));


extern volatile __bit LATB5 __attribute__((address(0x7C55)));


extern volatile __bit LATB6 __attribute__((address(0x7C56)));


extern volatile __bit LATB7 __attribute__((address(0x7C57)));


extern volatile __bit LATC0 __attribute__((address(0x7C58)));


extern volatile __bit LATC1 __attribute__((address(0x7C59)));


extern volatile __bit LATC2 __attribute__((address(0x7C5A)));


extern volatile __bit LATC3 __attribute__((address(0x7C5B)));


extern volatile __bit LATC4 __attribute__((address(0x7C5C)));


extern volatile __bit LATC5 __attribute__((address(0x7C5D)));


extern volatile __bit LATC6 __attribute__((address(0x7C5E)));


extern volatile __bit LATC7 __attribute__((address(0x7C5F)));


extern volatile __bit LATD0 __attribute__((address(0x7C60)));


extern volatile __bit LATD1 __attribute__((address(0x7C61)));


extern volatile __bit LATD2 __attribute__((address(0x7C62)));


extern volatile __bit LATD3 __attribute__((address(0x7C63)));


extern volatile __bit LATD4 __attribute__((address(0x7C64)));


extern volatile __bit LATD5 __attribute__((address(0x7C65)));


extern volatile __bit LATD6 __attribute__((address(0x7C66)));


extern volatile __bit LATD7 __attribute__((address(0x7C67)));


extern volatile __bit LATE0 __attribute__((address(0x7C68)));


extern volatile __bit LATE1 __attribute__((address(0x7C69)));


extern volatile __bit LATE2 __attribute__((address(0x7C6A)));


extern volatile __bit LB0 __attribute__((address(0x7C50)));


extern volatile __bit LB1 __attribute__((address(0x7C51)));


extern volatile __bit LB2 __attribute__((address(0x7C52)));


extern volatile __bit LB3 __attribute__((address(0x7C53)));


extern volatile __bit LB4 __attribute__((address(0x7C54)));


extern volatile __bit LB5 __attribute__((address(0x7C55)));


extern volatile __bit LB6 __attribute__((address(0x7C56)));


extern volatile __bit LB7 __attribute__((address(0x7C57)));


extern volatile __bit LC0 __attribute__((address(0x7C58)));


extern volatile __bit LC1 __attribute__((address(0x7C59)));


extern volatile __bit LC2 __attribute__((address(0x7C5A)));


extern volatile __bit LC3 __attribute__((address(0x7C5B)));


extern volatile __bit LC4 __attribute__((address(0x7C5C)));


extern volatile __bit LC5 __attribute__((address(0x7C5D)));


extern volatile __bit LC6 __attribute__((address(0x7C5E)));


extern volatile __bit LC7 __attribute__((address(0x7C5F)));


extern volatile __bit LD0 __attribute__((address(0x7C60)));


extern volatile __bit LD1 __attribute__((address(0x7C61)));


extern volatile __bit LD2 __attribute__((address(0x7C62)));


extern volatile __bit LD3 __attribute__((address(0x7C63)));


extern volatile __bit LD4 __attribute__((address(0x7C64)));


extern volatile __bit LD5 __attribute__((address(0x7C65)));


extern volatile __bit LD6 __attribute__((address(0x7C66)));


extern volatile __bit LD7 __attribute__((address(0x7C67)));


extern volatile __bit LE0 __attribute__((address(0x7C68)));


extern volatile __bit LE1 __attribute__((address(0x7C69)));


extern volatile __bit LE2 __attribute__((address(0x7C6A)));


extern volatile __bit LVDEN __attribute__((address(0x7E94)));


extern volatile __bit LVDIE __attribute__((address(0x7D02)));


extern volatile __bit LVDIF __attribute__((address(0x7D0A)));


extern volatile __bit LVDIN __attribute__((address(0x7C05)));


extern volatile __bit LVDIP __attribute__((address(0x7D12)));


extern volatile __bit LVDL0 __attribute__((address(0x7E90)));


extern volatile __bit LVDL1 __attribute__((address(0x7E91)));


extern volatile __bit LVDL2 __attribute__((address(0x7E92)));


extern volatile __bit LVDL3 __attribute__((address(0x7E93)));


extern volatile __bit LVV0 __attribute__((address(0x7E90)));


extern volatile __bit LVV1 __attribute__((address(0x7E91)));


extern volatile __bit LVV2 __attribute__((address(0x7E92)));


extern volatile __bit LVV3 __attribute__((address(0x7E93)));


extern volatile __bit MCLR __attribute__((address(0x7C23)));


extern volatile __bit NEGATIVE __attribute__((address(0x7EC4)));


extern volatile __bit NOT_A __attribute__((address(0x7E3D)));


extern volatile __bit NOT_ADDRESS __attribute__((address(0x7E3D)));


extern volatile __bit NOT_BOR __attribute__((address(0x7E80)));


extern volatile __bit NOT_CS __attribute__((address(0x7C22)));


extern volatile __bit NOT_DONE __attribute__((address(0x7E11)));


extern volatile __bit NOT_MCLR __attribute__((address(0x7C23)));


extern volatile __bit NOT_PD __attribute__((address(0x7E82)));


extern volatile __bit NOT_POR __attribute__((address(0x7E81)));


extern volatile __bit NOT_RBPU __attribute__((address(0x7F8F)));


extern volatile __bit NOT_RD __attribute__((address(0x7C20)));


extern volatile __bit NOT_RI __attribute__((address(0x7E84)));


extern volatile __bit NOT_SS __attribute__((address(0x7C05)));


extern volatile __bit NOT_T1SYNC __attribute__((address(0x7E6A)));


extern volatile __bit NOT_T3SYNC __attribute__((address(0x7D8A)));


extern volatile __bit NOT_TO __attribute__((address(0x7E83)));


extern volatile __bit NOT_W __attribute__((address(0x7E3A)));


extern volatile __bit NOT_WR __attribute__((address(0x7C21)));


extern volatile __bit NOT_WRITE __attribute__((address(0x7E3A)));


extern volatile __bit OBF __attribute__((address(0x7CB6)));


extern volatile __bit OERR __attribute__((address(0x7D59)));


extern volatile __bit OSC1 __attribute__((address(0x7C07)));


extern volatile __bit OSC2 __attribute__((address(0x7C06)));


extern volatile __bit OSCFIE __attribute__((address(0x7D07)));


extern volatile __bit OSCFIF __attribute__((address(0x7D0F)));


extern volatile __bit OSCFIP __attribute__((address(0x7D17)));


extern volatile __bit OSTS __attribute__((address(0x7E9B)));


extern volatile __bit OV __attribute__((address(0x7EC3)));


extern volatile __bit OVERFLOW __attribute__((address(0x7EC3)));


extern volatile __bit P1A __attribute__((address(0x7C12)));


extern volatile __bit P1B __attribute__((address(0x7C1D)));


extern volatile __bit P1C __attribute__((address(0x7C1E)));


extern volatile __bit P1D __attribute__((address(0x7C1F)));


extern volatile __bit P1M0 __attribute__((address(0x7DEE)));


extern volatile __bit P1M1 __attribute__((address(0x7DEF)));


extern volatile __bit PA1 __attribute__((address(0x7C12)));


extern volatile __bit PA2 __attribute__((address(0x7C11)));


extern volatile __bit PB2 __attribute__((address(0x7C22)));


extern volatile __bit PC2 __attribute__((address(0x7C21)));


extern volatile __bit PC3E __attribute__((address(0x7C23)));


extern volatile __bit PCFG0 __attribute__((address(0x7E08)));


extern volatile __bit PCFG1 __attribute__((address(0x7E09)));


extern volatile __bit PCFG2 __attribute__((address(0x7E0A)));


extern volatile __bit PCFG3 __attribute__((address(0x7E0B)));


extern volatile __bit PD __attribute__((address(0x7E82)));


extern volatile __bit PD2 __attribute__((address(0x7C20)));


extern volatile __bit PDC0 __attribute__((address(0x7DB8)));


extern volatile __bit PDC1 __attribute__((address(0x7DB9)));


extern volatile __bit PDC2 __attribute__((address(0x7DBA)));


extern volatile __bit PDC3 __attribute__((address(0x7DBB)));


extern volatile __bit PDC4 __attribute__((address(0x7DBC)));


extern volatile __bit PDC5 __attribute__((address(0x7DBD)));


extern volatile __bit PDC6 __attribute__((address(0x7DBE)));


extern volatile __bit PEIE __attribute__((address(0x7F96)));


extern volatile __bit PEIE_GIEL __attribute__((address(0x7F96)));


extern volatile __bit PEN __attribute__((address(0x7E2A)));


extern volatile __bit PGC __attribute__((address(0x7C0E)));


extern volatile __bit PGD __attribute__((address(0x7C0F)));


extern volatile __bit PGM __attribute__((address(0x7C0D)));


extern volatile __bit PLLEN __attribute__((address(0x7CDE)));


extern volatile __bit POR __attribute__((address(0x7E81)));


extern volatile __bit PRSEN __attribute__((address(0x7DBF)));


extern volatile __bit PSA __attribute__((address(0x7EAB)));


extern volatile __bit PSP0 __attribute__((address(0x7C18)));


extern volatile __bit PSP1 __attribute__((address(0x7C19)));


extern volatile __bit PSP2 __attribute__((address(0x7C1A)));


extern volatile __bit PSP3 __attribute__((address(0x7C1B)));


extern volatile __bit PSP4 __attribute__((address(0x7C1C)));


extern volatile __bit PSP5 __attribute__((address(0x7C1D)));


extern volatile __bit PSP6 __attribute__((address(0x7C1E)));


extern volatile __bit PSP7 __attribute__((address(0x7C1F)));


extern volatile __bit PSPIE __attribute__((address(0x7CEF)));


extern volatile __bit PSPIF __attribute__((address(0x7CF7)));


extern volatile __bit PSPIP __attribute__((address(0x7CFF)));


extern volatile __bit PSPMODE __attribute__((address(0x7CB4)));


extern volatile __bit PSSAC0 __attribute__((address(0x7DB2)));


extern volatile __bit PSSAC1 __attribute__((address(0x7DB3)));


extern volatile __bit PSSBD0 __attribute__((address(0x7DB0)));


extern volatile __bit PSSBD1 __attribute__((address(0x7DB1)));


extern volatile __bit __attribute__((__deprecated__)) RA0 __attribute__((address(0x7C00)));


extern volatile __bit __attribute__((__deprecated__)) RA1 __attribute__((address(0x7C01)));


extern volatile __bit __attribute__((__deprecated__)) RA2 __attribute__((address(0x7C02)));


extern volatile __bit __attribute__((__deprecated__)) RA3 __attribute__((address(0x7C03)));


extern volatile __bit __attribute__((__deprecated__)) RA4 __attribute__((address(0x7C04)));


extern volatile __bit __attribute__((__deprecated__)) RA5 __attribute__((address(0x7C05)));


extern volatile __bit __attribute__((__deprecated__)) RA6 __attribute__((address(0x7C06)));


extern volatile __bit __attribute__((__deprecated__)) RA7 __attribute__((address(0x7C07)));


extern volatile __bit __attribute__((__deprecated__)) RB0 __attribute__((address(0x7C08)));


extern volatile __bit __attribute__((__deprecated__)) RB1 __attribute__((address(0x7C09)));


extern volatile __bit __attribute__((__deprecated__)) RB2 __attribute__((address(0x7C0A)));


extern volatile __bit __attribute__((__deprecated__)) RB3 __attribute__((address(0x7C0B)));


extern volatile __bit __attribute__((__deprecated__)) RB4 __attribute__((address(0x7C0C)));


extern volatile __bit __attribute__((__deprecated__)) RB5 __attribute__((address(0x7C0D)));


extern volatile __bit __attribute__((__deprecated__)) RB6 __attribute__((address(0x7C0E)));


extern volatile __bit __attribute__((__deprecated__)) RB7 __attribute__((address(0x7C0F)));


extern volatile __bit RBIE __attribute__((address(0x7F93)));


extern volatile __bit RBIF __attribute__((address(0x7F90)));


extern volatile __bit RBIP __attribute__((address(0x7F88)));


extern volatile __bit RBPU __attribute__((address(0x7F8F)));


extern volatile __bit __attribute__((__deprecated__)) RC0 __attribute__((address(0x7C10)));


extern volatile __bit __attribute__((__deprecated__)) RC1 __attribute__((address(0x7C11)));


extern volatile __bit RC1IE __attribute__((address(0x7CED)));


extern volatile __bit RC1IF __attribute__((address(0x7CF5)));


extern volatile __bit RC1IP __attribute__((address(0x7CFD)));


extern volatile __bit __attribute__((__deprecated__)) RC2 __attribute__((address(0x7C12)));


extern volatile __bit __attribute__((__deprecated__)) RC3 __attribute__((address(0x7C13)));


extern volatile __bit __attribute__((__deprecated__)) RC4 __attribute__((address(0x7C14)));


extern volatile __bit __attribute__((__deprecated__)) RC5 __attribute__((address(0x7C15)));


extern volatile __bit __attribute__((__deprecated__)) RC6 __attribute__((address(0x7C16)));


extern volatile __bit __attribute__((__deprecated__)) RC7 __attribute__((address(0x7C17)));


extern volatile __bit RC8_9 __attribute__((address(0x7D5E)));


extern volatile __bit RC9 __attribute__((address(0x7D5E)));


extern volatile __bit RCD8 __attribute__((address(0x7D58)));


extern volatile __bit RCEN __attribute__((address(0x7E2B)));


extern volatile __bit RCIDL __attribute__((address(0x7DC6)));


extern volatile __bit RCIE __attribute__((address(0x7CED)));


extern volatile __bit RCIF __attribute__((address(0x7CF5)));


extern volatile __bit RCIP __attribute__((address(0x7CFD)));


extern volatile __bit RCMT __attribute__((address(0x7DC6)));


extern volatile __bit __attribute__((__deprecated__)) RD __attribute__((address(0x7D30)));


extern volatile __bit __attribute__((__deprecated__)) RD0 __attribute__((address(0x7C18)));


extern volatile __bit __attribute__((__deprecated__)) RD1 __attribute__((address(0x7C19)));


extern volatile __bit RD163 __attribute__((address(0x7D8F)));


extern volatile __bit __attribute__((__deprecated__)) RD2 __attribute__((address(0x7C1A)));


extern volatile __bit __attribute__((__deprecated__)) RD3 __attribute__((address(0x7C1B)));


extern volatile __bit __attribute__((__deprecated__)) RD4 __attribute__((address(0x7C1C)));


extern volatile __bit __attribute__((__deprecated__)) RD5 __attribute__((address(0x7C1D)));


extern volatile __bit __attribute__((__deprecated__)) RD6 __attribute__((address(0x7C1E)));


extern volatile __bit __attribute__((__deprecated__)) RD7 __attribute__((address(0x7C1F)));


extern volatile __bit RDE __attribute__((address(0x7C20)));


extern volatile __bit __attribute__((__deprecated__)) RE0 __attribute__((address(0x7C20)));


extern volatile __bit __attribute__((__deprecated__)) RE1 __attribute__((address(0x7C21)));


extern volatile __bit __attribute__((__deprecated__)) RE2 __attribute__((address(0x7C22)));


extern volatile __bit __attribute__((__deprecated__)) RE3 __attribute__((address(0x7C23)));


extern volatile __bit RI __attribute__((address(0x7E84)));


extern volatile __bit RJPU __attribute__((address(0x7C07)));


extern volatile __bit RSEN __attribute__((address(0x7E29)));


extern volatile __bit RW __attribute__((address(0x7E3A)));


extern volatile __bit RX __attribute__((address(0x7C17)));


extern volatile __bit RX9 __attribute__((address(0x7D5E)));


extern volatile __bit RX9D __attribute__((address(0x7D58)));


extern volatile __bit RXCKP __attribute__((address(0x7DC5)));


extern volatile __bit RXDTP __attribute__((address(0x7DC5)));


extern volatile __bit R_NOT_W __attribute__((address(0x7E3A)));


extern volatile __bit R_W __attribute__((address(0x7E3A)));


extern volatile __bit R_nW __attribute__((address(0x7E3A)));


extern volatile __bit SBOREN __attribute__((address(0x7E86)));


extern volatile __bit SCK __attribute__((address(0x7C13)));


extern volatile __bit SCKP __attribute__((address(0x7DC4)));


extern volatile __bit SCL __attribute__((address(0x7C13)));


extern volatile __bit SCS0 __attribute__((address(0x7E98)));


extern volatile __bit SCS1 __attribute__((address(0x7E99)));


extern volatile __bit SDA __attribute__((address(0x7C14)));


extern volatile __bit SDI __attribute__((address(0x7C14)));


extern volatile __bit SDO __attribute__((address(0x7C15)));


extern volatile __bit SEN __attribute__((address(0x7E28)));


extern volatile __bit SENDB __attribute__((address(0x7D63)));


extern volatile __bit SENDB1 __attribute__((address(0x7D63)));


extern volatile __bit SMP __attribute__((address(0x7E3F)));


extern volatile __bit SOSCEN __attribute__((address(0x7E6B)));


extern volatile __bit SOSCEN3 __attribute__((address(0x7D8B)));


extern volatile __bit SP0 __attribute__((address(0x7FE0)));


extern volatile __bit SP1 __attribute__((address(0x7FE1)));


extern volatile __bit SP2 __attribute__((address(0x7FE2)));


extern volatile __bit SP3 __attribute__((address(0x7FE3)));


extern volatile __bit SP4 __attribute__((address(0x7FE4)));


extern volatile __bit SPEN __attribute__((address(0x7D5F)));


extern volatile __bit SREN __attribute__((address(0x7D5D)));


extern volatile __bit SRENA __attribute__((address(0x7D5D)));


extern volatile __bit SS __attribute__((address(0x7C05)));


extern volatile __bit SS2 __attribute__((address(0x7C1F)));


extern volatile __bit SSPEN __attribute__((address(0x7E35)));


extern volatile __bit SSPIE __attribute__((address(0x7CEB)));


extern volatile __bit SSPIF __attribute__((address(0x7CF3)));


extern volatile __bit SSPIP __attribute__((address(0x7CFB)));


extern volatile __bit SSPM0 __attribute__((address(0x7E30)));


extern volatile __bit SSPM1 __attribute__((address(0x7E31)));


extern volatile __bit SSPM2 __attribute__((address(0x7E32)));


extern volatile __bit SSPM3 __attribute__((address(0x7E33)));


extern volatile __bit SSPOV __attribute__((address(0x7E36)));


extern volatile __bit START __attribute__((address(0x7E3B)));


extern volatile __bit STKFUL __attribute__((address(0x7FE7)));


extern volatile __bit STKOVF __attribute__((address(0x7FE7)));


extern volatile __bit STKUNF __attribute__((address(0x7FE6)));


extern volatile __bit STOP __attribute__((address(0x7E3C)));


extern volatile __bit SWDTE __attribute__((address(0x7E88)));


extern volatile __bit SWDTEN __attribute__((address(0x7E88)));


extern volatile __bit SYNC __attribute__((address(0x7D64)));


extern volatile __bit SYNC1 __attribute__((address(0x7D64)));


extern volatile __bit T016BIT __attribute__((address(0x7EAE)));


extern volatile __bit T08BIT __attribute__((address(0x7EAE)));


extern volatile __bit T0CKI __attribute__((address(0x7C04)));


extern volatile __bit T0CS __attribute__((address(0x7EAD)));


extern volatile __bit T0IE __attribute__((address(0x7F95)));


extern volatile __bit T0IF __attribute__((address(0x7F92)));


extern volatile __bit T0PS0 __attribute__((address(0x7EA8)));


extern volatile __bit T0PS1 __attribute__((address(0x7EA9)));


extern volatile __bit T0PS2 __attribute__((address(0x7EAA)));


extern volatile __bit T0PS3 __attribute__((address(0x7EAB)));


extern volatile __bit T0SE __attribute__((address(0x7EAC)));


extern volatile __bit T13CKI __attribute__((address(0x7C10)));


extern volatile __bit T1CKI __attribute__((address(0x7C10)));


extern volatile __bit T1CKPS0 __attribute__((address(0x7E6C)));


extern volatile __bit T1CKPS1 __attribute__((address(0x7E6D)));


extern volatile __bit T1OSCEN __attribute__((address(0x7E6B)));


extern volatile __bit T1OSI __attribute__((address(0x7C11)));


extern volatile __bit T1OSO __attribute__((address(0x7C10)));


extern volatile __bit T1RD16 __attribute__((address(0x7E6F)));


extern volatile __bit T1RUN __attribute__((address(0x7E6E)));


extern volatile __bit T1SYNC __attribute__((address(0x7E6A)));


extern volatile __bit T2CKPS0 __attribute__((address(0x7E50)));


extern volatile __bit T2CKPS1 __attribute__((address(0x7E51)));


extern volatile __bit T2OUTPS0 __attribute__((address(0x7E53)));


extern volatile __bit T2OUTPS1 __attribute__((address(0x7E54)));


extern volatile __bit T2OUTPS2 __attribute__((address(0x7E55)));


extern volatile __bit T2OUTPS3 __attribute__((address(0x7E56)));


extern volatile __bit T3CCP1 __attribute__((address(0x7D8B)));


extern volatile __bit T3CCP2 __attribute__((address(0x7D8E)));


extern volatile __bit T3CKPS0 __attribute__((address(0x7D8C)));


extern volatile __bit T3CKPS1 __attribute__((address(0x7D8D)));


extern volatile __bit T3RD16 __attribute__((address(0x7D8F)));


extern volatile __bit T3SYNC __attribute__((address(0x7D8A)));


extern volatile __bit TMR0IE __attribute__((address(0x7F95)));


extern volatile __bit TMR0IF __attribute__((address(0x7F92)));


extern volatile __bit TMR0IP __attribute__((address(0x7F8A)));


extern volatile __bit TMR0ON __attribute__((address(0x7EAF)));


extern volatile __bit TMR1CS __attribute__((address(0x7E69)));


extern volatile __bit TMR1IE __attribute__((address(0x7CE8)));


extern volatile __bit TMR1IF __attribute__((address(0x7CF0)));


extern volatile __bit TMR1IP __attribute__((address(0x7CF8)));


extern volatile __bit TMR1ON __attribute__((address(0x7E68)));


extern volatile __bit TMR2IE __attribute__((address(0x7CE9)));


extern volatile __bit TMR2IF __attribute__((address(0x7CF1)));


extern volatile __bit TMR2IP __attribute__((address(0x7CF9)));


extern volatile __bit TMR2ON __attribute__((address(0x7E52)));


extern volatile __bit TMR3CS __attribute__((address(0x7D89)));


extern volatile __bit TMR3IE __attribute__((address(0x7D01)));


extern volatile __bit TMR3IF __attribute__((address(0x7D09)));


extern volatile __bit TMR3IP __attribute__((address(0x7D11)));


extern volatile __bit TMR3ON __attribute__((address(0x7D88)));


extern volatile __bit TO __attribute__((address(0x7E83)));


extern volatile __bit TOUTPS0 __attribute__((address(0x7E53)));


extern volatile __bit TOUTPS1 __attribute__((address(0x7E54)));


extern volatile __bit TOUTPS2 __attribute__((address(0x7E55)));


extern volatile __bit TOUTPS3 __attribute__((address(0x7E56)));


extern volatile __bit TRISA0 __attribute__((address(0x7C90)));


extern volatile __bit TRISA1 __attribute__((address(0x7C91)));


extern volatile __bit TRISA2 __attribute__((address(0x7C92)));


extern volatile __bit TRISA3 __attribute__((address(0x7C93)));


extern volatile __bit TRISA4 __attribute__((address(0x7C94)));


extern volatile __bit TRISA5 __attribute__((address(0x7C95)));


extern volatile __bit TRISA6 __attribute__((address(0x7C96)));


extern volatile __bit TRISA7 __attribute__((address(0x7C97)));


extern volatile __bit TRISB0 __attribute__((address(0x7C98)));


extern volatile __bit TRISB1 __attribute__((address(0x7C99)));


extern volatile __bit TRISB2 __attribute__((address(0x7C9A)));


extern volatile __bit TRISB3 __attribute__((address(0x7C9B)));


extern volatile __bit TRISB4 __attribute__((address(0x7C9C)));


extern volatile __bit TRISB5 __attribute__((address(0x7C9D)));


extern volatile __bit TRISB6 __attribute__((address(0x7C9E)));


extern volatile __bit TRISB7 __attribute__((address(0x7C9F)));


extern volatile __bit TRISC0 __attribute__((address(0x7CA0)));


extern volatile __bit TRISC1 __attribute__((address(0x7CA1)));


extern volatile __bit TRISC2 __attribute__((address(0x7CA2)));


extern volatile __bit TRISC3 __attribute__((address(0x7CA3)));


extern volatile __bit TRISC4 __attribute__((address(0x7CA4)));


extern volatile __bit TRISC5 __attribute__((address(0x7CA5)));


extern volatile __bit TRISC6 __attribute__((address(0x7CA6)));


extern volatile __bit TRISC7 __attribute__((address(0x7CA7)));


extern volatile __bit TRISD0 __attribute__((address(0x7CA8)));


extern volatile __bit TRISD1 __attribute__((address(0x7CA9)));


extern volatile __bit TRISD2 __attribute__((address(0x7CAA)));


extern volatile __bit TRISD3 __attribute__((address(0x7CAB)));


extern volatile __bit TRISD4 __attribute__((address(0x7CAC)));


extern volatile __bit TRISD5 __attribute__((address(0x7CAD)));


extern volatile __bit TRISD6 __attribute__((address(0x7CAE)));


extern volatile __bit TRISD7 __attribute__((address(0x7CAF)));


extern volatile __bit TRISE0 __attribute__((address(0x7CB0)));


extern volatile __bit TRISE1 __attribute__((address(0x7CB1)));


extern volatile __bit TRISE2 __attribute__((address(0x7CB2)));


extern volatile __bit TRMT __attribute__((address(0x7D61)));


extern volatile __bit TRMT1 __attribute__((address(0x7D61)));


extern volatile __bit TUN0 __attribute__((address(0x7CD8)));


extern volatile __bit TUN1 __attribute__((address(0x7CD9)));


extern volatile __bit TUN2 __attribute__((address(0x7CDA)));


extern volatile __bit TUN3 __attribute__((address(0x7CDB)));


extern volatile __bit TUN4 __attribute__((address(0x7CDC)));


extern volatile __bit TX __attribute__((address(0x7C16)));


extern volatile __bit TX1IE __attribute__((address(0x7CEC)));


extern volatile __bit TX1IF __attribute__((address(0x7CF4)));


extern volatile __bit TX1IP __attribute__((address(0x7CFC)));


extern volatile __bit TX8_9 __attribute__((address(0x7D66)));


extern volatile __bit TX9 __attribute__((address(0x7D66)));


extern volatile __bit TX91 __attribute__((address(0x7D66)));


extern volatile __bit TX9D __attribute__((address(0x7D60)));


extern volatile __bit TX9D1 __attribute__((address(0x7D60)));


extern volatile __bit TXCKP __attribute__((address(0x7DC4)));


extern volatile __bit TXD8 __attribute__((address(0x7D60)));


extern volatile __bit TXEN __attribute__((address(0x7D65)));


extern volatile __bit TXEN1 __attribute__((address(0x7D65)));


extern volatile __bit TXIE __attribute__((address(0x7CEC)));


extern volatile __bit TXIF __attribute__((address(0x7CF4)));


extern volatile __bit TXIP __attribute__((address(0x7CFC)));


extern volatile __bit UA __attribute__((address(0x7E39)));


extern volatile __bit ULPWUIN __attribute__((address(0x7C00)));


extern volatile __bit VCFG0 __attribute__((address(0x7E0C)));


extern volatile __bit VCFG01 __attribute__((address(0x7E0C)));


extern volatile __bit VCFG1 __attribute__((address(0x7E0D)));


extern volatile __bit VCFG11 __attribute__((address(0x7E0D)));


extern volatile __bit VDIRMAG __attribute__((address(0x7E97)));


extern volatile __bit VPP __attribute__((address(0x7C23)));


extern volatile __bit VREFN __attribute__((address(0x7C02)));


extern volatile __bit VREFP __attribute__((address(0x7C03)));


extern volatile __bit W4E __attribute__((address(0x7DC1)));


extern volatile __bit WAIT0 __attribute__((address(0x7E5C)));


extern volatile __bit WAIT1 __attribute__((address(0x7E5D)));


extern volatile __bit WCOL __attribute__((address(0x7E37)));


extern volatile __bit WM0 __attribute__((address(0x7E58)));


extern volatile __bit WM1 __attribute__((address(0x7E59)));


extern volatile __bit __attribute__((__deprecated__)) WR __attribute__((address(0x7D31)));


extern volatile __bit WRE __attribute__((address(0x7C21)));


extern volatile __bit WREN __attribute__((address(0x7D32)));


extern volatile __bit WRERR __attribute__((address(0x7D33)));


extern volatile __bit WUE __attribute__((address(0x7DC1)));


extern volatile __bit ZERO __attribute__((address(0x7EC2)));


extern volatile __bit nA __attribute__((address(0x7E3D)));


extern volatile __bit nADDRESS __attribute__((address(0x7E3D)));


extern volatile __bit nBOR __attribute__((address(0x7E80)));


extern volatile __bit nCS __attribute__((address(0x7C22)));


extern volatile __bit nDONE __attribute__((address(0x7E11)));


extern volatile __bit nMCLR __attribute__((address(0x7C23)));


extern volatile __bit nPD __attribute__((address(0x7E82)));


extern volatile __bit nPOR __attribute__((address(0x7E81)));


extern volatile __bit nRBPU __attribute__((address(0x7F8F)));


extern volatile __bit nRD __attribute__((address(0x7C20)));


extern volatile __bit nRI __attribute__((address(0x7E84)));


extern volatile __bit nSS __attribute__((address(0x7C05)));


extern volatile __bit nT1SYNC __attribute__((address(0x7E6A)));


extern volatile __bit nT3SYNC __attribute__((address(0x7D8A)));


extern volatile __bit nTO __attribute__((address(0x7E83)));


extern volatile __bit nW __attribute__((address(0x7E3A)));


extern volatile __bit nWR __attribute__((address(0x7C21)));


extern volatile __bit nWRITE __attribute__((address(0x7E3A)));
# 321 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\pic18_chip_select.h" 2 3
# 9 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\pic18.h" 2 3
# 19 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\pic18.h" 3
__attribute__((__unsupported__("The " "flash_write" " routine is no longer supported. Please use the MPLAB X MCC."))) void flash_write(const unsigned char *, unsigned int, __far unsigned char *);
__attribute__((__unsupported__("The " "EraseFlash" " routine is no longer supported. Please use the MPLAB X MCC."))) void EraseFlash(unsigned long startaddr, unsigned long endaddr);







# 1 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\errata.h" 1 3
# 28 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\pic18.h" 2 3
# 156 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\pic18.h" 3
__attribute__((__unsupported__("The " "Read_b_eep" " routine is no longer supported. Please use the MPLAB X MCC."))) unsigned char Read_b_eep(unsigned int badd);
__attribute__((__unsupported__("The " "Busy_eep" " routine is no longer supported. Please use the MPLAB X MCC."))) void Busy_eep(void);
__attribute__((__unsupported__("The " "Write_b_eep" " routine is no longer supported. Please use the MPLAB X MCC."))) void Write_b_eep(unsigned int badd, unsigned char bdat);
# 192 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\pic18.h" 3
unsigned char __t1rd16on(void);
unsigned char __t3rd16on(void);
# 34 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\xc.h" 2 3
# 10 "./pin_manager.h" 2
# 9 "main.c" 2

# 1 "./eusart1.h" 1
# 10 "./eusart1.h"
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\stdbool.h" 1 3
# 10 "./eusart1.h" 2


# 1 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\stdio.h" 1 3
# 24 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\stdio.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\bits/alltypes.h" 1 3





typedef void * va_list[1];




typedef void * __isoc_va_list[1];
# 137 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long ssize_t;
# 246 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long long off_t;
# 399 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\bits/alltypes.h" 3
typedef struct _IO_FILE FILE;
# 24 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\stdio.h" 2 3
# 52 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\stdio.h" 3
typedef union _G_fpos64_t {
 char __opaque[16];
 double __align;
} fpos_t;

extern FILE *const stdin;
extern FILE *const stdout;
extern FILE *const stderr;





FILE *fopen(const char *restrict, const char *restrict);
FILE *freopen(const char *restrict, const char *restrict, FILE *restrict);
int fclose(FILE *);

int remove(const char *);
int rename(const char *, const char *);

int feof(FILE *);
int ferror(FILE *);
int fflush(FILE *);
void clearerr(FILE *);

int fseek(FILE *, long, int);
long ftell(FILE *);
void rewind(FILE *);

int fgetpos(FILE *restrict, fpos_t *restrict);
int fsetpos(FILE *, const fpos_t *);

size_t fread(void *restrict, size_t, size_t, FILE *restrict);
size_t fwrite(const void *restrict, size_t, size_t, FILE *restrict);

int fgetc(FILE *);
int getc(FILE *);
int getchar(void);
int ungetc(int, FILE *);

int fputc(int, FILE *);
int putc(int, FILE *);
int putchar(int);

char *fgets(char *restrict, int, FILE *restrict);

char *gets(char *);


int fputs(const char *restrict, FILE *restrict);
int puts(const char *);

__attribute__((__format__(__printf__, 1, 2)))
int printf(const char *restrict, ...);
__attribute__((__format__(__printf__, 2, 3)))
int fprintf(FILE *restrict, const char *restrict, ...);
__attribute__((__format__(__printf__, 2, 3)))
int sprintf(char *restrict, const char *restrict, ...);
__attribute__((__format__(__printf__, 3, 4)))
int snprintf(char *restrict, size_t, const char *restrict, ...);

__attribute__((__format__(__printf__, 1, 0)))
int vprintf(const char *restrict, __isoc_va_list);
int vfprintf(FILE *restrict, const char *restrict, __isoc_va_list);
__attribute__((__format__(__printf__, 2, 0)))
int vsprintf(char *restrict, const char *restrict, __isoc_va_list);
__attribute__((__format__(__printf__, 3, 0)))
int vsnprintf(char *restrict, size_t, const char *restrict, __isoc_va_list);

__attribute__((__format__(__scanf__, 1, 2)))
int scanf(const char *restrict, ...);
__attribute__((__format__(__scanf__, 2, 3)))
int fscanf(FILE *restrict, const char *restrict, ...);
__attribute__((__format__(__scanf__, 2, 3)))
int sscanf(const char *restrict, const char *restrict, ...);

__attribute__((__format__(__scanf__, 1, 0)))
int vscanf(const char *restrict, __isoc_va_list);
int vfscanf(FILE *restrict, const char *restrict, __isoc_va_list);
__attribute__((__format__(__scanf__, 2, 0)))
int vsscanf(const char *restrict, const char *restrict, __isoc_va_list);

void perror(const char *);

int setvbuf(FILE *restrict, char *restrict, int, size_t);
void setbuf(FILE *restrict, char *restrict);

char *tmpnam(char *);
FILE *tmpfile(void);




FILE *fmemopen(void *restrict, size_t, const char *restrict);
FILE *open_memstream(char **, size_t *);
FILE *fdopen(int, const char *);
FILE *popen(const char *, const char *);
int pclose(FILE *);
int fileno(FILE *);
int fseeko(FILE *, off_t, int);
off_t ftello(FILE *);
int dprintf(int, const char *restrict, ...);
int vdprintf(int, const char *restrict, __isoc_va_list);
void flockfile(FILE *);
int ftrylockfile(FILE *);
void funlockfile(FILE *);
int getc_unlocked(FILE *);
int getchar_unlocked(void);
int putc_unlocked(int, FILE *);
int putchar_unlocked(int);
ssize_t getdelim(char **restrict, size_t *restrict, int, FILE *restrict);
ssize_t getline(char **restrict, size_t *restrict, FILE *restrict);
int renameat(int, const char *, int, const char *);
char *ctermid(char *);







char *tempnam(const char *, const char *);
# 12 "./eusart1.h" 2
# 31 "./eusart1.h"
typedef union {
    struct {
        unsigned perr : 1;
        unsigned ferr : 1;
        unsigned oerr : 1;
        unsigned reserved : 5;
    };
    uint8_t status;
}eusart1_status_t;
# 66 "./eusart1.h"
void EUSART1_Initialize(void);
# 114 "./eusart1.h"
_Bool EUSART1_is_tx_ready(void);
# 162 "./eusart1.h"
_Bool EUSART1_is_rx_ready(void);
# 209 "./eusart1.h"
_Bool EUSART1_is_tx_done(void);
# 257 "./eusart1.h"
eusart1_status_t EUSART1_get_last_status(void);
# 277 "./eusart1.h"
uint8_t EUSART1_Read(void);
# 297 "./eusart1.h"
void EUSART1_Write(uint8_t txData);
# 317 "./eusart1.h"
void EUSART1_SetFramingErrorHandler(void (* interruptHandler)(void));
# 335 "./eusart1.h"
void EUSART1_SetOverrunErrorHandler(void (* interruptHandler)(void));
# 353 "./eusart1.h"
void EUSART1_SetErrorHandler(void (* interruptHandler)(void));
# 10 "main.c" 2

# 1 "./interrupt_manager.h" 1
# 110 "./interrupt_manager.h"
void INTERRUPT_Initialize (void);
# 11 "main.c" 2

# 1 "./tmr2.h" 1
# 103 "./tmr2.h"
void TMR2_Initialize(void);
# 132 "./tmr2.h"
void TMR2_StartTimer(void);
# 164 "./tmr2.h"
void TMR2_StopTimer(void);
# 199 "./tmr2.h"
uint8_t TMR2_ReadTimer(void);
# 238 "./tmr2.h"
void TMR2_WriteTimer(uint8_t timerVal);
# 290 "./tmr2.h"
void TMR2_LoadPeriodRegister(uint8_t periodVal);
# 308 "./tmr2.h"
void TMR2_ISR(void);
# 326 "./tmr2.h"
 void TMR2_CallBack(void);
# 343 "./tmr2.h"
 void TMR2_SetInterruptHandler(void (* InterruptHandler)(void));
# 361 "./tmr2.h"
extern void (*TMR2_InterruptHandler)(void);
# 379 "./tmr2.h"
void TMR2_DefaultInterruptHandler(void);
# 12 "main.c" 2

# 1 "./adc.h" 1
# 72 "./adc.h"
typedef uint16_t adc_result_t;
# 86 "./adc.h"
typedef enum
{
    channel_CTMU = 0x1C,
    channel_Temp_diode = 0x1D,
    channel_Vdd_core = 0x1E,
    channel_1_024V_bandgap = 0x1F,
    channel_AN0 = 0x0,
    channel_AN1 = 0x1,
    channel_AN2 = 0x2,
    channel_AN3 = 0x3,
    channel_AN4 = 0x4

} adc_channel_t;
# 133 "./adc.h"
void ADC_Initialize(void);
# 162 "./adc.h"
void ADC_StartConversion(adc_channel_t channel);
# 194 "./adc.h"
_Bool ADC_IsConversionDone(void);
# 227 "./adc.h"
adc_result_t ADC_GetConversionResult(void);
# 257 "./adc.h"
adc_result_t ADC_GetConversion(adc_channel_t channel);
# 285 "./adc.h"
void ADC_TemperatureAcquisitionDelay(void);
# 13 "main.c" 2

# 1 "./spi.h" 1
# 13 "./spi.h"
typedef enum {
    SPI_DEFAULT
} spi_modes_t;

void SPI_Initialize(void);
_Bool SPI_Open(spi_modes_t spiUniqueConfiguration);
void SPI_Close(void);
uint8_t SPI_ExchangeByte(uint8_t data);
void SPI_ExchangeBlock(void *block, size_t blockSize);
void SPI_WriteBlock(void *block, size_t blockSize);
void SPI_ReadBlock(void *block, size_t blockSize);
void SPI_WriteByte(uint8_t byte);
uint8_t SPI_ReadByte(void);
# 14 "main.c" 2


# 1 "./ST7735_TFT.h" 1
# 17 "./ST7735_TFT.h"
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\string.h" 1 3
# 25 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\string.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\bits/alltypes.h" 1 3
# 411 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\bits/alltypes.h" 3
typedef struct __locale_struct * locale_t;
# 25 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\string.h" 2 3


void *memcpy (void *restrict, const void *restrict, size_t);
void *memmove (void *, const void *, size_t);
void *memset (void *, int, size_t);
int memcmp (const void *, const void *, size_t);
void *memchr (const void *, int, size_t);

char *strcpy (char *restrict, const char *restrict);
char *strncpy (char *restrict, const char *restrict, size_t);

char *strcat (char *restrict, const char *restrict);
char *strncat (char *restrict, const char *restrict, size_t);

int strcmp (const char *, const char *);
int strncmp (const char *, const char *, size_t);

int strcoll (const char *, const char *);
size_t strxfrm (char *restrict, const char *restrict, size_t);

char *strchr (const char *, int);
char *strrchr (const char *, int);

size_t strcspn (const char *, const char *);
size_t strspn (const char *, const char *);
char *strpbrk (const char *, const char *);
char *strstr (const char *, const char *);
char *strtok (char *restrict, const char *restrict);

size_t strlen (const char *);

char *strerror (int);
# 65 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\string.h" 3
char *strtok_r (char *restrict, const char *restrict, char **restrict);
int strerror_r (int, char *, size_t);
char *stpcpy(char *restrict, const char *restrict);
char *stpncpy(char *restrict, const char *restrict, size_t);
size_t strnlen (const char *, size_t);
char *strdup (const char *);
char *strndup (const char *, size_t);
char *strsignal(int);
char *strerror_l (int, locale_t);
int strcoll_l (const char *, const char *, locale_t);
size_t strxfrm_l (char *restrict, const char *restrict, size_t, locale_t);




void *memccpy (void *restrict, const void *restrict, int, size_t);
# 17 "./ST7735_TFT.h" 2
# 51 "./ST7735_TFT.h"
extern uint8_t tft_width, tft_height;
# 116 "./ST7735_TFT.h"
void write_command(uint8_t );
void write_data(uint8_t );
# 130 "./ST7735_TFT.h"
void TFT_BlackTab_Initialize(void);



void Rcmd2red();
# 146 "./ST7735_TFT.h"
void Gcmd();
void Rcmd1();
void Rcmd3();


void setAddrWindow(uint8_t , uint8_t , uint8_t , uint8_t );
void fillScreen(uint16_t color);
void drawFastVLine(uint8_t x, uint8_t y, uint8_t h, uint16_t color);
void drawFastHLine(uint8_t x, uint8_t y, uint8_t w, uint16_t color);
void drawPixel(uint8_t , uint8_t , uint16_t );
void fillRectangle(uint8_t , uint8_t , uint8_t , uint8_t , uint16_t );
void fillRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint16_t color);

void invertDisplay(_Bool i);
void NormalDisplay(void);
void pushColor(uint16_t color);



void setScrollDefinition(uint8_t top_fix_height, uint8_t bottom_fix_height, _Bool _scroll_direction);
void VerticalScroll(uint8_t _vsp);




void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
void drawRectWH(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint16_t color);
void drawRoundRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint8_t r, uint16_t color);
void fillRoundRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint8_t r, uint16_t color);
void drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
void drawCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, uint16_t color);
void fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, int16_t delta, uint16_t color);
void fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
void drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
void fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);




void drawChar(uint8_t x, uint8_t y, uint8_t c, uint16_t color, uint16_t bg, uint8_t size);
void setTextWrap(_Bool w);
void drawText(uint8_t x, uint8_t y, const char *_text, uint16_t color, uint16_t bg, uint8_t size);



void setRotation(uint8_t m);




typedef struct {
  uint16_t bitmapOffset;
  uint8_t width;
  uint8_t height;
  uint8_t xAdvance;
  int8_t xOffset;
  int8_t yOffset;
} GFXglyph;


typedef struct {
  uint8_t *bitmap;
  GFXglyph *glyph;
  uint16_t first;
  uint16_t last;
  uint8_t yAdvance;
  const char *subset;
} GFXfont;

extern GFXfont *_gfxFont;
void setFont(const GFXfont *f);
# 16 "main.c" 2

# 1 "./FreeSansBold9pt7b.h" 1
const uint8_t FreeSansBold9pt7bBitmaps[] = {
    0xFF, 0xFF, 0xFE, 0x48, 0x7E, 0xEF, 0xDF, 0xBF, 0x74, 0x40, 0x19, 0x86,
    0x67, 0xFD, 0xFF, 0x33, 0x0C, 0xC3, 0x33, 0xFE, 0xFF, 0x99, 0x86, 0x61,
    0x90, 0x10, 0x1F, 0x1F, 0xDE, 0xFF, 0x3F, 0x83, 0xC0, 0xFC, 0x1F, 0x09,
    0xFC, 0xFE, 0xF7, 0xF1, 0xE0, 0x40, 0x38, 0x10, 0x7C, 0x30, 0xC6, 0x20,
    0xC6, 0x40, 0xC6, 0x40, 0x7C, 0x80, 0x39, 0x9C, 0x01, 0x3E, 0x03, 0x63,
    0x02, 0x63, 0x04, 0x63, 0x0C, 0x3E, 0x08, 0x1C, 0x0E, 0x01, 0xF8, 0x3B,
    0x83, 0xB8, 0x3F, 0x01, 0xE0, 0x3E, 0x67, 0x76, 0xE3, 0xEE, 0x1C, 0xF3,
    0xC7, 0xFE, 0x3F, 0x70, 0xFF, 0xF4, 0x18, 0x63, 0x1C, 0x73, 0x8E, 0x38,
    0xE3, 0x8E, 0x18, 0x70, 0xC3, 0x06, 0x08, 0x61, 0x83, 0x0E, 0x38, 0x71,
    0xC7, 0x1C, 0x71, 0xC6, 0x38, 0xE3, 0x18, 0x40, 0x21, 0x3E, 0x45, 0x28,
    0x38, 0x70, 0xE7, 0xFF, 0xE7, 0x0E, 0x1C, 0xFC, 0x9C, 0xFF, 0xC0, 0xFC,
    0x08, 0xC4, 0x23, 0x10, 0x84, 0x62, 0x11, 0x88, 0x00, 0x3E, 0x3F, 0x9D,
    0xDC, 0x7E, 0x3F, 0x1F, 0x8F, 0xC7, 0xE3, 0xF1, 0xDD, 0xCF, 0xE3, 0xE0,
    0x08, 0xFF, 0xF3, 0x9C, 0xE7, 0x39, 0xCE, 0x73, 0x80, 0x3E, 0x3F, 0xB8,
    0xFC, 0x70, 0x38, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x0F, 0xF7, 0xF8,
    0x3C, 0x7F, 0xE7, 0xE7, 0x07, 0x0C, 0x0E, 0x07, 0x07, 0xE7, 0xE7, 0x7E,
    0x3C, 0x0E, 0x1E, 0x1E, 0x2E, 0x2E, 0x4E, 0x4E, 0x8E, 0xFF, 0xFF, 0x0E,
    0x0E, 0x0E, 0x7F, 0x3F, 0x90, 0x18, 0x0D, 0xE7, 0xFB, 0x9E, 0x07, 0x03,
    0x81, 0xF1, 0xFF, 0xE7, 0xC0, 0x3E, 0x3F, 0x9C, 0xFC, 0x0E, 0xE7, 0xFB,
    0xDF, 0xC7, 0xE3, 0xF1, 0xDD, 0xEF, 0xE3, 0xE0, 0xFF, 0xFF, 0xC0, 0xE0,
    0xE0, 0x60, 0x70, 0x30, 0x38, 0x1C, 0x0C, 0x0E, 0x07, 0x03, 0x80, 0x3F,
    0x1F, 0xEE, 0x3F, 0x87, 0xE3, 0xCF, 0xC7, 0xFB, 0xCF, 0xE1, 0xF8, 0x7F,
    0x3D, 0xFE, 0x3F, 0x00, 0x3E, 0x3F, 0xBD, 0xDC, 0x7E, 0x3F, 0x1F, 0xDE,
    0xFF, 0x3B, 0x81, 0xF9, 0xCF, 0xE3, 0xC0, 0xFC, 0x00, 0x07, 0xE0, 0xFC,
    0x00, 0x07, 0xE5, 0xE0, 0x00, 0x83, 0xC7, 0xDF, 0x0C, 0x07, 0x80, 0xF8,
    0x1F, 0x01, 0x80, 0xFF, 0xFF, 0xC0, 0x00, 0x0F, 0xFF, 0xFC, 0x00, 0x70,
    0x3F, 0x03, 0xE0, 0x38, 0x7D, 0xF1, 0xE0, 0x80, 0x00, 0x3E, 0x3F, 0xB8,
    0xFC, 0x70, 0x38, 0x1C, 0x1C, 0x1C, 0x1C, 0x0E, 0x00, 0x03, 0x81, 0xC0,
    0x03, 0xF0, 0x0F, 0xFC, 0x1E, 0x0E, 0x38, 0x02, 0x70, 0xE9, 0x63, 0x19,
    0xC2, 0x19, 0xC6, 0x11, 0xC6, 0x33, 0xC6, 0x32, 0x63, 0xFE, 0x73, 0xDC,
    0x3C, 0x00, 0x1F, 0xF8, 0x07, 0xF0, 0x07, 0x00, 0xF0, 0x0F, 0x80, 0xF8,
    0x1D, 0x81, 0x9C, 0x19, 0xC3, 0x8C, 0x3F, 0xE7, 0xFE, 0x70, 0x66, 0x07,
    0xE0, 0x70, 0xFF, 0x9F, 0xFB, 0x83, 0xF0, 0x7E, 0x0F, 0xFF, 0x3F, 0xF7,
    0x06, 0xE0, 0xFC, 0x1F, 0x83, 0xFF, 0xEF, 0xF8, 0x1F, 0x83, 0xFE, 0x78,
    0xE7, 0x07, 0xE0, 0x0E, 0x00, 0xE0, 0x0E, 0x00, 0xE0, 0x07, 0x07, 0x78,
    0xF3, 0xFE, 0x1F, 0x80, 0xFF, 0x8F, 0xFC, 0xE0, 0xEE, 0x0E, 0xE0, 0x7E,
    0x07, 0xE0, 0x7E, 0x07, 0xE0, 0x7E, 0x0E, 0xE0, 0xEF, 0xFC, 0xFF, 0x80,
    0xFF, 0xFF, 0xF8, 0x1C, 0x0E, 0x07, 0xFB, 0xFD, 0xC0, 0xE0, 0x70, 0x38,
    0x1F, 0xFF, 0xF8, 0xFF, 0xFF, 0xF8, 0x1C, 0x0E, 0x07, 0xFB, 0xFD, 0xC0,
    0xE0, 0x70, 0x38, 0x1C, 0x0E, 0x00, 0x0F, 0x87, 0xF9, 0xE3, 0xB8, 0x3E,
    0x01, 0xC0, 0x38, 0xFF, 0x1F, 0xE0, 0x6E, 0x0D, 0xE3, 0x9F, 0xD0, 0xF2,
    0xE0, 0xFC, 0x1F, 0x83, 0xF0, 0x7E, 0x0F, 0xFF, 0xFF, 0xFF, 0x07, 0xE0,
    0xFC, 0x1F, 0x83, 0xF0, 0x7E, 0x0E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0xE7, 0xE7, 0xE7, 0x7E, 0x3C,
    0xE0, 0xEE, 0x1C, 0xE3, 0x8E, 0x70, 0xEE, 0x0F, 0xC0, 0xFE, 0x0F, 0x70,
    0xE7, 0x0E, 0x38, 0xE1, 0xCE, 0x0E, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0,
    0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xFF, 0xFF, 0xF8, 0x7F, 0xE1,
    0xFF, 0x87, 0xFE, 0x1F, 0xEC, 0x7F, 0xB3, 0x7E, 0xCD, 0xFB, 0x37, 0xEC,
    0xDF, 0x9E, 0x7E, 0x79, 0xF9, 0xE7, 0xE7, 0x9C, 0xE0, 0xFE, 0x1F, 0xC3,
    0xFC, 0x7F, 0xCF, 0xD9, 0xFB, 0xBF, 0x37, 0xE7, 0xFC, 0x7F, 0x87, 0xF0,
    0xFE, 0x0E, 0x0F, 0x81, 0xFF, 0x1E, 0x3C, 0xE0, 0xEE, 0x03, 0xF0, 0x1F,
    0x80, 0xFC, 0x07, 0xE0, 0x3B, 0x83, 0x9E, 0x3C, 0x7F, 0xC0, 0xF8, 0x00,
    0xFF, 0x9F, 0xFB, 0x87, 0xF0, 0x7E, 0x0F, 0xC3, 0xFF, 0xF7, 0xFC, 0xE0,
    0x1C, 0x03, 0x80, 0x70, 0x0E, 0x00, 0x0F, 0x81, 0xFF, 0x1E, 0x3C, 0xE0,
    0xEE, 0x03, 0xF0, 0x1F, 0x80, 0xFC, 0x07, 0xE1, 0xBB, 0x8F, 0x9E, 0x3C,
    0x7F, 0xE0, 0xFB, 0x80, 0x08, 0xFF, 0x8F, 0xFC, 0xE0, 0xEE, 0x0E, 0xE0,
    0xEE, 0x0E, 0xFF, 0xCF, 0xFC, 0xE0, 0xEE, 0x0E, 0xE0, 0xEE, 0x0E, 0xE0,
    0xF0, 0x3F, 0x0F, 0xFB, 0xC7, 0xF0, 0x7E, 0x01, 0xFC, 0x1F, 0xF0, 0x3F,
    0x00, 0xFC, 0x1D, 0xC7, 0xBF, 0xE1, 0xF8, 0xFF, 0xFF, 0xC7, 0x03, 0x81,
    0xC0, 0xE0, 0x70, 0x38, 0x1C, 0x0E, 0x07, 0x03, 0x81, 0xC0, 0xE0, 0xFC,
    0x1F, 0x83, 0xF0, 0x7E, 0x0F, 0xC1, 0xF8, 0x3F, 0x07, 0xE0, 0xFC, 0x1F,
    0xC7, 0xBF, 0xE1, 0xF0, 0x60, 0x67, 0x0E, 0x70, 0xE3, 0x0C, 0x30, 0xC3,
    0x9C, 0x19, 0x81, 0x98, 0x1F, 0x80, 0xF0, 0x0F, 0x00, 0xF0, 0x06, 0x00,
    0x61, 0xC3, 0xB8, 0xE1, 0x9C, 0x70, 0xCE, 0x3C, 0xE3, 0x36, 0x71, 0x9B,
    0x30, 0xED, 0x98, 0x36, 0x7C, 0x1B, 0x3C, 0x0F, 0x1E, 0x07, 0x8F, 0x01,
    0xC3, 0x80, 0xE1, 0x80, 0x70, 0xE7, 0x8E, 0x39, 0xC1, 0xF8, 0x1F, 0x80,
    0xF0, 0x07, 0x00, 0xF0, 0x1F, 0x81, 0x9C, 0x39, 0xC7, 0x0E, 0x70, 0xE0,
    0xE0, 0xFC, 0x39, 0xC7, 0x18, 0xC3, 0xB8, 0x36, 0x07, 0xC0, 0x70, 0x0E,
    0x01, 0xC0, 0x38, 0x07, 0x00, 0xE0, 0xFF, 0xFF, 0xC0, 0xE0, 0xE0, 0xF0,
    0x70, 0x70, 0x70, 0x78, 0x38, 0x38, 0x1F, 0xFF, 0xF8, 0xFF, 0xEE, 0xEE,
    0xEE, 0xEE, 0xEE, 0xEE, 0xEF, 0xF0, 0x86, 0x10, 0x86, 0x10, 0x84, 0x30,
    0x84, 0x30, 0x80, 0xFF, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x7F, 0xF0,
    0x18, 0x1C, 0x3C, 0x3E, 0x36, 0x66, 0x63, 0xC3, 0xFF, 0xC0, 0xCC, 0x3F,
    0x1F, 0xEE, 0x38, 0x0E, 0x3F, 0x9E, 0xEE, 0x3B, 0x9E, 0xFF, 0x9E, 0xE0,
    0xE0, 0x38, 0x0E, 0x03, 0xBC, 0xFF, 0xBC, 0xEE, 0x1F, 0x87, 0xE1, 0xF8,
    0x7F, 0x3B, 0xFE, 0xEF, 0x00, 0x1F, 0x3F, 0xDC, 0x7C, 0x0E, 0x07, 0x03,
    0x80, 0xE3, 0x7F, 0x8F, 0x00, 0x03, 0x81, 0xC0, 0xE7, 0x77, 0xFB, 0xBF,
    0x8F, 0xC7, 0xE3, 0xF1, 0xFD, 0xEF, 0xF3, 0xB8, 0x3E, 0x3F, 0x9C, 0xDC,
    0x3F, 0xFF, 0xFF, 0x81, 0xC3, 0x7F, 0x8F, 0x00, 0x3B, 0xDD, 0xFF, 0xB9,
    0xCE, 0x73, 0x9C, 0xE7, 0x00, 0x3B, 0xBF, 0xDD, 0xFC, 0x7E, 0x3F, 0x1F,
    0x8F, 0xEF, 0x7F, 0x9D, 0xC0, 0xFC, 0x77, 0xF1, 0xF0, 0xE0, 0x70, 0x38,
    0x1D, 0xEF, 0xFF, 0x9F, 0x8F, 0xC7, 0xE3, 0xF1, 0xF8, 0xFC, 0x7E, 0x38,
    0xFC, 0x7F, 0xFF, 0xFF, 0xFE, 0x77, 0x07, 0x77, 0x77, 0x77, 0x77, 0x77,
    0x7F, 0xE0, 0xE0, 0x70, 0x38, 0x1C, 0x7E, 0x77, 0x73, 0xF1, 0xF8, 0xFE,
    0x77, 0x39, 0xDC, 0x6E, 0x38, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xEF, 0x7B,
    0xFF, 0xFE, 0x39, 0xF8, 0xE7, 0xE3, 0x9F, 0x8E, 0x7E, 0x39, 0xF8, 0xE7,
    0xE3, 0x9F, 0x8E, 0x70, 0xEF, 0x7F, 0xF8, 0xFC, 0x7E, 0x3F, 0x1F, 0x8F,
    0xC7, 0xE3, 0xF1, 0xC0, 0x1E, 0x1F, 0xE7, 0x3B, 0x87, 0xE1, 0xF8, 0x7E,
    0x1D, 0xCE, 0x7F, 0x87, 0x80, 0xEF, 0x3F, 0xEF, 0x3B, 0x87, 0xE1, 0xF8,
    0x7E, 0x1F, 0xCE, 0xFF, 0xBB, 0xCE, 0x03, 0x80, 0xE0, 0x38, 0x00, 0x3B,
    0xBF, 0xFD, 0xFC, 0x7E, 0x3F, 0x1F, 0x8F, 0xEF, 0x7F, 0x9D, 0xC0, 0xE0,
    0x70, 0x38, 0x1C, 0xEF, 0xFF, 0x38, 0xE3, 0x8E, 0x38, 0xE3, 0x80, 0x3E,
    0x3F, 0xB8, 0xFC, 0x0F, 0xC3, 0xFC, 0x3F, 0xC7, 0xFF, 0x1F, 0x00, 0x73,
    0xBF, 0xF7, 0x39, 0xCE, 0x73, 0x9E, 0x70, 0xE3, 0xF1, 0xF8, 0xFC, 0x7E,
    0x3F, 0x1F, 0x8F, 0xC7, 0xFF, 0xBD, 0xC0, 0xE1, 0x98, 0x67, 0x39, 0xCC,
    0x33, 0x0D, 0xC3, 0xE0, 0x78, 0x1E, 0x07, 0x00, 0xE3, 0x1D, 0x9E, 0x66,
    0x79, 0x99, 0xE6, 0x77, 0xB8, 0xD2, 0xC3, 0xCF, 0x0F, 0x3C, 0x3C, 0xF0,
    0x73, 0x80, 0x73, 0x9C, 0xE3, 0xF0, 0x78, 0x1E, 0x07, 0x81, 0xE0, 0xFC,
    0x73, 0x9C, 0xE0, 0xE1, 0xD8, 0x67, 0x39, 0xCE, 0x33, 0x0E, 0xC3, 0xE0,
    0x78, 0x1E, 0x03, 0x00, 0xC0, 0x70, 0x38, 0x0E, 0x00, 0xFE, 0xFE, 0x0E,
    0x1C, 0x38, 0x38, 0x70, 0xE0, 0xFF, 0xFF, 0x37, 0x66, 0x66, 0x6E, 0xE6,
    0x66, 0x66, 0x67, 0x30, 0xFF, 0xFF, 0x80, 0xCE, 0x66, 0x66, 0x67, 0x76,
    0x66, 0x66, 0x6E, 0xC0, 0x71, 0x8E};

const GFXglyph FreeSansBold9pt7bGlyphs[] = {
    {0, 0, 0, 5, 0, 1},
    {0, 3, 13, 6, 2, -12},
    {5, 7, 5, 9, 1, -12},
    {10, 10, 12, 10, 0, -11},
    {25, 9, 15, 10, 1, -13},
    {42, 16, 13, 16, 0, -12},
    {68, 12, 13, 13, 1, -12},
    {88, 3, 5, 5, 1, -12},
    {90, 6, 17, 6, 1, -12},
    {103, 6, 17, 6, 0, -12},
    {116, 5, 6, 7, 1, -12},
    {120, 7, 8, 11, 2, -7},
    {127, 3, 5, 4, 1, -1},
    {129, 5, 2, 6, 0, -5},
    {131, 3, 2, 4, 1, -1},
    {132, 5, 13, 5, 0, -12},
    {141, 9, 13, 10, 1, -12},
    {156, 5, 13, 10, 2, -12},
    {165, 9, 13, 10, 1, -12},
    {180, 8, 13, 10, 1, -12},
    {193, 8, 13, 10, 2, -12},
    {206, 9, 13, 10, 1, -12},
    {221, 9, 13, 10, 1, -12},
    {236, 9, 13, 10, 0, -12},
    {251, 10, 13, 10, 0, -12},
    {268, 9, 13, 10, 1, -12},
    {283, 3, 9, 4, 1, -8},
    {287, 3, 12, 4, 1, -8},
    {292, 9, 9, 11, 1, -8},
    {303, 9, 6, 11, 1, -6},
    {310, 9, 9, 11, 1, -8},
    {321, 9, 13, 11, 1, -12},
    {336, 16, 15, 18, 0, -12},
    {366, 12, 13, 13, 0, -12},
    {386, 11, 13, 13, 1, -12},
    {404, 12, 13, 13, 1, -12},
    {424, 12, 13, 13, 1, -12},
    {444, 9, 13, 12, 1, -12},
    {459, 9, 13, 11, 1, -12},
    {474, 11, 13, 14, 1, -12},
    {492, 11, 13, 13, 1, -12},
    {510, 3, 13, 6, 1, -12},
    {515, 8, 13, 10, 1, -12},
    {528, 12, 13, 13, 1, -12},
    {548, 8, 13, 11, 1, -12},
    {561, 14, 13, 16, 1, -12},
    {584, 11, 13, 14, 1, -12},
    {602, 13, 13, 14, 1, -12},
    {624, 11, 13, 12, 1, -12},
    {642, 13, 14, 14, 1, -12},
    {665, 12, 13, 13, 1, -12},
    {685, 11, 13, 12, 1, -12},
    {703, 9, 13, 12, 2, -12},
    {718, 11, 13, 13, 1, -12},
    {736, 12, 13, 12, 0, -12},
    {756, 17, 13, 17, 0, -12},
    {784, 12, 13, 12, 0, -12},
    {804, 11, 13, 12, 1, -12},
    {822, 9, 13, 11, 1, -12},
    {837, 4, 17, 6, 1, -12},
    {846, 5, 13, 5, 0, -12},
    {855, 4, 17, 6, 0, -12},
    {864, 8, 8, 11, 1, -12},
    {872, 10, 1, 10, 0, 4},
    {874, 3, 2, 5, 0, -12},
    {875, 10, 10, 10, 1, -9},
    {888, 10, 13, 11, 1, -12},
    {905, 9, 10, 10, 1, -9},
    {917, 9, 13, 11, 1, -12},
    {932, 9, 10, 10, 1, -9},
    {944, 5, 13, 6, 1, -12},
    {953, 9, 14, 11, 1, -9},
    {969, 9, 13, 11, 1, -12},
    {984, 3, 13, 5, 1, -12},
    {989, 4, 17, 5, 0, -12},
    {998, 9, 13, 10, 1, -12},
    {1013, 3, 13, 5, 1, -12},
    {1018, 14, 10, 16, 1, -9},
    {1036, 9, 10, 11, 1, -9},
    {1048, 10, 10, 11, 1, -9},
    {1061, 10, 14, 11, 1, -9},
    {1079, 9, 14, 11, 1, -9},
    {1095, 6, 10, 7, 1, -9},
    {1103, 9, 10, 10, 1, -9},
    {1115, 5, 12, 6, 1, -11},
    {1123, 9, 10, 11, 1, -9},
    {1135, 10, 10, 10, 0, -9},
    {1148, 14, 10, 14, 0, -9},
    {1166, 10, 10, 10, 0, -9},
    {1179, 10, 14, 10, 0, -9},
    {1197, 8, 10, 9, 1, -9},
    {1207, 4, 17, 7, 1, -12},
    {1216, 1, 17, 5, 2, -12},
    {1219, 4, 17, 7, 2, -12},
    {1228, 8, 2, 9, 0, -4}};

const GFXfont FreeSansBold9pt7b = {(uint8_t *)FreeSansBold9pt7bBitmaps,
                                           (GFXglyph *)FreeSansBold9pt7bGlyphs,
                                           0x20, 0x7E, 22};
# 17 "main.c" 2

# 1 "./Picopixel.h" 1



const uint8_t PicopixelBitmaps[] = {
    0xE8, 0xB4, 0x57, 0xD5, 0xF5, 0x00, 0x4E, 0x3E, 0x80, 0xA5, 0x4A, 0x4A,
    0x5A, 0x50, 0xC0, 0x6A, 0x40, 0x95, 0x80, 0xAA, 0x80, 0x5D, 0x00, 0x60,
    0xE0, 0x80, 0x25, 0x48, 0x56, 0xD4, 0x75, 0x40, 0xC5, 0x4E, 0xC5, 0x1C,
    0x97, 0x92, 0xF3, 0x1C, 0x53, 0x54, 0xE5, 0x48, 0x55, 0x54, 0x55, 0x94,
    0xA0, 0x46, 0x64, 0xE3, 0x80, 0x98, 0xC5, 0x04, 0x56, 0xC6, 0x57, 0xDA,
    0xD7, 0x5C, 0x72, 0x46, 0xD6, 0xDC, 0xF3, 0xCE, 0xF3, 0x48, 0x72, 0xD4,
    0xB7, 0xDA, 0xF8, 0x24, 0xD4, 0xBB, 0x5A, 0x92, 0x4E, 0x8E, 0xEB, 0x58,
    0x80, 0x9D, 0xB9, 0x90, 0x56, 0xD4, 0xD7, 0x48, 0x56, 0xD4, 0x40, 0xD7,
    0x5A, 0x71, 0x1C, 0xE9, 0x24, 0xB6, 0xD4, 0xB6, 0xA4, 0x8C, 0x6B, 0x55,
    0x00, 0xB5, 0x5A, 0xB5, 0x24, 0xE5, 0x4E, 0xEA, 0xC0, 0x91, 0x12, 0xD5,
    0xC0, 0x54, 0xF0, 0x90, 0xC7, 0xF0, 0x93, 0x5E, 0x71, 0x80, 0x25, 0xDE,
    0x5E, 0x30, 0x6E, 0x80, 0x77, 0x9C, 0x93, 0x5A, 0xB8, 0x45, 0x60, 0x92,
    0xEA, 0xAA, 0x40, 0xD5, 0x6A, 0xD6, 0x80, 0x55, 0x00, 0xD7, 0x40, 0x75,
    0x90, 0xE8, 0x71, 0xE0, 0xBA, 0x40, 0xB5, 0x80, 0xB5, 0x00, 0x8D, 0x54,
    0xAA, 0x80, 0xAC, 0xE0, 0xE5, 0x70, 0x6A, 0x26, 0xFC, 0xC8, 0xAC, 0x5A};

const GFXglyph PicopixelGlyphs[] = {{0, 0, 0, 2, 0, 1},
                                            {0, 1, 5, 2, 0, -4},
                                            {1, 3, 2, 4, 0, -4},
                                            {2, 5, 5, 6, 0, -4},
                                            {6, 3, 6, 4, 0, -4},
                                            {9, 3, 5, 4, 0, -4},
                                            {11, 4, 5, 5, 0, -4},
                                            {14, 1, 2, 2, 0, -4},
                                            {15, 2, 5, 3, 0, -4},
                                            {17, 2, 5, 3, 0, -4},
                                            {19, 3, 3, 4, 0, -3},
                                            {21, 3, 3, 4, 0, -3},
                                            {23, 2, 2, 3, 0, 0},
                                            {24, 3, 1, 4, 0, -2},
                                            {25, 1, 1, 2, 0, 0},
                                            {26, 3, 5, 4, 0, -4},
                                            {28, 3, 5, 4, 0, -4},
                                            {30, 2, 5, 3, 0, -4},
                                            {32, 3, 5, 4, 0, -4},
                                            {34, 3, 5, 4, 0, -4},
                                            {36, 3, 5, 4, 0, -4},
                                            {38, 3, 5, 4, 0, -4},
                                            {40, 3, 5, 4, 0, -4},
                                            {42, 3, 5, 4, 0, -4},
                                            {44, 3, 5, 4, 0, -4},
                                            {46, 3, 5, 4, 0, -4},
                                            {48, 1, 3, 2, 0, -3},
                                            {49, 2, 4, 3, 0, -3},
                                            {50, 2, 3, 3, 0, -3},
                                            {51, 3, 3, 4, 0, -3},
                                            {53, 2, 3, 3, 0, -3},
                                            {54, 3, 5, 4, 0, -4},
                                            {56, 3, 5, 4, 0, -4},
                                            {58, 3, 5, 4, 0, -4},
                                            {60, 3, 5, 4, 0, -4},
                                            {62, 3, 5, 4, 0, -4},
                                            {64, 3, 5, 4, 0, -4},
                                            {66, 3, 5, 4, 0, -4},
                                            {68, 3, 5, 4, 0, -4},
                                            {70, 3, 5, 4, 0, -4},
                                            {72, 3, 5, 4, 0, -4},
                                            {74, 1, 5, 2, 0, -4},
                                            {75, 3, 5, 4, 0, -4},
                                            {77, 3, 5, 4, 0, -4},
                                            {79, 3, 5, 4, 0, -4},
                                            {81, 5, 5, 6, 0, -4},
                                            {85, 4, 5, 5, 0, -4},
                                            {88, 3, 5, 4, 0, -4},
                                            {90, 3, 5, 4, 0, -4},
                                            {92, 3, 6, 4, 0, -4},
                                            {95, 3, 5, 4, 0, -4},
                                            {97, 3, 5, 4, 0, -4},
                                            {99, 3, 5, 4, 0, -4},
                                            {101, 3, 5, 4, 0, -4},
                                            {103, 3, 5, 4, 0, -4},
                                            {105, 5, 5, 6, 0, -4},
                                            {109, 3, 5, 4, 0, -4},
                                            {111, 3, 5, 4, 0, -4},
                                            {113, 3, 5, 4, 0, -4},
                                            {115, 2, 5, 3, 0, -4},
                                            {117, 3, 5, 4, 0, -4},
                                            {119, 2, 5, 3, 0, -4},
                                            {121, 3, 2, 4, 0, -4},
                                            {122, 4, 1, 4, 0, 1},
                                            {123, 2, 2, 3, 0, -4},
                                            {124, 3, 4, 4, 0, -3},
                                            {126, 3, 5, 4, 0, -4},
                                            {128, 3, 3, 4, 0, -2},
                                            {130, 3, 5, 4, 0, -4},
                                            {132, 3, 4, 4, 0, -3},
                                            {134, 2, 5, 3, 0, -4},
                                            {136, 3, 5, 4, 0, -3},
                                            {138, 3, 5, 4, 0, -4},
                                            {140, 1, 5, 2, 0, -4},
                                            {141, 2, 6, 3, 0, -4},
                                            {143, 3, 5, 4, 0, -4},
                                            {145, 2, 5, 3, 0, -4},
                                            {147, 5, 3, 6, 0, -2},
                                            {149, 3, 3, 4, 0, -2},
                                            {151, 3, 3, 4, 0, -2},
                                            {153, 3, 4, 4, 0, -2},
                                            {155, 3, 4, 4, 0, -2},
                                            {157, 2, 3, 3, 0, -2},
                                            {158, 3, 4, 4, 0, -3},
                                            {160, 2, 5, 3, 0, -4},
                                            {162, 3, 3, 4, 0, -2},
                                            {164, 3, 3, 4, 0, -2},
                                            {166, 5, 3, 6, 0, -2},
                                            {168, 3, 3, 4, 0, -2},
                                            {170, 3, 4, 4, 0, -2},
                                            {172, 3, 4, 4, 0, -3},
                                            {174, 3, 5, 4, 0, -4},
                                            {176, 1, 6, 2, 0, -4},
                                            {177, 3, 5, 4, 0, -4},
                                            {179, 4, 2, 5, 0, -3}};

const GFXfont Picopixel = {(uint8_t *)PicopixelBitmaps,
                                   (GFXglyph *)PicopixelGlyphs, 0x20, 0x7E, 7};
# 18 "main.c" 2
# 41 "main.c"
void myTimer2ISR(void);
char getStates(void);
void change_state(char);
void update_display(int8_t);
void display_default(void);
void display_page1(void);
void display_page2(void);
void display_page3(void);
void display_page4(void);
int map(float,float,float,float,float);
void text6_display(uint8_t,uint8_t,float,uint16_t);
void text2_display(uint8_t,uint8_t,uint8_t,uint16_t);
void clean_writable_area(void);
uint8_t counter = 0;
uint8_t one_sec = 0;
uint8_t led_state = 0;
int8_t current_display = 0;
int8_t current_rotation = 1;
uint8_t flag_update_display = 1;
uint8_t flag_rotation = 1;
uint8_t not_retain_values = 1;
uint8_t position_text[8][2];
uint16_t previous_valus[8];
float previous_valus_ft[3];
uint8_t update = 0;
float adc_err;

void myTimer2ISR(void){
    counter++;
    update++;

    if(counter == 50)
    {
        counter = 0;
        one_sec = 1;
    }
}
char getStates(void)
{
    if (PORTAbits.RA7 == 1)
        return 1;
    if (PORTAbits.RA6 == 1)
        return 2;
    if (PORTCbits.RC0 == 1)
        return 3;
    if (PORTCbits.RC1 == 1)
        return 4;
return 0;
}
void change_state(char state)
{
    switch(state)
    {
        case 1: printf("b1");
                current_display--;
                if (current_display < 0)
                    current_display = 5;
                break;
        case 2: printf("b2");
                current_display++;
                if (current_display > 5)
                    current_display = 0;
                break;
        case 3: printf("b3");
                current_rotation--;
                if (current_rotation < 0)
                    current_rotation = 3;
                break;
        case 4: printf("b4");
                current_rotation++;
                if (current_rotation > 3)
                    current_rotation = 0;
                break;
        default:printf("b0");
                break;
    }
}


void update_display(int8_t cases)
{
    switch(cases)
 {
        case 0:
            display_page1();
            break;
        case 1:
            display_page1();
            break;
        case 2:
            display_page2();
            break;
        case 3:
            display_page3();
            break;
        case 4:
            display_page4();
            break;
        case 5:
            display_page4();
            break;
        default:
            display_page1();
    }
}

void main(void)
{
    char button_state;
    char last_button_state;
    uint16_t result;
    OSCCON = 0x70;
    TRISB = 0x00;
    TRISBbits.TRISB0 = 0;
    TRISAbits.TRISA7 = 1;
    TRISAbits.TRISA6 = 1;
    TRISCbits.TRISC1 = 1;
    TRISCbits.TRISC0 = 1;
    TRISCbits.TRISC2 = 0;

    TRISCbits.TRISC5 = 0;
    TRISCbits.TRISC4 = 1;

    LATBbits.LATB0 = 1;
    LATCbits.LATC2 = 1;


    EUSART1_Initialize();
    ADC_Initialize();
    SPI_Initialize();
    SPI_Open(SPI_DEFAULT);
 INTERRUPT_Initialize();
 TMR2_Initialize();
    TMR2_SetInterruptHandler(myTimer2ISR);
    printf("nauman\n\r");
    TFT_BlackTab_Initialize();
    fillScreen(0x0000);
    setRotation(1);
    setTextWrap(0);
    setFont(&FreeSansBold9pt7b);
    display_default();
    display_page1();
    (INTCONbits.GIE = 1);

    (INTCONbits.PEIE = 1);
    while(1)
    {
        button_state = getStates();
        if (button_state != last_button_state)
        {
            if(button_state > 0)
            {
                change_state(button_state);
                if(button_state == 3 || button_state == 4 )
                {
                    setRotation((uint8_t)current_rotation);
                    not_retain_values = 0;
                    if(current_rotation == 1 || current_rotation == 3)
                        flag_rotation = 1;
                    else
                        flag_rotation = 0;
                    display_default();
                }
                flag_update_display = 1;
            }
            last_button_state = button_state;
        }
        if(update >= 5)
        {
            result = ADC_GetConversion(channel_AN4);
            adc_err = ((result * (float)(5/1023.00))* 0.809);

            update_display(current_display);
            not_retain_values = 1;
            update = 0;
        }

    }
    return;
}


void display_default(void){
    uint8_t x0 = 5;
    uint8_t y0 = 5;
    fillScreen(0x0000);
    fillRoundRect(x0, y0, tft_width - 10,22, 1, 0x001F);

    x0 = tft_width - 25;
    y0 = 6;
    drawRoundRect(x0,y0,12,15,3,0xFFFF);
    drawFastVLine(x0+11,y0,15,0x001F);
    drawFastVLine(x0+10,y0,15,0x001F);
    fillTriangle(x0+10,y0+10,x0+10,y0+20,x0+15,y0+15,0xFFFF);


    x0 = 12;
    y0 = 6;
    drawRoundRect(x0,y0,12,15,3,0xFFFF);
    drawFastVLine(x0,y0,15,0x001F);
    drawFastVLine(x0+1,y0,15,0x001F);
    fillTriangle(x0+1,y0+10,x0+1,y0+20,x0-4,y0+15,0xFFFF);

    x0 = 5;
    y0 = tft_height - 22;
    fillRoundRect(x0,y0, ((tft_width - 5)/2) - 5, 22, 1, 0x001F);
    fillRoundRect(((tft_width - 5)/2) + 5, y0,((tft_width - 5)/2) - 5, 22, 1, 0x001F);

    y0 = y0 + 14;
    char *txttwo = "PREV";
    char *txtone = "NEXT";
    if(flag_rotation)
    {
        x0 = 18;
        drawText( x0, y0+3, txttwo, 0xFFFF, 0xFFFF, 1);
        x0 = ((tft_width - 5)/2) + 18;
        drawText( x0, y0+3, txtone, 0xFFFF, 0xFFFF, 1);
    }
    else
    {
        x0 = 10;
        drawText( x0, y0, txttwo, 0xFFFF, 0xFFFF, 1);
        x0 = ((tft_width - 5)/2) + 10;
        drawText( x0, y0, txtone, 0xFFFF, 0xFFFF, 1);
    }
}


void display_page1(void)
{
    uint8_t x0 = 5;
    uint8_t y0 = 5;
    uint8_t GP;
    float voltage,current,temp;
    float watt,ohms,mAh,mWh;
    uint16_t result[3];
    char v0[6];


    if(flag_update_display)
    {
        clean_writable_area();

        x0 = 5;
        y0 = 45;
        position_text[0][0] = x0;
        position_text[0][1] = y0;
        drawChar(x0 + 54 ,y0,'V',0x07E0, 0x0000, 1);


        uint8_t x1 = tft_width - 45;
        uint8_t y1 = y0-3;
        drawCircle(x1,y1,4,0xFFE0);
        fillCircle(x1,y1,2,0xFFE0);
        fillRect(x1,y1-11,1,8,0xFFE0);
        drawRoundRect(x1-2,y1-13,5,11,1,0xFFE0);
        drawFastVLine(x1+3,y1-11,1,0xFFE0);
        drawFastVLine(x1+3,y1-9,1,0xFFE0);
        drawFastVLine(x1+3,y1-7,1,0xFFE0);


        drawCircle(tft_width - 20,y0 - 10,1,0xFFE0);
        drawChar(tft_width - 19 ,y0,'C',0xFFE0, 0x0000, 1);


        position_text[1][0] = tft_width - 40;
        position_text[1][1] = y0;


        x0 = 5;
        y0 = y0 + 15;

        position_text[2][0] = x0;
        position_text[2][1] = y0;

        drawChar(x0 + 54,y0,'A',0x059F, 0x0000,1);


        drawChar(tft_width - 40 ,y0,'P',0xF800, 0x0000, 1);
        drawChar(tft_width - 50 ,y0,'G',0xF800, 0x0000, 1);

        position_text[3][0] = tft_width - 25;
        position_text[3][1] = y0;


        x0 = 5;
        y0 = y0 + 15;
        position_text[4][0] = 5;
        position_text[4][1] = y0;
        drawChar(55,y0,'m',0xF800, 0x0000, 1);
        drawChar(70,y0,'A',0xF800, 0x0000, 1);
        drawChar(81,y0,'h',0xF800, 0x0000, 1);

        if (flag_rotation)
        {
            position_text[5][0] = tft_width - 65;
            position_text[5][1] = y0;
            drawChar(tft_width - 15 ,y0,'0',0x001F, 0x0000, 1);
            drawFastHLine(tft_width - 15 ,y0,10,0x0000);
            drawFastHLine(tft_width - 15 ,y0,4,0x001F);
            drawFastHLine(tft_width - 9 ,y0,4,0x001F);
        }

        x0 = 5;
        y0 = y0 + 15;
        position_text[6][0] = x0;
        position_text[6][1] = y0;




        drawChar(55,y0,'m',0xFFE0, 0x0000, 1);
        drawChar(69,y0,'W',0xFFE0, 0x0000, 1);
        drawChar(84,y0,'h',0xFFE0, 0x0000, 1);

        if(flag_rotation)
        {
            position_text[7][0] = tft_width - 65;
            position_text[7][1] = y0;
            drawChar(tft_width - 16 ,y0,'W',0xFFFF, 0x0000, 1);
        }
        else
        {
            y0 = y0 + 15;
            position_text[7][0] = 5;
            position_text[7][1] = y0;

            drawChar(63,y0,'W',0xFFFF, 0x0000, 1);

            y0 = y0 + 15;
            position_text[5][0] = 5;
            position_text[5][1] = y0;

            drawChar(68,y0,'0',0x001F, 0x0000, 1);
            drawFastHLine(68 ,y0,10,0x0000);
            drawFastHLine(68 ,y0,4,0x001F);
            drawFastHLine(74,y0,4,0x001F);
        }
        if (current_display == 1 )
        {
            GP = 2;
            mWh = 10782;

            text2_display(position_text[3][0],position_text[3][1],GP,0xF800);

            text6_display(position_text[6][0],position_text[6][1],mWh,0xFFE0);
        }
        else
        {
            GP = 1;
            mWh = 10782;

            text2_display(position_text[3][0],position_text[3][1],GP,0xF800);

            text6_display(position_text[6][0],position_text[6][1],mWh,0xFFE0);
        }

    }


    if (current_display == 1 )
    {
        result[0] = ADC_GetConversion(channel_AN2);
        _delay((unsigned long)((1)*(8000000/4000.0)));
        result[1] = ADC_GetConversion(channel_AN1);
        _delay((unsigned long)((1)*(8000000/4000.0)));
    }
    else
    {
        result[0] = ADC_GetConversion(channel_AN3);
        _delay((unsigned long)((1)*(8000000/4000.0)));
        result[1] = ADC_GetConversion(channel_AN0);
        _delay((unsigned long)((1)*(8000000/4000.0)));
    }


    result[2] = ADC_GetConversion(channel_AN4);
    if (result[2] != previous_valus[2] || flag_update_display)
    {
        previous_valus[2] = result[2];
        temp = (result[2] * (float)(5/1023.00)) * 50.0 * adc_err;
        text2_display(position_text[1][0],position_text[1][1],(uint8_t)temp,0xFFE0);
    }

    if ((result[0] != previous_valus[0]) || (result[1] != previous_valus[1]) || flag_update_display)
    {

        if ((result[0] != previous_valus[0]) || flag_update_display)
        {
            previous_valus[0] = result[0];
            voltage = (result[0] * (float)(5/1023.00)) * adc_err;
            text6_display(position_text[0][0],position_text[0][1],voltage,0x07E0);


            mAh = mWh/voltage*10;
           text6_display(position_text[4][0],position_text[4][1],mAh,0xF800);
        }


        if ((result[1] != previous_valus[1]) || flag_update_display)
        {
            previous_valus[1] = result[1];
            current = (result[1] * (float)(5/1023.00)) * adc_err;
            text6_display(position_text[2][0],position_text[2][1],current,0x059F);
        }


        ohms = voltage/current;
        text6_display(position_text[5][0],position_text[5][1],ohms,0x001F);


        watt = voltage * current;
        text6_display(position_text[7][0],position_text[7][1],watt,0xFFFF);
    }
    flag_update_display = 0;
}
void display_page2(void){

    uint8_t x0 = 5;
    uint8_t y0 = 5;
    char v0[6];
    float mWh,mAh,A;
    static uint8_t hour,min,sec;

    if(flag_update_display)
    {
        clean_writable_area();

        x0 = 5;
        y0 = 45;
        position_text[0][0] = x0;
        position_text[0][1] = y0;

        drawChar(60,y0,'m',0x07E0, 0x0000, 1);
        drawChar(77,y0,'A',0x07E0, 0x0000, 1);
        drawChar(94,y0,'h',0x07E0, 0x0000, 1);


        x0 = 5;
        y0 = y0 + 15;
        position_text[1][0] = x0;
        position_text[1][1] = y0;

        drawChar(60,y0,'m',0x059F, 0x0000, 1);
        drawChar(76,y0,'W',0x059F, 0x0000, 1);
        drawChar(94,y0,'h',0x059F, 0x0000, 1);


        x0 = 5;
        y0 = y0 + 15;
        position_text[2][0] = x0;
        position_text[2][1] = y0;

        drawChar(28,y0,':',0xFFFF, 0x0000, 1);

        position_text[3][0] = 35;
        position_text[3][1] = y0;

        drawChar(59 ,y0,':',0xFFFF, 0x0000, 1);

        position_text[4][0] = 66;
        position_text[4][1] = y0;



        x0 = 5;
        y0 = y0 + 15;

        position_text[5][0] = 20;
        position_text[5][1] = y0;

        drawChar(70,y0,'A',0xFFFF, 0x0000, 1);

        drawChar(90,y0,'R',0xF800, 0x0000, 1);
        drawChar(103,y0,'E',0xF800, 0x0000, 1);
        drawChar(114,y0,'C',0xF800, 0x0000, 1);
        if (not_retain_values)
        {
            hour = 0;
            min = 0;
            sec = 0;
        }
    }


        mAh = 10782;
        if (mAh != previous_valus_ft[0] || flag_update_display)
        {
            previous_valus_ft[0] = mAh;
            text6_display(position_text[0][0],position_text[0][1],mWh,0x07E0);
        }

        mWh = 10782;
        if (mWh != previous_valus_ft[1] || flag_update_display)
        {
            previous_valus_ft[1] = mWh;
            text6_display(position_text[1][0],position_text[1][1],mWh,0x059F);
        }
        A = 1.245;
        if (A != previous_valus_ft[2] || flag_update_display)
        {
            previous_valus_ft[2] = A;
            text6_display(position_text[5][0],position_text[5][1],A,0xFFFF);
        }

        if (one_sec || flag_update_display)
        {
            one_sec = 0;
            sec++;
            if (sec == 60)
                {
                    sec = 0;
                    min++;
                }
            if (min == 60)
                {
                    min = 0;
                    hour++;
                }
            if (hour == 24)
                {
                    hour = 0;
                }
            if (hour != previous_valus[0] || flag_update_display)
            {
                previous_valus[0] = hour;
                text2_display(position_text[2][0],position_text[2][1],hour,0xFFFF);
            }

            if (min != previous_valus[1] || flag_update_display)
            {
                previous_valus[1] = min;
                text2_display(position_text[3][0],position_text[3][1],min,0xFFFF);
            }

            if (sec != previous_valus[2] || flag_update_display)
            {
                previous_valus[2] = sec;
                text2_display(position_text[4][0],position_text[4][1],sec,0xFFFF);
            }
        }

    flag_update_display = 0;
}
void display_page3(void){
    uint8_t x0 = 5;
    uint8_t y0 = 5;
    static uint8_t min,temp,bright;
    char v0[6];
    if(flag_update_display)
    {
        clean_writable_area();
        if(flag_rotation)
        {

            x0 = 5;
            y0 = 30;
            drawRoundRect(x0,y0,tft_width - 10,tft_height - 56,3,0xFFFF);
            drawFastVLine(x0 + 50,y0,tft_height - 56,0xFFFF);
            drawFastHLine(x0,y0+(tft_height - 56)/3,tft_width - 10,0xFFFF);
            drawFastHLine(x0,y0+2*(tft_height - 56)/3,tft_width - 10,0xFFFF);


            x0 = 20;
            y0 = 32;
            drawRectWH(x0,y0,18,18,0xF800);
            drawLine(x0,y0+9,x0+2,y0+9,0xF800);
            drawLine(x0+17,y0+9,x0+15,y0+9,0xF800);
            drawLine(x0+9,y0,x0+9,y0+2,0xF800);
            drawLine(x0+9,y0+17,x0+9,y0+15,0xF800);
            drawFastVLine(x0+9,y0+9-5,5,0xF800);
            drawFastHLine(x0+9,y0+9,5,0xF800);


            x0 = 58;
            y0 = 47;
            position_text[0][0] = x0;
            position_text[0][1] = y0;

            x0 = 81;
            char *txtthree = "Minutes";
            drawText(x0, y0, txtthree, 0xF800, 0xFFFF, 1);


            x0 = 30;
            y0 = 64;
            fillCircle(x0,y0,5,0x07E0);
            drawFastVLine(x0,y0-10,3,0x07E0);
            drawFastVLine(x0,y0+7,3,0x07E0);
            drawFastHLine(x0-10,y0,3,0x07E0);
            drawFastHLine(x0+7,y0,3,0x07E0);
            drawLine(x0,y0,x0+9,y0+9,0x07E0);
            drawLine(x0,y0,x0+9,y0-9,0x07E0);
            drawLine(x0,y0,x0-9,y0+9,0x07E0);
            drawLine(x0,y0,x0-9,y0-9,0x07E0);
            drawCircle(x0,y0,6,0x0000);


            x0 = 58;
            y0 = 69;
            position_text[1][0] = x0;
            position_text[1][1] = y0;
            x0 = 81;
            char *txtfive = "Bright";
            drawText(x0, y0, txtfive, 0x07E0, 0xFFFF, 1);


            uint8_t x1 = 30;
            uint8_t y1 = 92;
            drawCircle(x1,y1,4,0xFFE0);
            fillCircle(x1,y1,2,0xFFE0);
            fillRect(x1,y1-11,1,8,0xFFE0);
            drawRoundRect(x1-2,y1-13,5,11,1,0xFFE0);
            drawFastVLine(x1+3,y1-11,1,0xFFE0);
            drawFastVLine(x1+3,y1-9,1,0xFFE0);
            drawFastVLine(x1+3,y1-7,1,0xFFE0);

            x0 = 58;
            y0 = 93;
            position_text[2][0] = x0;
            position_text[2][1] = y0;
            x0 = 81;
            char *txtfour = "Temp";
            drawText(x0, y0, txtfour, 0xFFE0, 0xFFFF, 1);
        }
        else
        {
            x0 = 5;
            y0 = 30;
            drawRoundRect(x0,y0,tft_width - 10,tft_height - 56,3,0xFFFF);
            drawFastVLine(x0 + 30,y0,tft_height - 56,0xFFFF);
            drawFastHLine(x0,y0+(tft_height - 56)/3,tft_width - 10,0xFFFF);
            drawFastHLine(x0,y0+2*(tft_height - 56)/3,tft_width - 10,0xFFFF);


            x0 = 10;
            y0 = 38;
            drawRectWH(x0,y0,18,18,0xF800);
            drawLine(x0,y0+9,x0+2,y0+9,0xF800);
            drawLine(x0+17,y0+9,x0+15,y0+9,0xF800);
            drawLine(x0+9,y0,x0+9,y0+2,0xF800);
            drawLine(x0+9,y0+17,x0+9,y0+15,0xF800);
            drawFastVLine(x0+9,y0+9-5,5,0xF800);
            drawFastHLine(x0+9,y0+9,5,0xF800);

            x0 = 36;
            y0 = 53;
            position_text[0][0] = x0;
            position_text[0][1] = y0;
            x0 = 58;
            char *txtthree = "Minute";
            drawText(x0, y0, txtthree, 0xF800, 0xFFFF, 1);

            x0 = 20;
            y0 = 80;
            fillCircle(x0,y0,5,0x07E0);
            drawFastVLine(x0,y0-10,3,0x07E0);
            drawFastVLine(x0,y0+7,3,0x07E0);
            drawFastHLine(x0-10,y0,3,0x07E0);
            drawFastHLine(x0+7,y0,3,0x07E0);
            drawLine(x0,y0,x0+9,y0+9,0x07E0);
            drawLine(x0,y0,x0+9,y0-9,0x07E0);
            drawLine(x0,y0,x0-9,y0+9,0x07E0);
            drawLine(x0,y0,x0-9,y0-9,0x07E0);
            drawCircle(x0,y0,6,0x0000);

            x0 = 36;
            y0 = 85;
            position_text[1][0] = x0;
            position_text[1][1] = y0;
            x0 = 58;
            char *txtfive = "Bright";
            drawText(x0, y0, txtfive, 0x07E0, 0xFFFF, 1);


            uint8_t x1 = 20;
            uint8_t y1 = 122;
            drawCircle(x1,y1,4,0xFFE0);
            fillCircle(x1,y1,2,0xFFE0);
            fillRect(x1,y1-11,1,8,0xFFE0);
            drawRoundRect(x1-2,y1-13,5,11,1,0xFFE0);
            drawFastVLine(x1+3,y1-11,1,0xFFE0);
            drawFastVLine(x1+3,y1-9,1,0xFFE0);
            drawFastVLine(x1+3,y1-7,1,0xFFE0);


            x0 = 36;
            y0 = 120;
            position_text[2][0] = x0;
            position_text[2][1] = y0;
            x0 = 58;
            char *txtfour = "Temp";
            drawText(x0, y0, txtfour, 0xFFE0, 0xFFFF, 1);


            min = 0;
            bright = 0;
            temp = 0;

        }
    }


    if(one_sec){
        min++;
        bright++;
        temp++;
        one_sec = 0;
    }

    if (min != previous_valus[0] || flag_update_display)
    {
        previous_valus[0] = min;
        text2_display(position_text[0][0],position_text[0][1],min,0xF800);
    }

    if (bright != previous_valus[1] || flag_update_display)
    {
        previous_valus[1] = bright;
        text2_display(position_text[1][0],position_text[1][1],bright,0x07E0);
    }

    if (temp != previous_valus[2] || flag_update_display)
    {
        previous_valus[2] = temp;
        text2_display(position_text[2][0],position_text[2][1],temp,0xFFE0);
    }

    flag_update_display = 0;
}
void display_page4(void){
    char v0[6];
    uint16_t result;
    float voltage;
    static uint8_t x0 = 5;
    static uint8_t y0 = 5;
    static uint8_t graph_y_min;
    static uint8_t graph_y_max;
    float k = 5.5;
    uint8_t value;
    uint8_t i;
    static uint8_t buffer_y[10];

    if (flag_update_display)
    {
        x0 = 25;
        y0 = 30;
        clean_writable_area();
        setFont(&Picopixel);
        snprintf(v0, 6, "%.2f", 5.00);
        drawText(x0-20,y0+3,v0, 0xFFFF, 0x0000, 1);
        drawChar(x0-5,y0+3,'V',0xFFFF, 0x0000, 1);
        drawFastHLine(x0-1,y0+1,3,0xFFFF);
        for ( i=0;i < 6;i++)
        {
            drawFastHLine(x0-1,y0+3+11*i,1,0xFFFF);
            drawFastHLine(x0-1,y0+5+11*i,1,0xFFFF);
            drawFastHLine(x0-1,y0+7+11*i,1,0xFFFF);
            drawFastHLine(x0-1,y0+9+11*i,1,0xFFFF);
            snprintf(v0, 6, "%.2f", 5.00 - 0.833*(i+1));
            drawText(x0-20,y0+3+11*(i+1),v0, 0xFFFF, 0x0000, 1);
            drawChar(x0-5,y0+3+11*(i+1),'V',0xFFFF, 0x0000, 1);
            drawFastHLine(x0-1,y0+1+11*(i+1),3,0xFFFF);
        }
        graph_y_min = y0 + 1;

        graph_y_max = y0 + 67;

        setFont(&FreeSansBold9pt7b);
        for (i = 0; i < 10; i++)
            buffer_y[i] = graph_y_max;
        i = 0;
    }
    if(current_display == 4)
        result = ADC_GetConversion(channel_AN2);
    else
        result = ADC_GetConversion(channel_AN3);
    voltage = result * (float)(5/1023.00) * adc_err ;
    value = map ((float)result,0.0,1023.0,(float)graph_y_max,(float)graph_y_min);
    for (i = 0; i < 10 - 1; i++)
        drawLine(x0+10*i,buffer_y[i],x0+10*(i+1),buffer_y[i+1],0x0000);
    for (i = 0; i < 10 -1;i++)
        {
            buffer_y[i] = buffer_y[i+1];
        }
    buffer_y[10 -1] = value;
    for (i = 0; i < 10 -1 ; i++)
        drawLine(x0+10*i,buffer_y[i],x0+10*(i+1),buffer_y[i+1],0xFFE0);


    flag_update_display = 0;
}

int map(float x, float in_min, float in_max, float out_min, float out_max) {

   float a = x - in_min;
   float b = out_max - out_min;
   float c = in_max - in_min;
   float d = (a/c);
   float e = d * b + out_min;
   return (int)e;
}

void clean_writable_area(void){
    fillRect(5,29,tft_width - 5,tft_height - 52,0x0000);
}
void text6_display(uint8_t x,uint8_t y,float value,uint16_t color)
{
   char v0[6];
   fillRect(x,y-12,50,15,0x0000);
   snprintf(v0, 6, "%4f", value);
   drawText(x,y,v0, color, 0x0000, 1);
}
void text2_display(uint8_t x,uint8_t y,uint8_t value,uint16_t color)
{
   char v0[6];
   fillRect(x,y-13,20,15,0x0000);
   snprintf(v0, 6, "%2d", value);
   drawText(x,y,v0, color, 0x0000, 1);
}
