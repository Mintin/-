#include "STM32Lib\\stm32f10x.h"
//#include "stm32f10x_usart.h"
/**********************************************
**�������ú���,����ʹ������������,���д���2ʹ�����жϽ���ģʽ
**
**********************************************/
u8 Uart2_Get_Flag;	//����2���յ����ݱ�־
u8 Uart2_Get_Data;	//����2���յ�����

void USART_Configuration(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;
	USART_ClockInitTypeDef USART_ClockInitStructure;
	
	//ʹ�ܴ���1��PA��AFIO����
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | 
            RCC_APB2Periph_AFIO |
            RCC_APB2Periph_USART1 , 
            ENABLE);

//    /* A9 USART1_Tx */
//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
//    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;		//�������-TX
//    GPIO_Init(GPIOA, &GPIO_InitStructure);
//
//    /* A10 USART1_Rx  */
//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//��������-RX
//    GPIO_Init(GPIOA, &GPIO_InitStructure);


    USART_InitStructure.USART_BaudRate = 9600;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	
	USART_ClockInitStructure.USART_Clock = USART_Clock_Disable;
	USART_ClockInitStructure.USART_CPOL = USART_CPOL_Low;
	USART_ClockInitStructure.USART_CPHA = USART_CPHA_2Edge;
	USART_ClockInitStructure.USART_LastBit = USART_LastBit_Disable;

	USART_ClockInit(USART1, &USART_ClockInitStructure);
    USART_Init(USART1, &USART_InitStructure);
    /* Enable the USARTx */
    USART_Cmd(USART1, ENABLE);
	
	
	//ʹ�ܴ���2ʱ��
/*	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);
	
	// A2 ��T2X
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    // A3 ��R2X 
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	USART_InitStructure.USART_BaudRate = 9600;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	
	USART_ClockInitStructure.USART_Clock = USART_Clock_Disable;
	USART_ClockInitStructure.USART_CPOL = USART_CPOL_Low;
	USART_ClockInitStructure.USART_CPHA = USART_CPHA_2Edge;
	USART_ClockInitStructure.USART_LastBit = USART_LastBit_Disable;

    USART_ClockInit(USART2, &USART_ClockInitStructure);
    USART_Init(USART2, &USART_InitStructure);
    
    USART_Cmd(USART2, ENABLE);
	//����2ʹ�ý����ж�
	USART_ITConfig(USART2,USART_IT_RXNE,ENABLE);*/
}

void USART1_Putc(unsigned char c)
{
    USART_SendData(USART1, c);
    while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET );
}

void USART1_Puts(char * str)
{
    while(*str)
    {
        USART_SendData(USART1, *str++);
        /* Loop until the end of transmission */
        while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
    }
}

/*void USART2_Putc(unsigned char c)
{
    USART_SendData(USART2, c);
    while(USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET );
}

void USART2_Puts(char * str)
{
    while(*str)
    {
        USART_SendData(USART2, *str++);
        // Loop until the end of transmission 
      while(USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET);
    }

}*/