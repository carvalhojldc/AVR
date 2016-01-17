/*
* usart.c
*
* Created: 04/25/2015
*/

#include "usart.h"

void usart_init(void) {
    UBRR0H = (UBRR0 >> 8);				// Ajusta a taxa de transmisão
    UBRR0L = UBRR0;						// baud rate
	UCSR0B |= (1 << RXEN0);				// Habilita o receptor
    UCSR0C |= (1<<UCSZ00) | (1<<UCSZ01); // Modo assíncrono [UMSEL01 UMSEL00] -> [0 0]
    									// 8 bits de dados
										
	/*
		NOMES DE REGISTRADORES 
	*/
}

//Transmite o dado para o SRCAD
void usart_transmit(uint8_t data) {
	while ( !( UCSR0A & (1<<UDRE0)) );
	UDR0 = data;
}

uint8_t usart_receive(void) {
	while( !(UCSR0A & (1<<RXC0)) );	// Espera o dado ser recebido
	return UDR0; 					// Lê o dado recebido e retorna
}

