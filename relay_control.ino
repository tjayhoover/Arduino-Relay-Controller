#define liftUpPin 7
#define liftDownPin 6
#define triggerPin 2

// Variables will change:
int ledState = HIGH;         // the current state of the output pin
int triggerState;             // the current reading from the input pin
int lastTriggerState = LOW;   // the previous reading from the input pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 200;    // the debounce time; increase if the output flickers

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(liftUpPin, OUTPUT);
  pinMode(liftDownPin, OUTPUT);
  pinMode(triggerPin, INPUT);
}

  void loop() {
  // read the state of the switch into a local variable:
  int reading = digitalRead(triggerPin);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastTriggerState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != triggerState) {
      triggerState = reading;

      // only toggle the LED if the new button state is HIGH
      if (triggerState == HIGH) {
        lower_lift();
      }
      else if(triggerState == LOW) {
        raise_lift();
      }
    }
  }
  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastTriggerState = reading;
}

void hit_button(int pinNumber) {
  digitalWrite(pinNumber, HIGH); // Press the button
  delay(500);
  digitalWrite(pinNumber, LOW); // Release the button
}

void lower_lift() {
  Serial.print("lift down\n");
  hit_button(liftDownPin);
}

void raise_lift() {
  Serial.print("lift up\n");
  hit_button(liftUpPin);
}
