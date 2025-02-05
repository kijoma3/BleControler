#include <BleGamepad.h>

#define AXIS_X 4
#define AXIS_Y 5
#define BUTTON 6
#define KNOPFA 17
#define KNOPFB 18

int x = 0;
int y = 0;
int xGame = 0;
int yGame = 0;
bool button = false;
bool knopfA = false;
bool knopfB = false;

BleGamepad gamepad;
void setup() {
  Serial.begin(115200);
  gamepad.begin();

  pinMode(AXIS_X, INPUT);
  pinMode(AXIS_Y, INPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(KNOPFA, INPUT_PULLUP);
  pinMode(KNOPFB, INPUT_PULLUP);
  gamepad.setAxes(0, 0, 0, 0, 0, 0, 0, 0);
  
}

void loop() {
  button = digitalRead(BUTTON) == LOW;
  x = analogRead(AXIS_X);
  y = analogRead(AXIS_Y);

  

  if (gamepad.isConnected()) {
    button = digitalRead(BUTTON) == LOW;
    knopfA = digitalRead(KNOPFA) == LOW;
    knopfB = digitalRead(KNOPFB) == LOW;
    x = analogRead(AXIS_X);
    y = analogRead(AXIS_Y);

    xGame = map(x, 0, 4095, 0, 65535);
    yGame = map(y, 0, 4095, 0, 65535);
    
  /*   if (xGame < 15500 && xGame > 14500){
      xGame = 16450;
    }
    if (yGame < 15500 && yGame > 14500){
      yGame = 16450;
    } */

     if (xGame < 31000 && xGame > 16000){
      xGame = 16050;
    }
    if (yGame < 31000 && yGame > 16000){
      yGame = 16050;
    }

    gamepad.setAxes(xGame, yGame, 0, 0, 0, 0, 0, 0);

    if (button == 1) {
      gamepad.press(1);
    } else {
      gamepad.release(1);
    }

    if (knopfA == 1) {
      gamepad.press(2);
    } else {
      gamepad.release(2);
    }

    if (knopfB == 1) {
      gamepad.press(3);
    } else {
      gamepad.release(3);
    }


  Serial.print("X: ");
  Serial.print(xGame);
  Serial.println("");
  Serial.print("Y: ");
  Serial.print(yGame);
  Serial.println("");
  Serial.print("StickButton: ");
  Serial.print(button);
  Serial.println("");
  Serial.print("ButtonA: ");
  Serial.print(knopfA);
  Serial.println("");
  Serial.print("ButtonB: ");
  Serial.print(knopfB);
  Serial.println("");
    
  } else {
   //Serial.println("Bluetooth not Connected");
  }

  delay(10);
}