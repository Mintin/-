#include "STM32Lib\\stm32f10x.h"
#include "intrins.h"
#include "hal.h"
#include <math.h>
#define STRT 	4	//����ͨ����ʼλ
#define JSTRT	3	//ע��ͨ����ʼλ
#define JEOC	2	//ע��ͨ��ת������λ
#define EOC		1	//����ͨ��ת������λ
#define AWD		0	//ģ�⿴�Ź���־λ
#define	ADON		0	//ADCʹ��λ

//const uchar sw[16]={0X00,0X08,0x04,0x0C,0X02,0X0A,0X06,0X0E,0X01,0X09,0X05,0X0D,0X03,0X0B,0X07,0X0F};/*16�ж���*/
uchar COUNT=15,COUNT1=0,LINE=15,G;
u16 ADC_Count=0; 
u8 FFTcolor;
u8 Mode=0;               
int Temp_Real,Temp_Imag,temp;                // �м���ʱ����  
uint TEMP1;
//uint tx;
u8 adc_over=0;   //256��adcת�����
uchar fractional_frequency=24;//��Ƶ	
extern uint16_t TableFFT[];
long FFT_IN[NPT];         /* Complex input vector */
long FFT_OUT[NPT];        /* Complex output vector */
 
u8  LED_TAB2[64];				//��¼ Ư���� �Ƿ���Ҫ ͣ��һ��
u8  LED_TAB[64];				//��¼��ɫ��״ 
u8  LED_TAB1[64];				//��¼ Ư����
/*******************************************/
void FFT(void)
{    u8 j;             
    int32_t lX,lY;
  for (j=8; j < 32; j++)
  {

	lX= (FFT_OUT[j]<<16)>>16; 
    lY= (FFT_OUT[j] >> 16);       
    {
//      float X=  256*((float)lX)/32768;
//      float Y = 256*((float)lY)/32768;
      //float Mag =   // ��ƽ����,�ٿ���
      TEMP1 = sqrt(lX*lX+ lY*lY)/7;
	  if(TEMP1<1)TEMP1=0;
   		 else
		 {
		 	TEMP1=TEMP1-1;	
		 }
		 if(TEMP1>23)
		   TEMP1=23;
	    if(TEMP1>(LED_TAB[j-8]))LED_TAB[j-8]=TEMP1;        
        if(TEMP1>(LED_TAB1[j-8]))
        {   LED_TAB1[j-8]=TEMP1;
             LED_TAB2[j-8]=10;                                                //����ٶ�=12
        }
    }    
  
}	
}


 /*******************************************************************************
* Function Name  : TIM2_IRQHandler TIM2�ж�
* Description    : This function handles TIM2 global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM2_IRQHandler(void)
{
	/**************************************************/
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)
	{
	   		//Fft_Real[LIST_TAB[ADC_Count]]=ADC_ConvertedValue;//��ȡad��� //ADC_ConvertedValue[0];
			ADC1->CR2|=(1<<ADON);			//����ת��
			//ADC1->CR2|=(1<<ADON);			//����ת��
	  	 //TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
		 TIM2->SR&=~(1<<0);		    //����жϱ�־
	//	while(ADC_ConvertedValue>0XFF0)
		
			FFT_IN[ADC_Count]= (TestAdc())<< 16 ;
			if(ADC_Count<=255)ADC_Count++;
	  		else 
			{
				  	TIM2->CR1&=~(1<<0);   //�رն�ʱ��2
					ADC_Count=0;
					adc_over=1;
				  //USART1_Putc(ADC_ConvertedValue);
				 // TIM_ITConfig( TIM2,TIM_IT_CC4,DISABLE ); //�ر�TIM_IT_CC4�ж�
				// ADC_Cmd(ADC1, DISABLE); 
			}
		 
		 	
	}
} 


