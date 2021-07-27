#ifndef __24C02_H__
#define __24C02_H__

#include "reg52.h"

#define AT24C02_WRITE_ADDRESS          0xA0//24c02的写地址
#define AT24C02_READ_ADDRESS           0xA1//24c02的读地址（由于最后一位的不同而造成的不同，最后一位==1时为读）      

sbit SCL=P0^0;
sbit SDA=P0^1;

/////////////////6050/////////////////
     ////定义MPU6050内部地址/////
#define	SMPLRT_DIV		0x19	//陀螺仪采样率，典型值:0x07(125Hz)
#define	CONFIG			0x1A	//低通滤波频率，典型值:0x06(5Hz)

#define	GYRO_CONFIG		0x1B	//陀螺仪自检及测量范围，典型值:0x18(???,2000deg/s)
#define	ACCEL_CONFIG	        0x1C	//加速度计自检、测量范围及高通滤波范围，典型值,???:0x01(???,2G,5Hz)
#define PWR_MGMT_1  0x6B //电源管理，典型手�:0x00(????)
#define WHO_AM_I   0x75 //IIC地址寄存器(默认设数值0x68,??)
#define SlaveAddress 0xD0 //IIC写入时的地址字节数据,+1为读取

         //加速度的宏//
#define	ACCEL_XOUT_H	        0x3B    //a
#define	ACCEL_XOUT_L	        0x3C    //b
#define	ACCEL_YOUT_H	        0x3D    //c
#define	ACCEL_YOUT_L	        0x3E    //d
#define	ACCEL_ZOUT_H	        0x3F    //e
#define	ACCEL_ZOUT_L	        0x40    //f

         //陀螺仪的宏//
#define	GYRO_XOUT_H		0x43
#define	GYRO_XOUT_L		0x44	
#define	GYRO_YOUT_H		0x45
#define	GYRO_YOUT_L		0x46
#define	GYRO_ZOUT_H		0x47
#define	GYRO_ZOUT_L		0x48




//extern void delay7ms(void);
//extern void delay_ms(unsigned int );  //延时的函数
//extern void I2C_start();//开始信号
//extern void I2C_stop();//停止信号
//extern void I2C_send_answer();//主器件发送应答信号
//extern int I2C_receive_answer();//主器件接收应答信号
extern void I2C_send_byte(unsigned char);//向24c02发送一个字节
extern void I2C_writedata(unsigned char,unsigned char,unsigned char);//向24c02写一个8位数据
extern unsigned char I2C_readdata(unsigned char,unsigned char);//从23c02读一个8位数据
#endif