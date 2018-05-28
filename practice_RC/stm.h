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

typedef enum
{
  GPIO_Mode_AIN = 0x0,
  GPIO_Mode_IN_FLOATING = 0x04,
  GPIO_Mode_IPD = 0x28,                                      //coocoo8488
  GPIO_Mode_IPU = 0x48,                                      //coocoo8488
  GPIO_Mode_Out_OD = 0x14,
  GPIO_Mode_Out_PP = 0x10,
  GPIO_Mode_AF_OD = 0x1C,
  GPIO_Mode_AF_PP = 0x18,  
}GPIOMode_TypeDef;

typedef struct
{
  uint16_t GPIO_Pin;
  GPIOSpeed_TypeDef GPIO_Speed;
  GPIOMode_TypeDef GPIO_Mode;
}GPIO_InitTypeDef;

typedef enum
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




