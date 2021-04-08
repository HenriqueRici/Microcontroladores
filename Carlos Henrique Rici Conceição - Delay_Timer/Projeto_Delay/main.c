#include <16F877A.h>

#device ADC=8

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=20000000)
void main()
{
   unsigned int valuePot;
   int16 tempoTotal = 1000, tempoOn, tempoOff;
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports(AN0);
   set_adc_channel(0);
   delay_us(10);

   while(TRUE)
   {
      valuePot = read_adc();
      
      tempoOn = valuePot*3.92156862;   //1000/255 = 3.92156862
      
      tempoOff = tempoTotal - tempoOn;
      output_high(PIN_B1);
      delay_us(tempoOn);
      output_low(PIN_B1);
      delay_us(tempoOff); 
   }

}
