#include <stdint.h>

#define RCC_BASE 0x40021000
#define GPIOA_BASE 0x50000000

#define RCC_IOPENR (*(volatile uint32_t*)(RCC_BASE + 0x34))
#define GPIOA_MODER (*(volatile uint32_t*)(GPIOA_BASE + 0x00))
#define GPIOA_ODR (*(volatile uint32_t*)(GPIOA_BASE + 0x14))

void delay(volatile uint32_t time)
{
     while (time)
     {
        time--;
     }
}
int main(void)
{

  RCC_IOPENR |= (1<<0);

  GPIOA_MODER &= ~(3<<(5*2));
  GPIOA_MODER |= (1<<(5*2));


  while(1)
  {
    GPIOA_ODR ^=(1<<5);
    delay(1000000);
  }

}


