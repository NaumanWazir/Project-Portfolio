/*
 * File:   pid_controller.c
 * Author: nauma
 *
 * Created on February 27, 2024, 6:43 PM
 */


#include "xc.h"
#include "pid_controller.h"

double pid(PID_vars *vars, double current_err){
   vars->_integral_sum += current_err*(vars->_dt);
  
   double output = (vars->Kp)*current_err                     \
                + (vars->Ki)*(vars->_integral_sum)           \
                + (vars->Kd)*((current_err-(vars->_prev_err))\
                              /(vars->_dt)); 
  vars->_prev_err = current_err;
  
  /* limit output within output_min and output_max */
  if (output>(vars->output_max))
    output = vars->output_max;
  else if (output<(vars->output_min))
    output = vars->output_min;
  
  return output;
  
}

void pid_vars_init(PID_vars*x,double Kp,double Ki,double Kd,double output_max,double output_min,double _integral_sum,double _prev_err, double _dt){
    x->Kp = Kp;
    x->Ki = Ki;
    x->Kd = Kd;
    x->output_max = output_max;
    x->output_min = output_min;
    x->_integral_sum = _integral_sum;
    x->_dt = _dt;
    x->_prev_err = _prev_err;
}