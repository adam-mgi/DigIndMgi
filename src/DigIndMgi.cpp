#include <DigIndMgi.h>

/*!
   * @brief Method to call in the setup function to initialize the object
   * @param meas_sig_pin Pin used to start a digital indicator measurement
   * @param baud_rate Baud rate of the USB host communicating with the digital indicator
   * @return no return
   */
void DigIndMgi::Begin(int meas_sig_pin, int baud_rate)
{
    this->meas_sig_pin_ = meas_sig_pin;
    
    //start serial 1 to communicate with the USB host
    Serial1.begin(baud_rate);
    delay(100);

    // set the meas_sig_pin as an output and
    // initialize it to HIGH
    pinMode(meas_sig_pin, OUTPUT);
    digitalWrite(meas_sig_pin, HIGH);
}

/*!
   * @brief Performs a digital indicator measurement
   * @return The measurement as a floating point decimal number
   */
float DigIndMgi::Measure()
{
    //signal the indicator to take a measurement
    digitalWrite( this->meas_sig_pin_, LOW);
    delay(100);
    digitalWrite(this->meas_sig_pin_, HIGH);

    // get the data from the serial port
    String meas_data = "";
    while (Serial1.available())
    {
        delay(2);
        char c = Serial1.read();
        meas_data += c;
    }

    meas_data.trim();
    return meas_data.toFloat();

}
