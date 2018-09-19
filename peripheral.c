/*********************************************************************************/
/* é¸ï”IOÇÃèâä˙âª                                                                */
/*                                         designed by hamayan since 2018/09/19  */
/*********************************************************************************/
#include  "peripheral.h"

/*************************************************************************/
/* GPIOí[éqèâä˙âª                                                        */
/*************************************************************************/
void GPIO_Terminal_Init( GPIO_TypeDef* GPIOx, int Mode, u16 Pins )
{
  GPIO_InitTypeDef GPIO_InitStructure;

  switch (Mode)
  {
    case OUT2M_PP :
      GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
      GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
      GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
      break;
    case OUT25M_PP :
      GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
      GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
      GPIO_InitStructure.GPIO_Speed = GPIO_Speed_25MHz;
      break;
    case OUT50M_PP :
      GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
      GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
      GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
      break;
    case OUT100M_PP :
      GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
      GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
      GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
      break;
    case OUT2M_OD :
      GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
      GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
      GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
      break;
    case OUT25M_OD :
      GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
      GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
      GPIO_InitStructure.GPIO_Speed = GPIO_Speed_25MHz;
      break;
    case OUT50M_OD :
      GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
      GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
      GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
      break;
    case OUT100M_OD :
      GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
      GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
      GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
      break;
    case IN_FLOAT :
      GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
      GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
      break;
    case IN_UP :
      GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
      GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
      break;
    case IN_DOWN :
      GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
      GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
      break;
    case AF_PP :
      GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;
      GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
      GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
      //GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
      break;
    case AF_OD :
      GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;
      GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
      GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
      //GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
      break;
    case AN_IN :
      GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AN;
      GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
      break;
  }

  GPIO_InitStructure.GPIO_Pin = Pins;
  GPIO_Init( GPIOx, &GPIO_InitStructure );
}

/*********************************************************************************/
/* end of file                                                                   */
/*                                         designed by hamayan since 2018/09/19  */
/*********************************************************************************/
