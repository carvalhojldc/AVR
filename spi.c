/*
* spi.c
*
* Created: 04/27/2015
*/

#include "spi.h"

void spi_init(void) {   
	SPCR |= (1<<MSTR); 			 // Habilita modo Master
	DDRB |= (1<<MOSI)|(1<<SCK);  // Ajusta os pinos MOSI (PBx) e CLK (PBx) como saída
	SPCR |= (0<<SPR0)|(0<<SPR1); // Configura o dividor para o gerador de clock.
    SPCR |= (1<<SPE); 			 // Habilita a comunicação SPI.
}

uint8_t spi_transfere(uint8_t data) {
    SPDR = data; 			   // Envia o dado.
    while( !( SPSR & SPIF ) ); // Aguarda o final da troca.
	return SPDR;               // Retorna o dado recebido.
}
