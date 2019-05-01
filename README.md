# DigitalCtrl

## Features

DigitalCtrl is a digital control algorithm library designed to simplify the programming of digital closed-loop controllers based on microcontrollers, DSPs, and processors, and to provide closed-loop controller algorithms with optimized performance and space optimization. The current version implements the PID/PI controller function and will support various derivative PID algorithms in the future, including integral limiter PID, weighted average PID, and highly optimized PID for low-frequency MCUs.

## 功能介绍

DigitalCtrl 是一个数字控制算法库，目的是简化基于单片机、DSP、处理器的数字闭环控制器的程序设计，提供性能优化、空间优化的闭环控制器算法。目前版本实现 PID/PI 控制器功能，未来将支持各类派生 PID 算法，包括积分限幅 PID、加权平均 PID、用于低主频 MCU 的高度优化 PID 等。

## 使用说明

* 包含头文件 `#include "digital_ctrl.h"`
* 定义名为xxx的结构体变量 `struct dc_pid xxx;`

函数名 | 功能 
-|-
dc_pid_init | 初始化 PID 控制器
dc_pid_calc | 执行当前周期 PID 计算
dc_pi_calc  | 执行当前周期 PI 计算（忽略参数 D）
