#include "Random.h"

std::random_device Random::rd;
std::mt19937 Random::mt(rd());

Random::Random(int min, int max)
{
	this->min = min;
	this->max = max;
}

Random::~Random()
{
}

int Random::RandomInt()
{
	std::uniform_int_distribution dist(min, max);

	return dist(mt);
}
