#include <main.h>
#include "mod_lcd.c"


int status = 0, valorTemp = 27;
float temp = 0;

int16 duty(int valorTemp, float temp){
   int16 valorDuty = 0;

   if((valorTemp - temp) > 10){
      valorDuty = 1024;
   }else if((valorTemp - temp) <= 10  && (valorTemp - temp) > 5){
      valorDuty = 750;
   }else if((valorTemp - temp) <= 5  && (valorTemp - temp) > 2){ 
      valorDuty = 500;
   }else if((valorTemp - temp) <= 2 && (valorTemp - temp) > 1) {
      valorDuty = 250;
   }else if((valorTemp - temp) <= 1){
       valorDuty = 100;
   }
      
   
   
   return valorDuty;
}

void main()
{
   setup_adc_ports(AN0);
   setup_adc(ADC_CLOCK_DIV_2);
   setup_timer_2(T2_DIV_BY_16,255,1);      //819 us overflow, 819 us interrupt

   lcd_ini();
   delay_ms(50);
   
   setup_ccp1(CCP_PWM);
   set_pwm1_duty((int16)0);

   while(TRUE)
   {
      if(!input(PIN_B3)){
         if(status){
            status = 0;
         }else{
            status = 1;
         }
      }
      
      if(!input(PIN_B4)){
         valorTemp++;
      }
      if(!input(PIN_B5)){
         valorTemp--;
      }
      
      temp = read_adc() * 1.9642857142857142857142857142857; //27,5 % 14
      
      
      if(status){
         printf(lcd_escreve, "Status: ON \r\n");
         set_pwm1_duty(duty(valorTemp, temp));
      }else{
         printf(lcd_escreve, "Status: OFF \r\n");
         set_pwm1_duty((int16)0);
      }
      printf(lcd_escreve, "T:%f |R:%d", temp, valorTemp);
      delay_ms(100);
      printf(lcd_escreve, "\f");
      
   }

}
