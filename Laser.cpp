/* -*- mode:C++; coding:utf-8-with-signature -*-
 *
 * Laser.cpp - Project PetitShooter
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
 * since Fri Aug 18 16:41:00 2017
 */
#include "Debug.h"
#include "RenderManager.h"
#include "Player.h"
#include "Laser.h"

namespace UTJ {

void
Laser::init(const Real& x, const Real& y,
			const Real& vx, const Real& vy,
			LockCollider& lock_collider, const Real& arrival_time)
{
	x_ = x;
	y_ = y;
	x_.setVelocity(vx);
	y_.setVelocity(vy);
	lock_collider_ = &lock_collider;
	arrival_time_ = arrival_time;
	alive_ = true;
}

void
Laser::update(Player& player)
{
	if (!alive_) {
		return;
	}

	if (lock_collider_->getMode() != LockModeChased) {
		alive_ = false;
		return;
	}

	x_.setForceArrivalTime(lock_collider_->getX(), arrival_time_);
	y_.setForceArrivalTime(lock_collider_->getY(), arrival_time_);
	arrival_time_ -= DynamicReal::getDT();
	if (arrival_time_ <= 0) {
		lock_collider_->hit();
		alive_ = false;
		return;
	}

	x_.update();
	y_.update();
}

void
Laser::render(RenderManager& render_manager)
{
	if (alive_) {
		render_manager.drawPoint(x_.getValue(), y_.getValue());
	}
}

} // namespace UTJ {
/*
 * End of Laser.cpp
 */
