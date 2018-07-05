//Motor 1 (10, 6, 7, A1)
//Motor 2 (9, 4, 5, A0)
//Motor 3 (3, 1, 2, A2)
//Motor 4 (11, 12, 13, A3)


#define enA 9
#define in1 4
#define in2 5
#define enB 10
#define in3 6
#define in4 7
#define enC 3
#define in5 1
#define in6 2
#define enD 11
#define in7 12
#define in8 13

int motorSpeed_1 = 0;
int motorSpeed_2 = 0;
int motorSpeed_3 = 0;
int motorSpeed_4 = 0;


void setup(){
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enC, OUTPUT);
  pinMode(enD, OUTPUT);
  pinMode(in5, OUTPUT);
  pinMode(in6, OUTPUT);
  pinMode(in7, OUTPUT);
  pinMode(in8, OUTPUT);
}

void loop() {
  int mot_1 = analogRead(A1); // Le joystick no motr 1
  int mot_2 = analogRead(A0); // Le joystick no motor 2

  // motor 2 usado para mover para cima e baixo

  if (mot_2 < 470) {
    // definir motor 2 para baixo
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    // motor 1 movendo para direita 
      if (mot_1 < 470){        
       digitalWrite (in3, LOW);
       digitalWrite (in4, HIGH);
       motorSpeed_1 = map(mot_1,470, 0, 0, 255);
       }
       //motor 1 movendo para esquerda
    else if (mot_1 > 550)  {
      digitalWrite (in3, HIGH);
      digitalWrite (in4, LOW);
      motorSpeed_1 = map(mot_1,550, 1023, 0, 255);}
    else {
      motorSpeed_1 = 0;
    }  
    
    // Converter a leitura em decaimento para ir para tras a partir de 470
    motorSpeed_2 = map(mot_2, 470, 0, 0, 255);
     
  }
  else if (mot_2 > 550) {
   // definir motor 2 para frente
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    //definir motor 1 para direita e esquerda
    if (mot_1 < 470){
       digitalWrite (in3, LOW);
       digitalWrite (in4, HIGH);
       motorSpeed_1 = map(mot_1,470, 0, 0, 255);
       }
    else if (mot_1 > 550)  {
      digitalWrite (in3, HIGH);
      digitalWrite (in4, LOW);
      motorSpeed_1 = map(mot_1,550, 1023, 0, 255);}
    else {
      motorSpeed_1 = 0;
    }  
    // Converter leitura de crescimento para ir para frente a partir de 550
    motorSpeed_2 = map(mot_2, 550, 1023, 0, 255);
    
  }
   // Se joystick ficar no meio o motor nao se move
  else {
    motorSpeed_2 = 0;
    motorSpeed_1 = 0;
   }

      //Prevenir ruidos em velocidades baixas 
      if (motorSpeed_2 < 70) {
        motorSpeed_2 = 0;
      }
      if (motorSpeed_1 < 70) {
        motorSpeed_1 = 0;
      }
      analogWrite(enA, motorSpeed_2); //enviar sinal PWM para motor 2
      analogWrite(enB, motorSpeed_1); //enviar sinal PWM para motor 1

    // Outro Joystick

  int mot_3 = analogRead (A2); //Le joystick no motor 3
  int mot_4 = analogRead (A3); //Le joystick para motor 4
  
  //motor 3 usado para mover para cima e para baixo

  if (mot_3 < 470) {
    // definir motor 3 para baixo
    digitalWrite (in5, HIGH);
    digitalWrite (in6, LOW);
    //definir motor 4 cima ou baixo
    if (mot_4 < 470){
       digitalWrite (in7, LOW);
       digitalWrite (in8, HIGH);
       motorSpeed_4 = map(mot_4,470, 0, 0, 255);
       }
    else if (mot_4 > 550)  {
      digitalWrite (in7, HIGH);
      digitalWrite (in8, LOW);
      motorSpeed_4 = map(mot_4,550, 1023, 0, 255);}
    else {
      motorSpeed_4 = 0;
    }  
    motorSpeed_3 = map(mot_3, 470, 0, 0, 255); } 
  else if (mot_3 > 550) {
    // definir motor 3 para cima
    digitalWrite (in5, LOW);
    digitalWrite (in6, HIGH);
    //definir motor 4 cima ou baixo
    if (mot_4 < 470){
       digitalWrite (in7, LOW);
       digitalWrite (in8, HIGH);
       motorSpeed_4 = map(mot_4,470, 0, 0, 255);
       }
    else if (mot_4 > 550)  {
      digitalWrite (in7, HIGH);
      digitalWrite (in8, LOW);
      motorSpeed_4 = map(mot_4,550, 1023, 0, 255);}
    else {
      motorSpeed_4 = 0;
    }
    motorSpeed_3 = map(mot_3, 550, 1023, 0, 255);  
      }
         
   //se joystick ficar no meio motor nao se move
  else {  
    motorSpeed_3 = 0;
    motorSpeed_4 = 0;        
  }
   //Prevenir ruidos em velocidades baixas 
      if (motorSpeed_3 < 70) {
        motorSpeed_3 = 0;
      }
      if (motorSpeed_4 < 70) {
        motorSpeed_4 = 0;
      }
      analogWrite(enC,motorSpeed_3); //enviar sinal PWM para motor 3
      analogWrite(enD, motorSpeed_4); //enviar sinal PWM para motor 4
  
  }

