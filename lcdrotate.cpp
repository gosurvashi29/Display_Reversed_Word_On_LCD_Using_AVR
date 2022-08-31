/*
 * table2.cpp
 *
 * Created: 12-08-2014 15:43:18
 *  Author: Urvashi
 */ 

# define F_CPU 1000000
#include <avr/io.h>
# include <util/delay.h>
void lcd_init();
void disp_cmd(unsigned int cmd);
void disp_data(int cmd);
int main(void)
{
	DDRB = 0XFF;
	lcd_init();
    while(1)
    {
		disp_cmd(0X80);
		disp_data('A');
		disp_data('B');
		disp_data('C');
		disp_data('D');
		_delay_ms(1000);
		disp_cmd(0X01);
		_delay_ms(1);
        disp_cmd(0X84);
        disp_data('A');
        disp_data('B');
        disp_data('C');
        disp_data('D');
		_delay_ms(1000);
		disp_cmd(0X01);
		_delay_ms(1);
		 disp_cmd(0XCC);
		  disp_data('A');
		  disp_data('B');
		  disp_data('C');
		  disp_data('D');
		  _delay_ms(1000);
		disp_cmd(0X01);
		_delay_ms(1);
		 disp_cmd(0XC0);
		   disp_data('A');
		   disp_data('B');
		   disp_data('C');
		   disp_data('D');
		
		  _delay_ms(1000);
		  disp_cmd(0X01);
		  _delay_ms(1);
		}
		
		return 0;
}

void lcd_init()
{
	disp_cmd(0X02);
	disp_cmd(0X28);
	disp_cmd(0X0C);
	disp_cmd(0X06);
}

void disp_cmd(unsigned int cmd)
{
	PORTB=((cmd & 0XF0)+0X04);
	_delay_ms(1);
	PORTB=PORTB - 0X04;
	PORTB=(((cmd<<4)& 0XF0)+0X04);
	_delay_ms(1);
	PORTB=PORTB-0X04;
	
}
void disp_data( int cmd)
{
	PORTB=((cmd  & 0XF0)+0X05);
	_delay_ms(1);
	PORTB=PORTB - 0X04;
	PORTB=(((cmd <<4)& 0XF0)+0X05);
	_delay_ms(1);
	PORTB=PORTB-0X04;
	
}

