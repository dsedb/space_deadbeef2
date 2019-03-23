/* -*- mode:C++; coding:utf-8-with-signature -*-
 *
 * Explosion.cpp - Project PetitShooter
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
 * since Thu Aug 17 11:49:53 2017
 */

#include "RenderManager.h"
#include "Explosion.h"

namespace UTJ {

void
Explosion::init(const Real& x, const Real& y)
{
	x_ = x;
	y_ = y;
	phase_ = 0;
}

void
Explosion::update()
{
	if (phase_ >= 0) {
		++phase_;
	}
}

void
Explosion::render(const RenderManager& render_manager)
{
	switch (phase_) {
	case 0:
		// FALLTHROUGH
	case 1:
		// FALLTHROUGH
	case 2:
		render_manager.drawPoint(x_, y_-1);
		render_manager.drawPoint(x_, y_+1);
		render_manager.drawPoint(x_-1, y_);
		render_manager.drawPoint(x_+1, y_);
		break;
	case 3:
	case 4:
		render_manager.drawPoint(x_-1, y_-1);
		render_manager.drawPoint(x_+1, y_-1);
		render_manager.drawPoint(x_-1, y_+1);
		render_manager.drawPoint(x_+1, y_+1);
		break;
	case 5:
	case 6:
		render_manager.drawPoint(x_-2, y_-2);
		render_manager.drawPoint(x_+2, y_-2);
		render_manager.drawPoint(x_-2, y_+2);
		render_manager.drawPoint(x_+2, y_+2);
		break;
	case 7:
	case 8:
		render_manager.drawPoint(x_-3, y_-3);
		render_manager.drawPoint(x_+3, y_-3);
		render_manager.drawPoint(x_-3, y_+3);
		render_manager.drawPoint(x_+3, y_+3);
		break;
	default:
		phase_ = -1;
		break;
	}
}

} // namespace UTJ {
/*
 * End of Explosion.cpp
 */
