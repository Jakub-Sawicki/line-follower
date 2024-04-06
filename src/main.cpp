#include <Arduino.h>

#include "PID.h"
#include "config.h"

void setup() {
  Serial.begin(115200);

  for(int i = 0; i < 8; i++) {
    pinMode(SENSOR_PIN[i], INPUT);
  }
  
  pinMode(MOTOR_PIN[0], OUTPUT);
  pinMode(MOTOR_PIN[1], OUTPUT);
}

void loop() {
  //getting sensor information
  static int sensor_state[8];
  static int last_sensor_state[8] = {0, 0, 0, 0, 0, 0, 0, 0};

  for(int i = 0; i < 8; i++) {
    if(analogRead(SENSOR_PIN[i]) >= DETECTION_THERSHOLD) {
      sensor_state[i] = 1;
    }
    else {
      sensor_state[i] = 0;
    }
  }

  // calculating robot state
  static int robot_state = 0;
  int detections = detection_amount(sensor_state);

  if(detections == 8) {
    robot_state = 6;  // crossed another path
  }
  else if(detections >= 3) {  // 90 degree turn
    if(sensor_state[1] == 1) {
      robot_state = 5;  // 90 degree turn to the left
    }
    else if(sensor_state[6] == 1) {
      robot_state = 4;  // 90 degree turn to the right
    }
  }
  else if(detections == 0) {  // lost path
    if(last_sensor_state[0] == 1) {
      robot_state = 2;  // went to the right of the path
    }
    else if(last_sensor_state[7] == 1) {
      robot_state = 3;  // went to the left of the path
    }
  }
  else { 
    robot_state = 1;  // normal operations
  }

  // performing action based on the robot state
  if(robot_state == 1) {

  }
  else if (robot_state == 2) {

  }
  else if (robot_state == 3) {
    
  }
  else if (robot_state == 4) {
    
  }
  else if (robot_state == 5) {
    
  }
  else if (robot_state == 6) {
    
  }
  else if (robot_state == 7) {
    
  }
}





int detection_amount(int sensor_state[]) {
  int detections = 0;

  for(int i = 0; i < 8; i++) {
    if(sensor_state[i] == 1) {
      detections++;
    }
  }

  return detections;
}
