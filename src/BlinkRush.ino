
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define BTN_BLUE    5      
#define BTN_RED     7
#define LED_BLUE    4
#define LED_RED     6

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(9600); 

  pinMode(BTN_BLUE, INPUT_PULLUP);   
  pinMode(BTN_RED,  INPUT_PULLUP);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_RED, OUTPUT);

  randomSeed(analogRead(A0));

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while(true);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
}

void loop() {

  digitalWrite(LED_BLUE, LOW);
  digitalWrite(LED_RED, LOW);

  display.clearDisplay();
  display.println("Bereit...");
  display.display();

  unsigned long waitTime = random(2000, 7001);
  delay(waitTime);

  //Startsignal
  digitalWrite(LED_BLUE, HIGH);
  digitalWrite(LED_RED, HIGH);

        display.clearDisplay();
        display.println("JETZT!");
        display.display();

  unsigned long startTime = millis();

  int winnerLED = -1;
  unsigned long reactionTime = 0;

  // Auf Tastendruck warten
  while (winnerLED == -1) {

    if (digitalRead(BTN_BLUE) == LOW) {
      reactionTime = millis() - startTime;
      winnerLED = LED_BLUE;

      display.clearDisplay();
      display.setCursor(0, 0);
      display.println("Blau gewinnt!");
      display.setCursor(0, 30);
      display.print(reactionTime);
      display.println(" ms");
      display.display();
    }

    if (digitalRead(BTN_RED) == LOW) {
      reactionTime = millis() - startTime;
      winnerLED = LED_RED;

       display.clearDisplay();
      display.setCursor(0, 0);
      display.println("Rot gewinnt!");
      display.setCursor(0, 30);
      display.print(reactionTime);
      display.println(" ms");
      display.display();
    }
  }

  digitalWrite(LED_BLUE, LOW);
  digitalWrite(LED_RED, LOW);

  // Gewinner blinkt
  for (int i = 0; i < 10; i++) {
    digitalWrite(winnerLED, HIGH);
    delay(200);
    digitalWrite(winnerLED, LOW);
    delay(200);
  }

  while (true);
}