#include<lpc21xx.h>
#include"password_header.h"

int password_evaluate(char *old,char *new){
int i;
for(i=0;old[i];i++){
if(old[i]!=new[i])
break;
}
if(old[i]=='\0'){
uart_tx_string("\r\n_____Password is Correct_____\r\n");
return 1;
}
else{
uart_tx_string("\r\nPassword is Incorrect\r\n");
return 0;
}
}
