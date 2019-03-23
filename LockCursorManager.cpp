/* -*- mode:C++; coding:utf-8-with-signature -*-
 *
 * EnemyManager.cpp - Project PetitShooter
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
 * since Thu Aug 17 11:07:12 2017
 */
#include <string.h>
#include "Debug.h"
#include "LockCursorManager.h"

namespace UTJ {

void
LockCursorManager::init()
{
	for (int i = 0; i < LOCKCURSOR_MAX; ++i) {
		pool_[i].init(Real(0), Real(0), Real(0));
	}
}

void
LockCursorManager::spawn(const Real& x, const Real& y)
{
	LockCursor& lockcursor = pool_[current_idx_];
	lockcursor.init(x, y, Real(20.0f));
	++current_idx_;
	if (current_idx_ >= LOCKCURSOR_MAX) {
		current_idx_ = 0;
	}
}

void
LockCursorManager::update()
{
	for (int i = 0; i < LOCKCURSOR_MAX; ++i) {
		pool_[i].update();
	}
}

void
LockCursorManager::render(const RenderManager& render_manager)
{
	for (int i = 0; i < LOCKCURSOR_MAX; ++i) {
		pool_[i].render(render_manager);
	}
}

} // namespace UTJ {
/*
 * End of LockCursorManager.cpp
 */
