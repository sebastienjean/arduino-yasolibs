#ifndef NOTE_h
#define NOTE_h

#include <core/Arduino.h>

/**
 * This class allows to handle notes
 */
class Note
{

private:

  /**
   * Returns the base frequency (in Hz) of the note
   * @return
   */
  double
  getBaseFrequencyInHz();

public:

  /**
   * Constant representing the frequency of C0
   */
  static const double FREQ_C0 = 16.352;

  /**
   * Constant representing gap between two half-tones (in multiple of frequency)
   */
  static const double HALF_TONE_FACTOR = 1.0594631;

  /**
   * Constant reprsenting the octuple whole relative duration, in multiple of quarters
   */
  static const double OCTUPLE_WHOLE_RELATIVE_DURATION = 32.0;

  /**
   * Constant representing a silence note
   */
  static const int SILENCE = -1;

  /**
   * Constant representing a C note
   */
  static const int C = 0;

  /**
   * Constant representing a C sharp note
   */
  static const int C_SHARP = 1;

  /**
   * Constant representing a D flat note
   */
  static const int D_FLAT = 1;

  /**
   * Constant representing a D note
   */
  static const int D = 2;

  /**
   * Constant representing a D sharp note
   */
  static const int D_SHARP = 3;

  /**
   * Constant representing a E flat note
   */
  static const int E_FLAT = 3;

  /**
   * Constant representing a E note
   */
  static const int E = 4;

  /**
   * Constant representing a F note
   */
  static const int F = 5;

  /**
   * Constant representing a F sharp note
   */
  static const int F_SHARP = 6;

  /**
   * Constant representing a G flat note
   */
  static const int G_FLAT = 6;

  /**
   * Constant representing a G note
   */
  static const int G = 7;

  /**
   * Constant representing a G sharp note
   */
  static const int G_SHARP = 8;

  /**
   * Constant representing a A flat note
   */
  static const int A_FLAT = 8;

  /**
   * Constant representing a A note
   */
  static const int A = 9;

  /**
   * Constant representing a A sharp note
   */
  static const int A_SHARP = 10;

  /**
   * Constant representing a B flat note
   */
  static const int B_FLAT = 10;

  /**
   * Constant representing a B note
   */
  static const int B = 11;

  /**
   * Constant representing the identifier of a octuple whole relative duration
   */
  static const int OCTUPLE_WHOLE = 0;

  /**
   * Constant representing the identifier of a quadruple whole relative duration
   */
  static const int QUADRUPLE_WHOLE = 1;

  /**
   * Constant representing the identifier of a double whole relative duration
   */
  static const int DOUBLE_WHOLE = 2;

  /**
   * Constant representing the identifier of a  whole relative duration
   */
  static const int WHOLE = 3;

  /**
   * Constant representing the identifier of a half  relative duration
   */
  static const int HALF = 4;

  /**
   * Constant representing the identifier of a quarter relative duration
   */
  static const int QUARTER = 5;

  /**
   * Constant representing the identifier of a eighth relative duration
   */
  static const int EIGHTH = 6;

  /**
   * Constant representing the identifier of a sixteenth relative duration
   */
  static const int SIXTEENTH = 7;

  /**
   * Constant representing the identifier of a thirty second relative duration
   */
  static const int THIRTY_SECOND = 8;

  /**
   * Constant representing the identifier of a sixty fourth relative duration
   */
  static const int SIXTY_FOURTH = 9;

  /**
   * Constant representing the identifier of a hundred twenty eighth relative duration
   */
  static const int HUNDRED_TWENTY_EIGHTH = 10;

  /**
   * Constant representing the identifier of a two hundred sixty fourth relative duration
   */
  static const int TWO_HUNDRED_SIXTY_FOURTH = 11;

  /**
   * The identifier of the pitch of the note
   */
  const int pitchID;

  /**
   * The octave of the note
   */
  const int octave;

  /**
   * The identifier of the relative duration of the note
   */
  const int relativeDurationID;

  /**
   * Creates a new note, for given pitch identifier, octave and relative duration identifier
   * @param pitchID the pitch identifier
   * @param octave the octave
   * @param relativeDurationID the relative duration identifier
   */
  Note(int pitchID, int octave, int relativeDurationID);

  /**
   * Indicates if the note is a silence
   * @return
   */
  boolean
  isSilence();

  /**
   * Returns the note frequency (in Hz)
   * @return the note frequency (in Hz)
   */
  double
  getFrequencyInHz();

  /**
   * Returns the note relative duration (in multiple of quarters, so in [1/64, 32])
   * @return the note  relative duration (in multiple of quarters)
   */
  double
  getRelativeDuration();

};

#endif
