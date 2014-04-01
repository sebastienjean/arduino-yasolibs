#include <Note.h>

Note::Note(int pitchID, int octave, int relativeDurationID) : pitchID(pitchID), octave(octave), relativeDurationID(relativeDurationID)
{
}

boolean Note::isSilence()
{
  return (this->pitchID == Note::SILENCE);
}

static double multiplyFrequencyByAGivenFactorAGivenNumberOfTimes(double baseFrequencyInHz, double factor, int times)
{
  double frequencyInHz = baseFrequencyInHz;
    while (times-- > 0)
      frequencyInHz *= factor;
    return frequencyInHz;
}

double
Note::getBaseFrequencyInHz()
{
  if (this->isSilence()) return 0.0;
  return multiplyFrequencyByAGivenFactorAGivenNumberOfTimes(Note::FREQ_C0, Note::HALF_TONE_FACTOR, this->pitchID);
}

double
Note::getFrequencyInHz()
{
  return multiplyFrequencyByAGivenFactorAGivenNumberOfTimes(this->getBaseFrequencyInHz(), 2, this->octave);
}

double
Note::getRelativeDuration()
{
  int relativeDurationID = this->relativeDurationID;
  double baseRelativeDuration = Note::OCTUPLE_WHOLE_RELATIVE_DURATION;
  while (relativeDurationID-- > 0)
    baseRelativeDuration /= 2;
  return baseRelativeDuration;
}
