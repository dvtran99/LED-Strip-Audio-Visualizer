#include <FastLED.h>

// Constant defines
#define NUM_LEDS       300
#define LEDS_IN_GROUP  10
#define LED_PIN        7
#define IN_PIN         A0
#define MAX_ITERATIONS 10

// LED logic variables
CRGB leds[NUM_LEDS];
int steps = NUM_LEDS / LEDS_IN_GROUP;
int inputVal = 0;
int iterations = 0;
int max = -999;

// LED color presets
CRGB redColor = CRGB(255, 0, 0);
CRGB orangeColor = CRGB(255, 32, 0);
CRGB yellowColor = CRGB(255, 255, 0);
CRGB greenColor = CRGB(0, 255, 0);
CRGB blueColor = CRGB(0, 0, 255);
CRGB purpleColor = CRGB(64, 0, 64);
CRGB pinkColor = CRGB(255, 0, 255);
CRGB noColor = CRGB(0, 0, 0);

CRGB currentColor = noColor;

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);

  Serial.begin(19200);
}

void loop() {
  // Get offset ADC reading and treat negatives like positives
  inputVal = analogRead(IN_PIN) - 511;
  inputVal = abs(inputVal);

  // Keep max sample for updating next state
  if (inputVal > max) {
    max = inputVal;
  }

  if (++iterations == MAX_ITERATIONS) {
    // Configure new LED state
    if (max > 180) {
      currentColor = pinkColor;
    }
    if (max > 155) {
      currentColor = purpleColor;
    }
    else if (max > 130) {
      currentColor = blueColor;
    }
    else if (max > 105) {
      currentColor = greenColor;
    }
    else if (max > 80) {
      currentColor = yellowColor;
    }
    else if (max > 55) {
      currentColor = orangeColor;
    }
    else if (max > 30) {
      currentColor = redColor;
    }
    else {
      currentColor = noColor;
    }

    for (int i = 0; i < LEDS_IN_GROUP - 3; i++)
    {
      leds[i] = currentColor; 
    }

    // Update existing LED state
    for (int i = steps - 1; i >= 0; i--)
    {
      for (int j = 0; j < LEDS_IN_GROUP; j++)
      {
        leds[(i * LEDS_IN_GROUP) + j + LEDS_IN_GROUP] = leds[(i * LEDS_IN_GROUP) + j];
      }
    }

    FastLED.show();

    // Reset variables
    max = -999;
    iterations = 0;
  }

  delay(5);
}
