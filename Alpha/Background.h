#include "Object.h"
#include "Image.h"
#include "Sprite.h"

#ifndef BACKGROUND_H
#define BACKGROUND_H

// Estrutura para gerenciar posições x e y de cada sprite do background
struct BackgroundInfo {
	float x, y;
	Sprite* sprite;
};

class Background : public Object {
private:
	Image* image;					// Imagem do Background
	BackgroundInfo backgs[3][3];	// Matriz de sprites para o background

public:
	Background();
	~Background();
	void Update();
	void Draw();
	void MoveLeft();				// Mover os sprites para esquerda
	void MoveRight();				// Mover os sprites para direita
	void MoveUp();					// Mover os sprites para cima
	void MoveDown();				// Mover os sprites para baixo

};

#endif // !BACKGROUND_H
