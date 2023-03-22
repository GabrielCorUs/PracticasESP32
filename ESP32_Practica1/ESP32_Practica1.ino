// Declarar el pin 34 que es el GPIO 34 que funciona como adc (Analog ADC1_CH6) 
const int potPin = 34;

// Variable para almacenar el valor del potenciometro
int potValue = 0;

void setup() {
  Serial.begin(115200);//Se inicia el puerto serial en 115200 baulio
  delay(1000);
}

void loop() {
  // Leer el valor del potenciometro 
  potValue = analogRead(potPin);
  Serial.println(potValue);
  delay(500);
}
