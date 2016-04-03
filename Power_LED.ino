
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

void loop()
{
  digitalWrite(GPIO_POWER, HIGH);
  delay(200);

  analogWrite(GPIO_RED, 10);
  delay(1000);
  digitalWrite(GPIO_RED, LOW);
 
  analogWrite(GPIO_GREEN, 10);
  delay(1000);
  digitalWrite(GPIO_GREEN, LOW);
 
  analogWrite(GPIO_BLUE, 10);
  delay(1000);
  digitalWrite(GPIO_BLUE, LOW);
  
  digitalWrite(GPIO_POWER, LOW);
  delay(2000);
}
