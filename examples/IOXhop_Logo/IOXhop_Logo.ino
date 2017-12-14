/* modified by IOXhop (www.ioxhop.com) */

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_TFTLCD.h> // Hardware-specific library
#include <avr/pgmspace.h>

extern const uint16_t image_data_logo[];

#define LCD_CS A3 // Chip Select goes to Analog 3
#define LCD_CD A2 // Command/Data goes to Analog 2
#define LCD_WR A1 // LCD Write goes to Analog 1
#define LCD_RD A0 // LCD Read goes to Analog 0
#define LCD_RESET A4 // Can alternately just connect to Arduino's reset pin

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

uint16_t data;
void setup(void) {
  Serial.begin(9600);
  Serial.println(F("TFT LCD test"));
  tft.reset();
  
  tft.begin(0x9481);
  tft.setRotation(2);
  
  tft.fillScreen(0xffff);
  unsigned long nowPoint = 0;
  for (int y = 0; y < 60; y++) {
    for (int x = 0; x < 200; x++) {
      data = pgm_read_word_near(image_data_logo + nowPoint);
      tft.drawPixel(x + 63, y + 212, data);
      nowPoint++;
    }
  }
}

void loop(void) {

}
