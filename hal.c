/***************************************************
**HAL.c
**��Ҫ����оƬӲ�����ڲ���Χ���ⲿ��Χ�ĳ�ʼ��������INIT����
**��MAIN�е��ã�ʹMAIN�����о�����Ӳ�����޹�
***************************************************/

#include "STM32Lib\\stm32f10x.h"


//�����ڲ�Ӳ��ģ������ú���
extern void GPIO_Configuration(void);			//GPIO
extern void RCC_Configuration(void);			//RCC
extern void TIM_Configuration(void);			//TIM
extern void NVIC_Configuration(void);			//NVIC
extern void IWDG_Configuration(void);			//IWDG
extern void USART_Configuration(void);			//����
extern void ADC_DMA_Configuration(void);
extern void ADC_Configuration(void);
/*******************************
**������:ChipHalInit()
**����:Ƭ��Ӳ����ʼ��
*******************************/
void  ChipHalInit(void)
{
	//��ʼ��ʱ��Դ
	RCC_Configuration();
	
	//��ʼ���ж�Դ
	NVIC_Configuration();

	//��ʼ��GPIO
	GPIO_Configuration();
		
	//��ʼ����ʱ��
	TIM_Configuration();

		//��ʼ������
//	USART_Configuration();

	ADC_Configuration();
//��ʼ���������Ź�
	IWDG_Configuration();
}


/*********************************
**������:ChipOutHalInit()
**����:Ƭ��Ӳ����ʼ��
*********************************/
void  ChipOutHalInit(void)
{
	
}
/***********************************************************************************
************************************************************************************
*******************DIY�ӽ��Ʒ   http://59tiaoba.taobao.com*************************
************************************************************************************
*************************************************************************************/