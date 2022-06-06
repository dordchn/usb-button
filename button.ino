/**
Created by Dor Cohen.
IG account: @do.robotics
3D Model: https://www.thingiverse.com/thing:5400168
*/

#include <TrinketHidCombo.h>

const int buttonPin = 0;
bool pressed = false;

void setup() {
  pinMode(buttonPin, INPUT);

  TrinketHidCombo.begin();
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH && !pressed) {
    TrinketHidCombo.pressKey(0, KEYCODE_ENTER);
    TrinketHidCombo.pressKey(0, 0); // key release
    pressed = true;
    delay(100);
  } else {
    TrinketHidCombo.poll();
    if (buttonState == LOW) pressed = false;
  }
}

/*
 * See keycode here:
 * https://github.com/adafruit/Adafruit-Trinket-USB/blob/master/TrinketHidCombo/TrinketHidCombo.h
 * https://github.com/adafruit/Adafruit-Trinket-USB/blob/master/TrinketHidCombo/TrinketHidCombo.cpp (special keycodes)
*/

/*
 * Some other useful stuff
 * TrinketHidCombo.pressKey(KEYCODE_MOD_LEFT_ALT, KEYCODE_F4);
 * TrinketHidCombo.pressMultimediaKey(MMKEY_VOL_UP);
 */

 /* Useful links:
  *  Tutorial:          https://www.instructables.com/DIGIKEYPAD-DigiSpark/
  *  Drivers & Setup:   https://www.youtube.com/watch?v=MmDBvgrYGZs&list=LL&index=1
  *  Library:           https://github.com/adafruit/Adafruit-Trinket-USB/tree/master/TrinketHidCombo
  */
