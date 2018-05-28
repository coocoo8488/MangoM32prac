#ifndef __HW_CONFIG_H       //__HW_CONFIG_H가 정의 되어 있지 않다면
#define __HW_CONFIG_H       //__HW_CONFIG_H를 이렇게 정의하라

/* include 목록 */

#include <stdint.h>         //표준 헤더 인클루드
#include <stdio.h>
#include "stm.h"            //표준이 아닌 헤더 인클루드

/*defines*/

#define GPIO_LED            GPIOB     //GPIOB는 GPIO_LED 기능으로 정의
#define GPIO_KEY            GPIOA     //GPIOA는 GPIO_KEY 기능으로 정의
#define GPIO_USART          GPIOA     //GPIOA는 USART를 사용하도록 정의

#define GPIO_LED1_PIN       GPIO_Pin_9   //GPIO의 핀 9번은 LED1으로 정의 /*RED*/
#define GPIO_LED2_PIN       GPIO_Pin_5   //YELLOW
#define GPIO_LED3_PIN       GPIO_Pin_8   //BLUE

#define GPIO_KEY1_PIN       GPIO_Pin_0   //LEFT WKUP
#define GPIO_KEY2_PIN       GPIO_Pin_1   //Right USER

#define GPIO_USART_Rx_Pin   GPIO_Pin_10  //GPIOA 포트에서 10번핀은 USART_Rx 핀이다
#define GPIO_USART_Tx_Pin   GPIO_Pin_9   //GPIOA 포트에서 9번핀은 USART_Tx 핀이다

/*main.c 에서 이 헤더를 불러와서 사용될 함수 정의 */
/*해당 함수 구현은 이 헤더에서 불러오는 stm.h에 정의되어 있다 */

void LED_On_Red(void);
void LED_Off_Red(void);
void LED_On_Yellow(void);
void LED_Off_Yellow(void);
void LED_On_Blue(void);
void LED_Off_Blue(void);
void LED_On_All(void);
void LED_Off_Blue(void);

void LED_Test(void);
void KEY_Test(void);
void Seven_Segment_Test(void);

void delay_1_second(void);
void delay_100_milli_second(void);

void RCC_Configuration(void);
void GPIO_Configuration(void);
void USART1_Init(void);
uint8_t USART_GetCharacter(USART_TypeDef * usart_p);

#endif



/*ifndef 정의 끝*/
