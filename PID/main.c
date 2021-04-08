#include <main.h>
#include "mod_lcd.c"

int n = 0;
signed int16   saidaSensor = 0.0, referencia = 0.0, erro = 0.0,
tempAnterior = 0.0, controle = 0.0,
p = 0.0, i = 0.0, d = 0.0;
   
#INT_RTCC
void  RTCC_isr(void){
   if(n <= controle){
      output_high(PIN_C5);
   }else{
      output_low(PIN_C5);
   }   
   n++;
   if(n == 19){
      n = 0;        
   }   
}


void main(){
   setup_adc_ports(AN0_AN1_AN2_AN3_AN4);
   
   lcd_ini();  
   delay_ms(10);
   
   setup_adc(ADC_CLOCK_DIV_16);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1|RTCC_8_bit);      //51,2 us overflow
   setup_timer_2(T2_DIV_BY_16,255,1);      //819 us overflow, 819 us interrupt

   setup_ccp1(CCP_PWM);
   set_pwm1_duty((int16)510);

   enable_interrupts(INT_RTCC);
   enable_interrupts(GLOBAL);

   while(TRUE){    
      //Lendo a referencia de entrada
      set_adc_channel(0);
      delay_us(10);
      //Converte analogico para temperatura de 27 a 70 
      referencia = (read_adc() * 0.0420332355816227)+27;
      
      //Lendo a saida do sensor
      set_adc_channel(2);
      delay_us(10);
      saidaSensor = (read_adc()/2) - 1;
      
      //Disturbio (Coller) 
      set_adc_channel(1);
      delay_us(10);
      set_pwm1_duty(read_adc());
      
      
      //Calculando erro
      erro = referencia - saidaSensor;
      
      //Incrementa no valor de saida para corrigir o erro
      p = erro * 10; //kp = 10
      
      //Soma o erro para se aproximar de zero
      i += erro * 0.1; //ki = 0.1
      
      //Variação da leitura anterior para a nova leitura
      d = (tempAnterior - saidaSensor) * 0.1; //kd = 0.1
      
      //Armazena a ultima saida do sensor
      tempAnterior = saidaSensor;
      
      //soma de controle
      controle = p + i + d;
      
      //Saidas de Log e Serial
      printf(lcd_escreve,"\fRef: %Ld Erro: %Ld\n\rTemp: %Ld",referencia, erro, saidaSensor);
     // printf(lcd_escreve,"\fControle: %Ld\n\rn: %d ",controle, n);
      fprintf(PORT1, "%Ld %Ld %Ld\n",referencia, saidaSensor, erro);
      delay_ms(10);
   }
}
