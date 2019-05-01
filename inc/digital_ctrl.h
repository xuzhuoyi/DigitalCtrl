/*
 * This file is part of the DigitalCtrl Library.
 *
 * Copyright (c) 2019, xuzhuoyi, <xzy476386434@vip.qq.com>
 *
 * Function: Header file of PID digital algorithm.
 * Created on: 2019-05-01
 */

struct dc_pid 			
{
    float ref;
    float feed_back;
    float pre_error;
    float sum_error;
    float p;
    float i;
    float d;
    float out_max;
    float out_min;
};

void dc_pid_init(struct dc_pid *pid,
                 float ref,
                 float p, float i, float d,
                 float out_max, float out_min);

float dc_pid_calc(struct dc_pid *pid);
float dc_pi_calc(struct dc_pid *pid);
