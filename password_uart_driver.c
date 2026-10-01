#include<lpc21xx.h>
#include"password_header.h"

void uart_init(u32 baud)
{
int result=0,PCLK;
if(VPBDIV==0)
PCLK=15000000;
else if(VPBDIV==1)
PCLK=60000000;
else if(VPBDIV==2)
PCLK=30000000;
result=PCLK/(16*baud);
PINSEL0|=0x05;
U0LCR=0X83;
U0DLL=result&0xff;
U0DLM=(result>>8)&0xff;
U0LCR=0X03;
}

#define THRE ((U0LSR>>5)&1)
void uart_tx(u8 data)
{
U0THR=data;
while(THRE==0);
}

#define RDR (U0LSR&1)
u8 uart_rx(void)
{
while(RDR==0);
return U0RBR;
}

void uart_tx_string(s8 *p)
{
while(*p)
{
uart_tx(*p);
p++;
}
}

void uart_tx_integer(s32 n)
{
int a[20],i=0;
if(n==0)
uart_tx('0');
else if(n<0)
{
n=-n;
uart_tx('-');
}
while(n>0)
{
a[i++]=n%10+48;
n=n/10;
}
for(i=i-1;i>=0;i--)
uart_tx(a[i]);
}

void uart_tx_float(float f)
{
int n;
if(f==0)
uart_tx_string("0.0");
else if(f<0)
{
f=-f; 
uart_tx('-');
}
n=f;
uart_tx_integer(n);
n=(f-n)*1000000;
uart_tx('.');
uart_tx_integer(n);
}

int uart_rx_integer()
{
	int flag=0,num=0;
	char ch;
	ch=uart_rx();
	uart_tx(ch);
	if(ch=='-')
	{
		flag=1;
	  ch=uart_rx();
		uart_tx(ch);
	}
	while(ch!='\r')
	{
		num=num*10+(ch-'0');
		ch=uart_rx();
		uart_tx(ch);
	}
	if(flag)
		num=-num;
	return num;
}
void uart_rx_string(char *p)
{
	char ch;
	int i=0;
	ch=uart_rx();
	uart_tx(ch);
	while(ch!='\r')
	{
		p[i++]=ch;
		ch=uart_rx();
		uart_tx(ch);
	}
	p[i]='\0';
}
