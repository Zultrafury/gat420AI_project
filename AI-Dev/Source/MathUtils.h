#pragma once

template<typename T>
inline T Lerp(const T& a, const T& b, float t)
{
	return static_cast<T>(a + ((b - a) * t));
}

template<typename T>
inline T Clamp(const T& value, const T& min, const T& max)
{
	return (value < min) ? min : (value > max) ? max : value;
}


