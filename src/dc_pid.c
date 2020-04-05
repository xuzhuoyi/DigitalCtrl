/*
 * This file is part of the DigitalCtrl Library.
 *
 * Copyright (c) 2019, xuzhuoyi, <xzy476386434@vip.qq.com>
 *
 * Function: Implementation of digital PID algorithm.
 * Created on: 2019-05-01
 */

#include "digital_ctrl.h"

void dc_pid_init(struct dc_pid *pid,
                 dc_t ref,
                 dc_t p, dc_t i, dc_t d,
                 dc_t out_max, dc_t out_min)
{
    pid->ref = ref;
    pid->feed_back = 0;
    pid->pre_error = 0;
    pid->sum_error = 0;
    pid->p = p;
    pid->i = i;
    pid->d = d;
    pid->out_max = out_max;
    pid->out_min = out_min;
}

dc_t dc_pid_calc(struct dc_pid *pid)
{
    dc_t error, integral, out;

    error = pid->ref - pid->feed_back;
    pid->sum_error += error;
    integral = pid->i * pid->sum_error;
    out = pid->p * error + integral + pid->d * (pid->pre_error - error);
    pid->pre_error = error;

    if (out > pid->out_max)
    {
        out = pid->out_max;
    }
    else if (out < pid->out_min)
    {
        out = pid->out_min;
    }
    
    return out;
}

dc_t dc_pi_calc(struct dc_pid *pid)
{
    dc_t error, integral, out;

    error = pid->ref - pid->feed_back;
    pid->sum_error += error;
    integral = pid->i * pid->sum_error;
    out = pid->p * error + integral;

    if (out > pid->out_max)
    {
        out = pid->out_max;
    }
    else if (out < pid->out_min)
    {
        out = pid->out_min;
    }
    
    return out;
}
