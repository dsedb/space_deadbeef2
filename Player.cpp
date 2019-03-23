/* -*- mode:C++; coding:utf-8-with-signature -*-
 *
 * Player.cpp - Project PetitShooter
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
 * since Thu Aug 17 10:23:29 2017
 */
#include "Debug.h"
#include "InputManager.h"
#include "Sound.h"
#include "RenderManager.h"
#include "BulletManager.h"
#include "LaserManager.h"
#include "Player.h"

namespace UTJ {

int Player::min_x = 0;
int Player::max_x = 0;
int Player::min_y = 0;
int Player::max_y = 0;
	
Player::Player()
{}

void
Player::init()
{
	min_x = 0;
	max_x = RenderManager::getScreenWidth() - 1;
	min_y = 1;
	max_y = RenderManager::getScreenHeight();
	x_ = min_x;
	y_ = min_y;
	homing_mode_ = false;
	searching_ = false;
}

void
Player::update(const InputManager& input_manager,
			   Sound& sound,
			   BulletManager& bullet_manager,
			   LaserManager& laser_manager,
			   EnemyManager& enemy_manager)
{
	if (input_manager.isUp()) {
		y_ += Real(-0.5f);
		if (y_ < min_y) {
			y_ = min_y;
		}
	}
	if (input_manager.isDown()) {
		y_ += Real(0.5f);
		if (y_ >= max_y) {
			y_ = max_y-1;
		}
	}
	if (homing_mode_) {
		if (input_manager.isFire()) {
			searching_ = true;
		} else {
			searching_ = false;
		}
		if (input_manager.isFireUp()) {
			laser_manager.fire(sound, x_, y_, enemy_manager);
		}
	} else {
		if (input_manager.isFireDown()) {
			bullet_manager.spawn(x_, y_);
			sound.play(NOTE_C4, 2 /* frames */);
		}
	}
	if (input_manager.isSwitchDown()) {
		sound.play(NOTE_D5, 3 /* frames */);
		homing_mode_ = !homing_mode_;
	}
}

void
Player::render(RenderManager& render_manager, int frame_cnt)
{
	if (homing_mode_) {
		render_manager.drawPoint(x_, y_);
		render_manager.drawPoint(x_, y_-1);
		render_manager.drawPoint(x_+1, y_-1);
		render_manager.drawPoint(x_+2, y_-1);
	} else {
		render_manager.drawPoint(x_, y_-1);
		render_manager.drawPoint(x_, y_);
		render_manager.drawPoint(x_+1, y_);
		render_manager.drawPoint(x_+2, y_);
	}
	if (searching_ && (frame_cnt&1)) {
		for (int x = int(x_)+3+(frame_cnt&3); x < RenderManager::getScreenWidth(); x += 4) {
			render_manager.drawPoint(x, y_);
		}
	}
}

} // namespace UTJ {
/*
 * End of Player.cpp
 */
