#include "hal.h"

uchar menu=0;
uchar ADJ;                    //��������
uchar e=0;
uchar    Read_RI=0;                  //�Ƚϱ��
uchar Light;
/************************************************************/
void KEY_Manage  (void)
{
	if(ADJ==1)
	{
		ADJ=0XFF;
	Light++;	//���ȿ���			 
	 if(Light>10)
	 {
			Light=1;
			
	 }

		MemWriteByte(0,Light); //��������;
	}
	if(ADJ==2)
	{
		ADJ=0XFF;
	  FFTcolor++;
		if(FFTcolor>1)
		FFTcolor=0;
		MemWriteByte(0x400,FFTcolor); //��������
	
	}
}
/*********************************************************************
* �� �� ��: ManageButton
* ��������: �����µİ���Ӧ��ִ�еĶ���
* ����˵��: �����µİ���Ӧ��ִ�еĶ���
* �� �� �� ���ڣ�2008-09-11 17:08
* �� �� �� ���ڣ�2008-09-11 17:08
* �� ���� v1.0.0
***********************************************************************/
/****************** ���������ִ�� ****************/
uchar ManageButton(uchar  Vale)
{
    //ң��ѧϰʱ�����а����ٿ�
    if((GET_LEFT()==0)||(GET_DOWN()==0))         //��Ka��Ϊ0
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
	
///////////��������/////////////////////////////////////////////////////////////////

}
