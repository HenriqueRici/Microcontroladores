#include <main.h>


unsigned int8 posicao[4]={0b0011, 0b0110, 0b1100, 0b1001};
signed int8 passo=0;
int1 dar_passo=0;
signed int8 sent=-1;
unsigned int8 referencia,contador=0;

#INT_RTCC

void  RTCC_isr(void) 
{
   if (++contador >= 50)
   {
      dar_passo=1;
      contador =0;
   }
   
   if (input_state(pin_b0) == 1)
      sent *= (-1);
   
   if (dar_passo == 1)
   {
      passo = passo + sent;
      if (passo > 3) passo = 0;
      if (passo < 0) passo = 3;
      OUTPUT_D (posicao[passo]);
      dar_passo = 0;
   }
}

void main()
{
   setup_adc_ports (AN0) ;
   setup_adc (ADC_CLOCK_DIV_2) ;
   setup_timer_0 (RTCC_INTERNAL|RTCC_DIV_1|RTCC_8_bit); //51, 2 us overflow
   setup_timer_2 (T2_DIV_BY_16, 255, 1); //819 us overflow, 819 us interrupt
   setup_ccp1 (CCP_PWM) ;
   set_pwm1_duty ( (int16) 510) ;
   enable_interrupts (INT_RTCC) ;
   enable_interrupts (GLOBAL) ;
   set_adc_channel (0) ;
   delay_us (50) ;
   referencia = 1;

   while (TRUE)
   {
      set_adc_channel (0) ;
      delay_us (50) ;     
      referencia = read_adc ();     
      set_pwm1_duty ( (int16) (referencia * 1021 / 255));
   }
}

