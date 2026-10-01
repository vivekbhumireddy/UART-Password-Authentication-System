#define u32 unsigned int
#define s32 int
#define s8 char
#define u8 unsigned char

extern void delay_ms(u32 ms);

extern void uart_init(u32);
extern void uart_tx(u8);
extern u8 uart_rx(void);
extern void uart_tx_string(s8 *);
extern void uart_tx_integer(s32);
extern void uart_tx_float(float);
extern s32 uart_rx_integer(void);
extern void uart_rx_string(s8 *);
extern int password_check(char *);
extern int password_evaluate(char *,char *);
