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
void disp_num(unsigned int num);
void disp_string(char *str);

int main(void)
{
	DDRB = 0XFF;
	int i;
	lcd_init();
    while(1)
    {
		
		for (i=0X80;i<=0X8F;i++)
		{
		
		disp_cmd(i);
		disp_string("ABCD");
		
		
		_delay_ms(1000);
		disp_cmd(0X01);
		_delay_ms(10);
        }
		for ( i=0XCF;i>=0XC0;i--)
		{
			disp_cmd(i);
			disp_string("ABCD");
			
			_delay_ms(1000);
			disp_cmd(0X01);
			_delay_ms(10);
		}		
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

void disp_string(char *str)
{
	int i=0;
	while (str[i]!='\0')
	{
		disp_data (str[i]);
		i++;
		
	}
}

void disp_num(unsigned int num)
{
	int a=0;
	if (num==0)
	{
		disp_data(48);
	}
	disp_cmd (0X04);
	while (num!=0)
	{
		a=num % 10;
		disp_data(a+48);
		num=num/10;
	}
}	