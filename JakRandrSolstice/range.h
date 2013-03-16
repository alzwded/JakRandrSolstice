#pragma once

#include "exceptions.h"

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
		if(count >= SIZE) throw OutOfRangeException();

		m_data[count++] = next;
	}

	T& operator[](int i)
	{
		if(i < 0 || i >= SIZE) throw OutOfRangeException();

		return m_data[i];
	}
private:
	int count;
	T m_data[SIZE];
};