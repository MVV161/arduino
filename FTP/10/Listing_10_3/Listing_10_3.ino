// Подключаем библиотеку управления сервомоторами.
#include <Servo.h>
// Создаем сервомотор поворота головы.
Servo neck;
void setup()
{ 
  // Инициализируем сервомотор, управление 14 портом.
  neck.attach(14);
}
void loop()
{
  int i;
  // Создаем цикл для равномерного поворота сервомотора.
  for(i=10; i<=170; i=i+10)
  {
    // Поворачиваем вал на угол i.
    neck.write(i); 
  // приостанавливаем программу.
  delay(100);
  }
  // Возвращаем голову назад.
  for(i=170; i>=10; i=i-10)
  {
    // Поворачиваем вал на угол i.
    neck.write(i); 
  // приостанавливаем программу.
  delay(100);
  }
}

