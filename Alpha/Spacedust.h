#include "Object.h"
#include "Vector2.h"
#include "Animation.h"
#include "TileSet.h"

#ifndef SPACEDUST_H
#define SPACEDUST_H

class Spacedust : public Object {
private:
	Animation* anim;		// animação da poeira espacial
	Vector2* direction;		// direção da poeira espacial

public:
	static TileSet* tiles;	// tiles da animação
	Spacedust();
	~Spacedust();
	void Update();
	void Draw();

};

#endif // !SPACEDUST_H
