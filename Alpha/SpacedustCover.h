#include "Object.h"
#include "TileSet.h"
#include "Animation.h"

#ifndef SPACEDUSTCOVER_H
#define SPACEDUSTCOVER_H

class SpacedustCover : public Object {
private:
	TileSet* tiles;				// tiles da animação
	Animation* anim;			// animação
	float timer;				// variável para marcar o tempo que está ativa
	bool isVisible;				// variável para controlar se a sujeira na tela é visível

public:
	SpacedustCover();
	~SpacedustCover();
	void SetVisibility(bool);	
	void Update();
	void Draw();

};

// método para setar a visibilidade
inline void SpacedustCover::SetVisibility(bool visibility)
{ timer = 0.0f; isVisible = visibility; }

#endif