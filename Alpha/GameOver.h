#include "Engine.h"
#include "Game.h"
#include "Sprite.h"
#include "Font.h"

#ifndef HOME_H
#define HOME_H

class GameOver : public Game {
private:
    Sprite* background = nullptr;           // Background
    Font* font = nullptr;                   // Fonte usada na tela de Game Over

public:
    static int score;                       // Variável estática usada para receber o score final
    void Init();
    void Update();
    void Draw();
    void Finalize();
};

#endif // !HOME_H
