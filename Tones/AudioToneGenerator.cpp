#include <Arduino.h>
#include <AudioToneGenerator.h>

AudioToneGenerator::AudioToneGenerator(int outputPin)
{
  this->outputPin = outputPin;
  pinMode(this->outputPin, OUTPUT);
}

void
AudioToneGenerator::generateAudioTone(double frequencyInHz, int durationInMilliseconds)
{
  boolean outputPinState = LOW;

  uint16_t halfPeriodDurationInMicroseconds = (1000000.0 /  (frequencyInHz * 2));
  uint16_t numberOfHalfPeriods =  ((1000.0 * durationInMilliseconds) / halfPeriodDurationInMicroseconds);

  for (uint16_t halfPeriodNumber = 0; halfPeriodNumber < numberOfHalfPeriods; halfPeriodNumber++)
  {
    outputPinState = !outputPinState;
    digitalWrite(this->outputPin, outputPinState);
    delayMicroseconds(halfPeriodDurationInMicroseconds);
  }
}

