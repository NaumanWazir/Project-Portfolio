/* This file is used to handle data package received and transmitted
 * *************************************************************************
 * 		@ file: 	user_type.h
 * 	 	@ author:	YANG Xiao
 * 	 	@ Version: 	1.0
 * 	 	@ date:		2019-11-27
 ****************************************************************************
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _PID_H_
#define _PID_H_

#ifdef __cplusplus
extern "C" {
#endif


#include "stdlib.h"
#include "math.h"

#define target  70
#define max     71
#define min     69.0

typedef struct
{
    float   setpoint;
	float proportiongain;	 //æ¯?ä¾?ç³»æ??
	float integralgain;		 //ç§???ç³»æ??
	float derivativegain;	 //å¾???ç³»æ??
	float lasterror;	//??ä¸?????å·?
	float result; //è¾??ºå??
	float integral;//ç§?????
	float errorabsmax;	//??å·?ç»?å¯¹å?¼æ??å¤§å??
	float errorabsmin;	//??å·?ç»?å¯¹å?¼æ??å°???
}POSPID;			//???PID

/*å®?ä¹?ç»???ä½??????¨ä?*/
typedef struct
{
	float   setpoint;	//
	float   proportiongain;
    float   integralgain;
	float   derivativegain;	 //
	float   lasterror;
    float   preerror;
	float   deadband;
    float result;
	float errorabsmax;	 
	float errorabsmin;	//??å·?ç»?å¯¹å?¼æ??å°???
}INCPID;		//???PID

extern float VariableIntergralCoefficient(float error,float absmax,float absmin);
extern void pos_PIDRegulation(POSPID *vPID,float processValue);
extern void inc_PIDRegulation(INCPID *vPID, float processValue);
extern void init_pid(void);
extern void dinit_pid(void);
extern void set_pid_target(float);

#ifdef __cplusplus
}
#endif

#endif

/************************ (C) COPYRIGHT *****END OF FILE****/
