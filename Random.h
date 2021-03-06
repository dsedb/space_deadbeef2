﻿/* -*- mode:C++; coding:utf-8-with-signature -*-
 *
 * Random.h - Project PetitShooter
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
 * since Thu Aug 17 12:32:43 2017
 */
#ifndef	SHOOTER01_RANDOM_H_THU_AUG_17_12_32_43_2017
#define	SHOOTER01_RANDOM_H_THU_AUG_17_12_32_43_2017

#include <inttypes.h>
#include "Real.h"

namespace UTJ {

class Random
{
private:
	int32_t x_;
	int32_t y_;
	int32_t z_;
	int32_t w_;

public:
	void seed(int value);
	int32_t get();
	int getRange(int inclusive_min, int exclusive_max);
	Real getRange(const Real& inclusive_min, const Real& exclusive_max) {
		int value = getRange(inclusive_min.getRawValue(),
							 exclusive_max.getRawValue());
		Real r;
		r.setRawValue(value);
		return r;
	}
	Real getRange(float inclusive_min, float exclusive_max) {
		return getRange(Real(inclusive_min), Real(exclusive_max));
	}
};

} // namespace UTJ {
#endif	/* SHOOTER01_RANDOM_H_THU_AUG_17_12_32_43_2017 */
/*
 * End of Random.h
 */
