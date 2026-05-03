

#include <stdint.h>

#define RCC_BASE 0x40021000UL
#define GPIOA_BASE 0x50000000UL


#define GPIOA_MODER (*(volatile uint32_t*)(GPIOA_BASE + 0x00))
#define RCC_IOPENR (*(volatile uint32_t*)(RCC_BASE + 0x34))
#define GPIOA_ODR (*(volatile uint32_t*)(GPIOA_BASE + 0x14))
#define GPIOA_PUPDR (*(volatile uint32_t*)(GPIOA_BASE + 0x0C))
#define GPIOA_IDR (*(volatile uint32_t*)(GPIOA_BASE + 0x10))

int main (void)
{
  RCC_IOPENR &=~(1<<0);
  RCC_IOPENR |=(1<<0);

  GPIOA_MODER &=~(3<<(5*2));
  GPIOA_MODER |=(1<<(5*2));

  GPIOA_MODER &=~(3<<(4*2));

  GPIOA_PUPDR &=~(3<<(4*2));
  GPIOA_PUPDR |=(2<<(4*2));


  while(1)
  {
    if(GPIOA_IDR & (1<<4))
    {
      GPIOA_ODR ^=(1<<5);
    }

  }
}


