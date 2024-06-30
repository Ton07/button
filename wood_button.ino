#include <Keyboard.h>

#define BUTTON_PIN_W A0
#define BUTTON_PIN_A A1
#define BUTTON_PIN_S A2
#define BUTTON_PIN_D A3

void setup()
{
  Serial.begin(9600);
  
  pinMode(BUTTON_PIN_W, INPUT_PULLUP);
  pinMode(BUTTON_PIN_A, INPUT_PULLUP);
  pinMode(BUTTON_PIN_S, INPUT_PULLUP);
  pinMode(BUTTON_PIN_D, INPUT_PULLUP);
  
  // Start the Keyboard library
  Keyboard.begin();
}

void loop()
{
  byte buttonStateW = digitalRead(BUTTON_PIN_W);
  byte buttonStateA = digitalRead(BUTTON_PIN_A);
  byte buttonStateS = digitalRead(BUTTON_PIN_S);
  byte buttonStateD = digitalRead(BUTTON_PIN_D);
  
  if (buttonStateW == LOW) {
      Keyboard.press('w');
      Serial.println("W pressed");
  }
  else {
      Keyboard.release('w');
  }
  
  if (buttonStateA == LOW) {
      Keyboard.press('a');
      Serial.println("A pressed");
  }
  else {
      Keyboard.release('a');
  }
  
  if (buttonStateS == LOW) {
      Keyboard.press('s');
      Serial.println("S pressed");
  }
  else {
      Keyboard.release('s');
  }
  
  if (buttonStateD == LOW) {
      Keyboard.press('d');
      Serial.println("D pressed");
  }
  else {
      Keyboard.release('d');
  }

  // If no buttons are pressed
  if (buttonStateW != LOW && buttonStateA != LOW && buttonStateS != LOW && buttonStateD != LOW) {
      Serial.println("No buttons pressed");
  }

  delay(100);
}
