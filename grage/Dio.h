/*
 * IncFile1.h
 *
 * Created: 4/30/2024 3:16:28 PM
 *  Author: RS3
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_


void DIO_vsetpindir(unsigned char port,unsigned char pin,unsigned char direction);//output  or input
void DIO_vwrite(unsigned char port,unsigned char pin,unsigned char val);//OUTPUT==VALUE
void DIO_vtogglepin(unsigned char port,unsigned char pin);
unsigned char DIO_uread(unsigned char port ,unsigned char pin);
void DIO_vsetportdir(unsigned char port,unsigned char direction);
unsigned char DIO_ureadport(unsigned char port);
void DIO_vWRITEport(unsigned char port,unsigned char val);
void DIO_vtoggleport(unsigned char port);

//internal pull up
void DIO_vconnectpullup(char portname ,char pinnumber, char connect_pullup);

//seven bcd
void write_low_nibble(unsigned char portname,unsigned char val);

void write_high_nibble(unsigned char portname,unsigned char val);
#endif /* INCFILE1_H_ */