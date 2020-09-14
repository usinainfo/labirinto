#include <Stepper.h>   // Inclui a biblioteca Stepper

const int stepsPerRevolution = 500;   // Define o número de passos por volta

Stepper MotorPasso(stepsPerRevolution, 4, 6, 5, 7);     // Define os pinos do motor
Stepper MotorPasso2(stepsPerRevolution, 8, 10, 9, 11);  // Define os pinos do motor

int ValorX, ValorY;   // Inicia as variáveis do Joystick

void setup()  {
  Serial.begin(9600);         // Inicia a comunicação do baudrate em 9600
}

void loop()   {
  ValorY = analogRead(A0);    // Inicia os valores do eixo Y na porta A0
  ValorX = analogRead(A1);    // Inicia os valores do eixo X na porta A1

  Serial.println(ValorX);     // Imprime os valores do eixo X
  Serial.println(ValorY);     // Imprime os valores do eixo Y

  if (ValorX > 800)  {        // Se o valor de X for maior que 800 executa:
    MotorPasso.step(65);          // Define o número de passos executados e seu sentido
    MotorPasso.setSpeed(5000);    // Define a velocidade de execução dos passos
    delay(5);
  }

  else if (ValorX < 300)  {   // Se não, o valor será menor que 300 e executa:
    MotorPasso.step(-65);         // Define o número de passos executados e seu sentido
    MotorPasso.setSpeed(5000);    // Define a velocidade de execução dos passos
    delay(5);
  }

  if (ValorY > 800)  {        // Se o valor de X for maior que 800 executa:
    MotorPasso2.step(65);          // Define o número de passos executados e seu sentido
    MotorPasso2.setSpeed(5000);    // Define a velocidade de execução dos passos
    delay(5);
  }

  else if (ValorY < 300)  {   // Se não, o valor será menor que 300 e executa:
    MotorPasso2.step(-65);          // Define o número de passos executados e seu sentido
    MotorPasso2.setSpeed(5000);     // Define a velocidade de execução dos passos
    delay(5);
  }
}
