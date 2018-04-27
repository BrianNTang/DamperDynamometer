void setup() {
  Serial.begin(115200);                 // sets data rate (bits per second)
  //pinMode(Button, INPUT);               // intializes button (pin 2)
  pinMode(compressionPin, OUTPUT);      // intializes compression (pin 10)
  pinMode(reboundPin, OUTPUT);          // intializes rebound (pin 9)
  Wire.begin();
  
  // Ard2499 Library Initialization - LTC and EEPROM not jumpered
  ard2499board1.begin(ARD2499_ADC_ADDR_ZZZ, ARD2499_EEP_ADDR_ZZ);
  // Rejects line frequency noise @50&60Hz & converts at 2X speed
  ard2499board1.ltc2499ChangeConfiguration(LTC2499_CONFIG2_60_50HZ_REJ | LTC2499_CONFIG2_SPEED_2X);
  // Single-ended config., channel 3 as positive input with measured range at 2.048V max.
  ard2499board1.ltc2499ChangeChannel(LTC2499_CHAN_SINGLE_3P);
  
  // **edited TimerOne Library Initialization - Set period between ISR in microseconds
  Timer1.initialize(1000000);
  // **edited After a set period, perform the switchOutputs function
  Timer1.attachInterrupt(switchOutputs);
  
  t1 = millis()/1000;
  p1 = LinearPotActuation - (analogRead(LinearPot) * PositionConversion);
}
