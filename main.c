/**********************2015-12-6**************************************
**功能:实现DSP库的FFT 驱动32X64双色点阵进行频谱显示
256点FFT运算

**作者:Fucp

//24X24双色屏 红+翠绿
//屏接口 定义
GND     A     ABC行扫描 8扫屏
GND     B
GND     C
GND	    NC	 
GND	    STCP	锁存 
GND	    SHCP	时钟移位  
GND	    R1	   红色、绿色
GND     G1	 
GND	    OE  OE 使能端 
GND	  	GND
*************************************************************/

#include "STM32Lib\\stm32f10x.h"
#include "hal.h"
#include "stm32_dsp.h"
uchar switc=0; //
uchar windw=0; //
uchar Miao_color=1;  //
u16 i;
extern uchar Light;
uchar read_tem_bit=1;

int main(void)
{	
	
	ChipHalInit();			//片内硬件初始化
	ChipOutHalInit();		//片外硬件初始化
	delay_init(72);	
	//GPIO_Write(GPIOB, 0xFFFF); 
	Light=MemReadByte(0);
	if(Light>10)
		Light=4;
  FFTcolor=MemReadByte(0x400);	
   if(FFTcolor>1)
		FFTcolor=0;
	IWDG_Enable();			//启动看门狗,自动就会使能内部的40K           
 	LEDinit_OFF();//清屏
  OE_OFF;
	Key1_ON;
	Key2_ON;
	for(;;)
	{	  
	   	KEY_scan();		//--------------------------------按键扫描
	 	KEY_Manage  ();  //--------------------------按键执行
		IWDG_ReloadCounter();	//喂狗
		
	 /*************************************************/
	   if(adc_over==1)
	   {
			adc_over=0;
			
			cr4_fft_256_stm32(FFT_OUT, FFT_IN, NPT);
			FFT();
			TIM2->CR1|=1<<0;   //使能定时器2
			
		}

	 
	/***********************************************/
	}	
} 
/***********************************************************************************
************************************************************************************
*******************DIY视界出品   http://59tiaoba.taobao.com*************************
************************************************************************************
*************************************************************************************/

