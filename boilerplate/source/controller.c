#include "gpio.h"
#include "uart.h"
#include "controller.h"

#define CLK 11
#define LAT 9
#define DAT 10

#define GPIO_BASE 0xFE200000
static unsigned *gpio = (unsigned*)GPIO_BASE; // GPIO base

// GPIO setup macros. 
#define INP_GPIO(g) *(gpio+((g)/10)) &= ~(7<<(((g)%10)*3))
#define OUT_GPIO(g) *(gpio+((g)/10)) |= (1<<(((g)%10)*3))

#define CLO_REG 0xFE003004

#define buttons_size 16

void init_gpio(int pin, int func)
{
    unsigned int *gpio = (unsigned *) GPFSEL0;

    
    int index = pin / 10; // GPFSEL register to be used

    int bit_shift = (pin % 10) * 3; // bit shifting

    gpio[index] = (gpio[index] & ~(0b111 << bit_shift) ) | (func << bit_shift); // setting bits to function

}

void write_gpio(int pin_number, int val)
{
    if (val == 1)
    {
        // If val is 1 -> set bit in set registers
        // you would want to check if the pin >= 32 
            // if this was the case, target_addr = set register 1
        (*GPSET0) = 1 << pin_number;        
    } else {
        (*GPCLR0) = 1 << pin_number;
    }

}

int read_gpio(int pin_number)
{ 
     return ((*GPLEV0) >> pin_number) & 1; 

}

void init_snes_lines() {
    

    INP_GPIO(CLK); // CLK 11 
    OUT_GPIO(CLK);
    INP_GPIO(LAT); // LATCH 9 
    OUT_GPIO(LAT);
    INP_GPIO(DAT); // DATA 10
}

unsigned read_snes() {
   
   // reads snes data from controller

    int buttons[buttons_size];
    int b = 0;
    int i = 0;
    unsigned int snes_output=0;

    write_gpio(CLK,1);
    write_gpio(LAT,1);
    sleep_microseconds(12);
    write_gpio(LAT,0);

    while (i <= 15){
        sleep_microseconds(6);
        write_gpio(CLK,0); // edge falling
        sleep_microseconds(6);
        b = read_gpio(DAT); // bit i is read
        buttons[i] = b;
        write_gpio(CLK,1); // new cycle started 
        i++;
    }
 
    
    for (int j = 0; j < 12; j++){
        snes_output |= buttons[j] << (j);
    } 

    

    return ~snes_output;
}



void sleep_microseconds(int ms)
{
//sleep for microsecond
    unsigned *clo = (unsigned*)CLO_REG;
    unsigned c = *clo + 12; // micro Secs
    while (c > *clo);
}
