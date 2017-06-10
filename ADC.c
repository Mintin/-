/**************************************************************
 ADC PB1_ADC9 
 
***************************************************************/

#include "STM32Lib\\stm32f10x.h"
#include "hal.h"
#define ADC1_DR_Address ((u32)0x4001244C)

u16 ADC_ConvertedValue;
void ADC_DMA_Configuration(void)
{
	
	DMA_InitTypeDef DMA_InitStructure;
	/* Enable DMA1 clock */
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
	//(2) ��ʼ�� DMA �� ADC ģ����Ӧ�ó���
	/* DMA channel1 configuration ������������������������������-*/
	DMA_DeInit(DMA1_Channel1);
	DMA_InitStructure.DMA_PeripheralBaseAddr = ADC1_DR_Address;  // �����ַ
	DMA_InitStructure.DMA_MemoryBaseAddr = (u32)&ADC_ConvertedValue; // �ڴ��ַ
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;  // DMA ���䷽����
	DMA_InitStructure.DMA_BufferSize = 1;   // ����DMA�ڴ���ʱ�������ĳ��� word
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable; //����DMA�������ģʽ
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Disable; // ����DMA�ڴ����ģʽ
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;  // ���������ֳ�
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord; //�ڴ������ֳ�
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;  // ���ô���ģʽ�������ϵ�ѭ��ģʽ
	DMA_InitStructure.DMA_Priority = DMA_Priority_High; // ����DMA�����ȼ���
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable; // ����DMA��2��memory�еı����������
	DMA_Init(DMA1_Channel1, &DMA_InitStructure);

	  /* Enable DMA1 channel1 */
    DMA_Cmd(DMA1_Channel1, ENABLE);

}

void ADC_Configuration(void)
{
	ADC_InitTypeDef   ADC_InitStructure;
	GPIO_InitTypeDef  GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);//12M ADC�ٶ�
	/* PA2,  ADC�ɼ��ź�*/
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
		/* ADC1 */
		ADC_InitStructure.ADC_Mode               = ADC_Mode_Independent;		//����ģʽ
		ADC_InitStructure.ADC_ScanConvMode       = DISABLE;						//������ͨ��ģʽ
		ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;						//����ת��
		ADC_InitStructure.ADC_ExternalTrigConv   =ADC_ExternalTrigConv_None;	//ת������������ ADC_ExternalTrigConv_T2_CC2  ;//
		ADC_InitStructure.ADC_DataAlign          = ADC_DataAlign_Right;			//�Ҷ���
		ADC_InitStructure.ADC_NbrOfChannel       = 1;							//ɨ��ͨ����1
		ADC_Init(ADC1, &ADC_InitStructure);
	
		
	 
		 /* ADC1 regular channels configuration [����ģʽͨ������]*/ 
	    ADC_RegularChannelConfig(ADC1, ADC_Channel_2 , 1, ADC_SampleTime_55Cycles5);	//ͨ��X,����ʱ��Ϊ239.5����,1�������ͨ����1��
	   // ADC_RegularChannelConfig(ADC1, ADC_Channel_9 , 2, ADC_SampleTime_239Cycles5);
    
                        
	 /* Enable ADC1 DMA */
    ADC_DMACmd(ADC1, DISABLE);

	ADC_Cmd(ADC1, ENABLE);      /* Enable ADC1*/ 

	  /* Enable ADC1 reset calibaration register */   
  ADC_ResetCalibration(ADC1);
  /* Check the end of ADC1 reset calibration register */
  while(ADC_GetResetCalibrationStatus(ADC1));

  /* Start ADC1 calibaration */
  ADC_StartCalibration(ADC1);
  /* Check the end of ADC1 calibration */
  while(ADC_GetCalibrationStatus(ADC1));
     
  /* Start ADC1 Software Conversion */                       
	ADC_SoftwareStartConvCmd(ADC1,ENABLE);/* Start ADC1 Software Conversion     */ //ʹ��ת����ʼ

}

u16 TestAdc(void)
{
	u16 adc;
	if(ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC)==SET)
	{
		ADC_ClearFlag(ADC1, ADC_FLAG_EOC); 
		adc=(ADC1->DR);//ADC_GetConversionValue(ADC1);
		//USART1_Putc(ADC_GetConversionValue(ADC1)>>8);
		//USART1_Putc(ADC_GetConversionValue(ADC1));
		//USART1_Puts("\r\n");
	}
	return adc;
}
/***********************************************************************************
************************************************************************************
*******************DIY�ӽ��Ʒ   http://59tiaoba.taobao.com*************************
************************************************************************************
*************************************************************************************/