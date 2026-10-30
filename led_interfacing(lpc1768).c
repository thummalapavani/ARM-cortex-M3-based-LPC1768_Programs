DAY-1
LED INTERFACING:
1.WAP blink the LED (LED is connected to the PORT1.19)
 #include<lpc17xx.h>
void delay(unsigned int);
int main()
 
		LPC_GPIO1->FIODIR|=(1<<19);  
		while(1)
		{
			LPC_GPIO1->FIOSET=(1<<19);
			delay(400);
			LPC_GPIO1->FIOCLR=(1<<19);
			delay(400);
		}
}
void delay(unsigned int  ms)
{
		int i,j;
		for(i=0;i<ms;i++)
		for(j=0;j<700;j++);

}
void SystemInit(void)
{

}
2.WAP Blink the All LED's (LED's Are Connected To the Potr1.19 to Port1.26)
#include<lpc17xx.h>
void delay(unsigned int);
int main()
{
	LPC_GPIO1->FIODIR=(0xff<<19);
	while(1)
	{
		LPC_GPIO1->FIOSET=(0xff<<19);
		delay(300);
		LPC_GPIO1->FIOCLR=(0xff<<19);
		delay(300);
	
	}
}
void delay(unsigned int  ms)
{
		int i,j;
		for(i=0;i<ms;i++)
		for(j=0;j<700;j++);

}
void SystemInit(void)
{
}
3.WAP Implements the LED patterns Left to right and Right to Left  
#include<lpc17xx.h>
int main()
{
		int i;
		LPC_GPIO1->FIODIR=(0xff<<19);
		LPC_GPIO1->FIOCLR=(0xff<<19);
		while(1)
		{	
			for(i=19;i<27;i++)
			{
				LPC_GPIO1->FIOSET=(1<<i);
				delay(300);
				LPC_GPIO1->FIOCLR=(1<<i);
				delay(300);

			}
		}
}
4.WAP Implements the LED patterns Left to right and Left to Right
#include<lpc17xx.h>
int main()
{
		int i;
		LPC_GPIO1->FIODIR=(0xff<<19);
		LPC_GPIO1->FIOCLR=(0xff<<19);
		while(1)
		{	
			for(i=26;i>=19;i--)
			{
				LPC_GPIO1->FIOSET=(1<<i);
				delay(300);
				LPC_GPIO1->FIOCLR=(1<<i);
				delay(300);

			}
		}
}


SWITCH INTERFACING:
1. 1.WAP interface the Switch to the LPC1768 if the Switch is pressed LED need ON Else Led need OFF 
Common Cathode Configuration 
#include<lpc17xx.h>
int main()
{
		LPC_GPIO2->FIODIR&=~(1<<11);
		LPC_GPIO1->FIODIR|=(0xff<<19);
		while(1)
		{
			if((LPC_GPIO2->FIOPIN&(1<<11))==0)
			{
					LPC_GPIO1->FIOSET=(0xff<<19);
			}
			else
			{
					LPC_GPIO1->FIOCLR=(0xff<<19);
			}
}
		}
void SystemInit(void)
{
}
Common Anode Configuration 
#include<lpc17xx.h>
int main()
{
		LPC_GPIO2->FIODIR&=~(1<<11);
		LPC_GPIO1->FIODIR|=(0xff<<19);
		while(1)
		{
			if((LPC_GPIO2->FIOPIN&(1<<11))!=0)
			{
					LPC_GPIO1->FIOSET=(0xff<<19);
			}
			else
			{
					LPC_GPIO1->FIOCLR=(0xff<<19);
			}
}
		}
void SystemInit(void)
{
}


