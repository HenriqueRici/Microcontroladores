import processing.serial.*;
Serial port;
String buff = "";
int NEWLINE = 10;
int[] entrada = new int[100];
int[] temperatura = new int[100];
int[] erro = new int[100];
PFont fonte;
PFont FONTE;
void setup()
{
  fonte = createFont("Arial", 12, true);
  FONTE = createFont("Arial", 24, true);
  size(1000, 600); 
  port = new Serial(this, Serial.list()[0], 9600);// atenção para esta
    for (int i = 0; i<= 99; i++) {
      entrada[i] = 0;
      temperatura[i] = 0; 
      erro[i] = 0;
    }
  
}
void draw()
{
  while (port.available() > 0) {
    serialEvent(port.read());
  }
}

void serialEvent(int serial)
{
  if (serial != NEWLINE) {
    // Armazene todos os caracteres na linha
    buff += char(serial);
  } else {
    //println(buff);
    
    String recebido[] = split(buff, " ");
   
    if(recebido.length>=2){    
      entrada[99] = Integer.parseInt(recebido[0].trim());
      temperatura[99] = Integer.parseInt(recebido[1]);
      erro[99] = Integer.parseInt(recebido[2]);
    }

    for (int i = 1; i<100; i++) {
      entrada[i-1] = entrada[i];
      temperatura[i-1] = temperatura[i]; 
      erro[i-1] = erro[i];
    }
    
    desenhaMoldura();
    
    for (int i = 0; i < 99; i++) {
      int inicioX = (i*9) + 42;
      int fimX = (i+1)*9 + 42;
      stroke(#000AFC);
      line(inicioX, 256 - (entrada[i]*2.45),fimX , 256 - entrada[i+1]*2.45);
      stroke(#14FC00);
      line(inicioX, 256 - (temperatura[i]*2.45), fimX, 256 - temperatura[i+1]*2.45);
      stroke(#FC0004);
      line(inicioX, 256 - (erro[i]*2), fimX , 256 - erro[i+1]*2);
    }
    buff = "";
  }
}
void desenhaMoldura() {
  background(#454842);
  
  fill(0, 102, 153);
  stroke(175);                       
  line(40, height-65, 40, 0);

  stroke(175);                         
  line(40, height-65, width, height-65);

  textFont(FONTE);       
  fill(255);

  textAlign(RIGHT);
  fill(0);
  text("Controle de Temperatura PID", 650, 40); 

  fill(255);
  textAlign(RIGHT);
  text("°C", 70, 40);

  textAlign(RIGHT);
  text("VERMELHO= erro; VERDE= saida;  AZUL= referencia;", 600, 580);

  textAlign(RIGHT);
  text("t (s)", 950, 580);    


  fill(240);
  textFont(fonte); 

  textAlign(RIGHT);                 
  text("80 -", 40, 60);

  textAlign(RIGHT);                 
  text("70 -", 40, 85);
  
  textAlign(RIGHT);              
  text("60 -", 40, 110);
  
  textAlign(RIGHT);              
  text("50 -", 40, 135);

  textAlign(RIGHT);               
  text("40 -", 40, 160);
  
  textAlign(RIGHT);               
  text("30 -", 40, 185);

  textAlign(RIGHT);                
  text("20 -", 40, 210);
  
  textAlign(RIGHT);                
  text("10 -", 40, 235);

  textAlign(RIGHT);                
  text("0 -", 40, 260);
  
  textAlign(RIGHT);                
  text("-10 -", 40, 285);
  
  textAlign(RIGHT);                
  text("-20 -", 40, 310);
  
  textAlign(RIGHT);                
  text("-30 -", 40, 335);
  
   textAlign(RIGHT);                
   text("-40 -", 40, 360);
   
   textAlign(RIGHT);                
   text("-50 -", 40, 385);
   
   textAlign(RIGHT);                
   text("-60 -", 40, 410);
   
   textAlign(RIGHT);                
   text("-70 -", 40, 435);
   
   textAlign(RIGHT);                
   text("-80 -", 40, 460);
}
