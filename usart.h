/*
* usart.h
*
* Created: 04/25/2015
*/

/*
* UDR0
* UCSR0A -> RXC0 TXC0 UDRE0 FE0 DOR0 UPE0 U2X0 MPCM0
* UCSR0B -> RXCIE0 TXCIE0 UDRIE0 RXEN0 TXEN0 UCSZ02 RXB80 TXB80
* UCSR0C -> UMSEL01 UMSEL00 UPM01 UPM00 USBS0 UCSZ01 UCSZ00 UCPOL0
*/

/*
* Comunicação USART entre o ATmega328p e o computador
*
* Trabalhando com frame de 8 bits
*/

#ifndef _USART_H_
#define _USART_H_

#include "core.h"

#define BAUD 9600
#define UBRR0 F_CPU/(BAUD*16) - 1

#define RXD PD0 // Recebe
#define TXD PD1 // Envia

void usart_init(void);
// Init usart

void usart_transmit(uint8_t data);
// Transmite um inteiro sem sinal de 8 bits para o SRCAD

uint8_t usart_receive(void);
// Receiving Frames with 5 to 8 Data Bit

#endif // _USART_H_
