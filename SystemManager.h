/* -*- mode:C++; coding:utf-8-with-signature -*-
 *
 * SystemManager.h - Project PetitShooter
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
 * since Thu Aug 17 09:21:02 2017
 */
#ifndef	SHOOTER01_SYSTEMMANAGER_H_THU_AUG_17_09_21_02_2017
#define	SHOOTER01_SYSTEMMANAGER_H_THU_AUG_17_09_21_02_2017

#include "Random.h"
#include "InputManager.h"
#include "RenderManager.h"
#include "Sound.h"
#include "BulletManager.h"
#include "LaserManager.h"
#include "Player.h"
#include "EnemyManager.h"
#include "GameManager.h"
#include "ExplosionManager.h"
#include "LockCursorManager.h"

namespace UTJ {

class SystemManager
{
private:
	Random random_;
	InputManager input_manager_;
	RenderManager render_manager_;
	Sound sound_;
	BulletManager bullet_manager_;
	LaserManager laser_manager_;
	Player player_;
	EnemyManager enemy_manager_;
	GameManager game_manager_;
	ExplosionManager explosion_manager_;
	LockCursorManager lockcursor_manager_;
	int frame_cnt_;
	
public:
	void init();
	void update();
	void render();
	void boot_sequence();
};

} // namespace UTJ {
#endif	/* SHOOTER01_SYSTEMMANAGER_H_THU_AUG_17_09_21_02_2017 */
/*
 * End of SystemManager.h
 */
