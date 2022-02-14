#include <LedControl.h>

LedControl matrix = LedControl(12, 11, 10, 1);

const int leftButton  = 2;
const int rightButton = 3;
const int upButton    = 4;
const int downButton  = 5;

int x, y = 0;

void setup() {
  for(int i = leftButton; i <= downButton; i++) pinMode(i, INPUT);

  matrix.shutdown(0, false);
  matrix.setIntensity(0, 0);
  matrix.clearDisplay(0);
}

void loop() {
  switch(keys()) {
    case 1: moveLeft();  break;
    case 2: moveRight(); break;
    case 3: moveUp();    break;
    case 4: moveDown();  break;
  }

  if     (x > 7) x = 0;
  else if(x < 0) x = 7;

  if     (y > 7) y = 0;
  else if(y < 0) y = 7;
  
  matrix.setLed(0, x, y, HIGH);
}

int keys() {
  if     (digitalRead(leftButton))  return 1;
  else if(digitalRead(rightButton)) return 2;
  else if(digitalRead(upButton))    return 3;
  else if(digitalRead(downButton))  return 4;
  return 0;
}
void moveUp() {
  y += 1;
  delay(250);
  matrix.setLed(0, x, y - 1, LOW);
}
void moveDown() {
  y -= 1;
  delay(250);
  matrix.setLed(0, x, y + 1, LOW);
}
void moveLeft() {
  x -= 1;
  delay(250);
  matrix.setLed(0, x + 1, y, LOW);
}
void moveRight() {
  x += 1;
  delay(250);
  matrix.setLed(0, x - 1, y, LOW);
}
