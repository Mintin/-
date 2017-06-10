#include "STM32Lib\\stm32f10x.h"


void TIM_Configuration(void)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	u16 CCR1_Val = 4000;
	u16 CCR2_Val = 1000; 
	u16 CCR3_Val = 350;  //1MS
	u16 CCR4_Val = 15; //15us   44K�����ٶ� 
	
	/* TIM2 clock enable */
  	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
		/* TIM3 clock enable */
  	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);  

	/*  TIM2��������*/
	TIM_TimeBaseStructure.TIM_Period = 80;			//����ֵ   
	TIM_TimeBaseStructure.TIM_Prescaler = 72-1;    	//Ԥ��Ƶ,��ֵ+1Ϊ��Ƶ�ĳ���	�����ٶ�1000K
	TIM_TimeBaseStructure.TIM_ClockDivision = 0x0;  	//
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 	//���ϼ���
	
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
	
	/* �Ƚ�ͨ��1*/
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_Inactive;      		//����ȽϷ�����ģʽ
	TIM_OCInitStructure.TIM_Pulse = CCR1_Val;  
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;		//����Ϊ��
	  
	TIM_OC1Init(TIM2, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Disable);				//��ֹOC1��װ��,��ʵ����ʡ�����,��ΪĬ����4·������װ��.
	
	/*�Ƚ�ͨ��2 */        
	TIM_OCInitStructure.TIM_Pulse = CCR2_Val;  
	
	TIM_OC2Init(TIM2, &TIM_OCInitStructure); 
	TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Disable);
	
	/* �Ƚ�ͨ��3 */         
	TIM_OCInitStructure.TIM_Pulse = CCR3_Val;  
	
	TIM_OC3Init(TIM2, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(TIM2, TIM_OCPreload_Disable);
	
	/* �Ƚ�ͨ��4 */       
	TIM_OCInitStructure.TIM_Pulse = CCR4_Val;  
	
	TIM_OC4Init(TIM2, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Disable);
	
	/*ʹ��Ԥװ��*/
	TIM_ARRPreloadConfig(TIM2, ENABLE);
	/*Ԥ����������ж�λ*/
	TIM_ClearITPendingBit(TIM2, TIM_IT_CC1 | TIM_IT_CC2 | TIM_IT_CC3 | TIM_IT_CC4|TIM_IT_Update); 

	/* 4��ͨ��������������ж�*/
	//TIM_ITConfig(TIM2, TIM_IT_CC1 | TIM_IT_CC2 | TIM_IT_CC3 | TIM_IT_CC4|TIM_IT_Update, ENABLE);
	  TIM_ITConfig( TIM2, TIM_IT_Update, ENABLE);
	
	/* ����TIM2��ʼ���� */
	TIM_Cmd(TIM2, ENABLE);

	/*********************************************/
		/*  TIM3��������*/
	TIM_TimeBaseStructure.TIM_Period = 700;			//����ֵ   
	TIM_TimeBaseStructure.TIM_Prescaler = 72-1;    	//Ԥ��Ƶ,��ֵ+1Ϊ��Ƶ�ĳ���	�����ٶ�1000K
	TIM_TimeBaseStructure.TIM_ClockDivision = 0x0;  	//
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 	//���ϼ���
	
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
	
	/*ʹ��Ԥװ��*/
	TIM_ARRPreloadConfig(TIM3, ENABLE);
	/*Ԥ����������ж�λ*/
	TIM_ClearITPendingBit(TIM3, TIM_IT_Update); 

	/* ����������ж�*/
	  TIM_ITConfig( TIM3,TIM_IT_Update, ENABLE);
	
	/* ����TIM3��ʼ���� */
	TIM_Cmd(TIM3, ENABLE);

	/******************************************/
		/*  TIM1��������*/
	TIM_TimeBaseStructure.TIM_Period = 225;			//����ֵ   
	TIM_TimeBaseStructure.TIM_Prescaler = 108-1;    	//Ԥ��Ƶ,��ֵ+1Ϊ��Ƶ�ĳ���	�����ٶ�1000K
	TIM_TimeBaseStructure.TIM_ClockDivision = 0x0;  	//
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 	//���ϼ���
	//TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);
	
//	TIM_ClearFlag(TIM1, TIM_FLAG_Update); 
	/*ʹ��Ԥװ��*/
	TIM_ARRPreloadConfig(TIM1, ENABLE);
	/*Ԥ����������ж�λ*/
	TIM_ClearFlag(TIM1, TIM_FLAG_Update);  

	/* ����������ж�*/
	TIM_ITConfig( TIM1,TIM_IT_Update, ENABLE);
	
	/* ����TIM1��ʼ���� */
//	TIM_Cmd(TIM1, ENABLE);
}
/***********************************************************************************
************************************************************************************
*******************DIY�ӽ��Ʒ   http://59tiaoba.taobao.com*************************
************************************************************************************
*************************************************************************************/