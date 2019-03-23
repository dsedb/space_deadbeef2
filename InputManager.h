/* -*- mode:C++; coding:utf-8-with-signature -*-
 *
 * InputManager.h - Project PetitShooter
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
 * since Thu Aug 17 09:48:27 2017
 */
#ifndef	SHOOTER01_INPUTMANAGER_H_THU_AUG_17_09_48_27_2017
#define	SHOOTER01_INPUTMANAGER_H_THU_AUG_17_09_48_27_2017

#include <inttypes.h>

namespace UTJ {

class InputManager
{
private:
	static const int UP_PIN = 19;
	static const int DOWN_PIN = 18;
	static const int FIRE_PIN = 14;
	static const int SWITCH_PIN = 15;
	
	int8_t up_;
	int8_t down_;
	int8_t fire_;
	int8_t switch_;
	int8_t prev_up_;
	int8_t prev_down_;
	int8_t prev_fire_;
	int8_t prev_switch_;

public:
	InputManager();
	void init();
	void fetch();
	bool isUp() const { return up_ != 0; }
	bool isDown() const { return down_ != 0; }
	bool isFire() const { return fire_ != 0; }
	bool isFireDown() const { return fire_ != 0 && prev_fire_ == 0; }
	bool isFireUp() const { return fire_ == 0 && prev_fire_ != 0; }
	bool isSwitchDown() const { return switch_ != 0 && prev_switch_ == 0; }
	void boot() const;
};

} // namespace UTJ {
#endif	/* SHOOTER01_INPUTMANAGER_H_THU_AUG_17_09_48_27_2017 */
/*
 * End of InputManager.h
 */
