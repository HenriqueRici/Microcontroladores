#include <semaforo.h>

void main(){
   while(TRUE){ 
      output_high(verde);
      output_high(ped_vermelho);
      
      if(!input(PIN_A1)){
         delay_ms(10000);
         output_low(verde);
         delay_ms(250);
         output_high(amarelo);
         delay_ms(2000);
         output_low(amarelo);
         delay_ms(250);
         output_high(vermelho);
         delay_ms(1000);
         output_low(ped_vermelho);
         delay_ms(250);
         output_high(ped_verde);
         delay_ms(10000);
         
         int cont = 0;
         while(cont < 5){
            output_high(ped_verde);  
            delay_ms(500);
            output_low(ped_verde);
            delay_ms(500);
            cont++;
         }
         
         output_high(ped_vermelho);
         delay_ms(1000);
         output_low(vermelho); 
         delay_ms(250);
      }
   }
}
