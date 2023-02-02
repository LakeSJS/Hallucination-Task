// Generate white noise by toggling audioPin at random intervals
// this does not currently allow for filtering out of cue tone

// output pins
#define PIN_SPEAKER 8 // outpit to piezo speaker
// input pins
#define PIN_INPUT 3

void setup() {
    pinMode(PIN_SPEAKER, OUTPUT);
    pinMode(PIN_INPUT, INPUT);

    digitalWrite(PIN_SPEAKER, LOW); // initialize speaker to off
}
void loop() {
    // if button is pressed, generate white noise
    if (digitalRead(PIN_INPUT) == HIGH) {     
        digitalWrite(PIN_SPEAKER, LOW) ;
        delayMicroseconds(random(1000,3000)) ;
        digitalWrite(PIN_SPEAKER, HIGH) ;
        delayMicroseconds(random(1000,3000)) ;
    }
    if (digitalRead(PIN_INPUT) == LOW) {
        digitalWrite(PIN_SPEAKER, LOW) ;
    }
}