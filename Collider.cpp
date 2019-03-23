/* -*- mode:C++; coding:utf-8-with-signature -*-
 *
 * Collider.cpp - Project PetitShooter
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

#include "Collider.h"

namespace UTJ {

void
Collider::init(const Real& x, const Real& y,
			   const Real& offset_x, const Real& offset_y,
			   const Real& w, const Real& h)
{
	x_ = x;
	y_ = y;
	offset_x_ = offset_x;
	offset_y_ = offset_y;
	w_ = w;
	h_ = h;
	hit_ = false;
}

void
Collider::update(const Real& x, const Real& y)
{
	x_ = x;
	y_ = y;
	hit_ = false;
}

void
Collider::check(Collider& another)
{
	if (getLeftForComparison() < another.getRightForComparison() &&
		another.getLeftForComparison() < getRightForComparison() &&
		getTopForComparison() < another.getBottomForComparison() &&
		another.getTopForComparison() < getBottomForComparison()) {
		hit_ = true;
		another.hit_ = true;
	}
}

} // namespace UTJ {
/*
 * End of Collider.cpp
 */
