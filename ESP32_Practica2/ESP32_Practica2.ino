
//ISR CON PUSH BUTTON 

// Estructura para boton
struct Boton {
	const uint8_t PIN; 
	uint32_t numberKeyPresses;
	bool pressed;
};

// Rutina de servicio de la interrupción
void IRAM_ATTR isr() {
	button1.numberKeyPresses++;
	button1.pressed = true;
}

// se declara el pin al que se conecto el boton en este caso el 18, el numero de pulsaciones en 0 y el estado de inicio del boton
Boton button1 = {18, 0, false};

void setup() {
	Serial.begin(115200); //Iniciamos el monitor serial
	pinMode(button1.PIN, INPUT_PULLUP); // declaramos que esste pin actue como PULLUP
	attachInterrupt(button1.PIN, isr, FALLING); // Le decimos a ESP32  que llame a la rutina isr
}

// Se detecta he imprime cuantas inturrupciones se provacaron hasta el momento 

void loop() {
	if (button1.pressed) {
		Serial.printf("Se han producido %u interrupciones\n", button1.numberKeyPresses);
		button1.pressed = false;
	}
}