#include "Home.h"
#include "Alpha.h"

void Home::Init()
{
	isOnButton = false;
	title = new Sprite("Resources/Title.png");
	subtitle = new Sprite("Resources/Subtitle.png");
	background = new Sprite("Resources/StartBackground.png");
	buttonUnhovered = new Sprite("Resources/StartButtonUnhovered.png");
	buttonHovered = new Sprite("Resources/StartButtonHovered.png");
	buttonX = window->CenterX();
	buttonY = window->CenterY() + 50;
}

// verifica se o mouse está sobre o botão e se o botão foi clicado ou não
void Home::Update()
{
	float dx = buttonX - window->MouseX();
	float dy = buttonY - window->MouseY();

	float distance = sqrt((dx * dx) + (dy * dy));

	if (distance <= 64.0f)
		isOnButton = true;
	else
		isOnButton = false;

	if (window->KeyClicked(VK_LBUTTON) && isOnButton)
		Engine::Next<Alpha>();
}

// desenha o background, titulo do jogo e botão, dependendo do seu estado
void Home::Draw()
{
	background->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
	title->Draw(window->CenterX(), window->CenterY() - 100, Layer::FRONT);
	subtitle->Draw(window->CenterX(), window->CenterY() - 55, Layer::FRONT);
	if (isOnButton)
		buttonHovered->Draw(buttonX, buttonY);
	else
		buttonUnhovered->Draw(buttonX, buttonY);
}

void Home::Finalize()
{
	delete title;
	delete subtitle;
	delete background;
	delete buttonUnhovered;
	delete buttonHovered;
}
