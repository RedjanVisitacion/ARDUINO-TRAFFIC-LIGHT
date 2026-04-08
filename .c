#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// LED pins
const int redLED = 4;
const int yellowLED = 3;
const int greenLED = 2;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 allocation failed");
    for (;;);
  }

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 20);
  display.println("START");
  display.display();
  delay(2000);
}

void showMessage(const char* text, int seconds) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(20, 10);
  display.println(text);

  display.setTextSize(2);
  display.setCursor(50, 40);
  display.println(seconds);

  display.display();
}

void loop() {
  // RED
  digitalWrite(redLED, HIGH);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, LOW);
  for (int i = 5; i >= 1; i--) {
    showMessage("RED", i);
    delay(1000);
  }

  // YELLOW
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, HIGH);
  digitalWrite(greenLED, LOW);
  for (int i = 2; i >= 1; i--) {
    showMessage("WAIT", i);
    delay(1000);
  }

  // GREEN
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, HIGH);
  for (int i = 5; i >= 1; i--) {
    showMessage("GO", i);
    delay(1000);
  }

  // YELLOW
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, HIGH);
  digitalWrite(greenLED, LOW);
  for (int i = 2; i >= 1; i--) {
    showMessage("WAIT", i);
    delay(1000);
  }
}
