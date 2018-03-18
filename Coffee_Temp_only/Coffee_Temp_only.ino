int analogPin = 0;
int readValue = 0;
float temperature = 0;
float temperatureF = 0;

void setup() {
Serial.begin(9600);
}

void loop() {
readValue = analogRead(analogPin);
//Serial.println(readValue);
temperature = (readValue * 0.0049);
temperature = temperature * 100;
temperatureF = (temperature * 1.8) + 32;
Serial.print(temperatureF);
Serial.println();
delay(1000);
}
