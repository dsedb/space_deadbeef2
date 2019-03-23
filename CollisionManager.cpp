/* -*- mode:C++; coding:utf-8-with-signature -*-
 *
 * CollisionManager.cpp - Project PetitShooter
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
 * since Thu Aug 17 14:26:31 2017
 */
#include "Sound.h"
#include "BulletManager.h"
#include "EnemyManager.h"
#include "Player.h"
#include "CollisionManager.h"

namespace UTJ {

void
CollisionManager::check(Sound& sound,
						Player& player,
						BulletManager& bullet_manager,
						EnemyManager& enemy_manager,
						LockCursorManager& lockcursor_manager)
{
	// Collider
	for (int bidx = 0; bidx < bullet_manager.getBulletMax(); ++bidx) {
		Bullet& bullet = bullet_manager.getBullet(bidx);
		if (!bullet.isAlive()) {
			continue;
		}
		for (int eidx = 0; eidx < enemy_manager.getEnemyMax(); ++eidx) {
			Enemy& enemy = enemy_manager.getEnemy(eidx);
			if (!enemy.isAlive()) {
				continue;
			}
			bullet.getCollider().check(enemy.getCollider());
		}
	}

	// LockCollider
	if (player.isSearching()) {
		bool hitted = false;
		for (int eidx = 0; eidx < enemy_manager.getEnemyMax(); ++eidx) {
			if (!enemy_manager.canLock()) {
				break;
			}
			Enemy& enemy = enemy_manager.getEnemy(eidx);
			if (!enemy.isAlive()) {
				continue;
			}
			bool hit = enemy.getLockCollider().check(player.getSearchY(), Real(3.0f) /* height */, lockcursor_manager);
			if (hit) {
				hitted = true;
			}
		}
		if (hitted) {
			sound.play(NOTE_C7, 2 /* frames */);
		}
	}
}

} // namespace UTJ {
/*
 * End of CollisionManager.cpp
 */
