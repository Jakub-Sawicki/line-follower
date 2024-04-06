#ifndef CONFIG_H
#define CONFIG_H

unsigned int SENSOR_PIN[8] = {26, 27, 32, 33, 34, 35, 36, 39};  //from left to right
unsigned int MOTOR_PIN[2] = {23, 25};  //left - right
unsigned int ENCODER_A_PIN[2] = {};
unsigned int ENCODER_B_PIN[2] = {};

int sensor_weight[8] = {-8, -4, -2, -1, 1, 2, 4, 8};

#define MAX_OUTPUT 255
#define DETECTION_THERSHOLD 122

#endif // CONFIG_H