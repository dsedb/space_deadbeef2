/* -*- mode:C++; coding:utf-8-with-signature -*-
 *
 * Boss.cpp - Project PetitShooter
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
 * since Sun Aug 20 08:27:46 2017
 */
#include "Arduino.h"
#include "RenderManager.h"
#include "ExplosionManager.h"
#include "Score.h"
#include "Boss.h"

namespace UTJ {

void
Boss::init(int x, int y)
{
	x_ = x;
	y_ = y;
	collider_.init(x_, y_,
				   Real(0) /* offset_x */, Real(0) /* offset_y */,
				   Real(1) /* w */, Real(1) /* h */); 
	lock_collider_.init(x_, y_);
	vx_ = -0.1f;
	vy_ = 0.0f;
	alive_ = true;
	cnt_ = 0;
}

void
Boss::die()
{
	lock_collider_.setMode(LockModeNone);
	alive_ = false;
}

void
Boss::update(ExplosionManager& explosion_manager, Score& score)
{
	vy_ = (float)sin(((float)cnt_)*(10.0f*3.14f/180.0f)) * 0.25f;
	++cnt_;
	if (cnt_ >= 36) {
		cnt_ = 0;
	}

	x_ += vx_;
	y_ += vy_;
	if (x_ < 0) {
		die();
		return;
	}
	if (collider_.isHit()) {
		score.inc(10);
		explosion_manager.spawn(x_, y_);
		die();
		return;
	}
	if (lock_collider_.isHit()) {
		score.inc(10);
		explosion_manager.spawn(x_, y_);
		die();
		return;
	}
	collider_.update(x_, y_);
	lock_collider_.update(x_, y_);
}

void
Boss::render(RenderManager& render_manager)
{
	render_manager.drawPoint(x_, y_);
}

} // namespace UTJ {

/*
 * End of Boss.cpp
 */
