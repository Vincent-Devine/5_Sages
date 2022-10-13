#pragma once

#include <iostream>
#include <vector>
#include <Sage.hpp>

#include <Utils.hpp>

namespace Draw
{
	const void AskValue(Utils::InitValue& initValue);
	const void DrawStat(const std::vector<Sage>& p_sages, const unsigned int p_day);
}
