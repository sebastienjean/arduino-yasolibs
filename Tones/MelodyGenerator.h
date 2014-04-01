#ifndef MELODY_GENERATOR_h
#define MELODY_GENERATOR_h

#include <NoteGenerator.h>
#include <Note.h>
/**
 * This class allows to generate melodies on a given output pin
 */
class MelodyGenerator
{
private:

  NoteGenerator *noteGenerator;

  int length;

  Note **notes;

public:

  MelodyGenerator(NoteGenerator *noteGenerator);

  void setNotes(int length, Note **notes);

  void
  generateMelody(int pulsationInBeatsPerMinute);

};

#endif
