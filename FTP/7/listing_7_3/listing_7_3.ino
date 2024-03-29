#include "motor.h"
int diod_pin = 6;
// Функция инициализации, выполняется один раз.
void setup()
{
  // Переменные – номера контактов (пинов) Arduino.
  // Для левых и правых моторов машинки.
  setup_motor_system(2, 3, 5, 4);
  //переводим пин светодиода в режим вывода.
  pinMode(diod_pin, OUTPUT);
  //гасим светодиод.
  digitalWrite(diod_pin, 0);
  // Двигатели остановлены.
  _stop();
}
//===============================================
// Основная программа.
void loop()
{
  // Пример движения робота задан жестко в программе
  // и повторяется в цикле.
  forward(); // едет вперед 1 секунду.
  delay(1000);
  forward_left(); // поворачивает налево 0,5 секунд.
  delay(500);
  forward(); // едет вперед 0,5 секунд.
  delay(500);
  forward_right(); // поворачивает направо 0,5 секунд.
  delay(500);
  //Включаем светодиод.
  digitalWrite(diod_pin, 1);
  _stop();
  delay(500);
  //Гасим светодиод.
  digitalWrite(diod_pin, 0);
  backward(); // движется назад 0,8 секунд.
  delay(800);
}

