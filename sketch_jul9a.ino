#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>
#include <Wire.h>
#include <RTClib.h>

#define TFT_CS 7
#define TFT_RST 10
#define TFT_DC 8
#define TFT_SCLK 21
#define TFT_MOSI 20

#define button1pin 3
#define button2pin 2
#define button3pin 1
#define button4pin 0
#define button5pin 4
#define buzzerpin 5
#define backlightpin 6

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

bool alarmOn = false;
bool snooze = false;

int button1State = 0;
int button2State = 0;
int button3State = 0;
int button4State = 0;
int menu = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  RTC.begin()
  
  tft.init(284, 76); // screen dimensions
  tft.setColRowStart(82, 18); // Offsets to get the screen to line up with the weird size
  tft.setRotation(2); // this makes the screen landscape, could be different, try 0-3
  Serial.println("TFT Initialized!");
  tft.fillScreen(ST77XX_BLACK); // make sure there is nothing in the buffer

  tft.setCursor(0,0);
  tft.setTextSize(2);           
  tft.print("Hello, world!"); 

  pinMode(buzzerPin, OUTPUT);
  pinMode(button1pin, INPUT);
  pinMode(button2pin, INPUT);
  pinMode(button3pin, INPUT);
  pinMode(button4pin, INPUT);
  pinMode(button5pin, INPUT);



}

void loop() {
  // put your main code here, to run repeatedly:

  //reading the state of buttons
  button1State = digitalRead(button1pin);
  button2State = digitalRead(button2pin);
  button3State = digitalRead(button3pin);
  button4State = digitalRead(button4pin);
  button5State = digitalRead(button5pin);

  if (digitalRead(button1pin)== LOW)
  {
    menu = menu+1
  }

  if (menu==0)
  {
    DisplayDateTime();
    Alarm();
          }
  if (menu==1)
  {
    //set day
    SetDay()
  }
    if (menu==2)
  {
    //set hour
    SetHour()
  }
    if (menu==3)
  {
    //set minute
    SetMin()
  }
    if (menu==4)
  {
    //set alarm
    SetAlarm()
  }
    if (menu==5)
  {
    tft.print(" menu ")
    menu=0;
  }

  if (digitalRead(button2pin)== LOW)
  {
    analogWrite(backlightpin, 100);
  }

  if (digitalRead(button3pin)== LOW)
  {
    analogWrite(backlightpin, 225);
  }

  if (digitalRead(button4pin)== LOW)
  {
    alarmOn = false;
    Alarm()
  }

  if (digitalRead(button5pin)== LOW)
  {
    snooze = true;
    Alarm()
  }

}

void DisplayDateTime ()
{
  DateTime now = RTC.now();

  tft.setCursor(0,0);
  tft.setTextSize(2);           
  tft.print("Time:"); 
  tft.print(t, "%02:%02d:%02d", now.hour(), now.minute(), now.second());
}

void SetAlarm(){
  
}

void Alarm(){

  while (snooze == true){
    digitalWrite(buzzerpin, LOW);
  }

  while (alarmOn == true){
    digitalWrite(buzzerpin, HIGH);
  }

}

void SetDay(){
  tft.clear();
}

void SetHour(){

}

void SetMin(){

}


