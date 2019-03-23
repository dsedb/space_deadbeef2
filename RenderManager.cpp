/* -*- mode:C++; coding:utf-8-with-signature -*-
 *
 * RenderManager.cpp - Project PetitShooter
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
 * since Thu Aug 17 09:25:51 2017
 */
#include <Arduino.h>
#include "RenderManager.h"
#include "Score.h"
#include "Player.h"

namespace UTJ {

RenderManager::RenderManager()
: lcd_(12, 13, 8, 9, 10, 11, 4, 5, 6, 7)
{}

void
RenderManager::init()
{
	lcd_.begin(16, 2);
	lcd_.clear();
	lcd_.setCursor(0, 0);
	memset(buffer_, 0, sizeof(buffer_));
}

void
RenderManager::drawPoint(int x, int y)
{
	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {
		return;
	}
	int cx = x/6;
	int rx = x%6;
	if (rx == 5) {
		return;
	}
	int cy = y/9;
	int ry = y%9;
	if (ry == 8) {
		return;
	}

	int idx = cx+cy*4;
	buffer_[idx][ry] |= (1<<(4-rx));
}

void
RenderManager::begin()
{
	memset(buffer_, 0, sizeof(buffer_));
}

void
RenderManager::end()
{
	for (int idx = 0; idx < 8; ++idx) {
		lcd_.createChar(idx, buffer_[idx]);
	}
	for (int cy = 0; cy < 2; ++cy) {
		lcd_.setCursor(OFFSET_X, cy);
		for (int cx = 0; cx < 4; ++cx) {
			int idx = cx+cy*4;
			lcd_.write((uint8_t)idx);
		}
	}
}
 
void
RenderManager::display(bool homing_mode, int locked_num, int lock_max, const Score& score)
{
	lcd_.setCursor(0, 1);
	for (int i = 0; i < lock_max; ++i) {
		char ch = homing_mode ? ((i < locked_num) ? 0b11011011 : 0b10100001) : ' ';
		lcd_.write(ch);
	}
	char buf[8];
	lcd_.setCursor(5, 0);
	lcd_.write(0xffff);
	lcd_.setCursor(5, 1);
	lcd_.write(0xffff);
	lcd_.setCursor(10, 0);
	snprintf(buf, sizeof(buf), "%c %cGUN", 0xffff, homing_mode ? ' ' : 0b01111110);
	lcd_.print(buf);
	lcd_.setCursor(10, 1);
	snprintf(buf, sizeof(buf), "%c %cHOM", 0xffff, homing_mode ? 0b01111110 : ' ');
	lcd_.print(buf);
	lcd_.setCursor(0, 0);
	snprintf(buf, sizeof(buf), "%05d", score.getValue());
	lcd_.print(buf);
}

void
RenderManager::boot()
{
	lcd_.setCursor(0, 0);
	lcd_.print("SPACE DEADBEEF 2");
	lcd_.setCursor(0, 1);
	lcd_.print("press red button");
}

void
RenderManager::clear()
{
	lcd_.clear();
}

} // namespace UTJ {
/*
 * End of RenderManager.cpp
 */
