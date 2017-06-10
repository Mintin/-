
#include "hal.h"
//#include <intrins.h>
#include <stdlib.h>
u8 hh,ss;
u8 week;
u8 x;
uchar pop;
/**************************************************/
void LEDinit_OFF()//����
{  
 uchar x;
 for(x=0;x<64;x++)//��R,G������ȫ��������0
 {
 		LED_TAB[x]=0;
		LED_TAB1[x]=0;	
 }
}

/**************************************************************/ 

void delay_5us(uchar time)   //10us
{
    unsigned char a,b,c;
	for(c=time;c>0;c--)
	{
    	 for(b=30;b>0;b--)
        for(a=5;a>0;a--);
	}
}
/***************************************/
void scan(unsigned char Value)
{switch(Value)
        {case  0: scan0;break;
		  case  1: scan1;break;
		   case  2: scan2;break;
		    case  3: scan3;break;
             case  4: scan4;break;
		      case  5: scan5;break;
		       case  6: scan6;break;
		        case  7: scan7;break;
	   default:break;
        }
}
/*******************************************************************************
* Function Name  : TIM3_IRQHandler
* Description    : This function handles TIM3 global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM3_IRQHandler(void)
{		 
	
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)
	{
		 TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
	   
  /**************************************************************/ 	
/******************************************************************************/

	
/*******************************************************************/
      //����������� һ�е� ����  
		  for(G=24;G>0;)
			{				
				SDA_R_OFF;SDA_G_OFF;
				G=G-8;
			 if(FFTcolor==0)  //����� ��״��ɫ
				{
				for(pop=G;pop<G+8;pop++)
				{
					SHCP_OFF;
					if(LED_TAB[pop]<=LINE+16)
					{
						SDA_R_ON;
					}
					else 
					{
						SDA_R_OFF;
					}
					if(LED_TAB1[pop]==LINE+16)
					{
							SDA_G_ON;
					}
					else
					{
							SDA_G_OFF;
					}
						
					  SHCP_ON;//��λ		
				}
				/****************************/
			
				for(pop=G;pop<G+8;pop++)
				{
					SHCP_OFF;
					if(LED_TAB[pop]<=LINE+8)
					{
						SDA_R_ON;
					}
					else 
					{
						SDA_R_OFF;
					}
					if(LED_TAB1[pop]==LINE+8)
					{
							SDA_G_ON;
					}
					else
					{
							SDA_G_OFF;
					}
						
					  SHCP_ON;//��λ		
				}
				/**************************************/
				for(pop=G;pop<G+8;pop++)
				{
					SHCP_OFF;
					if(LED_TAB[pop]<=LINE)
					{
						SDA_R_ON;
					}
					else 
					{
						SDA_R_OFF;
					}
					if(LED_TAB1[pop]==LINE)
					{
							SDA_G_ON;
					}
					else
					{
							SDA_G_OFF;
					}
						
					  SHCP_ON;//��λ		
				}
			}
				else if(FFTcolor==1)  //�������״ ��ɫƯ�����Ǻ�ɫ
				{	
					for(pop=G;pop<G+8;pop++)
				{
					SHCP_OFF;
					if(LED_TAB[pop]<=LINE+16)
					{
						SDA_G_OFF;
					}
					else 
					{
						SDA_G_ON;
					}
					if(LED_TAB1[pop]==LINE+16)
					{
							SDA_R_OFF;
					}
					else
					{
							SDA_R_ON;
					}
						
					  SHCP_ON;//��λ		
				}
				/****************************/
			
				for(pop=G;pop<G+8;pop++)
				{
					SHCP_OFF;
					if(LED_TAB[pop]<=LINE+8)
					{
						SDA_G_OFF;
					}
					else 
					{
						SDA_G_ON;
					}
					if(LED_TAB1[pop]==LINE+8)
					{
							SDA_R_OFF;
					}
					else
					{
							SDA_R_ON;
					}
						
					  SHCP_ON;//��λ		
				}
				/**************************************/
				for(pop=G;pop<G+8;pop++)
				{
					SHCP_OFF;
					if(LED_TAB[pop]<=LINE)
					{
						SDA_G_OFF;
					}
					else 
					{
						SDA_G_ON;
					}
					if(LED_TAB1[pop]==LINE)
					{
							SDA_R_OFF;
					}
					else
					{
							SDA_R_ON;
					}
						
					  SHCP_ON;//��λ	
			
				}
			}
		}
	    
			STCP_ON;STCP_OFF;
		   scan(7-LINE);
			if(LINE>0)LINE--;
			else LINE=7;
			 
		
		if(++ss>1)
		{
			ss=0;
			for(x=0;x<1;x++) //��״�ݼ����ٶ�
			{
		   		
				if(LED_TAB[COUNT]>0)
					LED_TAB[COUNT]--;		   //��״�ݼ���
		 		if(COUNT>0)
					COUNT--;	
				else 
				{
					//if(fractional_frequency==64)
					COUNT=23;
					//else
				//	mo=fractional_frequency+3;
				} 
	
			}
	   	}
	
			week++;
			if(week==2)
			{
				week=0;
				hh=1;	
			}
			else
			hh=0;		
		for(x=0;x<hh;x++)	//16  Stop_time ����Ư����ݼ��ٶȿ���
		{
		   	if(LED_TAB2[COUNT1]==0)	//Ư�����Ƿ�ͣ��
		   	{
		   		if(LED_TAB1[COUNT1]>LED_TAB[COUNT1])  //Ư����>��״ ��
					LED_TAB1[COUNT1]--; 
		   	}
		   	else 
				LED_TAB2[COUNT1]--;
		   	COUNT1++;
		}	
			if(COUNT1>=24)
				COUNT1=0;
		  OE_OFF;
			delay_us(Light*30);//��������
			OE_ON;
 	}
 
/*************************************************/			
}
/***********************************************************************************
************************************************************************************
*******************DIY�ӽ��Ʒ   http://59tiaoba.taobao.com*************************
************************************************************************************
*************************************************************************************/


