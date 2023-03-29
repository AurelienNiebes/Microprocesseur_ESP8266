
#include <LedController.hpp>
#define LED_DATA_PIN 7
#define LED_CLOCK_PIN 5
#define LED_CS_PIN 6

ByteBlock cross = {
        B00000000,
        B01000010,
        B00100100,
        B00011000,
        B00011000,
        B00100100,
        B01000010,
        B00000000
};

ByteBlock circle = {
        B00000000,
        B00111100,
        B01000010,
        B01000010,
        B01000010,
        B01000010,
        B00111100,
        B00000000
};
LedController<1,1> ledController;
void setup() {
  Serial.begin(115200); //115200 baudrate (vitesse de communication)
  Serial.println("Starting...");
  ledController.init(LED_DATA_PIN, LED_CLOCK_PIN, LED_CS_PIN, 1);
  Serial.println("Started");
}

void loop() {
  Serial.println("clearing matrix");
  ledController.clearMatrix();
  Serial.println("Cleared");
  ledController.displayOnSegment(0, cross);
  delay(2000);
  Serial.println("clearing matrix");
  ledController.clearMatrix();
  Serial.println("Cleared");
  ledController.displayOnSegment(0, circle);
  delay(2000);
}
