/* -*- mode:C++; coding:utf-8-with-signature -*-
 *
 * SystemManager.cpp - Project PetitShooter
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
 * since Thu Aug 17 09:22:07 2017
 */
#include <Arduino.h>
#include "Debug.h"
#include "CollisionManager.h"
#include "SystemManager.h"

namespace UTJ {

void
SystemManager::init()
{
	Debug::init();
	random_.seed(12345);
	input_manager_.init();
	render_manager_.init();
	sound_.init();
	bullet_manager_.init();
	laser_manager_.init();
	player_.init();
	enemy_manager_.init();
	game_manager_.init();
	explosion_manager_.init();
	frame_cnt_ = 0;

	boot_sequence();
}

void
SystemManager::update()
{
	input_manager_.fetch();
	sound_.update();
	game_manager_.update(enemy_manager_, random_);
	player_.update(input_manager_, sound_, bullet_manager_, laser_manager_, enemy_manager_);
	bullet_manager_.update();
	laser_manager_.update(player_);
	enemy_manager_.update(sound_, explosion_manager_, game_manager_.getScore());
	explosion_manager_.update();
	lockcursor_manager_.update();
	CollisionManager::check(sound_, player_,
							bullet_manager_, enemy_manager_, lockcursor_manager_);
}

void
SystemManager::render()
{
	render_manager_.begin();

	player_.render(render_manager_, frame_cnt_);
	bullet_manager_.render(render_manager_);
	laser_manager_.render(render_manager_);
	enemy_manager_.render(render_manager_);
	explosion_manager_.render(render_manager_);
	lockcursor_manager_.render(render_manager_);

	render_manager_.end();
	render_manager_.display(player_.isHomingMode(),
							enemy_manager_.getLockedNum(),
							enemy_manager_.getLockMax(),
							game_manager_.getScore());

	++frame_cnt_;
}


void
SystemManager::boot_sequence()
{
	render_manager_.boot();
	sound_.boot();
	input_manager_.boot();
	sound_.gameStart();
	render_manager_.clear();
}

} // namespace UTJ {
/*
 * End of SystemManager.cpp
 */
