
/**************************************/
/*              ARE 2009              */
/*      e-mail: biuro@are.net.pl      */
/*      www   : are.net.pl            */
/**************************************/

#define F_CPU 1000000UL  // 1 MHz
//#define F_CPU 14.7456E6
#include <util/delay.h>
#include <avr/io.h>

void delay_ms( int ms)
	{
	volatile long unsigned int i;
	for(i=0;i<ms;i++)
		_delay_ms(1);
	}


int main(void)
{
//ustalenie kierunku pinow
DDRD=0xFF;
DDRA=0xFF;

//zdefiniowanie zmiennej odpowiadajacej za opoznienia
int ms=1000;
int i=0;

//ustawienie stanu poczatkowego portu
PORTD=0x01;
PORTA=0x01;

//"biegajace" diody
while(1)
	{
	for(i=0;i<=4;i++)
	  {
	  PORTD=~(0x01<<i);
	  PORTA=~(0x01<<i);
	  delay_ms(ms);
	  }
	for(i=4;i>=0;i--)
	  {

	  PORTA=~(0x01<<i);
	  PORTD=~(0x01<<i);
	  delay_ms(ms);
	  }
	};

return(0);
}
/* diodywsz.c
 *
 *  Created on: 22 mar 2018
 *      Author: Student
 */


