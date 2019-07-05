#include <stdint.h>

enum GP2YDustSensorType
{
    GP2Y1010AU0F,
    GP2Y1014AU0F
};

class GP2YDustSensor
{
    private:
        GP2YDustSensorType type;
        uint32_t maxAdc;
        uint8_t ledOutputPin;
        uint8_t analogReadPin;
        float zeroDustVoltage;
        float calibrationFactor;
        float sensitivity;
        int *runningAverageBuffer;
        int runningAverageCount;
        int nextRunningAverageCounter;
        int runningAverageCounter;

    protected:
        uint16_t readDustRawOnce();
        void updateRunningAverage(uint16_t dustDensity);

    public:
        GP2YDustSensor(GP2YDustSensorType type, uint8_t ledOutputPin, uint8_t analogReadPin, uint16_t runningAverageCount = 60);
        ~GP2YDustSensor();
        void begin();
        uint16_t getDustDensity(uint16_t numSamples = 20);
        uint16_t getRunningAverage();
        float getBaseline();
        void setBaseline(float zeroDustVoltage);
        void setSensitivity(float sensitivity);
        float getSensitivity();
        void setCalibrationFactor(float slope);
};