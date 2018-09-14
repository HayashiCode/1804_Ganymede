/*********************************************************************************/
/* STM32F407ZET6�̊g���o�X�̎���IO�̏�����                                       */
/*                                         designed by hamayan since 2018/09/13  */
/*********************************************************************************/
#include  "stm32f4xx.h"
#include  "delivertive.h"
#include  "peripheral.h"

/*************************************************************************/
/* ���̑��̒�`                                                          */
/*************************************************************************/

/*************************************************************************/
/* ���ϐ��錾                                                          */
/*************************************************************************/

/*************************************************************************/
/* �v���g�^�C�v�錾                                                      */
/*************************************************************************/
static void gpioPortSetting( void );

/*************************************************************************/
/* �[�q��`                                                              */
/*************************************************************************/

/*************************************************************************/
/* �|�[�g�̐ݒ�                                                          */
/*************************************************************************/
static void gpioPortSetting( void )
{
  GPIO_Terminal_Init( GPIOF, AF_PP, GPIO_Pin_0 );
  GPIO_PinAFConfig( GPIOF, GPIO_PinSource0, GPIO_AF_FSMC );  //a0

  GPIO_Terminal_Init( GPIOF, AF_PP, GPIO_Pin_1 );
  GPIO_PinAFConfig( GPIOF, GPIO_PinSource1, GPIO_AF_FSMC );  //a1

  GPIO_Terminal_Init( GPIOF, AF_PP, GPIO_Pin_2 );
  GPIO_PinAFConfig( GPIOF, GPIO_PinSource2, GPIO_AF_FSMC );  //a2

  GPIO_Terminal_Init( GPIOF, AF_PP, GPIO_Pin_3 );
  GPIO_PinAFConfig( GPIOF, GPIO_PinSource3, GPIO_AF_FSMC );  //a3

  GPIO_Terminal_Init( GPIOF, AF_PP, GPIO_Pin_4 );
  GPIO_PinAFConfig( GPIOF, GPIO_PinSource4, GPIO_AF_FSMC );  //a4

  GPIO_Terminal_Init( GPIOF, AF_PP, GPIO_Pin_5 );
  GPIO_PinAFConfig( GPIOF, GPIO_PinSource5, GPIO_AF_FSMC );  //a5

  GPIO_Terminal_Init( GPIOF, AF_PP, GPIO_Pin_12 );
  GPIO_PinAFConfig( GPIOF, GPIO_PinSource12, GPIO_AF_FSMC );  //a6

  GPIO_Terminal_Init( GPIOF, AF_PP, GPIO_Pin_13 );
  GPIO_PinAFConfig( GPIOF, GPIO_PinSource13, GPIO_AF_FSMC );  //a7

  GPIO_Terminal_Init( GPIOF, AF_PP, GPIO_Pin_14 );
  GPIO_PinAFConfig( GPIOF, GPIO_PinSource14, GPIO_AF_FSMC );  //a8

  GPIO_Terminal_Init( GPIOF, AF_PP, GPIO_Pin_15 );
  GPIO_PinAFConfig( GPIOF, GPIO_PinSource15, GPIO_AF_FSMC );  //a9

  GPIO_Terminal_Init( GPIOG, AF_PP, GPIO_Pin_0 );
  GPIO_PinAFConfig( GPIOG, GPIO_PinSource0, GPIO_AF_FSMC );  //a10

  GPIO_Terminal_Init( GPIOG, AF_PP, GPIO_Pin_1 );
  GPIO_PinAFConfig( GPIOG, GPIO_PinSource1, GPIO_AF_FSMC );  //a11

  GPIO_Terminal_Init( GPIOD, AF_PP, GPIO_Pin_14 );
  GPIO_PinAFConfig( GPIOD, GPIO_PinSource14, GPIO_AF_FSMC );  //d0

  GPIO_Terminal_Init( GPIOD, AF_PP, GPIO_Pin_15 );
  GPIO_PinAFConfig( GPIOD, GPIO_PinSource15, GPIO_AF_FSMC );  //d1

  GPIO_Terminal_Init( GPIOD, AF_PP, GPIO_Pin_0 );
  GPIO_PinAFConfig( GPIOD, GPIO_PinSource0, GPIO_AF_FSMC );  //d2

  GPIO_Terminal_Init( GPIOD, AF_PP, GPIO_Pin_1 );
  GPIO_PinAFConfig( GPIOD, GPIO_PinSource1, GPIO_AF_FSMC );  //d3

  GPIO_Terminal_Init( GPIOE, AF_PP, GPIO_Pin_7 );
  GPIO_PinAFConfig( GPIOE, GPIO_PinSource7, GPIO_AF_FSMC );  //d4

  GPIO_Terminal_Init( GPIOE, AF_PP, GPIO_Pin_8 );
  GPIO_PinAFConfig( GPIOE, GPIO_PinSource8, GPIO_AF_FSMC );  //d5

  GPIO_Terminal_Init( GPIOE, AF_PP, GPIO_Pin_9 );
  GPIO_PinAFConfig( GPIOE, GPIO_PinSource9, GPIO_AF_FSMC );  //d6

  GPIO_Terminal_Init( GPIOE, AF_PP, GPIO_Pin_10 );
  GPIO_PinAFConfig( GPIOE, GPIO_PinSource10, GPIO_AF_FSMC );  //d7

  GPIO_Terminal_Init( GPIOE, AF_PP, GPIO_Pin_11 );
  GPIO_PinAFConfig( GPIOE, GPIO_PinSource11, GPIO_AF_FSMC );  //d8

  GPIO_Terminal_Init( GPIOE, AF_PP, GPIO_Pin_12 );
  GPIO_PinAFConfig( GPIOE, GPIO_PinSource12, GPIO_AF_FSMC );  //d9

  GPIO_Terminal_Init( GPIOE, AF_PP, GPIO_Pin_13 );
  GPIO_PinAFConfig( GPIOE, GPIO_PinSource13, GPIO_AF_FSMC );  //d10

  GPIO_Terminal_Init( GPIOE, AF_PP, GPIO_Pin_14 );
  GPIO_PinAFConfig( GPIOE, GPIO_PinSource14, GPIO_AF_FSMC );  //d11

  GPIO_Terminal_Init( GPIOE, AF_PP, GPIO_Pin_15 );
  GPIO_PinAFConfig( GPIOE, GPIO_PinSource15, GPIO_AF_FSMC );  //d12

  GPIO_Terminal_Init( GPIOD, AF_PP, GPIO_Pin_8 );
  GPIO_PinAFConfig( GPIOD, GPIO_PinSource8, GPIO_AF_FSMC );  //d13

  GPIO_Terminal_Init( GPIOD, AF_PP, GPIO_Pin_9 );
  GPIO_PinAFConfig( GPIOD, GPIO_PinSource9, GPIO_AF_FSMC );  //d14

  GPIO_Terminal_Init( GPIOD, AF_PP, GPIO_Pin_10 );
  GPIO_PinAFConfig( GPIOD, GPIO_PinSource10, GPIO_AF_FSMC );  //d15

  GPIO_Terminal_Init( GPIOD, AF_PP, GPIO_Pin_4 );
  GPIO_PinAFConfig( GPIOD, GPIO_PinSource4, GPIO_AF_FSMC );  //rd

  GPIO_Terminal_Init( GPIOD, AF_PP, GPIO_Pin_5 );
  GPIO_PinAFConfig( GPIOD, GPIO_PinSource5, GPIO_AF_FSMC );  //wr

  GPIO_Terminal_Init( GPIOD, AF_PP, GPIO_Pin_7 );
  GPIO_PinAFConfig( GPIOD, GPIO_PinSource7, GPIO_AF_FSMC );  //dpram cs

  GPIO_Terminal_Init( GPIOG, AF_PP, GPIO_Pin_9 );
  GPIO_PinAFConfig( GPIOG, GPIO_PinSource9, GPIO_AF_FSMC );  //adc1 cs

  GPIO_Terminal_Init( GPIOG, AF_PP, GPIO_Pin_10 );
  GPIO_PinAFConfig( GPIOG, GPIO_PinSource10, GPIO_AF_FSMC );  //adc2 cs

  GPIO_Terminal_Init( GPIOE, AF_PP, GPIO_Pin_0 );
  GPIO_PinAFConfig( GPIOE, GPIO_PinSource0, GPIO_AF_FSMC );  //ble

  GPIO_Terminal_Init( GPIOE, AF_PP, GPIO_Pin_1 );
  GPIO_PinAFConfig( GPIOE, GPIO_PinSource1, GPIO_AF_FSMC );  //bhe
}

/*************************************************************************/
/* �v���Z�b�T�O���o�X��L���ɂ���                                        */
/*************************************************************************/
void ExtBusInit( void )
{
  gpioPortSetting();
  /* FSMC clock enable */
  RCC_AHB3PeriphResetCmd( RCC_AHB3Periph_FSMC, DISABLE );
  RCC_AHB3PeriphClockCmd( RCC_AHB3Periph_FSMC, ENABLE );

  /*dpram bank1��sram�̈��L����*/
  volatile unsigned long *bcr1 = (volatile unsigned long *)FSMC_Bank1_R_BASE;
  volatile unsigned long *btr1 = (volatile unsigned long *)(FSMC_Bank1_R_BASE + 4);
  volatile unsigned long *bwtr1 = (volatile unsigned long *)(FSMC_Bank1E_R_BASE);

  /*NE1 SRAM�ݒ� 0x60000000*/
  *bcr1 = 0x000030db;
  *bcr1 &= ~(FSMC_BCR1_ASYNCWAIT | FSMC_BCR1_WAITEN | FSMC_BCR1_MTYP | FSMC_BCR1_MUXEN | FSMC_BCR1_EXTMOD | FSMC_BCR1_MWID | FSMC_BCR1_MBKEN);
  *bcr1 |= (FSMC_BCR1_EXTMOD | FSMC_BCR1_MWID_0 | FSMC_BCR1_MBKEN);

  /*�ǂݍ��ݑ��ݒ�*/
  /*idt70v24s55��read�̃T�C�N���^�C����55ns*/
  *btr1 = 0x0fffffff;
  *btr1 &= ~(FSMC_BTR1_ACCMOD | FSMC_BTR1_DATAST | FSMC_BTR1_ADDHLD | FSMC_BTR1_ADDSET | FSMC_BTR1_BUSTURN );
  /*�A�h���X�L������f�[�^�L���܂�35ns*/
  /*cs�L������f�[�^�L���܂�35ns*/
  /*bhe,ble�L������f�[�^�L���܂�15ns*/
  *btr1 |= FSMC_BTR1_ADDSET_2 | FSMC_BTR1_ADDSET_1;  //  chip select pulse width = 90ns
  /*rd�L������f�[�^�L���܂�15ns*/
  *btr1 |= FSMC_BTR1_DATAST_3 | FSMC_BTR1_DATAST_0;  // read pulse width = 54ns
  /*cs��������f�[�^�����܂�15ns*/
  /*rd��������f�[�^�����܂�10ns*/
  /*bhe,ble��������f�[�^�����܂�10ns*/
  /*���Ԓ���*/
  *btr1 |= FSMC_BTR1_BUSTURN_1;  //18ns

  /*�������ݑ��ݒ�*/
  /*idt70v24s55��write�̃T�C�N���^�C����min:55ns -> 112ns */
  *bwtr1 = 0x0fffffff;
  *bwtr1 &= ~(FSMC_BWTR1_ACCMOD | FSMC_BWTR1_DATAST | FSMC_BWTR1_ADDSET | FSMC_BTR1_BUSTURN );
  /*�A�h���X�Z�b�g�A�b�v0ns*/
  /*cs��95ns*/
  *bwtr1 |= FSMC_BWTR1_ADDSET_2 | FSMC_BWTR1_ADDSET_1;
  /*wr�� min:40ns -> 55ns*/
  /*�f�[�^�Z�b�g�A�b�v min:30ns*/
  *bwtr1 |= FSMC_BWTR1_DATAST_3 | FSMC_BWTR1_DATAST_0;
  /*���Ԓ���*/
  *bwtr1 |= FSMC_BTR1_BUSTURN_1;  //12ns -> 18ns


  /*adc1 bank1��sram�̈��L����*/
  volatile unsigned long *bcr2 = (volatile unsigned long *)(FSMC_Bank1_R_BASE + (8 * 1));
  volatile unsigned long *btr2 = (volatile unsigned long *)(FSMC_Bank1_R_BASE + 4 + (8 * 1));
  volatile unsigned long *bwtr2 = (volatile unsigned long *)(FSMC_Bank1E_R_BASE + (8 * 1));

  /*NE2 SRAM�ݒ� 0x64000000*/
  *bcr2 = 0x000030db;
  *bcr2 &= ~(FSMC_BCR2_ASYNCWAIT | FSMC_BCR2_WAITEN | FSMC_BCR2_MTYP | FSMC_BCR2_MUXEN | FSMC_BCR2_EXTMOD | FSMC_BCR2_MWID | FSMC_BCR2_MBKEN);
  *bcr2 |= (FSMC_BCR2_EXTMOD | FSMC_BCR2_MWID_0 | FSMC_BCR2_MBKEN);

  /*�ǂݍ��ݑ��ݒ�*/
  /*max1316ecm��read�̃T�C�N���^�C����min:60ns -> 100ns??*/
  *btr2 = 0x0fffffff;
  *btr2 &= ~(FSMC_BTR2_ACCMOD | FSMC_BTR2_DATAST | FSMC_BTR2_ADDHLD | FSMC_BTR2_ADDSET | FSMC_BTR2_BUSTURN );
  /*cs�̕���min:30ns -> 77ns*/
  /*rd�̕���min:30ns -> 72ns*/
  /*rd����̃f�[�^�Z�b�g�A�b�v��max:30ns*/
  /*rd����̃f�[�^�z�[���h��max:30ns*/
  *btr2 |= FSMC_BTR2_DATAST_3 | FSMC_BTR2_DATAST_2; //72ns
  /*�A�h���X�Z�b�g�A�b�v�͎�����K�薳��*/
  *btr2 |= FSMC_BTR2_ADDSET_0;
  /*���Ԓ���*/
  *btr2 |= FSMC_BTR2_BUSTURN_2;  //??ns

  /*�������ݑ��ݒ�*/
  /*max1316ecm��write�̃T�C�N���^�C����??ns*/
  *bwtr2 = 0x0fffffff;
  *bwtr2 &= ~(FSMC_BWTR2_ACCMOD | FSMC_BWTR2_DATAST | FSMC_BWTR2_ADDSET | FSMC_BTR2_BUSTURN );
  /*cs�̕��� min:30ns -> 71ns*/
  /*wr�̕��� min:30ns -> 60ns*/
  /*wr����̃f�[�^�Z�b�g�A�b�v�� min:10ns*/
  /*wr����̃f�[�^�z�[���h�� min:10ns*/
  *bwtr2 |= FSMC_BWTR2_DATAST_3 | FSMC_BWTR2_DATAST_1;  //54ns
  /*�A�h���X�Z�b�g�A�b�v�͎�����K�薳��*/
  *bwtr2 |= FSMC_BWTR2_ADDSET_0;
  /*���Ԓ���*/
  *bwtr2 |= FSMC_BTR2_BUSTURN_2;  //??ns


  /*adc2 bank2��sram�̈��L����*/
  volatile unsigned long *bcr3 = (volatile unsigned long *)(FSMC_Bank1_R_BASE + (8 * 2));
  volatile unsigned long *btr3 = (volatile unsigned long *)(FSMC_Bank1_R_BASE + 4 + (8 * 2));
  volatile unsigned long *bwtr3 = (volatile unsigned long *)(FSMC_Bank1E_R_BASE + (8 * 2));

  /*NE3 SRAM�ݒ� 0x68000000*/
  *bcr3 = 0x000030db;
  *bcr3 &= ~(FSMC_BCR3_ASYNCWAIT | FSMC_BCR3_WAITEN | FSMC_BCR3_MTYP | FSMC_BCR3_MUXEN | FSMC_BCR3_EXTMOD | FSMC_BCR3_MWID | FSMC_BCR3_MBKEN);
  *bcr3 |= (FSMC_BCR3_EXTMOD | FSMC_BCR3_MWID_0 | FSMC_BCR3_MBKEN);

  /*�ǂݍ��ݑ��ݒ�*/
  /*max1316ecm��read�̃T�C�N���^�C����min:60ns -> 137ns??*/
  *btr3 = 0x0fffffff;
  *btr3 &= ~(FSMC_BTR3_ACCMOD | FSMC_BTR3_DATAST | FSMC_BTR3_ADDHLD | FSMC_BTR3_ADDSET | FSMC_BTR3_BUSTURN );
  /*cs�̕���min:30ns -> 77ns*/
  /*rd�̕���min:30ns -> 72ns*/
  /*rd����̃f�[�^�Z�b�g�A�b�v��max:30ns*/
  /*rd����̃f�[�^�z�[���h��max:30ns*/
  *btr3 |= FSMC_BTR3_DATAST_3 | FSMC_BTR3_DATAST_2; //72ns
  /*�A�h���X�Z�b�g�A�b�v�͎�����K�薳��*/
  *btr3 |= FSMC_BTR3_ADDSET_0;
  /*���Ԓ���*/
  *btr3 |= FSMC_BTR3_BUSTURN_2;  //??ns

  /*�������ݑ��ݒ�*/
  /*max1316ecm��write�̃T�C�N���^�C����100ns*/
  *bwtr3 = 0x0fffffff;
  *bwtr3 &= ~(FSMC_BWTR3_ACCMOD | FSMC_BWTR3_DATAST | FSMC_BWTR3_ADDSET | FSMC_BTR3_BUSTURN );
  /*cs�̕��� min:30ns -> 71ns*/
  /*wr�̕��� min:30ns -> 60ns*/
  /*wr����̃f�[�^�Z�b�g�A�b�v�� min:10ns*/
  /*wr����̃f�[�^�z�[���h�� min:10ns*/
  *bwtr3 |= FSMC_BWTR3_DATAST_3 | FSMC_BWTR3_DATAST_1;  //54ns
  /*�A�h���X�Z�b�g�A�b�v�͎�����K�薳��*/
  *bwtr3 |= FSMC_BWTR3_ADDSET_0;
  /*���Ԓ���*/
  *bwtr3 |= FSMC_BTR3_BUSTURN_2;  //??ns
}


/*********************************************************************************/
/* end of file                                                                   */
/*                                         designed by hamayan since 2018/09/13  */
/*********************************************************************************/
