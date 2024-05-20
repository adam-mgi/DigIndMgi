#pragma once

#include <Arduino.h>

class DigIndMgi
{
    private:
        int meas_sig_pin_;

    public:
        void Begin(int meas_sig_pin, int baud_rate);
        float Measure();
};