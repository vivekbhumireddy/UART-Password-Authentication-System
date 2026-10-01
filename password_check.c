#include<lpc21xx.h>
#include"password_header.h"

int password_check(char *p){
int i,upper=0,lower=0,numeric=0,special=0,len=0;
for(i=0;p[i];i++,len++){
if((p[i]>='A') && (p[i]<='Z'))
upper=1;
else if((p[i]>='a') && (p[i]<='z'))
lower=1;
else if((p[i]>='0') && (p[i]<='9'))
numeric=1;
else
special=1;
}
if(!upper || !lower || !numeric || !special){
uart_tx_string("\r\nPassword must contain  atleast \r\n1-uppercase,1-lowercase,1-numeric,1-specialchar\r\n");
return 0;
}
else if(len<8){
uart_tx_string("\r\nPassword must contain atlest 8 characters\r\n");
return 0;
}
else{
uart_tx_string("\r\nPassword Created Succesfully\r\n");
return 1;
}
}
