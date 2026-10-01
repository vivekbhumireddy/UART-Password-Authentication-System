#include<lpc21xx.h>
#include"password_header.h"

char password[100];

int main(){ 
char new[100]; 
int flag,c=0;
uart_init(9600);
uart_tx_string("Create Your Password\r\n");
uart_rx_string(password);
flag=password_check(password);
while(flag==0){
uart_tx_string("\r\nCreate Your Password\r\n");
uart_rx_string(password);
flag=password_check(password);
}
uart_tx_string("\r\nCheck your password\r\n");
while(1){
if(c==3){
uart_tx_string("\r\nPassword Limit Reached wait for 15seconds\r\n");
c=0;
delay_ms(1500);
uart_tx_string("\r\nTry Again\r\n");
}
uart_tx_string("\r\nEnter your Password\r\n");
uart_rx_string(new);
flag=password_evaluate(password,new);
if(flag){
return 1;
}
uart_tx_string("\r\nTry Again\r\n");
c++;
}
}
