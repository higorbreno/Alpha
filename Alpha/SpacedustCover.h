#include "Object.h"
#include "TileSet.h"
#include "Animation.h"

#ifndef SPACEDUSTCOVER_H
#define SPACEDUSTCOVER_H

class SpacedustCover : public Object {
private:
	TileSet* tiles;				// tiles da anima��o
	Animation* anim;			// anima��o
	float timer;				// vari�vel para marcar o tempo que est� ativa
	bool isVisible;				// vari�vel para controlar se a sujeira na tela � vis�vel

public:
	SpacedustCover();
	~SpacedustCover();
	void SetVisibility(bool);	
	void Update();
	void Draw();

};

// m�todo para setar a visibilidade
inline void SpacedustCover::SetVisibility(bool visibility)
{ timer = 0.0f; isVisible = visibility; }

#endif