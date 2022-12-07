const int analogPin = A0;
const int display_mode = 0;  //0 para anodo comun, 1 para catodo comun
int pines[] = { 13, 12, 11, 10, 9, 8, 7 };
char chars[] = {
  '1',
  '2',
  '3',
  '4',
  '5',
  '6',
  '7',
  '8',
  '9',
  '0',
};
String bins[] = { "0001001", "1011110", "1011011", "1101001", "1110011", "1110111", "1011001", "1111111", "1111001", "0111111" };
int sensorValue = 0;
int outputValue = 0;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < sizeof(pines); i++) {
    pinMode(pines[i], OUTPUT);
  }
}

void loop() {
  sensorValue = analogRead(analogPin);
  outputValue = map(sensorValue, 0, 1023, 0, 100);
  Serial.println(outputValue);
  outputValue = map(sensorValue, 0, 1023, 9, 0);
  display_write(outputValue + '0');
  delay(100);
}

void display_write(char character) {
  for (int i = 0; i < sizeof(chars); i++) {
    if (chars[i] == character) {
      String temp = bins[i];
      int pos = 0;
      for (int e = 13; e >= 7; e--) {
        led_write(e, temp[pos]);
        pos++;
      }
    }
  }
}

void led_write(int pin, char val) {
  if (display_mode == 1) {
    if (val == '1') {
      digitalWrite(pin, HIGH);
    } else {
      digitalWrite(pin, LOW);
    }
  } else {
    if (val == '1') {
      digitalWrite(pin, LOW);
    } else {
      digitalWrite(pin, HIGH);
    }
  }
}