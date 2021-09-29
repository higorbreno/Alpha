#include "Object.h"
#include "Sprite.h"
#include "Vector2.h"

#ifndef BULLET_H
#define BULLET_H

class Bullet : public Object {
private:
	Sprite* sprite;						// Sprite local da bala
	Vector2* direction;					// Objeto que dita a direção da bala

public:
	static Image* image;				// Imagem usada nos sprites da bala
	Bullet(float, float, Vector2*);
	~Bullet();
	void Update();
	void Draw();

};

#endif