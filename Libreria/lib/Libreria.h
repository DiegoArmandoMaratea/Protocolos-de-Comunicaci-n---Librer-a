#include <MKL25Z4.h>
#ifndef Libreria_h
#define Libreria_h


void Libreria_init();
void Libreria_start();
void Libreria_stop();
void Libreria_write(uint8_t data);
uint8_t Libreria_read();

#endif