#include <mini1.h>


void main()
{
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports(AN0);
   setup_adc(ADC_CLOCK_DIV_2);
   set_adc_channel(0);
   delay_us(10);
   delay_us(10); 
   unsigned int pot;
   while(TRUE)
   {
      //PIN_B1 = a
      //PIN_B2 = b
      //PIN_B3 = c
      pot = read_adc();
     
      if(pot < 143){                   //N1
         output_low(PIN_B1);
         output_low(PIN_B2);
         output_low(PIN_B3);
         delay_ms(10); 

      }else if(pot >= 143 & pot < 159){  //N2
         output_high(PIN_B1);
         output_low(PIN_B2);
         output_low(PIN_B3);
         delay_ms(10); 

      }else if(pot >= 143 & pot < 159){  //N3
         output_low(PIN_B1);
         output_low(PIN_B2);
         output_high(PIN_B3);
         delay_ms(10); 

      }else if(pot >= 159 & pot < 175){ //N4
         output_high(PIN_B1);
         output_high(PIN_B2);
         output_low(PIN_B3);
         delay_ms(10); 

      }else if(pot >= 175 & pot < 191){ //N5
         output_high(PIN_B1);
         output_low(PIN_B2);
         output_high(PIN_B3);
         delay_ms(10); 

      }else if(pot >= 191 & pot < 207){ //N6
         output_low(PIN_B1);
         output_high(PIN_B2);
         output_low(PIN_B3);
         delay_ms(10); 

      }else if(pot >= 207 & pot < 223){ //N7
         output_low(PIN_B1);
         output_high(PIN_B2);
         output_high(PIN_B3);
         delay_ms(10); 

      }else if(pot >= 223 & pot < 255){ //N8
         output_high(PIN_B1);
         output_high(PIN_B2);
         output_high(PIN_B3);
         delay_ms(10); 

      }
    
   }
     
   }

