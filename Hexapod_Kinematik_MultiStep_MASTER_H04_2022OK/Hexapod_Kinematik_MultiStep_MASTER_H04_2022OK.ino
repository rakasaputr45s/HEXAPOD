//Hexapod_Kinematik_MultiStep_MASTER_H04_03a
//by Siful Jamaan, PhD, 16-07-2021
//Hexapod_Kinematik_MultiStep_MASTER_H04_2022
//by Siful Jamaan, PhD, 31-05-2022

#include "1_Variable.h"

int P36       = 6;
byte smothtly = 2;         //  1, 2, 3, 4
int JS        = 12;        //  6, 12, 18, 24 smoothly
byte calSt = 1;
byte dir = 1;
byte pushSt = 1;    //BT
byte btSt = 0;
byte clrSt       = 0;
byte oledSt      = 0;
byte kipasSt     = 0;
byte apiSt       = 0;
byte buzzerApiSt = 0;
int  menuSt       = 0;

//EEPROM.writeInt(405, fireLimit);
byte printOut = 3;
byte activeSt = 1;
byte runSt = 1;

void setup() {
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
  beep();
  beep();
}

void loop() {       // ini untuk mencoba fungsi dari bbrp void
 
  timer();
  angkat();
  // action();
  kalibrasi();
  if (maj)  maju(0);
  if (mun)  mundur(0);
  if (kan)  belokKanan(0);
  if (kir)  belokKiri(0);



}

void loopDemo() 
{
  
  pinMode(30, INPUT_PULLUP);
  if (digitalRead(30) == LOW) 
  {
    if (runSt == 1) {
      counterLilin = 0;
      runSt = 0;
      beep();
      beep();
    }
    else {
      runSt = 1;
      beep();
    }
  }
  
  switch (runSt) {
    case 0:
      //stanBy();
      jumlahLangkah = 0;
      break;
    case 1:
      maju(0);
      if (jumlahLangkah == 5) runSt = 2;
      break;
    case 2:
      putarKiri(0);
      if (jumlahLangkah == 10) runSt = 3;
      break;
    case 3:
      tarok();
      delay(200);
      gripperOpen();
      delay(200);
      runSt = 4;
      //angkat();
      //if (jumlahLangkah == 13) runSt = 4;
      //putarKanan(0);
      break;
    case 4:
      maju(0);
      if (jumlahLangkah == 13) runSt = 5;
      kipasOn();
      break;
    case 5:
      kipasOff();
      gripperClose();
      delay(200);
      angkat();
      delay(200);
      runSt = 6;
      //mundur(0);
      //runSt = 0;
      break;
    case 6:
      if (jumlahLangkah == 17) runSt = 7;
      mundur(0);

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

void loop1() {

  if (calSt == 1) {
    gaitsTrajectoryCalculation(smothtly);
    moveToCalculation(dir);
    calSt = 0;
  } else {
    runningMainProgram();
    //runningMainProgram1();
  }
  timer();
  ukurJarak();
}


void runningMainProgram1() {
  switch (runSt) {
    case 60:
      mundur(2);
      break;
  }
}

void runningMainProgram() {
  if (activeSt == 1) {
    switch (runSt) {
      case 0:

        break;
      case 1:
        maju(0);
        //majuAction(0, 70, 50, 10, 99);
        //majuAction(0, 80, 30, 0, 99);
        break;
      case 2:
        belokKanan(0.5);
        break;
      case 3:
        putarKanan(0);
        break;
      case 5:
        mundur(0);
        break;
      case 7:
        putarKiri(0);
        break;
      case 8:
        belokKiri(0.5);
        break;
      case 9:
        action();
        break;
      case 10:
        stanBy();
        break;
      case 11:
        geserKiri(2);
        break;
      case 12:
        geserKanan(2);
        break;
      case 13:
        setupServo(1);
        runSt = 0;
        break;
      case 60:
        //mundur1(3);
        break;
      case 61:
        //putarKanan1(6);
        break;
      case 20: // lilin
        bacaApi();
        break;
      case 21:
        padamkanLilin();
        break;
      case 22:
        putarKiriAction(2, 80, 50, 10, 15, 23);
        break;
      case 23:
        putarKananAction(3, 80, 50, 10, 15, 24);
        break;
      case 24:
        kipasOff();
        break;
      case 30:
        mundurAction(2, 80, 40, 10, 20, 31);
        break;
      case 31:
        putarKananAction(6, 80, 50, 10, 15, 32);
        break;
      case 32:
        mundurAction(2, 80, 40, 10, 20, 33);
        break;
      case 33:
        gripperClose();
        angkat();
        runSt = 34;
        break;
      case 34:
        putarKiriAction(6, 80, 50, 10, 15, 35);
        break;
      case 35:

        break;
    }
  }
}

void action() 
{
  if (langkah < addStep)
    langkah++;
  action_1(langkah);
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
