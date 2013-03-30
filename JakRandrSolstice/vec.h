#pragma once

#include "exceptions.h"
#include "range.h"

template<int SIZE>
class vec sealed
{
public:
	vec() {}

	vec(const range<float, SIZE> data)
	{
		for(int i = 0; i < SIZE; ++i) {
			m_data[i] = data[i];
		}
	}

	template<int OTHER_SIZE>
	vec(const vec<OTHER_SIZE>& other)
	{
		for(int i = 0; i < std::min(SIZE, OTHER_SIZE); ++i) {
			m_data[i] = other[i];
		}
	}

	float& operator[](int i) 
	{
		if(i < 0 || i >= SIZE) {
			THROW(OutOfRangeException);
		}

		return m_data[i];
	}

	float operator*()
	{
		float ret(0.0f);
		for(int i = 0; i < SIZE; ++i) {
			ret += m_data[i] * m_data[i];
		}
		return ret;
	}

	vec<SIZE> operator*(const float a)
	{
		vec<SIZE> ret;
		for(int i = 0; i < SIZE; ++i) {
			ret[i] = m_data[i] * a;
		}
		return ret;
	}

	vec<SIZE> operator*(const vec<SIZE>& other)
	{
		// TODO
	}

	vec<SIZE> operator+(const vec<SIZE>& other)
	{
		vec<SIZE> ret;
		for(int i = 0; i < SIZE; ++i) {
			ret[i] = m_data[i] + other[i];
		}
	}

	vec<SIZE> normalized()
	{
		vec<SIZE> v;
		float modulus = **this;
		for(int i = 0; i < SIZE; ++i) {
			v[i] = m_data[i] / modulus;
		}
		return v;
	}

private:
	float m_data[SIZE];
};

typedef vec<2> vec2;
typedef vec<3> vec3;
typedef vec<4> vec4;