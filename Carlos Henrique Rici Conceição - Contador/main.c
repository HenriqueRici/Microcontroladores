#include <main.h>

void main()
{
  int8 A[]={0b11101110,0b00101000,0b11001101,
                   0b01101101,0b00101011,0b01100111,
                   0b11100111,0b00101100,0b11101111,
                   0b00101111};
   int8 B[]={0b11111110,0b00111000,0b11011101,
                  0b01111101,0b00111011,0b01110111,
                   0b11110111,0b00111100,0b11111111,
                   0b00111111};   
                   
   while(TRUE){
   
      for(int i = 0; i < 10; i++){
         for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
               output_high(PIN_B4);
               output_b(A[i]);
               delay_ms(50);
               output_low(PIN_B4);
               output_b(B[j]);
               delay_ms(50);
            }
         }
      }   
   
   }
}
