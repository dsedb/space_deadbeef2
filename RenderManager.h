/* -*- mode:C++; coding:utf-8-with-signature -*-
 *
 * RenderManager.h - Project PetitShooter
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
 * since Thu Aug 17 09:23:13 2017
 */
#ifndef	SHOOTER01_RENDERMANAGER_H_THU_AUG_17_09_23_13_2017
#define	SHOOTER01_RENDERMANAGER_H_THU_AUG_17_09_23_13_2017

#include "LiquidCrystal.h"
#include "Real.h"

namespace UTJ {

class Player;
class Score;

class RenderManager
{
private:
	static const int SCREEN_WIDTH = 23;
	static const int SCREEN_HEIGHT = 17;
	static const int OFFSET_X = 6;
	LiquidCrystal lcd_;
	int8_t buffer_[8][8];

public:
	RenderManager();
	static int getScreenWidth() { return SCREEN_WIDTH; }
	static int getScreenHeight() { return SCREEN_HEIGHT; }
	void init();
	void begin();
	void end();
	void drawPoint(int x, int y);
	void drawPoint(const Real& x, const Real& y) { drawPoint((int)x, (int)y); }
	void drawPoint(int x, const Real& y) { drawPoint(x, (int)y); }
	void display(bool homing_mode, int locked_num, int lock_max, const Score& score);
	void boot();
	void clear();
};

} // namespace UTJ {
#endif	/* SHOOTER01_RENDERMANAGER_H_THU_AUG_17_09_23_13_2017 */
/*
 * End of RenderManager.h
 */
