/* -*- mode:C++; coding:utf-8-with-signature -*-
 *
 * Debug.h - Project PetitShooter
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
 * since Thu Aug 17 11:10:54 2017
 */
#ifndef	SHOOTER01_DEBUG_H_THU_AUG_17_11_10_54_2017
#define	SHOOTER01_DEBUG_H_THU_AUG_17_11_10_54_2017

namespace UTJ {

class Debug
{
public:
	static void init();
	static void here(const char* file, const int line);
	static void value(const char* file, const int line, int value);
	static void warning(const char* file, const int line, const char* message);
};

} // namespace UTJ {

#define HERE() { Debug::here(__FILE__, __LINE__); }
#define VALUE(v) { Debug::value(__FILE__, __LINE__, v); }
#define WARNING(message) { Debug::warning(__FILE__, __LINE__, message); }

#endif	/* SHOOTER01_DEBUG_H_THU_AUG_17_11_10_54_2017 */
/*
 * End of Debug.h
 */
