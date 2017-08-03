
int ALARM_BUTTON_PIN = A3; 
int HOT_LED = 10; // LED pin for "too hot" alarm
int alarm_last_state = 0; //last read on alarm button (analog 0 - 1023)

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinmode(ALARM_BUTTON_PIN, INPUT); 
  pinmode(HOT_LED, OUTPUT);

}

void loop() {
  alarm_current = analogRead(alarm_button_pin);  // read alarm button state
  if (alarm_current >= 1000 && alarm_last_state == 0) { //if alarm button is pressed anew
    digitalWrite(HOT_LED, !digitalRead(HOT_LED));       //toggled the LED state
  }
  alarm_last_state = alarm_current; // refresh button state in memory
}
