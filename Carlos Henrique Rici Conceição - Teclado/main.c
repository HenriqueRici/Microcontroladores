#include <main.h>
#include "mod_lcd.c"
#include "kbd_ext_board2.c"

unsigned char tmp;

#INT_RTCC
void  RTCC_isr(void) 
{
   //-------------------------------------------
       tmp = tc_tecla(1500); // ms
   //-------------------------------------------
      if(tmp!=255){
         printf (lcd_escreve,"\f Boton %c",tmp);
         }
      else{ printf (lcd_escreve,"\f   TECLADO  ");
      }
}

void main()
{
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1|RTCC_8_bit);      //51,2 us overflow
   
   lcd_ini(); 
   delay_ms(10);
 
   printf (lcd_escreve,"\f iniciando..."); 
   delay_ms(1000);

   printf (lcd_escreve,"\f   TECLADO  ");
   delay_ms(2000);

   enable_interrupts(INT_RTCC);
   enable_interrupts(GLOBAL);

}
