const int pins[] = {13, 12, 14, 15, 18, 19, 21};
const int buzzer = 23;

//             gfedcba
const byte numbers[] = {
  0x3F,  // 0
  0x06,  // 1
  0x5B,  // 2
  0x4F,  // 3
  0x66,  // 4
  0x6D,  // 5
  0x7D,  // 6
  0x07,  // 7
  0x7F,  // 8
  0x6F   // 9
};

void setup() {

  // 7-segment pins
  for (int i = 0; i < 7; i++) {
    pinMode(pins[i], OUTPUT);
  }

  // Buzzer pin
  pinMode(buzzer, OUTPUT);
}

void loop() {

  // =========================
  // Count 0 -> 9
  // =========================
  for (int number = 0; number <= 9; number++) {

    // Display number
    for (int bit = 0; bit < 7; bit++) {
      digitalWrite(
        pins[bit],
        bitRead(numbers[number], bit)
      );
    }

    // Buzzer beep
    tone(buzzer, 2000);
    delay(100);
    noTone(buzzer);

    // Wait before next number
    delay(900);
  }


  // =========================
  // Count 8 -> 0
  // =========================
  for (int number = 8; number >= 0; number--) {

    // Display number
    for (int bit = 0; bit < 7; bit++) {
      digitalWrite(
        pins[bit],
        bitRead(numbers[number], bit)
      );
    }

    // Buzzer beep
    tone(buzzer, 2000);
    delay(100);
    noTone(buzzer);

    // Wait before next number
    delay(900);
  }
}