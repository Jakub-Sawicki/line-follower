#include "PID.h"

PID::PID(float Kp, float Kd, float Ki, float dt) : _Kp(Kp), _Kd(Kd), _Ki(Ki), _dt(dt), _integral(0), _last_e(0) {
    ;
}

float PID::calculate(float r, float y) {
    float e = r - y;

    float P = _Kp * e;

    _integral += e;
    float I = _Ki * _integral;

    float derivative = (e - _last_e) / _dt;
    _last_e = e;
    float D = _Kd * derivative;

    float u = P + I + D;

    return u;
}
