#include <16F877A.h>
#device ADC=8

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=20000000)

//T* = 1/2F
//57, 54, 50

unsigned int contador1=0;
unsigned int contador2=0;
unsigned int contador3=0;

#INT_RTCC
void  RTCC_isr(void) 
{
   contador1++; //171
   contador2++; //180
   contador3++; //195
}

void main()
{
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1|RTCC_8_bit);      //51,2 us overflow


   enable_interrupts(INT_RTCC);
   enable_interrupts(GLOBAL);

   while(TRUE)
   {
      
      if(input(PIN_B4)){
         output_high(PIN_B4);
      }else{
         output_low(PIN_B4);
      }
      
      
      
      if (contador1>171) {
         contador1=0;
         output_toggle(pin_B1);
      }
      
      if (contador2>180) {
         contador2=0;
         output_toggle(pin_B2);
      }
      
      if (contador3>195) {
         contador3=0;
         output_toggle(pin_B3);
      }
   }

}
