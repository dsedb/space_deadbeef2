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
#include "EnemyManager.h"
#include "LaserManager.h"

namespace UTJ {

EnemyManager::EnemyManager()
: LOCK_MAX(LaserManager::getLaserMax())
{}

void
EnemyManager::init()
{
	memset(alive_table_, 0, sizeof(alive_table_));
	memset(pool_, 0, sizeof(pool_));
	locked_num_ = 0;
}

void
EnemyManager::spawn(const Real& x, const Real& y)
{
	for (int i = 0; i < ENEMY_MAX; ++i) {
		if (alive_table_[i] == 0) {
			alive_table_[i] = 1;
			pool_[i].init(x, y);
			return;
		}
	}
	WARNING("out of poool");
}

void
EnemyManager::update(Sound& sound, ExplosionManager& explosion_manager, Score& score)
{
	int locked_num = 0;
	for (int i = 0; i < ENEMY_MAX; ++i) {
		if (alive_table_[i] != 0) {
			pool_[i].update(sound, explosion_manager, score);
			if (!pool_[i].isAlive()) {
				alive_table_[i] = 0;
			}
			LockMode mode = pool_[i].getLockCollider().getMode();
			if (mode == LockModeLocked ||
				mode == LockModeChased) {
				++locked_num;
			}
		}
	}
	locked_num_ = locked_num;
}

void
EnemyManager::render(RenderManager& render_manager)
{
	for (int i = 0; i < ENEMY_MAX; ++i) {
		if (alive_table_[i] != 0) {
			pool_[i].render(render_manager);
		}
	}
}

} // namespace UTJ {
/*
 * End of EnemyManager.cpp
 */
