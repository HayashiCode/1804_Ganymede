/*********************************************************************************/
/* 周辺IOの初期化                                                                */
/*                                         designed by hamayan since 2018/09/13  */
/*********************************************************************************/
#include  "stm32f4xx.h"
#include  "peripheral.h"
#include  "delivertive.h"
#include  "priority.h"
#include  "mul_tsk.h"
#include  "max1316.h"

/*************************************************************************/
/* その他の定義                                                          */
/*************************************************************************/

/*************************************************************************/
/* 大域変数宣言                                                          */
/*************************************************************************/
volatile unsigned short adc1Data[8][200 * 2];  /* 50hz wave,10ksps,8channels,2buffers */
volatile unsigned short adc2Data[8][200 * 2];  /* 50hz wave,10ksps,8channels,2buffers */
volatile unsigned short adc1Wptr;
volatile unsigned short adc1Rptr;
volatile unsigned short adc2Wptr;
volatile unsigned short adc2Rptr;
const unsigned short adc1DataCountLimit = sizeof(adc1Data[0]) / sizeof(adc1Data[0][0]);
const unsigned short adc2DataCountLimit = sizeof(adc2Data[0]) / sizeof(adc2Data[0][0]);

unsigned short waveData[16][ 200 * 2 ];  /* two wave buffers. */
signed short   signedWaveData[16][ 200 * 2 ];  /* two wave buffers. */
const unsigned short waveDataCountLimit = sizeof(waveData[0]) / sizeof(waveData[0][0]);

volatile unsigned long adc1OverWriteCount;
volatile unsigned long adc2OverWriteCount;


/*************************************************************************/
/* プロトタイプ宣言                                                      */
/*************************************************************************/
static void printCSV( const signed short wav[16][400] );
static unsigned short available( unsigned short w, unsigned short r, unsigned short s );

/*************************************************************************/
/* 端子定義                                                              */
/*************************************************************************/

/*************************************************************************/
/* How many counts from adc buffer?                                      */
/*************************************************************************/
static unsigned short available( unsigned short w, unsigned short r, unsigned short s )
{
  if( w < r ) return (w + s) - r;
  else return w - r;
}


/*************************************************************************/
/* print out by csv                                                      */
/*************************************************************************/
static void printCSV( const signed short wav[16][400] )
{
  xprintf( STDOUT,"\r\nMAX\r\nMIN\r\nDELTA\r\n\r\n" );
  xprintf( STDOUT,"NUM,CH1,CH2,CH3,CH4,CH5,CH6,CH7,CH8,CH9,CH10,CH11,CH12,CH13,CH14,CH15,CH16\r\n" );
  for( int i = 0; i < 400; i++ )
  {
    xprintf( STDOUT,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\r\n",
      i + 1,
      wav[0][i],wav[1][i],wav[2][i],wav[3][i],
      wav[4][i],wav[5][i],wav[6][i],wav[7][i],
      wav[8][i],wav[9][i],wav[10][i],wav[11][i],
      wav[12][i],wav[13][i],wav[14][i],wav[15][i]
    );
  }
  xprintf( STDOUT,"done.\r\n" );
}


/*************************************************************************/
/* adcタスク                                                             */
/*************************************************************************/
void adcTask( void )
{
  /* filter clock output. */
  fclkSet( FILTER_CLOCK_IS );
  /* initialize adc1 and adc2. */
  adc1Init();
  adc2Init();
  /* initialize sampling clock. */
  convertSet( SAMPLING_CLOCK_IS );
  /* enable adc interrupt. */
  adcIntEnable();
  /* conversion start. */
  GPIO_Terminal_Init( GPIOF, OUT25M_PP, GPIO_Pin_11 );
  convertStart();

  /* dispose one wave data. */
  while( available( adc1Wptr, adc1Rptr, adc1DataCountLimit ) < 200U ) rot_rdq();
  adc1Rptr = adc1Wptr;
  while( available( adc2Wptr, adc2Rptr, adc2DataCountLimit ) < 200U ) rot_rdq();
  adc2Rptr = adc2Wptr;

  /* recieve one wave data. */
  while( available( adc1Wptr, adc1Rptr, adc1DataCountLimit ) < 400U ) rot_rdq();
  while( available( adc2Wptr, adc2Rptr, adc2DataCountLimit ) < 400U ) rot_rdq();
  for( int i = 0; i < waveDataCountLimit; i++ )
  {
    waveData[0][ i ] = adc1Data[0][ adc1Rptr ];
    waveData[1][ i ] = adc1Data[1][ adc1Rptr ];
    waveData[2][ i ] = adc1Data[2][ adc1Rptr ];
    waveData[3][ i ] = adc1Data[3][ adc1Rptr ];
    waveData[4][ i ] = adc1Data[4][ adc1Rptr ];
    waveData[5][ i ] = adc1Data[5][ adc1Rptr ];
    waveData[6][ i ] = adc1Data[6][ adc1Rptr ];
    waveData[7][ i ] = adc1Data[7][ adc1Rptr ];

    waveData[8][ i ]  = adc2Data[0][ adc2Rptr ];
    waveData[9][ i ]  = adc2Data[1][ adc2Rptr ];
    waveData[10][ i ] = adc2Data[2][ adc2Rptr ];
    waveData[11][ i ] = adc2Data[3][ adc2Rptr ];
    waveData[12][ i ] = adc2Data[4][ adc2Rptr ];
    waveData[13][ i ] = adc2Data[5][ adc2Rptr ];
    waveData[14][ i ] = adc2Data[6][ adc2Rptr ];
    waveData[15][ i ] = adc2Data[7][ adc2Rptr ];

    adc1Rptr++;
    adc2Rptr++;
    if( adc1Rptr >= adc1DataCountLimit ) adc1Rptr = 0;
    if( adc2Rptr >= adc2DataCountLimit ) adc2Rptr = 0;
  }
#if 1
  /* averages. */
  long average[ 16 ] = {0L,0L,0L,0L,0L,0L,0L,0L,0L,0L,0L,0L,0L,0L,0L,0L};
  for( int i = 0; i < waveDataCountLimit; i++ )
  {
    average[0] += waveData[0][ i ];
    average[1] += waveData[1][ i ];
    average[2] += waveData[2][ i ];
    average[3] += waveData[3][ i ];
    average[4] += waveData[4][ i ];
    average[5] += waveData[5][ i ];
    average[6] += waveData[6][ i ];
    average[7] += waveData[7][ i ];

    average[8] += waveData[8][ i ];
    average[9] += waveData[9][ i ];
    average[10] += waveData[10][ i ];
    average[11] += waveData[11][ i ];
    average[12] += waveData[12][ i ];
    average[13] += waveData[13][ i ];
    average[14] += waveData[14][ i ];
    average[15] += waveData[15][ i ];
  }
  average[0] /= waveDataCountLimit;
  average[1] /= waveDataCountLimit;
  average[2] /= waveDataCountLimit;
  average[3] /= waveDataCountLimit;
  average[4] /= waveDataCountLimit;
  average[5] /= waveDataCountLimit;
  average[6] /= waveDataCountLimit;
  average[7] /= waveDataCountLimit;
  average[8] /= waveDataCountLimit;
  average[9] /= waveDataCountLimit;
  average[10] /= waveDataCountLimit;
  average[11] /= waveDataCountLimit;
  average[12] /= waveDataCountLimit;
  average[13] /= waveDataCountLimit;
  average[14] /= waveDataCountLimit;
  average[15] /= waveDataCountLimit;

  /* subtraction averages from data. */
  for( int i = 0; i < waveDataCountLimit; i++ )
  {
    signedWaveData[0][ i ] = (signed short)(waveData[0][ i ] - average[0]);
    signedWaveData[1][ i ] = (signed short)(waveData[1][ i ] - average[1]);
    signedWaveData[2][ i ] = (signed short)(waveData[2][ i ] - average[2]);
    signedWaveData[3][ i ] = (signed short)(waveData[3][ i ] - average[3]);
    signedWaveData[4][ i ] = (signed short)(waveData[4][ i ] - average[4]);
    signedWaveData[5][ i ] = (signed short)(waveData[5][ i ] - average[5]);
    signedWaveData[6][ i ] = (signed short)(waveData[6][ i ] - average[6]);
    signedWaveData[7][ i ] = (signed short)(waveData[7][ i ] - average[7]);
    signedWaveData[8][ i ] = (signed short)(waveData[8][ i ] - average[8]);
    signedWaveData[9][ i ] = (signed short)(waveData[9][ i ] - average[9]);
    signedWaveData[10][ i ] = (signed short)(waveData[10][ i ] - average[10]);
    signedWaveData[11][ i ] = (signed short)(waveData[11][ i ] - average[11]);
    signedWaveData[12][ i ] = (signed short)(waveData[12][ i ] - average[12]);
    signedWaveData[13][ i ] = (signed short)(waveData[13][ i ] - average[13]);
    signedWaveData[14][ i ] = (signed short)(waveData[14][ i ] - average[14]);
    signedWaveData[15][ i ] = (signed short)(waveData[15][ i ] - average[15]);
  }
#endif
  printCSV( signedWaveData );

  while( 1 )
  {
    dly_tsk( 1000UL );
  }
}

/*************************************************************************/
/* Filter clockの初期化                                                  */
/* FCLK端子はPD13。これをTIM4 CH2の出力に設定する                        */
/*************************************************************************/
void fclkSet( unsigned long hertz )
{
  TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
  TIM_OCInitTypeDef TIM_OCInitStructure;

  /* pd13 initialize */
  GPIO_Terminal_Init( GPIOD, AF_PP, GPIO_Pin_13 );
  GPIO_PinAFConfig( GPIOD, GPIO_PinSource13, GPIO_AF_TIM4 );

  /* TIM4 clock enable */
  RCC_APB1PeriphClockCmd( RCC_APB1Periph_TIM4, ENABLE );

  /* Time base configuration */
  TIM_TimeBaseStructInit( &TIM_TimeBaseStructure );
  TIM_TimeBaseStructure.TIM_Prescaler = 1 - 1;  /*プリスケーラで1/1*/
  TIM_TimeBaseStructure.TIM_Period = (APB1_CLOCK / hertz / 1) - 1;  /*周期設定*/
  TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;  /*クロック分周比=1*/
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseInit( TIM4, &TIM_TimeBaseStructure );
  
  /* Output Compare Toggle Mode configuration: Channel2 */
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_Toggle;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = 0;  /*コンペアマッチ=0*/
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
  TIM_OC2Init( TIM4, &TIM_OCInitStructure );
  TIM_OC2PreloadConfig( TIM4, TIM_OCPreload_Disable );

  /* TIM enable counter */
  TIM_Cmd( TIM4, ENABLE );
}


/*************************************************************************/
/* conversion clockの初期化                                              */
/* CONVERTはPC8。これをTIM8 CH3の出力に設定する                          */
/* TIM8はDMAのトリガに設定できる。DMA2のChannel0とChannel7がDMAのTIM8をソースに選べる*/
/* DMA2 Channel0 : TIM8 CH2, DMA2 Channel7 : TIM8 CH1                    */
/*************************************************************************/
void convertSet( unsigned long hertz )
{
  TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
  TIM_OCInitTypeDef TIM_OCInitStructure;

  /* pc8 initialize */
  GPIO_Terminal_Init( GPIOC, AF_PP, GPIO_Pin_8 );
  GPIO_PinAFConfig( GPIOC, GPIO_PinSource8, GPIO_AF_TIM8 );

  /* TIM8 channel3 */
  /* TIM8 clock enable */
  RCC_APB2PeriphClockCmd( RCC_APB2Periph_TIM8, ENABLE );

  /* Time base configuration */
  TIM_TimeBaseStructInit( &TIM_TimeBaseStructure );
  TIM_TimeBaseStructure.TIM_Prescaler = 2 - 1;  /*プリスケーラで2/1*/
  TIM_TimeBaseStructure.TIM_Period = (APB2_CLOCK / hertz / 1) - 1;  /*周期設定*/
  TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;  /*クロック分周比=1*/
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
  TIM_TimeBaseInit( TIM8, &TIM_TimeBaseStructure );

  /* Output PWM Mode configuration: Channel3 */
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = 84;  /* conversion pulse width = 1000ns */
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
  TIM_OC3Init( TIM8, &TIM_OCInitStructure );
  TIM_OC3PreloadConfig( TIM8, TIM_OCPreload_Disable );
//  TIM_OC3PreloadConfig( TIM8, TIM_OCPreload_Enable );
//  TIM_ARRPreloadConfig( TIM8, ENABLE );

  /* TIM enable counter */
//  TIM_Cmd( TIM8, ENABLE );
}


/*************************************************************************/
/* conversion clockの初期化                                              */
/* CONVERTはPC8。これをTIM3 CH3の出力に設定する                          */
/*************************************************************************/
void convertStart( void )
{
  /* TIM enable counter */
  TIM_Cmd( TIM8, ENABLE );
  TIM_CtrlPWMOutputs( TIM8, ENABLE );
}


/*************************************************************************/
/* adc1の初期化                                                          */
/*************************************************************************/
void adc1Init( void )
{
  volatile unsigned short *tempUS = (volatile unsigned short *)ADC1_BASE_ADR;
  *tempUS = 0x00ff;
}

/*************************************************************************/
/* adc2の初期化                                                          */
/*************************************************************************/
void adc2Init( void )
{
  volatile unsigned short *tempUS = (volatile unsigned short *)ADC2_BASE_ADR;
  *tempUS = 0x00ff;
}

/*************************************************************************/
/* adcの割り込み(EOLC1 or EOLC2)イネーブル                               */
/*************************************************************************/
void adcIntEnable( void )
{
  /* Enable clock for SYSCFG */
  RCC_APB2PeriphClockCmd( RCC_APB2Periph_SYSCFG, ENABLE );
  /* Configure EOLC1 EXTI line */
  EXTI_DeInit();
  EXTI_InitTypeDef EXTI_InitStruct;
  EXTI_StructInit( &EXTI_InitStruct );
  SYSCFG_EXTILineConfig( EXTI_PortSourceGPIOG, EXTI_PinSource5 );

  EXTI_InitStruct.EXTI_Line = EXTI_Line5;
  EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling;
  EXTI_InitStruct.EXTI_LineCmd = ENABLE;
  EXTI_Init( &EXTI_InitStruct );
  /* Configure EOLC2 EXTI line */
  SYSCFG_EXTILineConfig( EXTI_PortSourceGPIOG, EXTI_PinSource4 );
  EXTI_InitStruct.EXTI_Line = EXTI_Line4;
  EXTI_Init( &EXTI_InitStruct );

  /* initialize nvic*/
  NVIC_InitTypeDef NVIC_InitStructure;
  NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = BASE_PRIORITY;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = BASE_SUB_PRIORITY;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init( &NVIC_InitStructure );
  NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;
  NVIC_Init( &NVIC_InitStructure );
}


/*************************************************************************/
/* 割り込みハンドラ                                                      */
/* PG5: EOLC1,PG4 : EOLC2                                                */
/*************************************************************************/
void EXTI4_IRQHandler( void )
{
  if( EXTI_GetITStatus( EXTI_Line4 ) == SET )  /*XOVR*/
  {
    EXTI_ClearITPendingBit( EXTI_Line4 );  /*割込み要求要因の解除*/

    unsigned short next = adc2Wptr + 1;
    if( next >= adc2DataCountLimit ) next = 0;

    volatile unsigned short *adc2 = (volatile unsigned short *)ADC2_BASE_ADR;
    adc2Data[ 7 ][ adc2Wptr ] = *adc2 & ADC2_DATA_MASK;  /* channel 16 */
    adc2Data[ 6 ][ adc2Wptr ] = *adc2 & ADC2_DATA_MASK;  /* channel 15 */
    adc2Data[ 5 ][ adc2Wptr ] = *adc2 & ADC2_DATA_MASK;  /* channel 14 */
    adc2Data[ 4 ][ adc2Wptr ] = *adc2 & ADC2_DATA_MASK;  /* channel 13 */
    adc2Data[ 3 ][ adc2Wptr ] = *adc2 & ADC2_DATA_MASK;  /* channel 12 */
    adc2Data[ 2 ][ adc2Wptr ] = *adc2 & ADC2_DATA_MASK;  /* channel 11 */
    adc2Data[ 1 ][ adc2Wptr ] = *adc2 & ADC2_DATA_MASK;  /* channel 10 */
    adc2Data[ 0 ][ adc2Wptr ] = *adc2 & ADC2_DATA_MASK;  /* channel 9 */
    if( next == adc2Rptr )
    {
      adc2OverWriteCount++;
      return;  /* write pointer not update. */
    }
    adc2Wptr = next;
  }
}

void EXTI9_5_IRQHandler( void )
{
  if( EXTI_GetITStatus( EXTI_Line5 ) == SET )  /*XOVR*/
  {
    EXTI_ClearITPendingBit( EXTI_Line5 );  /*割込み要求要因の解除*/

    unsigned short next = adc1Wptr + 1;
    if( next >= adc1DataCountLimit ) next = 0;

    volatile unsigned short *adc1 = (volatile unsigned short *)ADC1_BASE_ADR;
#if 1
    adc1Data[ 7 ][ adc1Wptr ] = *adc1 & ADC1_DATA_MASK;  /* channel 8 */
    adc1Data[ 6 ][ adc1Wptr ] = *adc1 & ADC1_DATA_MASK;  /* channel 7 */
    adc1Data[ 5 ][ adc1Wptr ] = *adc1 & ADC1_DATA_MASK;  /* channel 6 */
    adc1Data[ 4 ][ adc1Wptr ] = *adc1 & ADC1_DATA_MASK;  /* channel 5 */
    adc1Data[ 3 ][ adc1Wptr ] = *adc1 & ADC1_DATA_MASK;  /* channel 4 */
    adc1Data[ 2 ][ adc1Wptr ] = *adc1 & ADC1_DATA_MASK;  /* channel 3 */
    adc1Data[ 1 ][ adc1Wptr ] = *adc1 & ADC1_DATA_MASK;  /* channel 2 */
    adc1Data[ 0 ][ adc1Wptr ] = *adc1 & ADC1_DATA_MASK;  /* channel 1 */
    if( next == adc1Rptr )
    {
      adc1OverWriteCount++;
      return;  /* write pointer not update. */
    }
    adc1Wptr = next;
#else
    volatile unsigned short dummy = *adc1;  /* channel 8 */
    if( dummy & 0x8000 )
    {
      GPIOF->BSRRL = (GPIO_Pin_11 << 0);
    }
    else
    {
      GPIOF->BSRRH = (GPIO_Pin_11 << 0);
    }
    dummy = *adc1;  /* channel 7 */
    dummy = *adc1;  /* channel 6 */
    dummy = *adc1;  /* channel 5 */
    dummy = *adc1;  /* channel 4 */
    dummy = *adc1;  /* channel 3 */
    dummy = *adc1;  /* channel 2 */
    dummy = *adc1;  /* channel 1 */
#endif
  }
}


/*********************************************************************************/
/* end of file                                                                   */
/*                                         designed by hamayan since 2018/09/13  */
/*********************************************************************************/
