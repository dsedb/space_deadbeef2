/* -*- mode:C++; coding:utf-8-with-signature -*-
 *
 * LockCollider.h - Project PetitShooter
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
 * since Thu Aug 17 14:56:44 2017
 */
#ifndef	SHOOTER01_LOCKCOLLIDER_H_THU_AUG_17_14_56_44_2017
#define	SHOOTER01_LOCKCOLLIDER_H_THU_AUG_17_14_56_44_2017

#include "Real.h"

namespace UTJ {

class LockCursorManager;

enum LockMode
{
	LockModeNone,
	LockModeActive,
	LockModeLocked,
	LockModeChased,
	LockModeHit,
};

class LockCollider
{
private:
	Real x_;
	Real y_;
	LockMode mode_;

public:
	const Real& getX() const { return x_; }
	const Real& getY() const { return y_; }
	void init(const Real& x, const Real& y);
	void update(const Real& x, const Real& y);
	LockMode getMode() const { return mode_; }
	void setMode(LockMode mode) { mode_ = mode; }
	bool check(const Real& searching_y, const Real& height, LockCursorManager& lockcursor_manager);
	void hit() { mode_ = LockModeHit; }
	bool isHit() const { return mode_ == LockModeHit; }
};

} // namespace UTJ {
#endif	/* SHOOTER01_LOCKCOLLIDER_H_THU_AUG_17_14_56_44_2017 */
/*
 * End of LockCollider.h
 */
