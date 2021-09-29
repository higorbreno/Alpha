#include "Background.h"
#include "Scene.h"

Background::Background()
{
	// inicializa os sprites com a imagem do background e os coloca numa grid de 3x3, 
	// para o player sempre estar em volta de backgrounds e o mundo parecer infinito
	image = new Image("Resources/Background.png");
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			backgs[i][j].sprite = new Sprite(image);
			backgs[i][j].x = float((j - 1) * backgs[i][j].sprite->Width());
			backgs[i][j].y = float((i - 1) * backgs[i][j].sprite->Height());
		}
	}
}

// deleta todos os sprites alocados
Background::~Background()
{
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			delete backgs[i][j].sprite;
		}
	}
	delete image;
}

// verifica se é necessário mudar a posição dos backgrounds para o player não ficar sem background atrás
void Background::Update()
{
	if (x + image->Width() < Scene::camera2d->X() + window->CenterX())
		MoveRight();
	else if (x > Scene::camera2d->X() + image->Width() + window->CenterX())
		MoveLeft();
	else if (y + image->Height() < Scene::camera2d->Y() + window->CenterY())
		MoveDown();
	else if (y > Scene::camera2d->Y() + image->Height() + window->CenterY())
		MoveUp();
}

// desenha os backgrounds
void Background::Draw()
{
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			backgs[i][j].sprite->Draw(
				backgs[i][j].x + window->CenterX(), 
				backgs[i][j].y + window->CenterY());
		}
	}
}

// move todos os sprites para esquerda
void Background::MoveLeft()
{
	MoveTo(x - image->Width(), y);

	BackgroundInfo bs[3][3];

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			bs[i][j] = backgs[i][j];
		}
	}

	// deslocando todos os sprites uma posição para esquerda no vetor
	for (int i = 0; i < 3; ++i) {
		backgs[i][0] = bs[i][2];
		backgs[i][1] = bs[i][0];
		backgs[i][2] = bs[i][1];
	}

	// deslocando todos os sprites para a esquerda pelo tamanho da imagem
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			backgs[i][j].x -= image->Width();
		}
	}
}

// move todos os sprites para direita
void Background::MoveRight()
{
	MoveTo(x + image->Width(), y);

	BackgroundInfo bs[3][3];

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			bs[i][j] = backgs[i][j];
		}
	}

	// deslocando todos os sprites uma posição para direita no vetor
	for (int i = 0; i < 3; ++i) {
		backgs[i][0] = bs[i][1];
		backgs[i][1] = bs[i][2];
		backgs[i][2] = bs[i][0];
	}

	// deslocando todos os sprites para a direita pelo tamanho da imagem
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			backgs[i][j].x += image->Width();
		}
	}
}

// move todos os sprites para cima
void Background::MoveUp()
{
	MoveTo(x, y - image->Height());

	BackgroundInfo bs[3][3];

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			bs[i][j] = backgs[i][j];
		}
	}

	// deslocando todos os sprites uma posição para cima no vetor
	for (int i = 0; i < 3; ++i) {
		backgs[0][i] = bs[2][i];
		backgs[1][i] = bs[0][i];
		backgs[2][i] = bs[1][i];
	}

	// deslocando todos os sprites para cima pelo tamanho da imagem
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			backgs[i][j].y -= image->Height();
		}
	}
}

// move todos os sprites para baixo
void Background::MoveDown()
{
	MoveTo(x, y + image->Height());

	BackgroundInfo bs[3][3];

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			bs[i][j] = backgs[i][j];
		}
	}

	// deslocando todos os sprites uma posição para baixo no vetor
	for (int i = 0; i < 3; ++i) {
		backgs[0][i] = bs[1][i];
		backgs[1][i] = bs[2][i];
		backgs[2][i] = bs[0][i];
	}

	// deslocando todos os sprites para baixo pelo tamanho da imagem
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			backgs[i][j].y += image->Height();
		}
	}
}
