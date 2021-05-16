#include "gd32vf103.h"
#include "drivers.h"
#include "dac.h"
#include "pwm.h"

int main(void){
    int speeda=0,speedb=0;
    //uint32_t button, sensor; 
    t5omsi();                               // Initialize timer5 1kHz

    T1powerUpInitPWM(0x0F);
    while (1)
    {
        if(t5expq())
        {
            T1setPWMmotorB(speedb=-1000);
            T1setPWMmotorA(speeda=+1000);
            /*button = gpio_input_bit_get(GPIOA, GPIO_PIN_5);
            sensor = gpio_input_bit_get(GPIOA, GPIO_PIN_6);
            if (button ==0)
            {
                 T1setPWMmotorA(speeda=10);
                 T1setPWMmotorB(speedb=10);

            }
            else{
                speeda=0;
                speedb=0;
                T1setPWMmotorA(speeda);
                T1setPWMmotorB(speedb);

            }
            if (sensor==0)
            {
                T1setPWMmotorB(speedb=10);
            }*/
            
            
        }
        
    }
}