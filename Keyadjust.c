#include "hal.h"

uchar menu=0;
uchar ADJ;                    //按键变量
uchar e=0;
uchar    Read_RI=0;                  //比较标记
uchar Light;
/************************************************************/
void KEY_Manage  (void)
{
	if(ADJ==1)
	{
		ADJ=0XFF;
	Light++;	//亮度控制			 
	 if(Light>10)
	 {
			Light=1;
			
	 }

		MemWriteByte(0,Light); //保存设置;
	}
	if(ADJ==2)
	{
		ADJ=0XFF;
	  FFTcolor++;
		if(FFTcolor>1)
		FFTcolor=0;
		MemWriteByte(0x400,FFTcolor); //保存设置
	
	}
}
/*********************************************************************
* 函 数 名: ManageButton
* 功能描述: 处理按下的按键应该执行的动作
* 函数说明: 处理按下的按键应该执行的动作
* 设 计 者 日期：2008-09-11 17:08
* 修 改 者 日期：2008-09-11 17:08
* 版 本： v1.0.0
***********************************************************************/
/****************** 按键检测与执行 ****************/
uchar ManageButton(uchar  Vale)
{
    //遥控学习时不进行按键操控
    if((GET_LEFT()==0)||(GET_DOWN()==0))         //当Ka不为0
    {
        Read_RI=0;
        if(GET_LEFT()==0)
        {
            Vale=1;
        }
        if(GET_DOWN()==0)
        {
            Vale=2;
        }
        while((GET_LEFT()==0)||(GET_DOWN()==0))
        {
            
        }
    }
    return(Vale);
}
/******************************************************************************************/
void KEY_scan(void)
{ 
   	 uchar LastKEY=0 ;
     LastKEY= ManageButton(LastKEY);
        if(LastKEY!=0)
        {
            ADJ=LastKEY;
            LastKEY=0;
        }
	
///////////按键操作/////////////////////////////////////////////////////////////////

}
