/*************************************************************************/
/* STM32F407ZET6のテストプログラム色々                                   */
/*                                 designed by hamayan since 2018/09/13  */
/*************************************************************************/
#include  <time.h>
#include  "stm32f4xx.h"
#include  "delivertive.h"
#include  "dpramTest.h"

/*************************************************************************/
/* 端子定義                                                              */
/*************************************************************************/

/*************************************************************************/
/* その他の定義                                                          */
/*************************************************************************/

/*************************************************************************/
/* 大域変数宣言                                                          */
/*************************************************************************/

/*************************************************************************/
/* プロトタイプ宣言                                                      */
/*************************************************************************/

/*************************************************************************/
/* DPRAM check                                                           */
/*************************************************************************/
static int ramCheckByte(void)
{
  int i;
  volatile unsigned char *ptr,data;
  volatile void *ram = (volatile void *)DPRAM_BASE_ADR;

  ptr = (volatile unsigned char *)ram;
  for( i = 0; i < DPRAM_SIZE; i++)
  {
    *ptr++ = (unsigned char)i;
  }

  ptr = (volatile unsigned char *)ram;
  for( i = 0; i < DPRAM_SIZE; i++)
  {
    data = *ptr++;
    if(data != (unsigned char)i)
    {
      return (-1);
    }
  }

  return 0;
}


static int ramCheckWord(void)
{
  #define  DPRAM_W_SIZE  (DPRAM_SIZE / 2)

  int i;
  volatile unsigned short *ptr,data;
  volatile void *ram = (volatile void *)DPRAM_BASE_ADR;

  ptr = (volatile unsigned short *)ram;
  for( i = 0; i < DPRAM_W_SIZE; i++)
  {
    *ptr++ = (unsigned short)i;
  }

  ptr = (volatile unsigned short *)ram;
  for( i = 0; i < DPRAM_W_SIZE; i++)
  {
    data = *ptr++;
    if(data != (unsigned short)i)
    {
      return (-1);
    }
  }

  return 0;
}


static int ramCheckLong(void)
{
  #define  MRAM_L_SIZE  (DPRAM_SIZE / 4)

  int i;
  volatile unsigned long *ptr,data;
  volatile void *ram = (volatile void *)DPRAM_BASE_ADR;

  ptr = (volatile unsigned long *)ram;
  for( i = 0; i < MRAM_L_SIZE; i++)
  {
    *ptr++ = (unsigned long)i;
  }

  ptr = (volatile unsigned long *)ram;
  for( i = 0; i < MRAM_L_SIZE; i++)
  {
    data = *ptr++;
    if(data != (unsigned long)i)
    {
      return (-1);
    }
  }

  return 0;
}


void dpramCheck(void)
{
//  accessCheck();
  SEMR_IS_1;

  while(1)
  {
    if( ramCheckByte() != 0 )
    {
      while(1) ;
    }

    if( ramCheckWord() != 0 )
    {
      while(1) ;
    }

    if( ramCheckLong() != 0 )
    {
      while(1) ;
    }
//    break;
  }
}

/*************************************************************************/
/* end of file                                                           */
/*                                 designed by hamayan since 2018/09/13  */
/*************************************************************************/
