#include "Object.h"
#include "Vector2.h"
#include "Animation.h"
#include "TileSet.h"

#ifndef SPACEDUST_H
#define SPACEDUST_H

class Spacedust : public Object {
private:
	Animation* anim;		// anima��o da poeira espacial
	Vector2* direction;		// dire��o da poeira espacial

public:
	static TileSet* tiles;	// tiles da anima��o
	Spacedust();
	~Spacedust();
	void Update();
	void Draw();

};

#endif // !SPACEDUST_H
