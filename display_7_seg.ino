const int display_mode = 0;  //0 para anodo comun, 1 para catodo comun
int pines[] = { 13, 12, 11, 10, 9, 8, 7 };
char chars[] = { 'a', 'b', 'c', 'd', 'e',
                 'f', 'g', 'h', 'i', 'j',
                 'k', 'l', 'm', 'n',
                 'o', 'p', 'q', 'r', 's',
                 't', 'u', 'v', 'w', 'x',
                 'y', 'z', '1', '2',
                 '3', '4', '5', '6', '7',
                 '8', '9', '0', ' ' };
String bins[] = { "1111101", "1100111", "1000110", "1001111", "1110110",
                  "1110100", "0110111", "1100101", "0000001", "0001111",
                  "1110101", "0100110", "0010101", "0111101",
                  "1000111", "1111100", "1111001", "0111100", "1110011",
                  "1100110", "0101111", "0101011", "0101010", "1101101",
                  "1101011", "1011010", "1110011", "1011110",
                  "1011011", "1101001", "1110011", "1110111", "1011001",
                  "1111111", "1111001", "0111111", "0000000" };

void setup() {
  for (int i = 0; i < sizeof(pines); i++) {
    pinMode(pines[i], OUTPUT);
  }
}

void loop() {
  char str[] = "juan";
  for (int i = 0; i < sizeof(str); i++) {
    display_write(str[i]);
    delay(1000);
  }
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