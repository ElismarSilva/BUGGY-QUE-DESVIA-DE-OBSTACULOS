
/*Projeto buggy desenvolvido por Elismar Silva
  19 de Novembro 2022
   Github(https://github.com/Olamundoio)
*/

//inclusao das blibliotecas>>
#include <SensorUltrasonico.h>  //inclusao da biblioteca
#include <Servo.h>
SensorUltrasonico dist_Cm(10, 11);

#define direcao 2  // pino do servo da direcao
#define motor_E 3  // pino do servo do lado esquerdo
#define motor_D 4  // pino do servo do lado direito
#define farol 5    // pino dos farois
#define buzina 7   // pino da buzina

// criacao de objeto dos servos
Servo motor_Esquerdo;
Servo motor_Direito;
Servo motor_direcao;

void direcao_E();
void direcao_Centro();
void Parado();
void direcao_D();
void Frente();
void Tras();
void tempo(int t);



void setup() {

  motor_direcao.attach(direcao);
  motor_Esquerdo.attach(motor_E);
  motor_Direito.attach(motor_D);
  pinMode(farol, OUTPUT);
  pinMode(buzina, OUTPUT);
  Serial.begin(9600);
  digitalWrite(farol, HIGH);
  direcao_Centro();
}

void loop() {

  mover();
}

//Funções
void Frente() {
  motor_Esquerdo.write(170);  // os motores se movimentam no sentido horario
  motor_Direito.write(0);
}
void Tras() {
  motor_Esquerdo.write(0);  // os mtores se movimentam no sentido anti-horario
  motor_Direito.write(170);
}
void Parado() {
  motor_Esquerdo.write(90);  // os motores param de girar
  motor_Direito.write(90);
}
void direcao_E() {
  motor_direcao.write(120);  // o servo motor gira para esquerda
}
void direcao_Centro() {
  motor_direcao.write(97);  // o servo motor fica centralizado
}
void direcao_D() {
  motor_direcao.write(74);  // o servo motor gira para a direita
}

void tempo(int tmp) {
  delay(tmp * 1000);
}
void mover() {
  double dist = dist_Cm.distanciaCM();

  if (dist <= 20) {
    Parado();
    tempo(2);
    Tras();
    direcao_E();
    tempo(1);
    Parado();
    tempo(1);
    direcao_D();
    tempo(1);

  } else
    direcao_Centro();
  Frente();
}
