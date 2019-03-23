/* -*- mode:C++; coding:utf-8-with-signature -*-
 *
 * DynamicReal.cpp - Project PetitShooter
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
 * since Fri Aug 18 16:44:12 2017
 */
#include "Debug.h"
#include "DynamicReal.h"

namespace UTJ {

const Real DynamicReal::DT(1.0f/30.0f);

void
DynamicReal::addSpringForce(const Real& target, const Real& ratio)
{
	Real diff = position_ - target;
	acceleration_ += ratio.preshiftOperatorMul(diff);
}

void
DynamicReal::setForceArrivalTime(const Real& target, const Real& arrival_time)
{
	Real diff = target - position_;
	acceleration_ = ((diff/arrival_time - velocity_)*2)/arrival_time;
}

void
DynamicReal::update()
{
	velocity_ += acceleration_.preshiftOperatorMul(DT);
	position_ += velocity_.preshiftOperatorMul(DT);
	acceleration_ = 0;
}

} // namespace UTJ {
/*
 * End of DynamicReal.cpp
 */
