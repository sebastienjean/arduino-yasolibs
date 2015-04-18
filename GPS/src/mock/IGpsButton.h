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

#ifndef IGPSBUTTON_H_
#define IGPSBUTTON_H_
/**
 * Interface defining a button
 */

class IGpsButton {
protected:
	IGpsButton();

public:
	virtual ~IGpsButton();
  /**
   * Get if the button is clicked or not
   * @return true if the button is enabled, false otherwise
   */
	virtual bool IsSet() const=0;
};

#endif /* IGPSBUTTON_H_ */
