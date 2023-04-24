#include <Servo.h>
#include <EEPROMex.h>
#include "Arduino.h"
#include <math.h>
#include <avr/pgmspace.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 Oled(128, 64, &Wire, 4);
#include <TimerThree.h>

#define ledOledPin A0
#define buzzerPin A1
#define btnOledPin A2
#define bat2sSensPin A3
#define bat1sSensPin A4
#define bluetoothEnaPin A6
#define bluetoothStatusPin 11

#define sApi1Pin A8
#define sApi2Pin A7
#define sApi3Pin A12
#define sApi4Pin A5
#define sApi5Pin A10

#define kipasPin 47
#define pompaPin 31
#define trig1Pin 29
#define echo1Pin 27
#define trig2Pin 25
#define echo2Pin 24
#define trig3Pin 44
#define echo3Pin 42
#define trig4Pin 43
#define echo4Pin 41
#define trig5Pin 17
#define echo5Pin 16
#define trig6Pin 5
#define echo6Pin 7
#define jumlahPing 6
#define jarakMak 250

#include <NewPing.h>
NewPing pinG[jumlahPing] = {NewPing(trig1Pin, echo1Pin, jarakMak),
                            NewPing(trig2Pin, echo2Pin, jarakMak),
                            NewPing(trig3Pin, echo3Pin, jarakMak),
                            NewPing(trig4Pin, echo4Pin, jarakMak),
                            NewPing(trig5Pin, echo5Pin, jarakMak),
                            NewPing(trig6Pin, echo6Pin, jarakMak),
                           }; // (triger, echo, jarakMak);
int   jarak[7];
int   api[6];
byte  jarakLilin = 0;
float voltageReading;
float voltageReading1;
float batVol, batVol1, batPct;
long  counterLilin = 0;
bool maj = 0, mun = 0, kan = 0, kir = 0;

Servo srv_1A; Servo srv_1B; Servo srv_1C;
Servo srv_2A; Servo srv_2B; Servo srv_2C;
Servo srv_3A; Servo srv_3B; Servo srv_3C;
Servo srv_4A; Servo srv_4B; Servo srv_4C;
Servo srv_5A; Servo srv_5B; Servo srv_5C;
Servo srv_6A; Servo srv_6B; Servo srv_6C;
Servo myservoA; Servo myservoB; Servo myservoC;
Servo srv_GR; Servo srv_UP; Servo srv_k;

#define JSD 25             //   25  //  19
#define stp 58             //   58       //   47  //  36

//=========PID VARIABLE
float Kp                = 5;
float Ki                = 1;
float Kd                = 0.1;
//=========PIT STOP VARIABLE
byte startPoint         = 0, 
     stopPoint          = 99, 
     wallDistance       = 10, 
     frontDistance      = 15;
int  fireLimit          = 300;
//=========RUN VARIABLE
extern int JS;
int addStep             = JS + JS - 2;
byte sp                 = 1;
float left              = 1, 
      right             = 1, 
      leftCalibration   = 1, 
      rightCalibration  = 1;

byte langkah            = 0,
     gaitsMode          = 3,    //   GAITS 1. Metachronal, 2. Ripple, 3. Tripod
     xspd               = 60,   //    max 20
     spd                = 60 - xspd;   

int   dly               = 5;
float wide              = 5;     // max 25
float lift              = 25;    // max 25

// ====================== run parameter
float yAxis             = 20,   // rentang kaki sudut x
      xAxis             = 40,   // rentang kaki sudut y (Min 70)
      zAxis             = 25;   // rentang kaki sudut z

// ====================== Body VARIABLE
float cx                = 40,   //  coxa a1
      fm                = 61,   //  femur a2
      tb                = 118,  //  tibia a3
      Zo                = 40;   //  40

//======================= Kinematik
int runAngle[]          = {0, 0, 0, 0, 0, 0, 0};
byte cxAngle            = 90,
     fmAngle            = 90,
     tbAngle            = 90,
     cx0                = 0,
     fm0                = 10,
     tb0                = 10;
long numberStep         = 0;
long jumlahLangkah      = 0;
byte testSt             = 0;
byte hitungJalan        = 0;

//======================== CALIBRATION VARIABLE
int calA[]              = {0, 0, 0, 0, 0, 0, 0};
int calB[]              = {0, 10, 10, 10, 10, 10, 10};
int calC[]              = {0, 10, 10, 10, 10, 10, 10};

float Adl1;               // untuk mencek Hasil perhitungan

byte batSt              = 2,
     readySt            = 0,
     direction          = 1,
     directionSt        = 0;
long startStep          = 0,
     runtStepNumber     = 0;
int pos0                = 180;

//======== Trajectory variable
float U1[stp];
float W1[stp];
float U2[stp];
float W2[stp];

//======== Gaits variable
byte s0[stp];   // stp
byte s1[stp];
byte s6[stp];
byte s2[stp];
byte s5[stp];
byte s4[stp];
byte s3[stp];

float pos_1A = cxAngle + calA[1], pos_1B = fmAngle + calB[1], pos_1C = tbAngle + calC[1];
float pos_2A = cxAngle + calA[2], pos_2B = fmAngle + calB[2], pos_2C = tbAngle + calC[2];
float pos_3A = cxAngle + calA[3], pos_3B = fmAngle + calB[3], pos_3C = tbAngle + calC[3];
float pos_4A = cxAngle + calA[4], pos_4B = fmAngle + calB[4], pos_4C = tbAngle + calC[4];
float pos_5A = cxAngle + calA[5], pos_5B = fmAngle + calB[5], pos_5C = tbAngle + calC[5];
float pos_6A = cxAngle + calA[6], pos_6B = fmAngle + calB[6], pos_6C = tbAngle + calC[6];

float AdL[JSD], BdL[JSD], CdL[JSD], AdR[JSD], BdR[JSD], CdR[JSD];
float AtL[JSD], BtL[JSD], CtL[JSD], AtR[JSD], BtR[JSD], CtR[JSD];
float AbL[JSD], BbL[JSD], CbL[JSD], AbR[JSD], BbR[JSD], CbR[JSD];

void beep() {
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, HIGH);
  digitalWrite(ledOledPin, HIGH);
  delay(100);
  digitalWrite(buzzerPin, LOW);
  digitalWrite(ledOledPin, LOW);
  delay(100);
}

float mapFloat(float x, float fromLow, float fromHigh, float toLow, float toHigh) {
  return (x - fromLow) * (toHigh - toLow) / (fromHigh - fromLow) + toLow;
}

void printSerial(String S1, String S2, String S3, float dA, float dB, float dC, int s) {
  Serial.print(S1 + "[" + String(s) + "] ");
  Serial.print(dA, 1); Serial.print(" \t");
  Serial.print(S2 + "[" + String(s) + "] ");
  Serial.print(dB, 1); Serial.print(" \t");
  Serial.print(S3 + "[" + String(s) + "] ");
  Serial.print(dC, 1);
  Serial.println();
  if (s == JS) Serial.println();
}

void printf_info() 
{
  Serial.print ("xAxis  \t" + String(xAxis) + " \t"); 
  Serial.print ("yAxis  \t" + String(yAxis) + " \t"); 
  Serial.print ("zAxis  \t" + String(zAxis) + " \t"); 
  Serial.print ("delay  \t" + String(dly) + " \t"); 
  Serial.print ("Speed  \t" + String(spd) + " \t"); 
}
