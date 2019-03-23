/* -*- mode:C++; coding:utf-8-with-signature -*-
 *
 * Real.h - Project PetitShooter
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
 * since Sat Aug 19 09:26:13 2017
 */
#ifndef	SHOOTER01_REAL_H_SAT_AUG_19_09_26_13_2017
#define	SHOOTER01_REAL_H_SAT_AUG_19_09_26_13_2017

#include <inttypes.h>

#define USE_FLOAT	0

namespace UTJ {

class Real
{
#if USE_FLOAT
private:
	float value_;

public:
	Real() : value_(0.0f) {}
	Real(int v) : value_(v) {}
	Real(float v) : value_(v) {}
	Real(const Real& another) : value_(another.value_) {}
	int getRawValue() const { return int(value_*256.0f); }
	float getFloat() const { return value_; }
	Real& operator=(const Real& another) { value_ = another.value_; return *this; }
	Real& operator=(int another) { value_ = another; return *this; }
	Real& operator=(float another) { value_ = another; return *this; }
	Real operator+=(const Real& another) { value_ += another.value_; return *this; }
	Real operator-=(const Real& another) { value_ -= another.value_; return *this; }
	Real operator*=(const Real& another) { value_ *= another.value_; return *this; }
	Real operator/=(const Real& another) { value_ /= another.value_; return *this; }
	Real operator+=(int another) { value_ += another; return *this; }
	Real operator-=(int another) { value_ -= another; return *this; }
	Real operator*=(int another) { value_ *= another; return *this; }
	Real operator/=(int another) { value_ /= another; return *this; }
	operator int() const { return int(value_); }
	operator int8_t() const { return int8_t(value_); }
	Real preshiftOperatorMul(const Real& another) const { return Real(*this) *= another; }
#else
private:
	static const int SHIFT = 8;
	int16_t value_;

public:
	Real() : value_(0) {}
	Real(int v) : value_(v<<SHIFT) {}
	Real(float v) : value_(v*(1<<SHIFT)) {}
	Real(const Real& another) : value_(another.value_) {}
	int getRawValue() const { return value_; }
	void setRawValue(int value) { value_ = value; }
	float getFloat() const { return float(value_)/float(1<<SHIFT); }
	Real& operator=(const Real& another) { value_ = another.value_; return *this; }
	Real& operator=(int another) { value_ = another<<SHIFT; return *this; }
	Real& operator=(float another) { value_ = another*(1<<SHIFT); return *this; }
	Real operator+=(const Real& another) { value_ += another.value_; return *this; }
	Real operator-=(const Real& another) { value_ -= another.value_; return *this; }
	Real operator*=(const Real& another) { value_ *= another.value_; value_ >>= SHIFT; return *this; }
	Real operator/=(const Real& another) { value_ /= another.value_; value_ <<= SHIFT; return *this; }
	Real operator+=(int another) { value_ += (another<<SHIFT); return *this; }
	Real operator-=(int another) { value_ -= (another<<SHIFT); return *this; }
	Real operator*=(int another) { value_ *= another; return *this; }
	Real operator/=(int another) { value_ /= another; return *this; }
	operator int() const { return int(value_ >> SHIFT); }
	operator int8_t() const { return int8_t(value_ >> SHIFT); }
	Real preshiftOperatorMul(const Real& another) { Real v; v.value_ = (value_>>SHIFT) * another.value_; return v; }
#endif
};

inline Real operator+(const Real& t1, const Real& t2) { return Real(t1) += t2; }
inline Real operator-(const Real& t1, const Real& t2) { return Real(t1) -= t2; }
inline Real operator*(const Real& t1, const Real& t2) { return Real(t1) *= t2; }
inline Real operator/(const Real& t1, const Real& t2) { return Real(t1) /= t2; }
inline Real operator+(const Real& t1, const int t2) { return Real(t1) += t2; }
inline Real operator-(const Real& t1, const int t2) { return Real(t1) -= t2; }
inline Real operator*(const Real& t1, const int t2) { return Real(t1) *= t2; }
inline Real operator/(const Real& t1, const int t2) { return Real(t1) /= t2; }

inline bool operator<(const Real& t1, const Real& t2) { return t1.getRawValue() < t2.getRawValue(); }
inline bool operator<(const Real& t1, int t2) { return t1.getRawValue() < Real(t2).getRawValue(); }
inline bool operator<(int t1, const Real& t2) { return Real(t1).getRawValue() < t2.getRawValue(); }
inline bool operator>(const Real& t1, const Real& t2) { return t2 < t1; }
inline bool operator>(const Real& t1, int t2) { return t2 < t1; }
inline bool operator>(int t1, const Real& t2) { return t2 < t1; }
inline bool operator<=(const Real& t1, const Real& t2) { return !(t1 > t2); }
inline bool operator<=(const Real& t1, int t2) { return !(t1 > t2); }
inline bool operator<=(int t1, const Real& t2) { return !(t1 > t2); }
inline bool operator>=(const Real& t1, const Real& t2) { return !(t1 < t2); }
inline bool operator>=(const Real& t1, int t2) { return !(t1 < t2); }
inline bool operator>=(int t1, const Real& t2) { return !(t1 < t2); }

inline bool operator==(const Real& t1, const Real& t2) { return t1.getRawValue() == t2.getRawValue(); }
inline bool operator==(const Real& t1, int t2) { return t1.getRawValue() == Real(t2).getRawValue(); }
inline bool operator==(const Real& t1, float t2) { return t1.getRawValue() == Real(t2).getRawValue(); }
inline bool operator!=(const Real& t1, const Real& t2) { return !(t1 == t2); }
inline bool operator!=(const Real& t1, int t2) { return !(t1 == t2); }
inline bool operator!=(const Real& t1, float t2) { return !(t1 == t2); }

} // namespace UTJ {
#endif	/* SHOOTER01_REAL_H_SAT_AUG_19_09_26_13_2017 */
/*
 * End of Real.h
 */
