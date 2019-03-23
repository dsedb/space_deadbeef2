/* -*- mode:C++; coding:utf-8-with-signature -*-
 *
 * Laser.h - Project PetitShooter
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
 * since Fri Aug 18 16:41:20 2017
 */
#ifndef	SHOOTER01_LASER_H_FRI_AUG_18_16_41_20_2017
#define	SHOOTER01_LASER_H_FRI_AUG_18_16_41_20_2017

#include "DynamicReal.h"
#include "LockCollider.h"

namespace UTJ {

class RenderManager;
class Player;

class Laser
{
private:
	DynamicReal x_;
	DynamicReal y_;
	LockCollider* lock_collider_;
	Real arrival_time_;
	bool alive_;
	
public:
	void init(const Real& x, const Real& y,
			  const Real& vx, const Real& vy,
			  LockCollider& lock_collider, const Real& arrival_time);
	bool isAlive() const { return alive_; }
	void update(Player& player);
	void render(RenderManager& render_manager);
};


} // namespace UTJ {
#endif	/* SHOOTER01_LASER_H_FRI_AUG_18_16_41_20_2017 */
/*
 * End of Laser.h
 */
