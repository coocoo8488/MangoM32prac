#ifndef __STM_H                                              //__STM_H가 정의 되어있지 않다면
#define __STM_H                                              //__STM_H를 이렇게 정의하라

/*include*/

#include <stdint.h>                                          //플랫폼간 이식성을 위해 정의된 자료형의 크기를 정해놓은 헤더 
#include <stdio.h>                                           //표준 입출력 헤더
#include "hw_config.h"                                       //hw_config와 서로 인클루드 해준다. 소스와 달리 헤더는 필요한 부분만 골라와서 컴파일

typedef enum
{
  GPIO_Speed_10MHz =1,
  GPIO_Speed_2MHz =,
  GPIO_Speed_50MHz
}GPIOSpeed_TypeDef;

typedef enum                                                 //GPIO 사용을 위한 레지스터 설정 부분
{
  GPIO_Mode_AIN = 0x0,                                       //mode 설정 레지스터에서 0x0=00이므로 최하위 2bit 00은 아날로그 인풋 모드
  GPIO_Mode_IN_FLOATING = 0x04,                              //cnfy 레지스터에서 0x04 = 0000 (01) (00) 이므로 2번bit on -> floating input 
  GPIO_Mode_IPD = 0x28,                                      //0x28=0010 1000 이므로 (풀다운)
  GPIO_Mode_IPU = 0x48,                                      //0x48=0100 1000 이므로 (풀업)
  GPIO_Mode_Out_OD = 0x14,                                   //0x14=0001 0100 이므로 output-open drain
  GPIO_Mode_Out_PP = 0x10,                                   //0x10=0001 0000 이므로 output-push pull
  GPIO_Mode_AF_OD = 0x1C,                                    //0x1C=0001 1100 이므로 output-alternate function open-drain
}GPIOMode_TypeDef;

typedef struct
{
  uint16_t GPIO_Pin;                                         //여러 변수, 함수를 동시에 정의
  GPIOSpeed_TypeDef GPIO_Speed;
  GPIOMode_TypeDef GPIO_Mode;
}GPIO_InitTypeDef;

typedef enum                                                 //단순 상수를 동시에 정의
{
  Bit_RESET = 0,
  Bit_SET
}BitAction;

typedef enum
{
  RESET = 0,
  SET = !RESET
}FlagStatus;

typedef enum
{
  DISABLE = 0,
  ENABLE = !DISABLE
}FunctionalState;

typedef struct
{
  uint32_t USART_BaudRate;
  uint16_t USART_WordLength;
  uint16_t USART_StopBits;
  uint16_t USART_Parity;
  uint16_t USART_Mode;
  uint16_t HardwareFlowControl;
}USART_InitTypeDef;

#define GPIO_Pin_0            ((uint16_t)0x0001)           //Pin 0 selected
#define GPIO_Pin_1            ((uint16_t)0x0002)           //Pin 1 selected
#define GPIO_Pin_2            ((uint16_t)0x0004)           //Pin 2 selected
#define GPIO_Pin_3            ((uint16_t)0x0008)           //Pin 3 selected
#define GPIO_Pin_4            ((uint16_t)0x0010)           //Pin 4 selected
#define GPIO_Pin_5            ((uint16_t)0x0020)           //Pin 5 selected
#define GPIO_Pin_6            ((uint16_t)0x0040)           //Pin 6 selected
#define GPIO_Pin_7            ((uint16_t)0x0080)           //Pin 7 selected
#define GPIO_Pin_8            ((uint16_t)0x0100)           //Pin 8 selected
#define GPIO_Pin_9            ((uint16_t)0x0200)           //Pin 9 selected
#define GPIO_Pin_10           ((uint16_t)0x0400)           //Pin 10 selected
#define GPIO_Pin_11           ((uint16_t)0x0800)           //Pin 11 selected
#define GPIO_Pin_12           ((uint16_t)0x1000)           //Pin 12 selected
#define GPIO_Pin_13           ((uint16_t)0x2000)           //Pin 13 selected
#define GPIO_Pin_14           ((uint16_t)0x4000)           //Pin 14 selected
#define GPIO_Pin_15           ((uint16_t)0x8000)           //Pin 15 selected
#define GPIO_Pin_All          ((uint16_t)0xFFFF)           //Pin all selected

#define RCC_APB2Periph_AFIO            ((uint32_t)0x00000001)
#define RCC_APB2Periph_GPIOA           ((uint32_t)0x00000004)
#define RCC_APB2Periph_GPIOB           ((uint32_t)0x00000008)
#define RCC_APB2Periph_GPIOC           ((uint32_t)0x00000010)
#define RCC_APB2Periph_GPIOD           ((uint32_t)0x00000020)
#define RCC_APB2Periph_GPIOE           ((uint32_t)0x00000040)
#define RCC_APB2Periph_GPIOF           ((uint32_t)0x00000080)
#define RCC_APB2Periph_GPIOG           ((uint32_t)0x00000100)
#define RCC_APB2Periph_ADC1            ((uint32_t)0x00000200)
#define RCC_APB2Periph_ADC2            ((uint32_t)0x00000400)
#define RCC_APB2Periph_TIM1            ((uint32_t)0x00000800)
#define RCC_APB2Periph_SPI1            ((uint32_t)0x00001000)
#define RCC_APB2Periph_TIM8            ((uint32_t)0x00002000)
#define RCC_APB2Periph_USART1          ((uint32_t)0x00004000)
#define RCC_APB2Periph_ADC3            ((uint32_t)0x00008000)

#define     __IO         volatile                    

typedef struct
{
  __IO uint32_t CR;
  __IO uint32_t CFGR;
  __IO uint32_t CIR;
  __IO uint32_t APB2RSTR;
  __IO uint32_t APB1RSTR;
  __IO uint32_t AHBENR;
  __IO uint32_t APB2ENR;
  __IO uint32_t APB1ENR;
  __IO uint32_t BDCR;
  __IO uint32_t CSR;
  
#ifdef STM32F10X_CL
  __IO uint32_t AHBRSTR;
  __IO uint32_t CFGR2;
#endif //stm32f10x_cl
}RCC_TypeDef;

typedef struct
{
  __IO uint32_t CRL;
  __IO uint32_t CRH;
  __IO uint32_t IDR;
  __IO uint32_t ODR;
  __IO uint32_t BSRR;
  __IO uint32_t BRR;
  __IO uint32_t LCKR;
}GPIO_TypeDef;

typedef struct
{
  __IO uint16_t SR;
  uint16_t  RESERVED0;
  __IO uint16_t DR;
  uint16_t  RESERVED1;
  __IO uint16_t BRR;
  uint16_t  RESERVED2;
  __IO uint16_t CR1;
  uint16_t  RESERVED3;
  __IO uint16_t CR2;
  uint16_t  RESERVED4;
  __IO uint16_t CR3;
  uint16_t  RESERVED5;
  __IO uint16_t GTPR;
  uint16_t  RESERVED6;
}USART_TypeDef;

typedef struct
{
  __IO uint32_t ACR;
  __IO uint32_t KEYR;
  __IO uint32_t OPTKEYR;
  __IO uint32_t SR;
  __IO uint32_t CR;
  __IO uint32_t AR;
  __IO uint32_t RESERVED;
  __IO uint32_t OBR;
  __IO uint32_t WRPR;
}FLASH_TypeDef;

/*usart_sr의 txe,rxne에 값이 들어 있는지 확인하기 위한 플래그 비트*/
#define USART_FLAG_TXE            ((uint16_t)0x0080)
#define USART_FLAG_RXNE           ((uint16_t)0x0020)

#define PERIPH_BASE               ((uint32_t)0x40000000)   /* SRAM에 사상된 페리페럴 시작번지 주소 */

/* 페리페럴 메모리 맵 사상 -> 바로위의 페리페럴 기본 주소를 바탕으로 한다 */
#define APB1PERIPH_BASE            PERIPH_BASE             //APB1 주소와 페리페럴 시작번지 주소가 같다 , 1번 APB가 바로 페리페럴시작점
#define APB2PERIPH_BASE           (PERIPH_BASE + 10000)    //APB2 주소는 1번 페리페럴의 마지막주소 바로다음, 0x10000(65536) 이후이다
#define AHBPERIPH_BASE            (PERIPH_BASE + 20000)    //왜 더 윗번지에 사상되었는지 공부필요

#define GPIOA_BASE                (APB2PERIPH_BASE + 0x0800)   //위에서 정의한 GPIOA의 시작주소 (0800=0000 1000 0000 0000)
#define GPIOB_BASE                (APB2PERIPH_BASE + 0x0C00)   //0X0C00=0000 1100 0000 0000 
#define GPIOC_BASE                (APB2PERIPH_BASE + 0x1000)   
#define GPIOD_BASE                (APB2PERIPH_BASE + 0x1400)
#define GPIOE_BASE                (APB2PERIPH_BASE + 0x1800)
#define GPIOF_BASE                (APB2PERIPH_BASE + 0x1C00)
#define GPIOG_BASE                (APB2PERIPH_BASE + 0x2000)
#define USART1_BASE               (APB2PERIPH_BASE + 0x3800)

/*RCC 메모리 사상 */
#define RCC_BASE                  (AHBPERIPH_BASE + 0x1000)
#define FLASH_R_BASE              (AHBPERIPH_BASE + 0x2000)      //플래쉬 레지스터 베이스 주소

#define RCC                       ((RCC_TypeDef *) RCC_BASE)
#define FLASH                     ((FLASH_TypeDef *) FLASH_R_BASE)

#define GPIOA                     ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB                     ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC                     ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD                     ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE                     ((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOF                     ((GPIO_TypeDef *) GPIOF_BASE)
#define GPIOG                     ((GPIO_TypeDef *) GPIOG_BASE)

#define USART1                    ((USART_TypeDef *) USART1_BASE)

#define USART_WordLength_8b       ((uint16_t)0x0000)             //USART로 보낼 데이터 크기 정의 
#define USART_WordLength_9b       ((uint16_t)0x1000)

/*USART 전송 방식중 스톱비트를 몇으로 할것이냐를 설정*/
#define USART_StopBits_1          ((uint16_t)0x0000)
#define USART_StopBits_0_5        ((uint16_t)0x1000)
#define USART_StopBits_2          ((uint16_t)0x2000)
#define USART_StopBits_1_5        ((uint16_t)0x3000)

/*패리티 설정시 사용값*/
#define USART_Parity_No           ((uint16_t)0x0000)
#define USART_Parity_Even         ((uint16_t)0x0400)
#define USART_Parity_Odd          ((uint16_t)0x0600)

/*Hw 플로우를 컨트롤할수 있다 보내기만 가능, 받기만 가능 등..*/
#define USART_HardwareFlowControl_None            ((uint16_t)0x0000)       //특별히 정의할 일 없을시 None으로 기본설정
#define USART_HardwareFlowControl_RTS             ((uint16_t)0x0100)
#define USART_HardwareFlowControl_CTS             ((uint16_t)0x0200)
#define USART_HardwareFlowControl_RTS_CTS         ((uint16_t)0x0300)

/*RxTx 모드 설정을 위한 값*/
#define USART_Mode_Rx                             ((uint16_t)0x0004)
#define USART_Mode_Tx                             ((uint16_t)0x0008)

#define HSI_Value                                 ((uint32_t)8000000)  //AHB는 HSI 클럭값 8000000을 사용

#define CR1_UE_Set                                ((uint16_t)0x2000)   //USART Enable 의 마스크

#define CR1_CLEAR_Mask                            ((uint16_t)0xE9F3)   //0xE9F3 = 1110 1001 1111 0011
#define CR2_STOP_CLEAR_Mask                       ((uint16_t)0xCFFF)   //0xCFFF = 1100 1111 1111 1111
#define CR3_CLEAR_Mask                            ((uint16_t)0xFCFF)   //0xFCFF = 1111 1100 1111 1111

#define RCC_CR_HSEON                              ((uint32_t)0x00010000)   //외부 고속 클럭 en
#define RCC_CR_HSERDY                             ((uint32_t)0x00020000)   //ready

#define HSEStartUp_Timeout                        ((uint16_t)0x0500)       
#define FLASH_ACR_PRFTBE                          ((uint8_t)0x10)
#define FLASH_ACR_LATENCY                         ((uint8_t)0x03)
#define FLASH_ACR_LATENCY_2                       ((uint8_t)0x02)

#define RCC_CFGR_HPRE_DIV1                        ((uint32_t)0x00000000) //시스템 클럭 분배없이 전량
#define RCC_CFGR_PPRE2_DIV1                       ((uint32_t)0x00000000) //HCLK NOT DIVIDED
#define RCC_CFGR_PPRE1_DIV2                       ((uint32_t)0x00000400) //HCLK DIVIDED BY 2

/* PLL 설정부, 추가 학습예정*/
#define RCC_CFGR_PLLSRC                           ((uint32_t)0x00010000)  //PLL 클럭소스 
#define RCC_CFGR_PLLXTPRE                         ((uint32_t)0x00020000)  //
#define RCC_CFGR_PLLMUL                           ((uint32_t)0x003C0000)  //

#define RCC_CFGR_PLLSRC_HSE                       ((uint32_t)0x00010000)  //
#define RCC_CFGR_PLLMULL6                         ((uint32_t)0x00100000)  //

#define RCC_CR_PLLON                              ((uint32_t)0x01000000)  //
#define RCC_CR_PLLRDY                             ((uint32_t)0x02000000)  //

#define RCC_CFGR_SW                               ((uint32_t)0x00000003)  //
#define RCC_CFGR_SW_PLL                           ((uint32_t)0x00000002)  //
#define RCC_CFGR_SWS                              ((uint32_t)0x0000000c)  //

uint8_t GPIO_ReadInputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void USART_SendData(USART_TypeDef* USARTx, uint16_t Data);
uint16_t USART_ReceiveData(USART_TypeDef* USARTx);
FlagStatus USART_GetFlagStatus(USART_TypeDef* USARTx, uint16_t USART_FLAG);
void USART_Init(USART_TypeDef* USARTx, USART_InitTypeDef* USART_InitStruct);
void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct);

#endif  /* __STM_H */








