#include "gd32vf103.h"
#include "drivers.h"
#include "dac.h"
#include "pwm.h"

int main(void){
    int speeda=0,speedb=0;
    t5omsi();                               // Initialize timer5 1kHz

    T1powerUpInitPWM(0x0F);
    while (1)
    {
        if(t5expq())
        {
            T1setPWMmotorB(speedb=+10000);
            T1setPWMmotorA(speeda=+10000);
            
        }
        
    }
}