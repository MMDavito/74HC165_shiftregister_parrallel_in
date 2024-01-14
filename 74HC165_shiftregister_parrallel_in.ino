//https://www.makerguides.com/interfacing-parallel-in-serial-out-shift-register-74hc165-with-arduino/


const int clockPin = 8;  /* CP */
const int latchPin = 9;  /* PL SH/LD*/
const int clkInh = 10;   /* Clock INH pin 15 */
const int dataPin = A0;   /* Q7 */

const int numBits = 8;   /* Set to 8 * number of shift registers */
boolean bitsValue[8] = {false, false, false, false, false, false, false, false};
void setup() {

  Serial.begin(9600);
  pinMode(dataPin, INPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clkInh, OUTPUT);

  digitalWrite(clkInh, LOW);
}

void loop() {
  // Step 1: Sample
  digitalWrite(latchPin, LOW);
  digitalWrite(latchPin, HIGH);
  for (int i = 0; i < numBits; i++) {
    
    bool bitValue = digitalRead(dataPin);
    
    digitalWrite(clockPin, HIGH); // Shift out the next bit
    digitalWrite(clockPin, LOW);
    if (i != 6 && i != 7) continue;
    
    if (bitValue != bitsValue[i])
    {
      Serial.print("Bit: ");
      Serial.print(i);
      Serial.print(", is now: ");
      Serial.println(bitValue);
      bitsValue[i] = bitValue;
    }
    /*
      // Step 2: Shift
      Serial.print("Bits: ");
      String bits = "";
      for (int i = 0; i < numBits; i++) {
      int bit = digitalRead(dataPin);
      if (i == 0 || i == 7)
      {
       if (bit == HIGH) {
         bits = "1" + bits;
       } else {
         bits = "0" + bits;
       }
      }
    */
  }
  //Serial.println(bits);
  //delay(1000);
}
