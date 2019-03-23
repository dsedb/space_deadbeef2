/* -*- mode:C++; coding:utf-8-with-signature -*-
 *
 * Boss.h - Project PetitShooter
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
 * since Sun Aug 20 08:28:59 2017
 */
#ifndef	SHOOTER01_BOSS_H_SUN_AUG_20_08_28_59_2017
#define	SHOOTER01_BOSS_H_SUN_AUG_20_08_28_59_2017

#include "Real.h"
#include "Collider.h"
#include "LockCollider.h"

namespace UTJ {

class RenderManager;
class ExplosionManager;
class Score;

class Boss
{
private:
	Collider collider_;
	LockCollider lock_collider_;
	Real x_;
	Real y_;
	Real vx_;
	Real vy_;
	bool alive_;
	int8_t cnt_;

public:
	void init(int x, int y);
	void die();
	bool isAlive() const { return alive_; }
	Collider& getCollider() { return collider_; }
	LockCollider& getLockCollider() { return lock_collider_; }
	void update(ExplosionManager& explosion_manager, Score& score);
	void render(RenderManager& render_manager);
};

} // namespace UTJ {
#endif	/* SHOOTER01_BOSS_H_SUN_AUG_20_08_28_59_2017 */
/*
 * End of Boss.h
 */
