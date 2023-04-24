void kalibrasi()
{
  if (Serial.available())
  {
    char temp = Serial.read();
    if (temp == 's')
    {
      printKalibrasi();
    }

    //   KAKI 1 A
    if (temp == 'a')
    { 
      calA[1]--;
      srv_1A.write(cxAngle + calA[1]);   Serial.print("Kaki 1 A: " + String(calA[1]));
    }
    else if (temp == 'A') // A1
    {
      calA[1]++;
      srv_1A.write(cxAngle + calA[1]);   Serial.print("Kaki 1 A: " + String(calA[1]));
    }
    //   KAKI 1 B
    if (temp == 'b')
    {
      calB[1]++;
      srv_1B.write(fmAngle + calB[1]);   Serial.print("Kaki 1 b: " + String(calB[1]));
    }
    else if (temp == 'B')
    {
      calB[1]--;
      srv_1B.write(fmAngle + calB[1]);   Serial.print("Kaki 1 B: " + String(calB[1]));
    }
    //   KAKI 1 C
    if (temp == 'c')
    { 
      calC[1]++;
      srv_1C.write(tbAngle + calC[1]);   Serial.print("KAKI 1 C : " + String(calC[1]));
    }
    else if (temp == 'C')
    {
      calC[1]--;
      srv_1C.write(tbAngle + calC[1]);   Serial.print("KAKI 1 C : " + String(calC[1]));
    }
    //   KAKI 2 A
    if (temp == 'd')
    {
      calA[2]++;
      srv_2A.write(cxAngle + calA[2]);   Serial.print("KAKI 2 A : " + String(calA[2]));
    }
    else if (temp == 'D')
    {
      calA[2]--;
      srv_2A.write(cxAngle + calA[2]);   Serial.print("KAKI 2 A : " + String(calA[2]));
    }
    //   KAKI 2 B
    if (temp == 'e')
    {
      calB[2]--;
      srv_2B.write(fmAngle + calB[2]);   Serial.print("KAKI 2 B : " + String(calB[2]));
    }
    else if (temp == 'E')
    {
      calB[2]++;
      srv_2B.write(fmAngle + calB[2]);   Serial.print("KAKI 2 B : " + String(calB[2]));
    }
    //   KAKI 2 C
    if (temp == 'f')
    {
      calC[2]--;
      srv_2C.write(tbAngle + calC[2]);   Serial.print("KAKI 2 C : " + String(calC[2]));
    }
    else if (temp == 'F')
    {
      calC[2]++;
      srv_2C.write(tbAngle + calC[2]);   Serial.print("KAKI 2 C : " + String(calC[2]));
    }
    //   KAKI 3 A
    if (temp == 'g')
    {
      calA[3]--;
      srv_3A.write(cxAngle + calA[3]);   Serial.print("KAKI 3 A : " + String(calA[3]));
    }
    else if (temp == 'G')
    {
      calA[3]++;
      srv_3A.write(cxAngle + calA[3]);   Serial.print("KAKI 3 A : " + String(calA[3]));
    }
    //   KAKI 3 B
    if (temp == 'h')
    {
      calB[3]++;
      srv_3B.write(fmAngle + calB[3]);   Serial.print("KAKI 3 B : " + String(calB[3]));
    }
    else if (temp == 'H')
    {
      calB[3]--;
      srv_3B.write(fmAngle + calB[3]);   Serial.print("KAKI 3 B : " + String(calB[3]));
    }
    //   KAKI 3 C
    if (temp == 'i')
    {
      calC[3]++;
      srv_3C.write(tbAngle + calC[3]);   Serial.print("KAKI 3 C : " + String(calC[3]));
    }
    else if (temp == 'I')
    {
      calC[3]--;
      srv_3C.write(tbAngle + calC[3]);   Serial.print("KAKI 3 C : " + String(calC[3]));
    }
    //   KAKI 4 A
    if (temp == 'j')
    {
      calA[4]++;
      srv_4A.write(cxAngle + calA[4]);   Serial.print("KAKI 4 A : " + String(calA[4]));
    }
    else if (temp == 'J')
    {
      calA[4]--;
      srv_4A.write(cxAngle + calA[4]);   Serial.print("KAKI 4 A : " + String(calA[4]));
    }
    //   KAKI 4 B
    if (temp == 'k')
    {
      calB[4]--;
      srv_4B.write(fmAngle + calB[4]);   Serial.print("KAKI 4 B : " + String(calB[4]));
    }
    else if (temp == 'K')
    {
      calB[4]++;
      srv_4B.write(fmAngle + calB[4]);   Serial.print("KAKI 4 B : " + String(calB[4]));
    }
    //   KAKI 4 C
    if (temp == 'l')
    {
      calC[4]--;
      srv_4C.write(tbAngle + calC[4]);   Serial.print("KAKI 4 C : " + String(calC[4]));
    }
    else if (temp == 'L')
    {
      calC[4]++;
      srv_4C.write(tbAngle + calC[4]);   Serial.print("KAKI 4 C : " + String(calC[4]));
    }
    //   KAKI 5 A
    if (temp == 'm')
    {
      calA[5]--;
      srv_5A.write(cxAngle + calA[5]);   Serial.print("KAKI 5 A : " + String(calA[5]));
    }
    else if (temp == 'M')
    {
      calA[5]++;
      srv_5A.write(cxAngle + calA[5]);
      Serial.print("KAKI 4 A : " + String(calA[4]));
    }
    //   KAKI 5 B
    if (temp == 'n')
    {
      calB[5]++;
      srv_5B.write(fmAngle + calB[5]);
      Serial.print("KAKI 5 B : " + String(calB[5]));
    }
    else if (temp == 'N')
    {
      calB[5]--;
      srv_5B.write(fmAngle + calB[5]);
      Serial.print("KAKI 5 B : " + String(calB[5]));
    }
    //   KAKI 5 C
    if (temp == 'o')
    {
      calC[5]++;
      srv_5C.write(tbAngle + calC[5]);
      Serial.print("KAKI 5 C : " + String(calC[5]));
    }
    else if (temp == 'O')
    {
      calC[5]--;
      srv_5C.write(tbAngle + calC[5]);
      Serial.print("KAKI 5 C : " + String(calC[5]));
    }
    //=====================
    if (temp == 'p')
    {
      calA[6]++;
      srv_6A.write(cxAngle + calA[6]);
      Serial.print("KAKI 6 A : " + String(calA[6]));
    }
    else if (temp == 'P')
    {
      calA[6]--;
      srv_6A.write(cxAngle + calA[6]);
      Serial.print("KAKI 6 A : " + String(calA[6]));
    }
    //=========
    if (temp == 'q')
    {
      calB[6]--;
      srv_6B.write(fmAngle + calB[6]);
      Serial.print("KAKI 6 B : " + String(calB[6]));
    }
    else if (temp == 'Q')
    {
      calB[6]++;
      srv_6B.write(fmAngle + calB[6]);
      Serial.print("KAKI 6 B : " + String(calB[6]));
    }
    //=========
    if (temp == 'r')
    {
      calC[6]--;
      srv_6C.write(tbAngle + calC[6]);
      Serial.print("KAKI 6 C : " + String(calC[6]));
    }
    else if (temp == 'R')
    {
      calC[6]++;
      srv_6C.write(tbAngle + calC[6]);
      Serial.print("KAKI 6 C : " + String(calC[6]));
    }
    else if (temp == 'z')
    {
      maj = 1;
    }
    else if (temp == 'Z')
    {
      maj = 0;
    }

    else if (temp == 'y')
    {
      mun = 1;
    }
    else if (temp == 'Y')
    {
      mun = 0;
    }

    else if (temp == 'x')
    {
      kan = 1;
    }
    else if (temp == 'X')
    {
      kan = 0;
    }

    else if (temp == 'v')
    {
      kir = 1;
    }
    else if (temp == 'V')
    {
      kir = 0;
    }
    if (testSt != 1)
    {
      saveCalibrationVariable();
    }

  }
}

void printKalibrasi()
{
  for (int as = 1; as < 7; as++) 
  {
  Serial.print("calA" + String(as) + " : " + String(calA[as]) + "\t");
  Serial.print("calB" + String(as) + " : " + String(calB[as]) + "\t");
  Serial.println("calC" + String(as) + " : " + String(calC[as]) + "\t");
  }
}
