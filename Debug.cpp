/* -*- mode:C++; coding:utf-8-with-signature -*-
 *
 * Debug.cpp - Project PetitShooter
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
 * since Thu Aug 17 11:11:18 2017
 */
#include <Arduino.h>
#include "Debug.h"

namespace UTJ {

void
Debug::init()
{
	Serial.begin(9600);
	Serial.print("boot\n");
}

void
Debug::here(const char* file, const int line)
{
	warning(file, line, "");
}

void
Debug::value(const char* file, const int line, int value)
{
	char buf[128];
	snprintf(buf, sizeof(buf), "[%s:%d]%d\n", file, line, value);
	Serial.print(buf);
}

void
Debug::warning(const char* file, const int line, const char* message)
{
	char buf[128];
	snprintf(buf, sizeof(buf), "[%s:%d]%s\n", file, line, message);
	Serial.print(buf);
}

} // namespace UTJ {
/*
 * End of Debug.cpp
 */
