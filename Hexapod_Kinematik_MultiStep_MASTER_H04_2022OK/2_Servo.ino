byte a1, a2, a3, a4, a5, a6, b1, b2, b3, b4, b5, b6, c1, c2, c3, c4, c5, c6, g1, g2, g3;
byte tunda = 100;
byte calibStA = 0;
byte calibStB = 0;
byte calibStC = 0;

void activeServo(byte x) 
{
  switch  (x) {
    case 1:
      a1 = 38, b1 = 39, c1 = 40;
      a2 = 18, b2 = 19, c2 = 22;
      a3 = 35, b3 = 33, c3 = 37;
      a4 = 6,  b4 = 8,  c4 = 9;
      a5 = 32, b5 = 34, c5 = 36;
      a6 = 2,  b6 = 3,  c6 = 4;
      g1 = 45, g2 = 46, g3 = 47;
      break;
    case 2:
      a1 = 38, b1 = 39, c1 = 40;
      a2 = 18, b2 = 19, c2 = 22;
      a3 = 35, b3 = 33, c3 = 37;
      a4 = 6,  b4 = 8,  c4 = 9;
      a5 = 32, b5 = 34, c5 = 36;
      a6 = 2,  b6 = 3,  c6 = 4;
      g1 = 45, g2 = 46, g3 = 47;
      break;


  }
  openCalibrationVariable();
  activeGriper();
  activeLeg1();    delay(tunda);   // kaki 1
  activeLeg2();    delay(tunda);   // kaki 2
  activeLeg3();    delay(tunda);   // kaki 3
  activeLeg4();    delay(tunda);   // kaki 4
  activeLeg5();    delay(tunda);   // kaki 5
  activeLeg6();    delay(tunda);   // kaki 6
}

byte posGp = 30;
byte posUd = 0;
byte gripperSt = 1;
byte UDSt = 1;
void activeGriper() {
  pinMode(kipasPin, OUTPUT);
  pinMode(pompaPin, OUTPUT);
  digitalWrite(kipasPin, LOW);
  digitalWrite(pompaPin, HIGH);
  srv_GR.attach(g1, 600, 2400); srv_GR.write(posGp); delay(tunda);// Gripper 100 tutup, 30 buka
  srv_UP.attach(g2, 600, 2400); srv_UP.write(posUd); delay(tunda);// 0 UP  180 Down
}

// gripper 95 tutup, 30 buka

void gripperOpen() {
  if (gripperSt == 0) {
    for (posGp = 15; posGp <= 60; posGp += 1) {
      srv_GR.write(posGp);
      delay(10);
    }
    gripperSt = 1;
  }

}

void gripperClose() {
  if (gripperSt == 1) {
    for (posGp = 60; posGp >= 15; posGp -= 1) {
      srv_GR.write(posGp);
      delay(10);
    }
    gripperSt = 0;
  }
}

void angkat() {
  // for (posUd = 1; posUd <= 180; posUd += 1) {
  //   srv_UP.write(posUd);
  //   delay(15);
  // }
    srv_UP.write(180);
    delay(15);
}

void tarok() {
  //if (UDSt == 0) {
  for (posUd = 180; posUd >= 1; posUd -= 1) {
    srv_UP.write(posUd);
    delay(15);
  }
  // UDSt = 1;
  // }
}

void pompaOn() {
  digitalWrite(pompaPin, LOW);
}
void pompaOff() {
  digitalWrite(pompaPin, HIGH);
}

void kipasOn() {
  digitalWrite(kipasPin, HIGH);

}
void kipasOff() {
  digitalWrite(kipasPin, LOW);
}
void setupServo(byte x) {
  //Serial.print ("Test Value AdL[1] ");
  //Serial.println (Adl1);
  if ((Adl1 > 0) and (Adl1 < 180)) {
    activeServo(x);
    readySt = 1;
    testSt = 0;
    Serial.println ("READY TO RUN");
  } else {
    readySt = 0;
    testSt = 0;
    Serial.println ("NOT READY ");
    beep();
  }
  Serial.print ("by Saiful Jamaan 05062021 ");
  Serial.println();
  printOut = 0;
}

void setServoA(int x, int p) {
  myservoA.attach(x);
  myservoA.write(p);
}

void setServoB(int x, int p) {
  myservoB.attach(x);
  myservoB.write(p);
}

void setServoC(int x, int p) {
  myservoC.attach(x);
  myservoC.write(p);
}

int pos = 0;
void testServo(int x) {
  myservoC.attach(x);
  for (pos = 0; pos <= 170; pos += 1) {
    myservoC.write(pos);
    delay(25);
  }

  for (pos = 170; pos >= 0; pos -= 1) {
    myservoC.write(pos);
    delay(25);
  }
}

void activeLeg1() {
  if (calibStA == 0)srv_1A.attach(a1, 600, 2400); srv_1A.write(pos_1A); delay(tunda);
  if (calibStB == 0)srv_1B.attach(b1, 600, 2400); srv_1B.write(pos_1B); delay(tunda);
  if (calibStC == 0)srv_1C.attach(c1, 600, 2400); srv_1C.write(pos_1C); delay(tunda);
}

void activeLeg2() {
  if (calibStA == 0)srv_2A.attach(a2, 600, 2400); srv_2A.write(pos_2A); delay(tunda);
  if (calibStB == 0)srv_2B.attach(b2, 600, 2400); srv_2B.write(pos_2B); delay(tunda);
  if (calibStC == 0)srv_2C.attach(c2, 600, 2400); srv_2C.write(pos_2C); delay(tunda);
}

void activeLeg3() {
  if (calibStA == 0)srv_3A.attach(a3, 600, 2400); srv_3A.write(pos_3A); delay(tunda);
  if (calibStB == 0)srv_3B.attach(b3, 600, 2400); srv_3B.write(pos_3B); delay(tunda);
  if (calibStC == 0)srv_3C.attach(c3, 600, 2400); srv_3C.write(pos_3C); delay(tunda);
}

void activeLeg4() {
  if (calibStA == 0)srv_4A.attach(a4, 600, 2400); srv_4A.write(pos_4A); delay(tunda);
  if (calibStB == 0)srv_4B.attach(b4, 600, 2400); srv_4B.write(pos_4B); delay(tunda);
  if (calibStC == 0)srv_4C.attach(c4, 600, 2400); srv_4C.write(pos_4C); delay(tunda);
}

void activeLeg5() {
  if (calibStA == 0)srv_5A.attach(a5, 600, 2400); srv_5A.write(pos_5A); delay(tunda);
  if (calibStB == 0)srv_5B.attach(b5, 600, 2400); srv_5B.write(pos_5B); delay(tunda);
  if (calibStC == 0)srv_5C.attach(c5, 600, 2400); srv_5C.write(pos_5C); delay(tunda);
}

void activeLeg6() {
  if (calibStA == 0)srv_6A.attach(a6, 600, 2400); srv_6A.write(pos_6A); delay(tunda);
  if (calibStB == 0)srv_6B.attach(b6, 600, 2400); srv_6B.write(pos_6B); delay(tunda);
  if (calibStC == 0)srv_6C.attach(c6, 600, 2400); srv_6C.write(pos_6C); delay(tunda);
}

void servoRun() 
{
  srv_1A.write(pos_1A);    srv_1B.write(pos_1B);    srv_1C.write(pos_1C);
  srv_2A.write(pos_2A);    srv_2B.write(pos_2B);    srv_2C.write(pos_2C);
  srv_3A.write(pos_3A);    srv_3B.write(pos_3B);    srv_3C.write(pos_3C);
  srv_4A.write(pos_4A);    srv_4B.write(pos_4B);    srv_4C.write(pos_4C);
  srv_5A.write(pos_5A);    srv_5B.write(pos_5B);    srv_5C.write(pos_5C);
  srv_6A.write(pos_6A);    srv_6B.write(pos_6B);    srv_6C.write(pos_6C);
}

void step0()
{
  srv_1A.write(pos_1A); delay(tunda);  srv_1B.write(pos_1B); delay(tunda);  srv_1C.write(pos_1C); delay(tunda);
  srv_2A.write(pos_2A); delay(tunda);  srv_2B.write(pos_2B); delay(tunda);  srv_2C.write(pos_2C); delay(tunda);
  srv_3A.write(pos_3A); delay(tunda);  srv_3B.write(pos_3B); delay(tunda);  srv_3C.write(pos_3C); delay(tunda);
  srv_4A.write(pos_4A); delay(tunda);  srv_4B.write(pos_4B); delay(tunda);  srv_4C.write(pos_4C); delay(tunda);
  srv_5A.write(pos_5A); delay(tunda);  srv_5B.write(pos_5B); delay(tunda);  srv_5C.write(pos_5C); delay(tunda);
  srv_6A.write(pos_6A); delay(tunda);  srv_6B.write(pos_6B); delay(tunda);  srv_6C.write(pos_6C); delay(tunda);
}
