/*
 * Copyright (c) 2013 Sebastien Jean.
 *
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the GNU Lesser Public License v3.0
 * which accompanies this distribution, and is available at
 * http://www.gnu.org/licenses/lgpl-3.0.html
 *
 * Contributors:
 *     Sebastien Jean - initial API and implementation
 */

#ifndef FCOEV2_h
#define FCOEV2_h

#include <inttypes.h>

/**
 * Milliseconds to wait after calling <tt>switchToNextMode</tt> in order to be sure that
 * camera has correctly process the order
 */
#define SWITCH_MODE_PAUSE_MILLIS 1000

/**
 * Number of periods (20ms) of IDLE signal.
 */
#define IDLE_PERIODS 25

/**
 * Number of periods (20ms) of ACTION signal.
 */
#define ACTION_PERIODS 25

/**
 * Number of periods (20ms) of CHANGE_MODE signal.
 */
#define CHANGE_MODE_PERIODS 200

/**
 * Width, in microseconds, of IDLE pulse.
 */
#define IDLE_HIGH_MICROS 1500

/**
 * PWM period, in milliseconds.
 */
#define PERIOD_MILLIS 20

/**
 * Width, in microseconds, of ACTION/CHANGE_MODE pulse.
 */
#define ACTION_OR_MODE_HIGH_MICROS 2000

typedef enum
{
  MODE_VIDEO = 0,     //!< Video mode
  MODE_PHOTO_SERIAL = 1,     //!< Serial photo mode
  MODE_PHOTO_SINGLE = 2     //!< Single photo mode
} FCOEV2_mode_status_enum;

/**
 * A FCOEV2 camera, attached to a given digital output.
 */
class FCOEV2
{
private:
  // per object data
  /**
   * Current mode
   */
  FCOEV2_mode_status_enum mode;

  /**
   * Running status
   */
  boolean running;

  /**
   * Pin used as output for PWM signal
   */
  uint8_t pwmPin;

private:
  // private methods

  /**
   * Sending idle signal.
   */
  void
  idle();

  /**
   * Sending a custom signal, corresponding to a given pulse width repeated a given time.
   * @param pulseWidthMicros the pulse width in microseconds
   * @param periods the number of periods to generate
   */
  void
  signal(uint16_t pulseWidthMicros, uint8_t periods);

public:
  // public methods
  /**
   * Creates a new FCOEV2 instance, using digital IO <tt>pwmPin</tt> for PWM output.
   * @param pwmPin digital IO where FCOEV2 is attached
   */
  FCOEV2(uint8_t pwmPin);

  /**
   * Resets FCOEV2 instance mode to MODE_VIDEO
   */
  void
  resetMode();

  /**
   * Toggles (on/off) the action associated to current mode.
   */
  void
  toggleAction();

  /**
   * Switches to next operating mode.
   */
  void
  switchToNextMode();

  /**
   * Switches to given operating mode.
   * @param mode mode to switch to
   */
  void
  switchToMode(FCOEV2_mode_status_enum mode);

  /**
   * Returns the current operating mode.
   */
  FCOEV2_mode_status_enum
  getCurrentMode();

  /**
   * Returns running status, i.e. if action has been toggled on
   * (this applies only to MODE_VIDEO and MODE_PHOTO_SERIAL).
   *
   * @return <tt>true</tt> if action is in progress
   */
  boolean
  getRunningStatus();
};
#endif
