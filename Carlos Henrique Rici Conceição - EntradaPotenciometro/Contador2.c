#include <Contador2.h>

void mostrar(int n){
   //vetor de nomeros a serem mandados a porta d
   int8 numero[] = {0b0111111,0b0000110,0b1011011,0b1001111,0b1100110
      0b1101101,0b1111101,0b0000111,0b1111111,0b1101111};
      
  //retorna posições do vetor                   
   int8 unidade = n % 10;
   int8 dezena  = (n % 100)/10;

   //retorna os numeros no display
   for(int i=0;i<10;i++){
         output_high(PIN_A4); //PIN_A4 = display 2
         output_d(numero[dezena]);
         delay_ms(50);
         output_low(PIN_A4); //PIN_A4 = display 2
         
         output_high(PIN_A5); //PIN_A5 = display 1
         output_d(numero[unidade]);
         delay_ms(50);
         output_low(PIN_A5); //PIN_A5 = display 1
   }
}

void main()
{
   int16 value, valor0_99;
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports(AN0);
   set_adc_channel(0);
   delay_us(10);
   
   while(TRUE)
   {
      // faz leitura do potenciometro
      value = read_adc();
      //calcula o valor com a entrada do potenciometro, com o valor entre 0 a 99
      valor0_99 = (99*value)/255;
      //chama a função para mostrar o valor no display
      mostrar(valor0_99);   
   }


}
