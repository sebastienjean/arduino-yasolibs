#include <Arduino.h>

#include <MelodyGenerator.h>
#include <NoteGenerator.h>
#include <Note.h>

MelodyGenerator::MelodyGenerator(NoteGenerator *noteGenerator)
{
  this->noteGenerator = noteGenerator;
  this->length = 0;
  this->notes = NULL;
}

void
MelodyGenerator::setNotes(int length, Note **notes)
{
  this->length = length;
  this->notes = notes;
}

void
MelodyGenerator::generateMelody(int pulsationInBeatsPerMinute)
{
  for (int noteNumber = 0; noteNumber < this->length; noteNumber++)
    this->noteGenerator->generateNote(notes[noteNumber], pulsationInBeatsPerMinute);
}
