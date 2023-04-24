
int16_t tempRaw;
int16_t timerPID;
float speed;
float eplaseTime,Op;
float pTerm, iTerm, dTerm, integrated_error, last_error, error, timePeriod;
const float K = 1.5;
float input2, outpur2, setPoint2, runEvery;

float input = wallDistance;

void follow(String LR)
{
  long t01 = millis();
  // ukurJarak();
  if (LR == "L")   { jarakKiri();   input = jarak[1]; }
  if (LR == "R")   { jarakKanan();  input = jarak[2]; }
  error = wallDistance - input; // 180 = level
  pTerm = Kp * error;
  integrated_error += error * eplaseTime;
  iTerm = Ki * constrain(integrated_error, -10, 10);
  dTerm = Kd * (error - last_error) / eplaseTime;
  last_error = error;
  speed = constrain(K * (pTerm + iTerm + dTerm), -255, 255);
  Op = mapFloat(speed, -255, 255, -0.85, 0.85);

  if (LR == "L")
  {
    if (error >= 0)  { right = 1 - Op; left = 1;  }
    if (error <= 0)  { left  = 1 + Op;  right = 1; }
  }
  if (LR == "R")
  {
    if (error >= 0)  { right = 1;  left  = 1 - Op; }
    if (error <= 0)  { left  = 1;  right = 1 + Op;}
  }
  // Serial.print("error  "); Serial.print(error);
  // Serial.print(", OutPut "); Serial.println(Op);
  // Serial.println();
  // Serial.print("left "); Serial.print(left);
  // Serial.print(", right "); Serial.println(right);
  // Serial.println();
  //  parameterCalculation();
  long t11 = millis();
  eplaseTime = t11 - t01;
  // Serial.print("eplaseTime "); Serial.println(eplaseTime);
  // Serial.println();
}
