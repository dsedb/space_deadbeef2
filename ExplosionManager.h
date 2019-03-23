/* -*- mode:C++; coding:utf-8-with-signature -*-
 *
 * ExplosionManager.h - Project PetitShooter
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
 * since Thu Aug 17 11:06:04 2017
 */
#ifndef	SHOOTER01_EXPLOSIONMANAGER_H_THU_AUG_17_11_06_04_2017
#define	SHOOTER01_EXPLOSIONMANAGER_H_THU_AUG_17_11_06_04_2017

#include "Explosion.h"

namespace UTJ {

class RenderManager;

class ExplosionManager
{
private:
	static const int EXPLOSION_MAX = 4;
	Explosion pool_[EXPLOSION_MAX];
	int current_idx_;

public:
	void init();
	void spawn(const Real& x, const Real& y);
	void update();
	void render(const RenderManager& render_manager);
};

} // namespace UTJ {
#endif	/* SHOOTER01_EXPLOSIONMANAGER_H_THU_AUG_17_11_06_04_2017 */
/*
 * End of ExplosionManager.h
 */
