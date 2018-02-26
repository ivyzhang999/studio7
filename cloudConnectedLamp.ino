int lastButtonState;
int debounceDelay;
int lastDebounceTime;
bool lightOn;
int color[] = {255, 255, 255};
int buttonState;
int bluePin = D0;
int greenPin = D2;
int redPin = D3;

STARTUP(WiFi.selectAntenna(ANT_AUTO));

void setup(){
  Serial.begin(9600);
  pinMode(bluePin, OUTPUT);
  pinMode(D1, INPUT_PULLUP);
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);


  lightOn = false;
  debounceDelay = 50;

  lastButtonState = 1;
  buttonState = 1;
  Particle.function("setPower", setLampPower);
}

void loop(){
  int reading = digitalRead(D1);


  if (reading != lastButtonState){
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay){
    if (reading != buttonState){
      buttonState = reading;
      if (buttonState == LOW){
        lightOn = !lightOn;
      }
    }
  }

  setLampPower(lightOn);

  lastButtonState = reading;
}

int setLampPower(String status) {
  if (status == "TRUE") {
    digitalWrite(bluePin, TRUE);
    digitalWrite(greenPin, TRUE);
    digitalWrite(redPin, TRUE);
  }
  else if (status == "FALSE") {
    digitalWrite(bluePin, FALSE);
    digitalWrite(greenPin, FALSE);
    digitalWrite(redPin, FALSE);
  }
  else {
    //do nothing
  }
}
