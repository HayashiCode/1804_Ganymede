/*********************************************************************************/
/* 全体に関する定義                                                              */
/*                                         designed by hamayan since 2018/09/13  */
/*********************************************************************************/

#ifndef	_DELIVERTIVE_H_
#define	_DELIVERTIVE_H_

/*************************************************************************/
/* クロック関連定義                                                      */
/*************************************************************************/
#define  SYS_CLK            (168000000UL)
#define  APB1_CLOCK         (42000000UL)
#define  APB2_CLOCK         (84000000UL)

//typedef  unsigned char   bool;
//enum BOOL { FALSE = 0, TRUE = ~FALSE };

/*************************************************************************/
/* 拡張バス関連定義                                                      */
/*************************************************************************/
#define  EXT_RAM_BASE_ADR 0x60000000  //
#define  DPRAM_BASE_ADR   (EXT_RAM_BASE_ADR + 0x00000000)
#define  ADC1_BASE_ADR    (EXT_RAM_BASE_ADR + 0x04000000)
#define  ADC2_BASE_ADR    (EXT_RAM_BASE_ADR + 0x08000000)
#define  DPRAM_FROM_V50_TO_ME_ADR  (DPRAM_BASE_ADR + (4096 - 2))  /* short size update counter */
#define  DPRAM_FROM_ME_TO_V50_ADR  (DPRAM_BASE_ADR + (4096 - 4))  /* short size update counter */
#define  DPRAM_FROM_V50_REQUEST_ADR  (DPRAM_BASE_ADR + (4096 - 8))  /* long size pulse pattern data */
#define  DPRAM_FROM_ME_RESULT_ADR  (DPRAM_BASE_ADR + (4096 - 12))  /* long size pulse pattern data */

#define  DPRAM_SIZE       (8192 / 1)  /* 4kbyte * 2 */


/*************************************************************************/
/* 端子定義                                                              */
/*************************************************************************/
/*  PC13: LCD R/W : output */
#define  LCD_RW_PORT     GPIOC
#define  LCD_RW_PIN      GPIO_Pin_13
#define  LCD_RW_IS_0     LCD_RW_PORT->BSRRH = (LCD_RW_PIN << 0)
#define  LCD_RW_IS_1     LCD_RW_PORT->BSRRL = (LCD_RW_PIN << 0)

/*  PC14: LCD RS : output */
#define  LCD_RS_PORT     GPIOC
#define  LCD_RS_PIN      GPIO_Pin_14
#define  LCD_RS_IS_0     LCD_RS_PORT->BSRRH = (LCD_RS_PIN << 0)
#define  LCD_RS_IS_1     LCD_RS_PORT->BSRRL = (LCD_RS_PIN << 0)

/*  PE6: LCD E : output */
#define  LCD_E_PORT     GPIOE
#define  LCD_E_PIN      GPIO_Pin_6
#define  LCD_E_IS_0     LCD_E_PORT->BSRRH = (LCD_E_PIN << 0)
#define  LCD_E_IS_1     LCD_E_PORT->BSRRL = (LCD_E_PIN << 0)

/*  PE2: LCD D4 : output */
/*  PE3: LCD D5 : output */
/*  PE4: LCD D6 : output */
/*  PE5: LCD D7 : output */
#define  LCD_DATA_PORT  GPIOE
#define  LCD_DATA_PIN   (GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5)
#define  LCD_D4_SOURCE  GPIO_PinSource2

/* PG11 :ACT LED */
#define  ACT_PORT       GPIOG
#define  ACT_PIN        GPIO_Pin_11
#define  ACT_IS_0       ACT_PORT->BSRRH = (ACT_PIN << 0)
#define  ACT_IS_1       ACT_PORT->BSRRL = (ACT_PIN << 0)
#define  ACT_IS         (ACT_PORT->ODR & ACT_PIN)
#define  ACT_RCC        RCC_AHB1Periph_GPIOG  //for virgo

/* PD12 :MASTER or SLAVE */
#define  M_S_PORT       GPIOD
#define  M_S_PIN        GPIO_Pin_12
#define  M_S_IS         (M_S_PORT->IDR & M_S_PIN)

/* PD11 :V50 INT */
#define  V50_INT_PORT   GPIOD
#define  V50_INT_PIN    GPIO_Pin_11
#define  V50_INT_IS_0   V50_INT_PORT->BSRRH = (V50_INT_PIN << 0)
#define  V50_INT_IS_1   V50_INT_PORT->BSRRL = (V50_INT_PIN << 0)

/* PG7 :GPIO0 */
#define  GPIO0_PORT     GPIOG
#define  GPIO0_PIN      GPIO_Pin_7
#define  GPIO0_IS_0     GPIO0_PORT->BSRRH = (GPIO0_PIN << 0)
#define  GPIO0_IS_1     GPIO0_PORT->BSRRL = (GPIO0_PIN << 0)
#define  GPIO0_IS       (GPIO0_PORT->IDR & GPIO0_PIN)

/* PG8 :GPIO1 */
#define  GPIO1_PORT     GPIOG
#define  GPIO1_PIN      GPIO_Pin_8
#define  GPIO1_IS_0     GPIO1_PORT->BSRRH = (GPIO1_PIN << 0)
#define  GPIO1_IS_1     GPIO1_PORT->BSRRL = (GPIO1_PIN << 0)
#define  GPIO1_IS       (GPIO1_PORT->IDR & GPIO1_PIN)

/* PB6 :SCL1 */
/* PB7 :SDA1 */
#define  I2C1_PORT      GPIOB
#define  I2C1_SCL_PIN   GPIO_Pin_6
#define  I2C1_SDA_PIN   GPIO_Pin_7
#define  I2C1_SCL_IS_0  I2C1_PORT->BSRRH = (I2C1_SCL_PIN << 0)
#define  I2C1_SCL_IS_1  I2C1_PORT->BSRRL = (I2C1_SCL_PIN << 0)
#define  I2C1_SCL_SOURCE GPIO_PinSource6
#define  I2C1_SDA_SOURCE GPIO_PinSource7

/*  PG2: SEMR : output */
#define  SEMR_PORT      GPIOG
#define  SEMR_PIN       GPIO_Pin_2
#define  SEMR_IS_0      SEMR_PORT->BSRRH = (SEMR_PIN << 0)
#define  SEMR_IS_1      SEMR_PORT->BSRRL = (SEMR_PIN << 0)

/*  PA9: TXD1 */
/*  PA10: RXD1 */
#define  USART1_PORT     GPIOA
#define  USART1_TXD_PIN  GPIO_Pin_9
#define  USART1_RXD_PIN  GPIO_Pin_10
#define  USART1_TXD_SOURCE  GPIO_PinSource9
#define  USART1_RXD_SOURCE  GPIO_PinSource10

/*  PB10: TXD3 */
/*  PB11: RXD3 */
#define  USART3_PORT     GPIOB
#define  USART3_TXD_PIN  GPIO_Pin_10
#define  USART3_RXD_PIN  GPIO_Pin_11
#define  USART3_TXD_SOURCE  GPIO_PinSource10
#define  USART3_RXD_SOURCE  GPIO_PinSource11

/*  PC10: TXD4 */
/*  PC11: RXD4 */
#define  UART4_PORT     GPIOC
#define  UART4_TXD_PIN  GPIO_Pin_10
#define  UART4_RXD_PIN  GPIO_Pin_11
#define  UART4_TXD_SOURCE  GPIO_PinSource10
#define  UART4_RXD_SOURCE  GPIO_PinSource11

/*  PC12: TXD5 */
/*  PD2: RXD5 */
#define  UART5_TXD_PORT  GPIOC
#define  UART5_RXD_PORT  GPIOD
#define  UART5_TXD_PIN   GPIO_Pin_12
#define  UART5_RXD_PIN   GPIO_Pin_2
#define  UART5_TXD_SOURCE  GPIO_PinSource12
#define  UART5_RXD_SOURCE  GPIO_PinSource2

/* 1411 */
/* PF7,PF8,PF9,PF10,PF11 :1411 */
#define  BD1411_PORT       GPIOF
#define  BD1411_SI_PIN     GPIO_Pin_11
#define  BD1411_SCLK_PIN   GPIO_Pin_10
#define  BD1411_LATCH_PIN  GPIO_Pin_9
#define  BD1411_OE_PIN     GPIO_Pin_8
#define  BD1411_CLR_PIN    GPIO_Pin_7
#define  BD1411_SI_IS_0    BD1411_PORT->BSRRH = (BD1411_SI_PIN << 0)
#define  BD1411_SI_IS_1    BD1411_PORT->BSRRL = (BD1411_SI_PIN << 0)
#define  BD1411_SCLK_IS_0  BD1411_PORT->BSRRH = (BD1411_SCLK_PIN << 0)
#define  BD1411_SCLK_IS_1  BD1411_PORT->BSRRL = (BD1411_SCLK_PIN << 0)
#define  BD1411_LATCH_IS_0 BD1411_PORT->BSRRH = (BD1411_LATCH_PIN << 0)
#define  BD1411_LATCH_IS_1 BD1411_PORT->BSRRL = (BD1411_LATCH_PIN << 0)
#define  BD1411_OE_IS_0    BD1411_PORT->BSRRH = (BD1411_OE_PIN << 0)
#define  BD1411_OE_IS_1    BD1411_PORT->BSRRL = (BD1411_OE_PIN << 0)
#define  BD1411_CLR_IS_0   BD1411_PORT->BSRRH = (BD1411_CLR_PIN << 0)
#define  BD1411_CLR_IS_1   BD1411_PORT->BSRRL = (BD1411_CLR_PIN << 0)

/* PA0,PA1 :MPX0,MPX1 */
#define  MPX_PORT    GPIOA
#define  MPX0_PIN    GPIO_Pin_1
#define  MPX1_PIN    GPIO_Pin_0
#define  MPX0_IS_0   MPX_PORT->BSRRH = (MPX0_PIN << 0)
#define  MPX0_IS_1   MPX_PORT->BSRRL = (MPX0_PIN << 0)
#define  MPX1_IS_0   MPX_PORT->BSRRH = (MPX1_PIN << 0)
#define  MPX1_IS_1   MPX_PORT->BSRRL = (MPX1_PIN << 0)

/* PB1 : PULSE1 */
#define  PULSE1_PORT   GPIOB
#define  PULSE1_PIN    GPIO_Pin_1
#define  PULSE1_IS     (PULSE1_PORT->IDR & PULSE1_PIN)
/* PB0 : PULSE2 */
#define  PULSE2_PORT   GPIOB
#define  PULSE2_PIN    GPIO_Pin_0
#define  PULSE2_IS     (PULSE2_PORT->IDR & PULSE2_PIN)
/* PC5 : PULSE3 */
#define  PULSE3_PORT   GPIOC
#define  PULSE3_PIN    GPIO_Pin_5
#define  PULSE3_IS     (PULSE3_PORT->IDR & PULSE3_PIN)
/* PC4 : PULSE4 */
#define  PULSE4_PORT   GPIOC
#define  PULSE4_PIN    GPIO_Pin_4
#define  PULSE4_IS     (PULSE4_PORT->IDR & PULSE4_PIN)
/* PA7 : PULSE5 */
#define  PULSE5_PORT   GPIOA
#define  PULSE5_PIN    GPIO_Pin_7
#define  PULSE5_IS     (PULSE5_PORT->IDR & PULSE5_PIN)
/* PA6 : PULSE6 */
#define  PULSE6_PORT   GPIOA
#define  PULSE6_PIN    GPIO_Pin_6
#define  PULSE6_IS     (PULSE6_PORT->IDR & PULSE6_PIN)
/* PA3 : PULSE7 */
#define  PULSE7_PORT   GPIOA
#define  PULSE7_PIN    GPIO_Pin_3
#define  PULSE7_IS     (PULSE7_PORT->IDR & PULSE7_PIN)
/* PA2 : PULSE8 */
#define  PULSE8_PORT   GPIOA
#define  PULSE8_PIN    GPIO_Pin_2
#define  PULSE8_IS     (PULSE8_PORT->IDR & PULSE8_PIN)


/*************************************************************************/
/* EEPROM 定義                                                           */
/*************************************************************************/
#define  I2C_EEPROM_ADR    0x50

/*************************************************************************/
/* その他の定義                                                          */
/*************************************************************************/
typedef enum
{
  STDNULL=0,
  STDOUT=1,
  STDOUT2,
  STDOUT3,
  STDOUT4,
  STDOUT5,
  STDEND,
} HANDLES;
#define  STDIN                    STDOUT

#define  Cpu_Delay100US(delay)    Dly100us(delay)
#define  HEAPSIZE                 (10000)  /**/

/*************************************************************************/
/* 大域変数宣言                                                          */
/*************************************************************************/

/*************************************************************************/
/* プロトタイプ宣言                                                      */
/*************************************************************************/
//#include  "mul_tsk.h"
int xprintf(int fd,const char *fmt, ...);
int _xwrite(int fd, char *str, int len);
int _xread(int fd, char *str, int len);
void gpioInit( void );

/*************************************************************************/
/* マルチタスク関連                                                      */
/*************************************************************************/
#define  MAX_TASK_NUMBER    4  //
enum TSK_ID
{
  ID_stackMonitor,
  ID_adcTask,
  ID_pulseOutputTask,
  ID_gpsMonitor,
};

#define  MAX_MBX_NUMBER    1  //最大メールボックス数
enum MBX_ID
{
  MBXID_dummy,         //使用しない
};


#endif	/*_DELIVERTIVE_H_*/

/*********************************************************************************/
/* end of file                                                                   */
/*                                         designed by hamayan since 2018/09/13  */
/*********************************************************************************/
