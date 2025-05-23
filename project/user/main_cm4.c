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
* 文件名称          main_cm4
* 公司名称          成都逐飞科技有限公司
* 版本信息          查看 libraries/doc 文件夹内 version 文件 版本说明
* 开发环境          IAR 9.40.1
* 适用平台          CYT2BL3
* 店铺链接          https://seekfree.taobao.com/
*
* 修改记录
* 日期              作者                备注
* 2024-11-19       pudding            first version
********************************************************************************************************************/

#include "zf_common_headfile.h"
// 打开新的工程或者工程移动了位置务必执行以下操作
// 第一步 关闭上面所有打开的文件
// 第二步 project->clean  等待下方进度条走完

// **************************** 代码区域 ****************************

int main(void)
{
    clock_init(SYSTEM_CLOCK_160M);                                              // 时钟配置及系统初始化<务必保留>
    
    debug_init();                                                               // 调试串口初始化
    // 此处编写用户代码 例如外设初始化代码等
    interrupt_global_disable();							// 关闭全局中断
    
    driver_gpio_init();                                                         // 板载普通GPIO功能初始化（按键、LED）
    
    driver_adc_init();                                                          // 电池检测初始化
    
    motor_driver_uart_init();                                                   // 驱动通讯串口初始化

    motor_control_init();                                                       // 双电机控制初始化    
    
    interrupt_global_enable(0);							// 开启全局中断
    // 此处编写用户代码 例如外设初始化代码等
    for(;;)
    {
        // 此处编写需要循环执行的代码
        
        driver_adc_loop();                                                      // 驱动 ADC 循环检测函数
        
        driver_gpio_loop();                                                     // 驱动 GPIO 循环检测函数
        
        driver_cmd_loop();                                                      // 驱动 控制指令 循环响应函数
        
        system_delay_ms(10);                                                    // 主循环延时
        
        // 此处编写需要循环执行的代码
    }
}

// **************************** 代码区域 ****************************
