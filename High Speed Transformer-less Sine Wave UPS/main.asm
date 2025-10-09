  list        p=16f877A    ; list directive to define processor
    #include    <p16f877A.inc>    ; processor specific variable definitions
    
    __CONFIG _CP_OFF & _WDT_OFF & _BODEN_OFF & _PWRTE_ON & _HS_OSC & _WRT_OFF & _LVP_ON & _CPD_OFF

    TEMP         EQU    21h
    COUNT        EQU    20h    
    ENDSINE      EQU    .40    ;28h
    TOGGLE       EQU    .08
    DLCOUNT     	 EQU    22h
    CHSELECT	   EQU    23h
    ADCREST        	EQU    24h
    REFCNT        EQU    25h
    REFVAL        EQU    26h
    DIFFER        EQU    27h        
    HALFSINE    EQU    .21
    TABLEV        EQU 29h
    
    ORG    0x000            ; processor reset vector

    NOP                        
      GOTO    MAIN          

    ORG    0x030            
MAIN    
        CLRF    COUNT
        CALL    TABLE
        BCF     STATUS, RP1
        BCF     STATUS, RP0        
        MOVWF    CCPR2L
        MOVWF    TABLEV
        BCF        PORTC,1
        BCF        PORTC,3
        CLRF    TMR2        
        CLRF    T2CON
		BSF		T2CON,0
        MOVLW    0x3C
        MOVWF    CCP2CON            
	    BSF     STATUS, RP0
        MOVLW   .249            ;4khz
        MOVWF   PR2
		CLRF    TRISD
        BCF     TRISC,1    
        BCF     TRISC,3
		BCF     TRISC,4		;oe
		BCF     TRISB,4		;LED
		BCF     TRISC,5		;rst_3525
        BCF     STATUS, RP0    
        BSF     PORTC,1
		BCF		PORTC,4	;oe
		BSF     PORTB,4		;LED
		BCF		PORTC,5
		BSF		PORTD,1
		BSF		PORTD,0
        BSF     T2CON,2        
REPEAT
        BCF     STATUS, RP0
        BCF     PIR1,TMR2IF
        CALL    DELAY_125us
        CALL    UPDATER
        CALL    LOOP
        GOTO    REPEAT    
LOOP
        BTFSS    PIR1,TMR2IF    
        GOTO    LOOP
        RETURN

UPDATER        
        MOVLW    .16                ;0,8,16,24,32,40,48,56
        MOVWF    CHSELECT
        CALL    ADCROUT
        CALL    REFERANCE
        MOVF    DIFFER,W
        BCF     STATUS, RP1
        BCF     STATUS, RP0        
        MOVWF    CCPR2L        
        MOVLW    ENDSINE
        SUBWF    COUNT,W
        BTFSC    STATUS,2
        GOTO    RECYCLE
        RETURN
RECYCLE    
        CLRF    COUNT
        BCF     STATUS, RP0
		CLRF    TMR2
        BCF        T2CON,2
		BSF		PORTC,4
        MOVLW    TOGGLE
        XORWF    PORTC,F
        BCF     STATUS, RP0
		BCF		PORTC,4
        BSF        T2CON,2
        RETURN    
ADCROUT
        BCF     STATUS, RP0 
        BCF     STATUS, RP1
        BSF        ADCON0,0
        BSF     STATUS, RP0 ;
        MOVLW    .255
        MOVWF    TRISA
        BCF     STATUS, RP0 
        MOVLW    .128
        IORWF    ADCON0,F
        MOVF    CHSELECT ,W
        IORWF    ADCON0,F
        BSF     STATUS, RP0 
        MOVLW    .00
        MOVWF    ADCON1
        CALL    DELAY_20us
        BCF     STATUS, RP0 
        BSF        ADCON0,2
CONLOOP
        BTFSC    ADCON0,2    
        GOTO    CONLOOP
        BCF     STATUS, RP0 
        MOVF    ADRESH,W
        MOVWF    ADCREST
        RETURN
REFERANCE
        CALL    REFTABLE
        MOVWF    REFVAL
        BTFSC    PORTC,3
        CALL    NEGAT
        BCF     STATUS, RP0
        MOVF    ADCREST,W
        MOVWF    TEMP
        MOVLW    .128
        SUBWF    TEMP,W    
        BTFSC    STATUS,2
        GOTO    NODIFF    
        SUBWF    REFVAL,W
        BTFSS    STATUS,0
        GOTO    NODIFF
        MOVWF    DIFFER
        GOTO    ADDER
NEGAT
        MOVF    ADCREST,W
        SUBLW    .128
        ADDLW    .128
        MOVWF    ADCREST
        RETURN
NODIFF    
        MOVLW    .0
        MOVWF    DIFFER
        GOTO    ADDER
ADDER
        CALL    TABLE
        MOVWF    TABLEV
        MOVWF    TEMP
        MOVF    DIFFER,W
        ADDWF    TABLEV,W
        MOVWF    DIFFER
        SUBLW    .249
        BTFSC    STATUS,0
        RETURN
        MOVF    TEMP,W
        MOVWF    DIFFER
        RETURN            
TABLE    INCF    COUNT,F
        MOVF    COUNT,W        
        ADDWF     PCL,F
        RETLW    .0
        RETLW    .20        ;1
        RETLW    .39        ;2
        RETLW    .58        ;3
        RETLW    .77        ;4
        RETLW    .95        ;5
        RETLW    .113    ;6
        RETLW     .130    ;7
        RETLW    .146    ;8
        RETLW     .162    ;9
        RETLW    .176    ;10
        RETLW     .189    ;11
        RETLW    .201    ;12
        RETLW     .212    ;13
        RETLW    .222    ;14
        RETLW     .230    ;15
        RETLW    .237    ;16
        RETLW     .242    ;17
        RETLW    .246    ;18
        RETLW     .248    ;19
        RETLW    .249    ;20
        RETLW     .248    ;21
        RETLW    .246   ;22
        RETLW     .242    ;23
        RETLW    .237   ;24
        RETLW     .230    ;25
        RETLW    .222    ;26
        RETLW     .212    ;27
        RETLW    .201    ;28
        RETLW     .189    ;29
        RETLW    .176    ;30
        RETLW     .162    ;31
        RETLW    .146    ;32
        RETLW    .130    ;33
        RETLW    .113    ;34
        RETLW    .95        ;35
        RETLW    .77        ;36
        RETLW    .58        ;37
        RETLW    .39        ;38
        RETLW    .20        ;39
        RETLW    .0        ;40    
REFTABLE
        MOVF    COUNT,W        
        ADDWF     PCL,F
        RETLW    .0
        RETLW    .9        ;1
        RETLW    .18        ;2
        RETLW    .26        ;3
        RETLW    .35        ;4
        RETLW    .43        ;5
        RETLW    .51        ;6
        RETLW     .59        ;7
        RETLW    .66        ;8
        RETLW     .73        ;9
        RETLW    .79        ;10
        RETLW     .85        ;11
        RETLW    .91        ;12
        RETLW     .95        ;13
        RETLW    .100    ;14
        RETLW     .103    ;15
        RETLW    .107    ;16
        RETLW     .109    ;17
        RETLW    .110    ;18
        RETLW     .111    ;19
        RETLW    .112    ;20
        RETLW     .111    ;21
        RETLW    .110    ;22
        RETLW     .109    ;23
        RETLW    .107    ;24
        RETLW     .103    ;25
        RETLW    .100    ;26
        RETLW     .95        ;27
        RETLW    .91        ;28
        RETLW     .85        ;29
        RETLW    .79        ;30
        RETLW     .73        ;31
        RETLW    .66        ;32
        RETLW    .59        ;33
        RETLW    .51        ;34
        RETLW    .43        ;35
        RETLW    .35        ;36
        RETLW    .26        ;37
        RETLW    .18        ;38
        RETLW    .9        ;39
        RETLW    .0        ;40        
DELAY_20us
        MOVLW    .50
        MOVWF    DLCOUNT
DELAY_1
        DECFSZ    DLCOUNT
        GOTO    DELAY_1
        RETURN

DELAY_125us
        MOVLW    .112
        MOVWF    DLCOUNT
DELAY_2
        NOP
        NOP
        DECFSZ    DLCOUNT
        GOTO    DELAY_2
        RETURN

END
    


        

