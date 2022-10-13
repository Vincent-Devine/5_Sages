#include <Draw.hpp>

#include <Windows.h>

namespace Draw
{
	const void AskValue(Utils::InitValue& initValue)
	{
		std::cout << "Enter min thinking time in second ? ";
			std::cin >> initValue.timeThinkMin;

		std::cout << "Enter max thinking time in second ? ";
		std::cin >> initValue.timeThinkMax;

		std::cout << "Enter min eating time in second ? ";
		std::cin >> initValue.timeEatMin;

		std::cout << "Enter max eating time in second ? ";
		std::cin >> initValue.timeEatMax;

		std::cout << "Enter total eating time in second ? ";
		std::cin >> initValue.timeEatTotal;

		std::cout << "Enter the number of sages ? ";
		std::cin >> initValue.nbSages;

		std::cout << "Enter the number of days ? ";
		std::cin >> initValue.nbDays;
	}

	const void DrawStat(const std::vector<Sage>& p_sages, const unsigned int p_day)
	{
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

		std::cout << "[Days : " << p_day + 1  << ", ";

		for (unsigned int i = 0; i < p_sages.size(); i++)
		{
			switch (p_sages[i].GetStat())
			{
			case Stats::THINK:
				SetConsoleTextAttribute(handle, 11); // blue
				std::cout << "T";
				SetConsoleTextAttribute(handle, 15); // white (default)
				break;

			case Stats::HUNGRY:
				SetConsoleTextAttribute(handle, 12); // red
				std::cout << "H";
				SetConsoleTextAttribute(handle, 15); // white (default)
				break;

			case Stats::EAT:
				SetConsoleTextAttribute(handle, 14); // yellow
				std::cout << "E";
				SetConsoleTextAttribute(handle, 15); // white (default)
				break;

			case Stats::SLEEP:
				SetConsoleTextAttribute(handle, 10); // green
				std::cout << "S";
				SetConsoleTextAttribute(handle, 15); // white (default)
				break;

			default:
				SetConsoleTextAttribute(handle, 15); // white (default)
				break;
			}

			if(i + 1 != p_sages.size())
				std::cout << " | ";
		}

		SetConsoleTextAttribute(handle, 15); // white (default)
 		std::cout  << "]" << "\t\r" << std::flush;
	}
}
