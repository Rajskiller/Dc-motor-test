#include "gd32vf103.h"
#include "drivers.h"
#include "dac.h"
#include "pwm.h"

int main(void){
    rcu_periph_clock_enable(RCU_GPIOA);
    gpio_init(GPIOA, GPIO_MODE_IN_FLOATING,GPIO_OSPEED_50MHZ,GPIO_PIN_5);
    gpio_init(GPIOA, GPIO_MODE_IN_FLOATING,GPIO_OSPEED_50MHZ,GPIO_PIN_6);
    uint32_t btn, sen;
    int speeda=0,speedb=0;
    t5omsi();                               

    T1powerUpInitPWM(0x0F);
    while (1)
    {
        btn= gpio_input_bit_get(GPIOA, GPIO_PIN_5);
        sen= gpio_input_bit_get(GPIOA, GPIO_PIN_6);
        if(t5expq())
        {
            speedb=50;
            speeda=50;
            T1setPWMmotorB_forwards(speedb);
            T1setPWMmotorA_forwards(speeda);
            if (btn == 1)
            {
                int time=0;
                while(time!=10){
                    T1setPWMmotorA_backwards(speeda);
                    T1setPWMmotorB_backwards(speedb);
                    time++;
                }
               
                
            }
            
        }
        
    }
}