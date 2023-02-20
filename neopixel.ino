#include <Adafruit_NeoPixel.h>

#define PIN       0
#define NUM_LEDS 16

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_LEDS, PIN);

uint16_t target_ms = 10000; //Target duration in ms
uint16_t interval = target_ms / 16;

void setup() {
  pixels.begin();
  pixels.setBrightness(30); // ~1/9 brightness
}

void loop() {
  uint8_t  i;

  for(i=0; i<NUM_LEDS; i++) {    // For each LED...
    pixels.setPixelColor(i, 0xFFFFFF);  // Set to white
  }
  pixels.show();                 // Refresh LED states

  for(i=0; i<NUM_LEDS; i++){
    pixels.setPixelColor(i, 0x000000);  // Disable LED
    pixels.show();                 // Refresh LED state
    delay(interval);
  }

  //Spin indefinitely
  while(true){
    for(i=0; i<NUM_LEDS; i++) {    // For each LED...
        uint32_t c = 0;              // Assume pixel will be "off" color
        if(((offset + i) & 7) < 2) { // For each 8 pixels, 2 will be...
          c = color;                 // ...assigned the current color
        }
        pixels.setPixelColor(i, c);  // Set color of pixel 'i'
      }
      pixels.show();                 // Refresh LED states
      delay(50);
      offset++;
  }
}
