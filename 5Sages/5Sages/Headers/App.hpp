#pragma once

#include <vector>

#include <Sage.hpp>
#include <Draw.hpp>
#include <Utils.hpp>

class App
{
	// Attribute
private:
	Utils::InitValue initValue;

	std::vector<Sage> sages;
	std::vector<std::mutex*> chopsticks;
	std::vector<std::thread> threads;

	// Methode
public:
	~App();

	void Init();
	void UpdateAndDraw();

private:
	void Start();
	const void Draw(const unsigned int p_day);

	const bool CheckAllSage() const;
};