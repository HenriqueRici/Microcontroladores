/*###################################################################### 
   Rotina utiliza��o do teclado da placa PicSim board4
   Adaptada para o compilador CCS
   Autor: Alberto Willia Mascarenhas (adaptou para o compilador)
   For e-mail suggestions :  awmascarenhas@gmail.com
######################################################################## */
unsigned char tc_tecla(unsigned int timeout)
{
  unsigned int to=0;
  unsigned char k = 0;  
  while(((to < timeout)||(!timeout))&&(!k)){
     
      
      //-------------------------------------------------------------------------
      //inicio do programa de varredura do teclado matricial
      //--------------------------------------------------------------------------
      //habilita primeira coluna do teclado
      output_low(PIN_D0);output_high(PIN_D1);output_high(PIN_D2);output_high(PIN_D3);
      delay_ms(20);
      if (input(PIN_B4) == 0){while(input(PIN_B4) == 0);k='1';};
      if (input(PIN_B5) == 0){while(input(PIN_B5) == 0);k='4';};
      if (input(PIN_B6) == 0){while(input(PIN_B6) == 0);k='7';};
      if (input(PIN_B7) == 0){while(input(PIN_B7) == 0);k='*';};
      //habilita segunda coluna do teclado
      output_high(PIN_D0);output_low(PIN_D1);output_high(PIN_D2);output_high(PIN_D3);
      delay_ms(20);      
      if (input(PIN_B4) == 0){while(input(PIN_B4) == 0);k='2';};
      if (input(PIN_B5) == 0){while(input(PIN_B5) == 0);k='5';};
      if (input(PIN_B6) == 0){while(input(PIN_B6) == 0);k='8';};
      if (input(PIN_B7) == 0){while(input(PIN_B7) == 0);k='0';};
      
      //habilita terceira coluna do teclado
      output_high(PIN_D0);output_high(PIN_D1);output_low(PIN_D2);output_high(PIN_D3);
      delay_ms(20);      
      if (input(PIN_B4) == 0){while(input(PIN_B4) == 0);k='3';};
      if (input(PIN_B5) == 0){while(input(PIN_B5) == 0);k='6';};
      if (input(PIN_B6) == 0){while(input(PIN_B6) == 0);k='9';};
      if (input(PIN_B7) == 0){while(input(PIN_B7) == 0);k='#';};
 
       //habilita quarta coluna do teclado
      output_high(PIN_D0);output_high(PIN_D1);output_high(PIN_D2);output_low(PIN_D3);
      delay_ms(20);      
      if (input(PIN_B4) == 0){while(input(PIN_B4) == 0);k='A';};
      if (input(PIN_B5) == 0){while(input(PIN_B5) == 0);k='B';};
      if (input(PIN_B6) == 0){while(input(PIN_B6) == 0);k='C';};
      if (input(PIN_B7) == 0){while(input(PIN_B7) == 0);k='D';};
 
      //printf (lcd_escreve,"\f saiu geral %u",k);
      //delay_ms(1000);
      delay_ms(5);
      to+=5;
  }
   if(!k)k=255;
  return k;  
}
