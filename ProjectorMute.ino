#include <SoftwareSerial.h>

/*
  Projector Mute
 
 Watches a digital input for state change.
 If gone high to low (external relay on), then send serial command to mute picture.
 Ig gone low to high (external relay off), then send serial command to un-mute picture.
 Uses interupt to detect state change.
 Runs LED blink in loop to show program is running.
 */

int led = 13;     // Pin 13 has the LED attached
int trigger = 2;  // Pin 2 is an input trigger

static byte pjmute[6]   = { 
  0x02,0x10,0x00,0x00,0x00,0x12 };
static byte pjunmute[6] = { 
  0x02,0x11,0x00,0x00,0x00,0x13 };


// the setup routine runs once when you press reset:
void setup() {
  // initialize the serial port
  Serial1.begin(38400);
  // initialize the trigger pin as an input.
  pinMode(trigger, INPUT_PULLUP);  
//pinMode(trigger, OUTPUT);
  // initialize the LED pin as an output.
  pinMode(led, OUTPUT);
  // setup an interupt on a state change on the trigger pin (Interrupt 0)
  attachInterrupt(1,projmute,CHANGE);  
}

// the loop routine runs over and over again forever:
void loop() {
  //digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  //digitalWrite(trigger,HIGH);
  delay(50);                // wait for half a second
  //digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  //digitalWrite(trigger,LOW);
  delay(500);                // wait for half a second
}

// interrupt handler
void projmute() {
  int state;
  state = digitalRead(trigger); 

  if (state == LOW) {
    // send projector video mute string  
    Serial1.write(pjmute,6);
    digitalWrite(led, LOW);
    delay(500);
  }
  else {
    // send projector video unmute string
    Serial1.write(pjunmute,6);
    digitalWrite(led, HIGH);
    delay(500);
  }
}

