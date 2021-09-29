#include "Engine.h"
#include "Game.h"
#include "Sprite.h"
#include "Font.h"

#ifndef HOME_H
#define HOME_H

class Home : public Game {
private:
    Sprite* title = nullptr;            // T�tulo do jogo
    Sprite* subtitle = nullptr;         // Subt�tulo do jogo
    Sprite* background = nullptr;       // background
    Sprite* buttonUnhovered = nullptr;  // sprite do bot�o sem o mouse em cima
    Sprite* buttonHovered = nullptr;    // sprite do bot�o com o mouse em cima
    bool isOnButton;                    // vari�vel para verificar se mouse est� em cima do bot�o
    float buttonX, buttonY;             // vari�veis para guardar as posi��es do bot�o

public:
    void Init();
    void Update();
    void Draw();
    void Finalize();
};

#endif // !HOME_H
