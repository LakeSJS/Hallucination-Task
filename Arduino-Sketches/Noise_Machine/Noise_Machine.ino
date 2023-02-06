
// output pins
#define PIN_SPEAKER 5 // output to piezo speaker
// input pins
#define PIN_INPUT 2 // input from larger arduino 
// set maxmimum and minimum frequencies that noise generator can produce

void setup() {
    pinMode(PIN_INPUT, INPUT);
    pinMode(PIN_SPEAKER, OUTPUT);
}
void loop() {
    // if button is pressed, generate white noise
    if (digitalRead(PIN_INPUT) == HIGH) {     
        //digitalWrite(PIN_SPEAKER, LOW) ;
        //delayMicroseconds(random(1000,3000)) ;
        //digitalWrite(PIN_SPEAKER, HIGH) ;
        //delayMicroseconds(random(1000,3000)) ;
        // digitalwrite random to create white noise
        digitalWrite(PIN_SPEAKER, random(0,2));
    }
    if (digitalRead(PIN_INPUT) == LOW) {
        digitalWrite(PIN_SPEAKER, LOW);
    }
}