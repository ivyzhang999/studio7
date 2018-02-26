int lastButtonState;
int debounceDelay;
int lastDebounceTime;
bool lightOn;
int color[] = {255, 255, 255};
int buttonState;

STARTUP(WiFi.selectAntenna(ANT_AUTO));

void setup(){
  Serial.begin(9600);
  pinMode(D0, OUTPUT);
  pinMode(D1, INPUT_PULLUP);


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
    digitalWrite(D0, TRUE);
  }
  else if (status == "FALSE") {
    digitalWrite(D1, FALSE);
  }
  else {
    //do nothing
  }
}
