#include <ps5.h>
#include <ps5Controller.h>
#include <ps5_int.h>
#define freq 50
#define ESC 23
#define threshold_throttle 1122

uint8_t trigger;
int mapped_trigger;
int throttle;
int delay_low;
int duty;


void setup() {
  // put your setup code here, to run once:
  pinMode(ESC, OUTPUT);
  Serial.begin(115200);
  while(!ps5.isconnected()){
    Serial.println("-------ps5 not connected---------");
  }
  Serial.println("-------ps5 connected---------");
  ledcSetup(0,freq,16);
  ledAttachPin(ESC, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  trigger = ps5.R2();
  trigger_BLDC(trigger);
  duty_cycle();
  ledWrite(0,duty);
}

void trigger_BLDC(uint8_t trigger){
  mapped_trigger = map(trigger, 0,255,0,878);
  throttle = threshold_throttle + mapped_trigger;
}
void duty_cycle(){
  duty = throttle * 65536 / 20000;
}
