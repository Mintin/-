#ifndef HAL_H
#define HAL_H
#include "STM32Lib\\stm32f10x.h"
#include "delay.h"
#define uchar unsigned char
#define uint unsigned int
#define NPT 256            /* NPT = No of FFT point*/
//硬件初始化
extern void  ChipHalInit(void);
extern void  ChipOutHalInit(void);
extern u16 TestAdc(void);

 //串口
extern void USART1_Putc(u8 c);
extern void USART1_Puts(char * str);


#define STCP_ON	   GPIOA->BSRR = GPIO_Pin_1
#define STCP_OFF   GPIOA->BRR = GPIO_Pin_1

#define SHCP_ON		GPIOA->BSRR = GPIO_Pin_3
#define SHCP_OFF 	GPIOA->BRR = GPIO_Pin_3


#define SDA_R_OFF	GPIOA->BSRR = GPIO_Pin_4
#define SDA_R_ON	GPIOA->BRR = GPIO_Pin_4

#define SDA_G_ON	GPIOA->BSRR = GPIO_Pin_5
#define SDA_G_OFF	GPIOA->BRR = GPIO_Pin_5

#define OE_ON		GPIOA->BSRR = GPIO_Pin_6
#define OE_OFF    GPIOA->BRR = GPIO_Pin_6

#define Key1_ON	GPIOB->BSRR = GPIO_Pin_0
#define Key2_ON	GPIOB->BSRR = GPIO_Pin_1

//输出宏定义
#define LA_ON	   GPIOB->BSRR = GPIO_Pin_8
#define LA_OFF   GPIOB->BRR = GPIO_Pin_8

#define LB_ON	   GPIOB->BSRR = GPIO_Pin_3
#define LB_OFF   GPIOB->BRR = GPIO_Pin_3

#define LC_ON	   GPIOB->BSRR = GPIO_Pin_4
#define LC_OFF   GPIOB->BRR = GPIO_Pin_4

//#define LD_ON	   GPIOA->BSRR = GPIO_Pin_0
//#define LD_OFF   GPIOA->BRR = GPIO_Pin_0

#define  scan0    {LA_OFF;LB_OFF;LC_OFF;}
#define  scan1    {LA_ON; LB_OFF;LC_OFF;}
#define  scan2    {LA_OFF;LB_ON; LC_OFF;}
#define  scan3    {LA_ON;LB_ON;LC_OFF;}
#define  scan4    {LA_OFF;LB_OFF;LC_ON;}
#define  scan5    {LA_ON;LB_OFF;LC_ON;}
#define  scan6    {LA_OFF;LB_ON;LC_ON;}
#define  scan7    {LA_ON;LB_ON;LC_ON;}

/*****??????????*************************/

//#define LED_ON		GPIOC->BSRR = GPIO_Pin_13
//#define LED_OFF	    GPIOC->BRR = GPIO_Pin_13
//设置DATA


//sbit   DQ= P3^6 ;
//输入宏定义
//#define GET_RIGHT()	(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_11))
//#define GET_UP()	(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_12))
#define GET_DOWN()	(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1))
#define GET_LEFT()	(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0))
//#define SET_DOWN()	GPIOB->BSRR = GPIO_Pin_6
//#define RSET_DOWN()	GPIOB->BRR = GPIO_Pin_6
extern uchar  LED_TAB2[64];				//记录 漂浮物 是否需要 停顿一下
extern uchar  LED_TAB[64];				//记录红色柱状 
extern uchar  LED_TAB1[64];				 	//记录 漂浮点
extern u16 ADC_ConvertedValue;		
extern void FFT(void);
extern u16 ADC_Count;
extern u16 TestAdc(void);
extern u8 adc_over;
/*****************task.c***************************************/
extern void SendByte(unsigned char dat);
extern uchar switc;
extern uchar windw; 
extern uchar old_ss;
extern uchar Miao_color;
extern uchar read_tem_bit;
extern uchar Light;

/**********************LED_WR.C******************************************************/
extern  void LEDinit(void);//清屏
/***********************Key_adjust*******************************************************/
extern void KEY_Manage(void);
extern void KEY_scan(void);
extern uchar ADJ;                    //按键变量
extern uchar menu;
extern void LEDinit_OFF(void);//清屏
extern void  Backtotime(void);
extern void ADC_Configuration(void);			//ADC
//extern void Beep_set(void);           //扬声器--确定设置
/**************************IR_Receive*****************************************************/
extern uchar  Remoter_KEY;
extern uchar Read_RI;

/**************************LED_WR.C********************************************/
//extern uchar switc;
extern void delay(uint xms);
extern uchar Read_adc;
/***************************FFT.C**********************************************/
extern  void Scan_FFT_Mode(void);
extern uchar fractional_frequency;
extern uchar G;
extern uchar Mode;//模式
//extern int  Fft_Real[128]; 
//extern int  Fft_Image[128];               // fft的虚部 
//extern uchar xdata LED_TAB2[64];				//记录 漂浮物 是否需要 停顿一下
//extern uchar xdata LED_TAB[64];				//记录红色柱状 
//extern uchar xdata LED_TAB1[64];				//记录 漂浮点
extern uchar LINE;
extern uchar FFTcolor;
//extern uchar j; 
extern uchar COUNT,COUNT1;
//extern uchar count_time;
//extern void FFT();
extern long FFT_IN[NPT];
extern long FFT_OUT[NPT]; 
/********************Flash.C*****************************************************/
extern u8 MemWriteByte(u16 address,u16 data);
extern u8 MemReadByte(u16 address) ;
#endif
