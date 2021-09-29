#include <random>

#ifndef RANDOM_H
#define RANDOM_H

class Random {
private:
	static std::random_device rd;
	static std::mt19937 mt;
	int min, max;

public:
	Random(int, int);
	~Random();
	int RandomInt();

};

#endif