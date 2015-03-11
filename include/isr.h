/*
 * isr.c
 *
 * Created: 4/11/2014
 *  Author:Damien
 */
#ifndef ISR_H_INCLUDED
#define ISR_H_INCLUDED
typedef enum 
{
GET,
SET,
COMPUTE,
NOSTATE
}eState;
void isr_init();

#endif // PWM_H_INCLUDED
