#include "Engine.h"
#include "Game.h"
#include "Resources.h"
#include "Font.h"
#include "Sprite.h"
#include "Scene.h"
#include "Player.h"
#include "Background.h"
#include "Bullet.h"
#include "Monster.h"
#include "SpacedustCover.h"

#ifndef ALPHA_H
#define ALPHA_H

enum ObjTypes {
    PLAYER, MONSTER, BULLET, SPACEDUST
};

class Alpha : public Game
{
private:
    Background* backg = nullptr;            // Objeto que gerencia o background do jogo
    Font* font = nullptr;                   // Fonte usada no jogo
    float timer;                            // Variável usada para gerenciar o tempo de spawn

public:
    static Player* player;                  // Objeto do player
    static Scene* scene;                    // Objeto da cena
    static SpacedustCover* cover;           // Objeto que gerencia a sujeira que aparece quando o player bate em poeira espacial
    static int score;                       // Variável que guarda a pontuação na partida

    void Init();
    void Update();
    void Draw();
    void Finalize();
};

#endif // !ALPHA_H
