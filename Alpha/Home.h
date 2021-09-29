#include "Engine.h"
#include "Game.h"
#include "Sprite.h"
#include "Font.h"

#ifndef HOME_H
#define HOME_H

class Home : public Game {
private:
    Sprite* title = nullptr;            // Título do jogo
    Sprite* subtitle = nullptr;         // Subtítulo do jogo
    Sprite* background = nullptr;       // background
    Sprite* buttonUnhovered = nullptr;  // sprite do botão sem o mouse em cima
    Sprite* buttonHovered = nullptr;    // sprite do botão com o mouse em cima
    bool isOnButton;                    // variável para verificar se mouse está em cima do botão
    float buttonX, buttonY;             // variáveis para guardar as posições do botão

public:
    void Init();
    void Update();
    void Draw();
    void Finalize();
};

#endif // !HOME_H
