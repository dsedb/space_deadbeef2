/* -*- mode:C++; coding:utf-8-with-signature -*-
 *
 * Enemy.h - Project PetitShooter
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
 * since Thu Aug 17 11:49:49 2017
 */
#ifndef	SHOOTER01_ENEMY_H_THU_AUG_17_11_49_49_2017
#define	SHOOTER01_ENEMY_H_THU_AUG_17_11_49_49_2017

#include "DynamicReal.h"
#include "Collider.h"
#include "LockCollider.h"

namespace UTJ {

class RenderManager;
class Sound;
class ExplosionManager;
class Score;

class Enemy
{
private:
	Collider collider_;
	LockCollider lock_collider_;
	DynamicReal x_;
	DynamicReal y_;
	Real target_y_;
	bool alive_;
	int8_t cnt_;

public:
	void init(const Real& x, const Real& y);
	void die();
	bool isAlive() const { return alive_; }
	Collider& getCollider() { return collider_; }
	LockCollider& getLockCollider() { return lock_collider_; }
	void update(Sound& sound, ExplosionManager& explosion_manager, Score& score);
	void render(RenderManager& render_manager);
};

} // namespace UTJ {
#endif	/* SHOOTER01_ENEMY_H_THU_AUG_17_11_49_49_2017 */
/*
 * End of Enemy.h
 */
