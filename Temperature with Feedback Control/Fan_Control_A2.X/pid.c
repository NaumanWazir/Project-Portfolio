#include "pid.h"

POSPID temp_ctrl;

/********************************************/
float VariableIntergralCoefficient(float error,float absmax,float absmin);
void pos_PIDRegulation(POSPID *vPID,float processValue);
void inc_PIDRegulation(INCPID *vPID, float processValue);
void init_pid(void);
void dinit_pid(void);
void set_pid_target(float);

/*****************************************/
float VariableIntergralCoefficient(float error,float absmax,float absmin)
{
    float factor=0.0;

    if(fabs(error)<=absmin)
	{
		factor=1.0;
	}
	else if(fabs(error)>absmax)
	{
		factor=0.0;
	}
	else
	{
	factor=(absmax-fabs(error))/(absmax-absmin);
	}

	return factor;
}


void pos_PIDRegulation(POSPID *vPID,float processValue)
{
	float thisError;
	float factor;

	thisError=vPID->setpoint-processValue;
	factor= VariableIntergralCoefficient(thisError, vPID->errorabsmax,vPID->errorabsmin);

	vPID->integral+= factor*thisError;
	//vPID->integral+= thisError;
	vPID->result=vPID->proportiongain*thisError+vPID->integralgain*vPID->integral-vPID->derivativegain*(processValue-vPID->lasterror);
	vPID->lasterror=processValue;
}


void inc_PIDRegulation(INCPID *vPID, float processValue)
{
	float thisError;
	float increment;
	float pError,dError,iError;
	float factor;

	thisError=vPID->setpoint-processValue; //å¾??°å??å·???
	factor=VariableIntergralCoefficient(thisError, vPID->errorabsmax,vPID->errorabsmin);

	pError=thisError-vPID->lasterror;
	iError=factor*thisError;
	//iError=thisError;
	dError=thisError-2*(vPID->lasterror)+vPID->preerror;
	increment=vPID->proportiongain*pError+vPID->integralgain*iError+vPID->derivativegain*dError;	//å¢???è®¡ç??

	vPID->preerror=vPID->lasterror;	//å­??¾å??å·??¨ä?ä¸?æ¬¡è?ç®?
	vPID->lasterror=thisError;
	vPID->result+=increment;
}

void set_pid_target(float settemp)
{
    temp_ctrl.setpoint = settemp;    
}

void init_pid(void)
{
   
   temp_ctrl.proportiongain = 1000;          //P
   temp_ctrl.integralgain = 50;              //I
   temp_ctrl.derivativegain = 0.2;           //D
   temp_ctrl.errorabsmax= 0.9;
   temp_ctrl.errorabsmin= 0.1;
   set_pid_target(target);
   //temp_ctrl.setpoint = target;    // temperature set point.  according the requirement, set to 70.
}

void dinit_pid(void)
{
   temp_ctrl.proportiongain= 0;
   temp_ctrl.integralgain =0;
   temp_ctrl.derivativegain =0;
   temp_ctrl.errorabsmax= 0;
   temp_ctrl.errorabsmin= 0;
}