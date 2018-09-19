/*********************************************************************************/
/* ���ӂɊւ����`                                                              */
/*                                         designed by hamayan since 2009/05/21  */
/*********************************************************************************/
#ifndef	_PERIPHERAL_H_
#define	_PERIPHERAL_H_

#include "stm32f4xx.h"

/*************************************************************************/
/* �v���g�^�C�v�錾                                                      */
/*************************************************************************/
void Dly100us( int delay );
void Dly50us( int delay );
void Dly10us( int delay );
void Dly1us( int delay );
void WaitMs( int delay );
void WaitUs( unsigned long delay );

void GPIO_Terminal_Init( GPIO_TypeDef* GPIOx, int Mode, u16 Pins );

enum  GPIO_MODE_TYPE {OUT2M_PP,OUT25M_PP,OUT50M_PP,OUT100M_PP,OUT2M_OD,OUT25M_OD,OUT50M_OD,OUT100M_OD,
  IN_FLOAT,IN_UP,IN_DOWN,AF_PP,AF_OD,AN_IN,};

void gpioInit( void );
void beginSCI( int ch, unsigned long brr );
void terminateSCI( int ch );

#endif	/* _PERIPHERAL_H_ */

/*********************************************************************************/
/* end of file                                                                   */
/*                                         designed by hamayan since 2009/05/21  */
/*********************************************************************************/
