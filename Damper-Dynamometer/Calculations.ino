// Load Calculation
int readLoad () {
  // Zeroing from LC&SGA Calibration with estimated attentuation factor
  return (ard2499board1.ltc2499Read() - 10471571);
}

// Velocity Calculation
float readVelocity () {
  // Linear Potentiometer Actuation: 4 in.
  // Arduino Onboard ADC is 10-bit (1024 divisions)
  p2 = LinearPotActuation - (analogRead(LinearPot) * PositionConversion);
  t2 = millis()/1000;
  return (p2-p1)/(t2-t1);
 }
