#pragma once

#include <dllDefines.h>

#include "exceptions.h"

/*
	intended usage:
	vec3 p(range<float, 3>(100.0)(50.0)(-10.0));
	range<range<float, 2>, 2> I2(range<float, 2>(1)(0), range<float, 2>(0)(1));
*/

template<class T, int SIZE>
class range sealed
{
public:
	range(const T& first)
	{
		m_data[0] = first;
		count = 1;
	}

	range& operator()(const T& next)
	{
		if(count >= SIZE) THROW(OutOfRangeException);

		m_data[count++] = next;
	}

	T& operator[](const int i)
	{
		if(i < 0 || i >= SIZE) THROW(OutOfRangeException);

		return m_data[i];
	}

	const T& operator[](const int i) const
	{
		if(i < 0 || i >= SIZE) THROW(OutOfRangeException);

		return m_data[i];
	}
private:
	int count;
	T m_data[SIZE];
};