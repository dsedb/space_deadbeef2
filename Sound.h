/* -*- mode:C++; coding:utf-8-with-signature -*-
 *
 * Sound.h - Project PetitShooter
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
 * since Sun Aug 20 09:38:06 2017
 */
#ifndef	SHOOTER01_SOUND_H_SUN_AUG_20_09_38_06_2017
#define	SHOOTER01_SOUND_H_SUN_AUG_20_09_38_06_2017

#include "SoundPitchDef.h"

namespace UTJ {

class Sound
{
private:
	int pin_;
	int frames_;
public:
	void init();
	void play(int frequency, int frames);
	void update();
	void boot() const;
	void gameStart() const;
};

} // namespace UTJ {
#endif	/* SHOOTER01_SOUND_H_SUN_AUG_20_09_38_06_2017 */
/*
 * End of Sound.h
 */
