#include <ps5.h>
#include <ps5Controller.h>
#include <ps5_int.h>

#define ESC 23
#define threshold_throttle 1122
uint8_t trigger;
int mapped_trigger;
int throttle;
int delay_low;


void setup() {
  // put your setup code here, to run once:
  pinMode(ESC, OUTPUT);
  Serial.begin(115200);
  while(!ps5.isconnected()){
    Serial.println("-------ps5 not connected---------");
  }
  Serial.println("-------ps5 connected---------");
}

void loop() {
  // put your main code here, to run repeatedly:
  trigger = ps5.R2();
  BLDC(trigger);

}

void BLDC(uint8_t trigger){
  mapped_trigger = map(trigger, 0,255,0,878);
  throttle = threshold_throttle + mapped_trigger;
  delay_low = 20000 - throttle;

  digitalWrite(ESC, HIGH);
  delayMicroSeconds(throttle);
  digitalWrite(ESC, LOW);
  delayMicroSeconds(delay_low);
}
