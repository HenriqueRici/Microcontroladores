//#include <main.h>
#include <16F877A.h>
#device ADC=8

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=20000000)

int cont = 0;
int tempoOn;
unsigned int valuePot;


#INT_RTCC
void  RTCC_isr(void) 
{

   valuePot = read_adc();
                 
   tempoOn = valuePot*0.0765931372549;   //  19,53125/255

   if(cont >= 19){
      cont = 0;
   }
   
   if(cont > tempoOn){
      output_low(PIN_B1);
   }else{
      output_high(PIN_B1);
   }
   
   cont++;
}

void main()
{
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1|RTCC_8_bit);      //51,2 us overflow     1000us /  51,2us = 19,53125

   enable_interrupts(INT_RTCC);
   enable_interrupts(GLOBAL);
   
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports(AN0);
   set_adc_channel(0);
   delay_us(10);
}
