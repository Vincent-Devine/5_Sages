#pragma once

namespace Utils
{
	struct InitValue
	{
		unsigned int timeThinkMin = 1;
		unsigned int timeThinkMax = 5;
		unsigned int timeEatMin = 1;
		unsigned int timeEatMax = 5;
		unsigned int timeEatTotal = 5;
		unsigned int nbSages = 5;
		unsigned int nbDays = 1;
	};

	const unsigned int GetRandomValue(const unsigned int p_min, const unsigned int p_max);
}