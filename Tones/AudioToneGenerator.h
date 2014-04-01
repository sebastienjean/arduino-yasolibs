#ifndef AUDIOTONE_GENERATOR_h
#define AUDIOTONE_GENERATOR_h

#include <Arduino.h>

/**
 * This class allows to generate audio signals on a given output pin
 */
class AudioToneGenerator
{
private:
  /**
   * The pin where to output audio signal
   */
  int outputPin;

public:

  /**
    * Creates a new audio tone generator
    *
    * @param outputPin the pin where to output audio signal
    */
  AudioToneGenerator(int outputPin);

  /**
    * Generates an audio signal, for a given frequency (in Hz) and duration (in ms)
    *
    * @param frequencyInHz the audio signal frequency (in Hz)
    * @param durationInMilliseconds the audio signal duration (in ms)
    */
  void
  generateAudioTone(double frequencyInHz, int durationInMilliseconds);
};

#endif
