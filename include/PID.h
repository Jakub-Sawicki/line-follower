#ifndef PID_H
#define PID_H

class PID {
    public:
        PID(float Kp, float Kd, float Ki, float dt);
        float calculate(float r, float y);

    private:
        float _Kp, _Kd, _Ki;
        float _integral, _last_e, _dt;
};

#endif // PID_H