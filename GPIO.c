#include "STM32Lib\\stm32f10x.h"
//#include "hal.h"
/*******************************************************************************
* Function Name  : GPIO_Configuration
* ����PD3,PD4,PD5,PD6Ϊ��������
* ����PB0,5,8,9; PC5,7; PD7 ;PA8 Ϊ���LED��
*******************************************************************************/
void GPIO_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	//EXTI_InitTypeDef EXTI_InitStructure;
	
	/*��������CLOCK,��ʹ��GPIO֮ǰ����������Ӧ�˵�ʱ��.
	��STM32����ƽǶ���˵,û������Ķ˽�������ʱ��,Ҳ�Ͳ������,
	����STM32���ܵ�һ�ּ���,*/
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE); 
	RCC->APB2ENR |=0x09;
	/*PA6=OE;PA5=G1;PA4=R1;PA3=SHCPʱ��;PA0=D;PA1=STCP����  �������*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6;//GPIO_Pin_All;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	//����
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//50Mʱ���ٶ�
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	
	/*PB8=A;PB3=B;PB4=C  P,���*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	//����
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//50Mʱ���ٶ�
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	//PB0  PB1 ����
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;		//��������
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable,ENABLE);          //�ر�JTAG 
}
/***********************************************************************************
************************************************************************************
*******************DIY�ӽ��Ʒ   http://59tiaoba.taobao.com*************************
************************************************************************************
*************************************************************************************/

