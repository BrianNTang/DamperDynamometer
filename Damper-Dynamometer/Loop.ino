void loop() {
  Serial.println("Press start button to begin testing.");
  if (digitalRead(Button) == HIGH) {  // when the button is pressed...
    Serial.println("Testing in progress");
    while (true) {
      // prints the calculated the velocity of the linearPot to 3 decimal places and calculated load from the LoadCell
      Serial.println(analogRead(LinearPot) + ", " + analogRead(LoadCell)); // LoadCell read determines overall speed
      p1 = p2;
      t1 = t2;

      // if the number of cycles performed has been reached...
      if (cycleCount >= 25) {
        Serial.println("Successfully Completed");
        break; // Exit loop
      }

      // To stop the program before successfully completing set number of cycles, press the start button again
      if (digitalRead(Button) == HIGH) { // if the button is pressed again...
        Serial.println("ERROR: In Progress Testing Stopped");
        break; // Exit Loop
      }
    }
  }
}

/*
// Helper Springs Testing
void loop() {
  digitalWrite(compressionPin, HIGH);
  /*while (cycleCount <= 400) {
    digitalWrite(reboundPin, LOW);
    digitalWrite(compressionPin, HIGH);
    delay(100);
    digitalWrite(reboundPin, HIGH);
    digitalWrite(compressionPin, LOW);
    cycleCount++;
    Serial.println(cycleCount);
    delay(200);
  }
  exit(0);
}
*/
