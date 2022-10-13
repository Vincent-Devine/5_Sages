#include <Utils.hpp>

#include <random>

namespace Utils
{
	const unsigned int GetRandomValue(const unsigned int p_min, const unsigned int p_max)
	{
		return rand() % p_max + p_min;
	}
}