/*********************************************************************************************************************
* CYT2BL3 Opensourec Library 即（ CYT2BL3 开源库）是一个基于官方 SDK 接口的第三方开源库
* Copyright (c) 2022 SEEKFREE 逐飞科技
*
* 本文件是 CYT2BL3 开源库的一部分
*
* CYT2BL3 开源库 是免费软件
* 您可以根据自由软件基金会发布的 GPL（GNU General Public License，即 GNU通用公共许可证）的条款
* 即 GPL 的第3版（即 GPL3.0）或（您选择的）任何后来的版本，重新发布和/或修改它
*
* 本开源库的发布是希望它能发挥作用，但并未对其作任何的保证
* 甚至没有隐含的适销性或适合特定用途的保证
* 更多细节请参见 GPL
*
* 您应该在收到本开源库的同时收到一份 GPL 的副本
* 如果没有，请参阅<https://www.gnu.org/licenses/>
*
* 额外注明：
* 本开源库使用 GPL3.0 开源许可证协议 以上许可申明为译文版本
* 许可申明英文版在 libraries/doc 文件夹下的 GPL3_permission_statement.txt 文件中
* 许可证副本在 libraries 文件夹下 即该文件夹下的 LICENSE 文件
* 欢迎各位使用并传播本程序 但修改内容时必须保留逐飞科技的版权声明（即本声明）
*
* 文件名称          fast_foc
* 公司名称          成都逐飞科技有限公司
* 版本信息          查看 libraries/doc 文件夹内 version 文件 版本说明
* 开发环境          IAR 9.40.1
* 适用平台          CYT2BL3
* 店铺链接          https://seekfree.taobao.com/
*
* 修改记录
* 日期              作者                备注
* 2025-01-03       pudding            first version
********************************************************************************************************************/

#ifndef _fast_foc_h_
#define _fast_foc_h_


#include "zf_common_headfile.h"

typedef struct 
{
    float       encoder_proportion;
    int32       encoder_pole_pairs;
    float       duty_proportion;
    
}fast_foc_calculate_struct;


typedef struct 
{
    fast_foc_calculate_struct calculate_value;
  
    int32 encoder_max_data;
    int32 duty_max_data;
    int32 motor_pole_pairs;
    int32 motor_zero_location;
    int32 motor_rotation_direction;
    
    uint16 ouput_duty[3];
}fast_foc_struct;


extern fast_foc_struct motor_left_foc_driver;

extern fast_foc_struct motor_right_foc_driver;



void fast_foc_calculate(fast_foc_struct *fast_foc_pointer, int32 now_encoder_data, float output_duty_max, int32 traction_angle);

void fast_foc_init(fast_foc_struct *fast_foc_pointer, int32 encoder_max_data, int32 duty_max_data, uint32 motor_pole_pairs, int32 zero_location, int32 rotation_direction);



#endif

