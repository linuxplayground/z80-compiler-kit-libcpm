#ifndef _RAND_H
#define _RAND_H
#include <stdint.h>

/*
 * Pseudo random number generator from Fuzix.
 *
 * Initialise the random number generator with a seed.
 */
void srand(uint16_t seed);

/*
 * Return a uint16_t pseudo random number.
 */
uint16_t rand();


// Seed data for fastrand. Default is 0x6969
extern uint16_t rdata;
/*
 * Return a uin8_t pseudo random number using a faster but less random algorythm.
 */
uint8_t fastrand();

#endif// _RAND_H

