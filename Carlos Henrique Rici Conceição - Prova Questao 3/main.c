#include <main.h>
#include "mod_lcd.c"


void main()
{  
   lcd_ini();
   delay_ms(50);
   
   
   while(TRUE)  
   {  
      printf(lcd_escreve, "Carlos Henrique\n");
      printf(lcd_escreve, "    RE  SOL");
             
       //conta milhar
       output_high(PIN_A2); 
       output_d(0b1011011); 
       delay_ms(25);
       output_low(PIN_A2);
                     
       //conta centena
       output_high(PIN_A3); 
       output_d(0b1001111); 
       delay_ms(25);
       output_low(PIN_A3);
                  
       //conta dezena
       output_high(PIN_A4); 
       output_d(0b1100110); 
       delay_ms(25);
       output_low(PIN_A4);
                     
       //conta unidade
       output_high(PIN_A5); 
       output_d(0b1101111); 
       delay_ms(25);
       output_low(PIN_A5);     
      
       printf(lcd_escreve, "\f");      
       
       
   }

}
