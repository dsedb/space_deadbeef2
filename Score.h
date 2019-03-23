/* -*- mode:C++; coding:utf-8-with-signature -*-
 *
 * Score.h - Project PetitShooter
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
 * since Thu Aug 17 15:34:06 2017
 */
#ifndef	SHOOTER01_SCORE_H_THU_AUG_17_15_34_06_2017
#define	SHOOTER01_SCORE_H_THU_AUG_17_15_34_06_2017

namespace UTJ {

class Score
{
private:
	int16_t score_;

public:
	void reset() { score_ = 0; }
	void inc(int value) { score_ += value; }
	int getValue() const { return score_; }
};

} // namespace UTJ {
#endif	/* SHOOTER01_SCORE_H_THU_AUG_17_15_34_06_2017 */
/*
 * End of Score.h
 */
