
#define GPIO_RED 13
#define GPIO_GREEN 12
#define GPIO_BLUE 11
#define GPIO_POWER 10

void setup()
{
    pinMode(GPIO_POWER, OUTPUT);
    digitalWrite(GPIO_POWER, LOW);
    pinMode(GPIO_RED, OUTPUT);
    digitalWrite(GPIO_RED, LOW);
    pinMode(GPIO_GREEN, OUTPUT);
    digitalWrite(GPIO_GREEN, LOW);
    pinMode(GPIO_BLUE, OUTPUT);
    digitalWrite(GPIO_BLUE, LOW);
}

void ramp(int pin, int start, int stop, int wait)
{
  if (stop > start)
    for (int value=start; value<=stop; value++)
    {
      analogWrite(pin, value);
      delay(wait);
    }
  else
    for (int value=start; value>=stop; value--)
    {
      analogWrite(pin, value);
      delay(wait);
    }
}

void loop()
{
  digitalWrite(GPIO_POWER, HIGH);
  delay(200);

  ramp(GPIO_RED, 0, 255, 10);
  delay(500);
  ramp(GPIO_GREEN, 0, 255, 10);
  delay(500);
  ramp(GPIO_RED, 255, 0, 10);
  delay(500); 
  ramp(GPIO_BLUE, 0, 255, 20);
  delay(500);
  ramp(GPIO_RED, 0, 255, 10);
  delay(500);
  ramp(GPIO_GREEN, 255, 0, 8);
  delay(500);
  ramp(GPIO_BLUE, 255, 0, 10);
  delay(500);
  ramp(GPIO_RED, 255, 0, 8);
  delay(500);
  
  digitalWrite(GPIO_POWER, LOW);
  delay(2000);
}
