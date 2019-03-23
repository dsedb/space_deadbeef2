/* -*- mode:C++; coding:utf-8-with-signature -*-
 *
 * Random.cpp - Project PetitShooter
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
 * since Thu Aug 17 12:33:10 2017
 */
#include "Random.h"

namespace UTJ {

void
Random::seed(int value)
{
	x_ = value;
	y_ = x_ * 1812433253 + 1;
	z_ = y_ * 1812433253 + 1;
	w_ = z_ * 1812433253 + 1;
}

int32_t
Random::get()
{
	int32_t t = x_ ^ (x_<<11);
	x_ = y_;
	y_ = z_;
	z_ = w_;
	w_ = (w_ ^ (w_>>19)) ^ (t ^ (t>>8));
	return w_;
}

int
Random::getRange(int inclusive_min, int exclusive_max)
{
	int32_t v = get();
	int diff = exclusive_max - inclusive_min;
	v %= diff;
	v += inclusive_min;
	return (int)v;
}

} // namespace UTJ {
/*
 * End of Random.cpp
 */
