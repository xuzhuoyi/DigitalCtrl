/*
 * This file is part of the DigitalCtrl Library.
 *
 * Copyright (c) 2019, xuzhuoyi, <xzy476386434@vip.qq.com>
 *
 * Function: Header file of PID digital algorithm.
 * Created on: 2019-05-01
 */

#ifdef DIGITALCTRL_USING_DOUBLE
typedef double dc_t;
#else
typedef float dc_t;
#endif

struct dc_pid 			
{
    dc_t ref;
    dc_t feed_back;
    dc_t pre_error;
    dc_t sum_error;
    dc_t p;
    dc_t i;
    dc_t d;
    dc_t out_max;
    dc_t out_min;
};

void dc_pid_init(struct dc_pid *pid,
                 dc_t ref,
                 dc_t p, dc_t i, dc_t d,
                 dc_t out_max, dc_t out_min);

dc_t dc_pid_calc(struct dc_pid *pid);
dc_t dc_pi_calc(struct dc_pid *pid);
