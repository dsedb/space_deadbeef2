/* -*- mode:C++; coding:utf-8-with-signature -*-
 *
 * Sound.cpp - Project PetitShooter
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
 * since Sun Aug 20 09:38:27 2017
 */
#include <Arduino.h>
#include "Sound.h"

namespace UTJ {

void
Sound::init()
{
	pin_ = 16;
	frames_ = 0;
}

void
Sound::play(int frequency, int frames)
{
	if (frames_ > 0) {
		noTone(pin_);
	}
	frames_ = frames;
	tone(pin_, frequency, frames*(1000/30 /* 1000msec/FPS */));
}
	
void
Sound::update()
{
	if (frames_ > 0) {
	    --frames_;
		if (frames_ == 0) {
			noTone(pin_);
		}
	}
}

#define TONE_N(note, length)	{ tone(pin_, NOTE_##note, PITCH*length); }
#define TONE(note, length)	{ TONE_N(note, length); delay(PITCH*length); }

void
Sound::boot() const
{
	static const int PITCH = 1000/8;
	TONE(C5, 1);
	TONE(B4, 1);
	TONE(C5, 1);
	TONE(E5, 1);
	TONE_N(G5, 4);
}

void
Sound::gameStart() const
{
	static const int PITCH = 1000/16;
	TONE(C6, 1);
	TONE(E6, 1);
	TONE_N(G6, 1);
	// TONE(E5, 2);
	// TONE(A5, 2);
	// TONE(B5, 1);
	// TONE(A5, 1);
	// TONE(B5, 1);
	// TONE(D6, 1);
	// TONE_N(C6, 8);
}

} // namespace UTJ {
/*
 * End of Sound.cpp
 */
