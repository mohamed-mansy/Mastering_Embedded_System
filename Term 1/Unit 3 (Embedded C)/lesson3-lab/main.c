
#include <stdint.h>
typedef volatile uint32_t 	vuint32_t;

#define RCC_BASE		0x40021000
#define PORTA_BASE		0x40010800
#define RCC_APB2ENR		*(volatile uint32_t *) (RCC_BASE + 0x18)
#define GPIOA_CRH		*(volatile uint32_t *) (PORTA_BASE + 0x04) // make the pin output
#define GPIOA_ODR		*(volatile uint32_t *) (PORTA_BASE + 0x0c)

extern void NMI_Handler(){
	
}

extern void Bus_fault(){
	
}


typedef union {
	vuint32_t all_fields;
	struct{
		vuint32_t reserved:13;
		vuint32_t pin13: 1;
	}pin;

}R_ODR_t;

volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)(PORTA_BASE + 0x0c);
volatile unsigned char arr[3] = {0 , 1 ,2};
volatile unsigned char const arr2[3] = {0 , 1 ,2};
volatile unsigned char arr3[3];


int main(void)
{
	RCC_APB2ENR |= 1 << 2;
	GPIOA_CRH &= 0xff0fffff;
	GPIOA_CRH |= 0x00200000;

	while(1){
		int i;
		//GPIOA_ODR |= (1 << 13);// set bit 13
		R_ODR->pin.pin13 = 1;
		for(i = 0; i < 5000; i++);// delay

		//GPIOA_ODR &= ~(1 << 13);// clear bit 13
		R_ODR->pin.pin13 = 0;
		for(i = 0; i < 5000; i++);
	}

}
