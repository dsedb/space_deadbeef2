/* -*- mode:C++; coding:utf-8-with-signature -*-
 *
 * InputManager.cpp - Project PetitShooter
 *
 * Copyright (c) 2017 Yuji YASUHARA
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * since Thu Aug 17 09:50:43 2017
 */
#include <Arduino.h>
#include "Debug.h"
#include "InputManager.h"

namespace UTJ {

InputManager::InputManager()
: up_(0)
, down_(0)
, fire_(0)
, switch_(0)
, prev_up_(0)
, prev_down_(0)
, prev_fire_(0)
, prev_switch_(0)
{}
	
void
InputManager::init()
{
	pinMode(UP_PIN, INPUT);
	pinMode(DOWN_PIN, INPUT);
	pinMode(FIRE_PIN, INPUT);
	pinMode(SWITCH_PIN, INPUT);
}

void
InputManager::fetch()
{
	prev_up_ = up_;
	prev_down_ = down_;
	prev_fire_ = fire_;
	prev_switch_ = switch_;
	up_ = digitalRead(UP_PIN);
	down_ = digitalRead(DOWN_PIN);
	fire_ = digitalRead(FIRE_PIN);
	switch_ = digitalRead(SWITCH_PIN);
}

void
InputManager::boot() const
{
	while (digitalRead(FIRE_PIN) == 0) {
		delay(100);
	}
}

} // namespace UTJ {
/*
 * End of InputManager.cpp
 */
