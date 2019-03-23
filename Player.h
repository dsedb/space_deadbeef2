/* -*- mode:C++; coding:utf-8-with-signature -*-
 *
 * Player.h - Project PetitShooter
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
 * since Thu Aug 17 10:23:05 2017
 */
#ifndef	SHOOTER01_PLAYER_H_THU_AUG_17_10_23_05_2017
#define	SHOOTER01_PLAYER_H_THU_AUG_17_10_23_05_2017

#include "Real.h"

namespace UTJ {

class InputManager;
class Sound;
class BulletManager;
class RenderManager;
class LaserManager;
class EnemyManager;

class Player
{
private:
	static int min_x;
	static int max_x;
	static int min_y;
	static int max_y;
	Real x_;
	Real y_;
	bool homing_mode_;
	bool searching_;

public:
	Player();
	void init();
	void update(const InputManager& input_manager,
				Sound& sound,
				BulletManager& bullet_manager,
				LaserManager& laser_manager,
				EnemyManager& enemy_manager);
	void render(RenderManager& render_manager, int frame_cnt);
	bool isHomingMode() const { return homing_mode_; }
	bool isSearching() const { return searching_; }
	const Real& getSearchY() { return y_; }
};

} // namespace UTJ {
#endif	/* SHOOTER01_PLAYER_H_THU_AUG_17_10_23_05_2017 */
/*
 * End of Player.h
 */
