#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define PIN       23
#define NUMPIXELS 1
#define GPIOLED   25

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 100

void setup() {
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  pixels.begin();
  pinMode(GPIOLED,OUTPUT);
}

void loop() {
  pixels.clear();
  int range = 3;
  
  for(int i=0; i<2; i++) {
    int red = rand () % range;
    int green = rand () % range;
    int blue = rand () % range;
    pixels.setPixelColor(0, pixels.Color(red, green, blue));
    pixels.show();
    if (i%2 == 0) {
      digitalWrite(GPIOLED, LOW);
    } else {
      digitalWrite(GPIOLED, HIGH);
    }
    
    delay(DELAYVAL);
  }
}
