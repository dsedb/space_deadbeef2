/* -*- mode:C++; coding:utf-8-with-signature -*-
 *
 * Bullet.cpp - Project PetitShooter
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
 * since Thu Aug 17 11:04:47 2017
 */
#include "RenderManager.h"
#include "Bullet.h"

namespace UTJ {

void
Bullet::init(const Real& x, const Real& y)
{
	x_ = x;
	y_ = y;
	collider_.init(x_, y_,
				   Real(-2) /* offset_x */, Real(-1) /* offset_y */,
				   Real(2) /* w */, Real(2) /* h */);
	vx_ = 0.8f;
	alive_ = true;
}

void
Bullet::update()
{
	x_ += vx_;
	if (x_ >= RenderManager::getScreenWidth()) {
		alive_ = false;
		return;
	}
	if (collider_.isHit()) {
		alive_ = false;
		return;
	}
	collider_.update(x_, y_);
}

void
Bullet::render(const RenderManager& render_manager)
{
	render_manager.drawPoint(x_, y_-1);
	render_manager.drawPoint(x_, y_);
}

} // namespace UTJ {
/*
 * End of Bullet.cpp
 */
