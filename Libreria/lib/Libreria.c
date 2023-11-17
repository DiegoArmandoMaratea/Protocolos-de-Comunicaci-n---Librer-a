#include <MKL25Z4.h>
#include "Libreria.h"

void Libreria_init(){
        SIM->SCGC4 |= SIM_SCGC4_Libreria1;
        SIM->SCGC5 |= SIM_SCGC5_PORTC;

        
    PORTC->PCR[2] = (PORTC->PCR[8] & PORT_PCR_MASK) | PORT_PCR_MUX(5);
     PORTC->PCR[3] = (PORTC->PCR[9] & PORT_PCR_MASK) | PORT_PCR_MUX(5);

     Libreria1->F = Libreria_F_MULT (0) | Libreria_F_ICR(24);
     Libreria1->C1 |= Libreria_C1_IICEN;

}

void Libreria_start(){
    Libreria1->C1 |= Libreria_C1_MST;
    Libreria1->C1 |= Libreria_C1_TX;

}

void Libreria_stop(){

    Libreria1->C1 &= Libreria_C1_MST;
    Libreria1->C1 &= Libreria_C1_TX;

}

void Libreria_write(uint8_t data){

    Libreria1->D= data;

    while (!(Libreria1->S & Libreria_S_IICIF));
    Libreria1->S |= Libreria_S_IICIF;

}

    uint8_t Libreria_read(){
        Libreria1->C1 &= I2C_C1_TX;

        while (!(Libreria1->S & Libreria_S_IICIF));
    Libreria1->S |= Libreria_S_IICIF;

    return Libreria->D;

    }