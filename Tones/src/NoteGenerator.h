#ifndef NOTE_GENERATOR_h
#define NOTE_GENERATOR_h

#include <AudioToneGenerator.h>
#include<Note.h>

/**
 * This class allows to play notes using a given audioToneGenerator.
 */
class NoteGenerator
{
private:

  /**
   * The audio tone generator used to generates audio signals corresponding to notes
   */
  AudioToneGenerator *audioToneGenerator;

  /**
   * Utility method used to calculate absolute durations of notes, given a relative duration and a BPM
   */
  static int
  getDurationInMillis(double relativeDuration, int pulsationInBeatsPerMinute);

public:


  /**
    * Creates a new note generator, for a given underlying audio tone generator
    *
    * @param audioToneGenerator the audio tone generator to use
    */
  NoteGenerator(AudioToneGenerator *audioToneGenerator);

  /**
   * Generates the audio signal corresponding to a note, for a given BPM
   * @param note the note to play
   * @param pulsationInBeatsPerMinute the BPM
   */
  void
  generateNote(Note *note, int pulsationInBeatsPerMinute);
};

#endif
