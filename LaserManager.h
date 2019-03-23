/* -*- mode:C++; coding:utf-8-with-signature -*-
 *
 * LaserManager.h - Project PetitShooter
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
 * since Fri Aug 18 16:54:39 2017
 */
#ifndef	SHOOTER01_LASERMANAGER_H_FRI_AUG_18_16_54_39_2017
#define	SHOOTER01_LASERMANAGER_H_FRI_AUG_18_16_54_39_2017

#include "Laser.h"

namespace UTJ {

class Player;
class RenderManager;
class Sound;
class EnemyManager;

class LaserManager
{
private:
	static const int LASER_MAX = 4;
	Laser pool_[LASER_MAX];

public:
	static int getLaserMax() { return LASER_MAX; }
	void init();
	void fire(Sound& sound,
			  const Real& x, const Real& y,
			  EnemyManager& enemy_manager);
	void update(Player& player);
	void render(RenderManager& render_manager);
};

} // namespace UTJ {
#endif	/* SHOOTER01_LASERMANAGER_H_FRI_AUG_18_16_54_39_2017 */
/*
 * End of LaserManager.h
 */
