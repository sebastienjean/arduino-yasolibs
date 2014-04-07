/*
  /*
 * Copyright (c) 2013-2014 Sebastien Jean.
 *
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the GNU Lesser Public License v3.0
 * which accompanies this distribution, and is available at
 * http://www.gnu.org/licenses/lgpl-3.0.html
 * Contributors:
 *     Khrisp
 */

#ifndef IGPSTIMEWATCH_H_
#define IGPSTIMEWATCH_H_

/**
 * Interface defining a stopWatch
 */
class IGpsTimeWatch {

protected:
	IGpsTimeWatch();

public:
	virtual ~IGpsTimeWatch();

  /**
   * Get time since the program start
   * @return time in ms
   */
	virtual unsigned long GetMilliseconds() const=0;

};

#endif /* IGPSTIMEWATCH_H_ */
