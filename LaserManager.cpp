/* -*- mode:C++; coding:utf-8-with-signature -*-
 *
 * LaserManager.cpp - Project PetitShooter
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
 * since Fri Aug 18 16:55:17 2017
 */

#include <string.h>
#include "Debug.h"
#include "Sound.h"
#include "EnemyManager.h"
#include "LaserManager.h"

namespace UTJ {

void
LaserManager::init()
{
	memset(pool_, 0, sizeof(pool_));
}

void
LaserManager::fire(Sound& sound,
				   const Real& x, const Real& y,
				   EnemyManager& enemy_manager)
{
	int idx = 0;
	Real arrival_time(0.8f);
	bool fired = false;
	for (int i = 0; i < EnemyManager::getEnemyMax(); ++i) {
		Enemy& enemy = enemy_manager.getEnemy(i);
		LockCollider& lock_collider = enemy.getLockCollider();
		if (lock_collider.getMode() == LockModeLocked) {
			pool_[idx].init(x, y,
							Real(20.0f), Real(1.0f),
							lock_collider, arrival_time);
			fired = true;
			arrival_time += DynamicReal::getDT()*8;
			lock_collider.setMode(LockModeChased);
			++idx;
			if (idx >= LASER_MAX) {
				break;
			}
		}
	}
	if (fired) {
		sound.play(NOTE_C3, 8 /* frames */);
	}
}

void
LaserManager::update(Player& player)
{
	for (int i = 0; i < LASER_MAX; ++i) {
		pool_[i].update(player);
	}
}

void
LaserManager::render(RenderManager& render_manager)
{
	for (int i = 0; i < LASER_MAX; ++i) {
		pool_[i].render(render_manager);
	}
}

} // namespace UTJ {
/*
 * End of LaserManager.cpp
 */
