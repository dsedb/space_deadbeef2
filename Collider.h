/* -*- mode:C++; coding:utf-8-with-signature -*-
 *
 * Collider.h - Project PetitShooter
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
#ifndef	SHOOTER01_COLLIDER_H_THU_AUG_17_14_56_44_2017
#define	SHOOTER01_COLLIDER_H_THU_AUG_17_14_56_44_2017

#include "Real.h"

namespace UTJ {

class Collider
{
private:
	Real x_;
	Real y_;
	Real offset_x_;
	Real offset_y_;
	Real w_;
	Real h_;
	bool hit_;
public:
	void init(const Real& x, const Real& y, const Real& offset_x, const Real& offset_y, const Real& w, const Real& h);
	void update(const Real& x, const Real& y);
	void check(Collider& another);
	bool isHit() const { return hit_; }
	int getLeftForComparison() const { return x_.getRawValue() + offset_x_.getRawValue(); }
	int getRightForComparison() const { return x_.getRawValue() + offset_x_.getRawValue() + w_.getRawValue(); }
	int getTopForComparison() const { return y_.getRawValue() + offset_y_.getRawValue(); }
	int getBottomForComparison() const { return y_.getRawValue() + offset_y_.getRawValue() + h_.getRawValue(); }
};


} // namespace UTJ {
#endif	/* SHOOTER01_COLLIDER_H_THU_AUG_17_14_56_44_2017 */
/*
 * End of Collider.h
 */
