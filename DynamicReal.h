/* -*- mode:C++; coding:utf-8-with-signature -*-
 *
 * DynamicReal.h - Project PetitShooter
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
 * since Fri Aug 18 16:43:41 2017
 */
#ifndef	SHOOTER01_DYNAMICFIXED_H_FRI_AUG_18_16_43_41_2017
#define	SHOOTER01_DYNAMICFIXED_H_FRI_AUG_18_16_43_41_2017

#include "Real.h"

namespace UTJ {

class DynamicReal
{
private:
	static const Real DT;
	Real position_;
	Real velocity_;
	Real acceleration_;

public:
	static const Real& getDT() { return DT; }
	DynamicReal() : position_(0), velocity_(0), acceleration_(0) {}
	DynamicReal(const Real& position) : position_(position), velocity_(0), acceleration_(0) {}
	DynamicReal& operator=(const Real& value) { position_ = value; return *this; }
	DynamicReal& operator=(int value) { position_ = Real(value); return *this; }
	DynamicReal& operator=(float value) { position_ = Real(value); return *this; }
	const Real& getValue() const { return position_; }
	void setVelocity(const Real v) { velocity_ = v; }
	void addForce(const Real& force) { acceleration_ += force; }
	void addSpringForce(const Real& target, const Real& ratio);
	void setForceArrivalTime(const Real& target, const Real& arrival_time);
	void update();
};

} // namespace UTJ {
#endif	/* SHOOTER01_DYNAMICFIXED_H_FRI_AUG_18_16_43_41_2017 */
/*
 * End of DynamicReal.h
 */
