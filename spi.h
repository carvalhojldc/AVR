/*
* spi.h
*
* Created: 04/27/2015
*/

// SPCR -> SPIE SPE DORD MSTR CPOL CPHA SPR1 SPR0 
// SPSR -> SPIF WCOL –- –- –- –- -– SPI2X 

#ifndef _SPI_H_
#define _SPI_H_

#define F_CPU 16000000UL // 16MHz

#include <avr/io.h>
#include <util/delay.h>

// Pinos para comunicação SPI
#define SS 		PB0
#define SCK 	PB1
#define MOSI 	PB2
#define MISO 	PB3

// Potas do SS
#define SSA PC5
#define SSB PC6
#define SSC PC7

void spi_init(void);

uint8_t spi_transfere(uint8_t data);

#endif // _SPI_H_
