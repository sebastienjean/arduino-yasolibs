#include <Arduino.h>
#include <AudioToneGenerator.h>
#include <NoteGenerator.h>
#include <Note.h>

int
NoteGenerator::getDurationInMillis(double relativeDuration, int pulsationInBeatsPerMinute)
{
  return (int) ((relativeDuration / (pulsationInBeatsPerMinute/60)) * 1000.0);
}

NoteGenerator::NoteGenerator(AudioToneGenerator *audioToneGenerator)
{
  this->audioToneGenerator = audioToneGenerator;
}

void
NoteGenerator::generateNote(Note *note, int pulsationInBeatsPerMinute)
{
  int noteDurationInMilliseconds = getDurationInMillis(note->getRelativeDuration(), pulsationInBeatsPerMinute);
  if (note->isSilence())
    delay(noteDurationInMilliseconds);
  else
    this->audioToneGenerator->generateAudioTone(note->getFrequencyInHz(), noteDurationInMilliseconds);
}

