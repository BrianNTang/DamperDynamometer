// Interrupt Service Routine (ISR)
void switchOutputs () {
  cState = !cState;
  digitalWrite(compressionPin, cState);
  rState = !rState;
  digitalWrite(reboundPin, rState);
  cycleCount += 0.5;
}
