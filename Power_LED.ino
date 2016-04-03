
#define GPIO_RED 13
#define GPIO_GREEN 12
#define GPIO_BLUE 11
#define GPIO_POWER 10

int BaumhausGruen[] = {17,107,4};

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

void ramp_rgb(
  int start_red, int stop_red,
  int start_green, int stop_green,
  int start_blue, int stop_blue,
  int wait)
{
  int steps = 100;
  float step_red   = (stop_red - start_red) / steps;
  float step_green = (stop_red - start_red) / steps;
  float step_blue  = (stop_blue - start_blue) / steps;

  for (int i=0; i<=100; i++)
  {
    analogWrite(GPIO_RED,   round(start_red + i*step_red));
    analogWrite(GPIO_GREEN, round(start_red + i*step_green));
    analogWrite(GPIO_BLUE,  round(start_red + i*step_blue));
    delay(wait);
  }
}

void loop()
{
  digitalWrite(GPIO_POWER, HIGH);
  delay(200);

  //ramp_rgb(0, BaumhausGruen[0], 0, BaumhausGruen[1], 0, BaumhausGruen[2], 10);
/*  ramp(GPIO_RED, 0, BaumhausGruen[0], 1);
  ramp(GPIO_GREEN, 0, BaumhausGruen[1], 1);
  ramp(GPIO_BLUE, 0, BaumhausGruen[2], 1);
  delay(5000);
  */
  
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
