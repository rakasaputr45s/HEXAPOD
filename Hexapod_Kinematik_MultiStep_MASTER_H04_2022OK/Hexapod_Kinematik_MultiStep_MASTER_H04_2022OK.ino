#include "1_Variable.h"

int P36           = 6;
byte smothtly     = 4;         //  1, 2, 3, 4
int JS            = 24;        //  6, 12, 18, 24 smoothly
byte calSt        = 1;
byte dir          = 1;
byte pushSt       = 1;         //  BT
byte clrSt        = 0;
byte oledSt       = 0;
byte kipasSt      = 0;
byte apiSt        = 0;
byte buzzerApiSt  = 0;
int  menuSt       = 0;
byte printOut     = 3;
byte activeSt     = 1;
byte runSt        = 0;

void setup() 
{
  Serial.begin(115200);
  Serial.println();
  Serial.println("Quadruped Robot Program");
  beep();

  if (calSt == 1) {
    gaitsTrajectoryCalculation(smothtly);
    moveToCalculation(dir);
    calSt = 0;
  }
  setupServo(1);
  delay(500);
  pushSt = 0;
  delay(1000);
  Serial.print("yAxis ");
  Serial.println(yAxis);
  int puter = 0;
  while (puter < 3)  beep();
  angkat();
  gripperClose();
}

void loop() 
{       
  timer();
  kalibrasi();
  run();
}

void run() 
{
  switch (runSt) {
    case 0:
      maju(28);
      if (jumlahLangkah == 28) // jika sudah dapat 28 langkah stop
      stopPoint();             // stop sampai disini jika lanjut step selanjutnya pakai nextstep
      break;
    case 1:
      putarKiri(14);
      if (jumlahLangkah == 14) nextPoint();
      // tarok();
      // delay(200);
      // gripperOpen();
      // delay(200);
      // nextPoint();
      break;
    case 2:
      maju(7);
      if (jumlahLangkah == 7) nextPoint();
      break;
    case 3:
      gripperClose();
      delay(200);
      angkat();
      delay(200);
      nextPoint();
      break;
    case 4:
      putarKiri(14);
      if (jumlahLangkah == 14) nextPoint();
      break;
    case 5:
      tarok();
      delay(200);
      gripperOpen();
      delay(200);
      runSt = 69;
      break;
    case 7:
      putarKanan(0);
      if (jumlahLangkah >= 22) runSt = 0;
      break;
    case 8:
      //kipasOn();
      //  timerLilin();
      break;
    case 9:

      break;
  }
}

void stanBy() {
  if (directionSt != 1) {
    moveToCalculation(2);
    directionSt = 1;
  }
  if (langkah >= addStep / 2) {
    if (langkah < addStep) {
      langkah++;
      moveTo(langkah);
    }
  } else if (langkah > 1) {
    numberStep -= 1;
    langkah--;
    moveTo(langkah);
  }
}



void nextPoint() 
{
runSt++;
}

void stopPoint() 
{
runSt = 69;
}