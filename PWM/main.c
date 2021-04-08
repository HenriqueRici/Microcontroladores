#include <main.h>
unsigned int pot1, pot2, pot3;
int16 value1, value2, value3;
int cont =0;
#INT_RTCC
void  RTCC_isr(void) 
{
   set_adc_channel(0);
   delay_us(10);
   pot1 = read_adc();
   value1 = pot1 * 4;//1020/255
   
   set_adc_channel(1);
   delay_us(10);
   pot2 = read_adc();
   value2 = pot2 * 4;//1020/255
   
   
   set_adc_channel(3);
   delay_us(10);
   pot3 = read_adc(); 
   value3 = pot3 * 0.0765931372549;   //  19,53125/255

   if(cont >= 19){
      cont = 0;
   }
   
   if(cont > value3){
      output_low(PIN_B1);
   }else{
      output_high(PIN_B1);
   }
   
   cont++; 

}

void main()
{
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1|RTCC_8_bit); //51,2 us overflow     1000us /  51,2us = 19,53125
   setup_adc_ports(AN0_AN1_AN3);
   setup_adc(ADC_CLOCK_DIV_2);
   setup_timer_2(T2_DIV_BY_16,255,1);      //819 us overflow, 819 us interrupt

   setup_ccp1(CCP_PWM);
   setup_ccp2(CCP_PWM);
   set_pwm1_duty((int16)510);
   set_pwm2_duty((int16)510);

   enable_interrupts(INT_RTCC);
   enable_interrupts(GLOBAL);

   while(TRUE)
   {
      //TODO: User Code
      set_pwm1_duty(value1);
      set_pwm2_duty(value2);
   }

}
