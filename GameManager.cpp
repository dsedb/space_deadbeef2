/* -*- mode:C++; coding:utf-8-with-signature -*-
 *
 * GameManager.cpp - Project PetitShooter
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
 * since Thu Aug 17 12:25:07 2017
 */
#include "Debug.h"
#include "EnemyManager.h"
#include "RenderManager.h"
#include "GameManager.h"
#include "Random.h"

namespace UTJ {

namespace {

	struct EnemyTable
	{
		int wait_;
		int y_;
		int type_;
	};
	
	static const EnemyTable enemy_table[] = {
		{ 50, -1, 1, },
		{ 25, -1, 1, },
		{ 25, -1, 1, },
	};
}

void
GameManager::init()
{
	pc_ = 0;
	cnt0_ = 0;
}

void
GameManager::update(EnemyManager& enemy_manager, Random& random)
{
	const EnemyTable& et = enemy_table[pc_];
	++cnt0_;
	if (cnt0_ > et.wait_) {
		int y = et.y_;
		if (y < 0) {
			y = random.getRange(2, RenderManager::getScreenHeight()-2);
		}
		Real spawn_x(RenderManager::getScreenWidth()-1);
		Real spawn_y(y);
		enemy_manager.spawn(spawn_x, spawn_y);

		cnt0_ = 0;
		++pc_;
		if (pc_ >= sizeof(enemy_table)/sizeof(EnemyTable)) {
			pc_ = 0;
		}
	}
}


} // namespace UTJ {
/*
 * End of GameManager.cpp
 */
