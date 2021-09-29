#include "GameOver.h"
#include "Alpha.h"

int GameOver::score = 0;

void GameOver::Init()
{
	background = new Sprite("Resources/StartBackground.png");
	font = new Font("Resources/Joystix33.png");
	font->Spacing("Resources/Joystix33.dat");
}

void GameOver::Update()
{
}

void GameOver::Draw()
{
	background->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
	font->Draw(window->CenterX() - 150, window->CenterY() - 100, "Game Over", { 1,1,1,1 }, Layer::FRONT);
	font->Draw(window->CenterX() - 180, window->CenterY(), "Final Score:", { 1,1,1,1 }, Layer::FRONT);
	font->Draw(window->CenterX() - 5, window->CenterY() + 50, std::to_string(score), { 1,1,1,1 }, Layer::FRONT);
}

void GameOver::Finalize()
{
	delete background;
	delete font;
}
