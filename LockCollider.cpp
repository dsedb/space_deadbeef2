/* -*- mode:C++; coding:utf-8-with-signature -*-
 *
 * LockCollider.cpp - Project PetitShooter
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
 * since Thu Aug 17 14:57:32 2017
 */

#include "Debug.h"
#include "LockCollider.h"
#include "LockCursorManager.h"

namespace UTJ {

void
LockCollider::init(const Real& x, const Real& y)
{
	x_ = x;
	y_ = y;
	mode_ = LockModeActive;
}

void
LockCollider::update(const Real& x, const Real& y)
{
	x_ = x;
	y_ = y;
}

bool
LockCollider::check(const Real& searching_y, const Real& height, LockCursorManager& lockcursor_manager)
{
	if (mode_ != LockModeActive) {
		return false;
	}
	Real up = searching_y - height/2;
	Real down = searching_y + height/2;
	bool hit = (up <= y_ && y_ <= down);
	if (hit) {
		mode_ = LockModeLocked;
		lockcursor_manager.spawn(x_, y_);
	}
	return hit;
}

} // namespace UTJ {
/*
 * End of LockCollider.cpp
 */
