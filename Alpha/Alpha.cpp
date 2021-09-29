#include "Alpha.h"
#include "Spacedust.h"
#include "SpacedustCover.h"
#include "Random.h"
#include "GameOver.h"

// ------------------------------------------------------------------------------

// inicialização das variáveis estáticas
Player* Alpha::player = nullptr;
Scene* Alpha::scene = nullptr;
SpacedustCover* Alpha::cover = nullptr;
int Alpha::score = 0;

// ------------------------------------------------------------------------------

void Alpha::Init()
{
    timer = 0;

    scene = new Scene();

    font = new Font("Resources/Joystix22.png");
    font->Spacing("Resources/Joystix22.dat");

    player = new Player();
    player->MoveTo(window->CenterX(), window->CenterY());
    scene->Add(player, MOVING);
    
    backg = new Background();
    backg->MoveTo(window->CenterX(), window->CenterY());
    scene->Add(backg, STATIC);

    cover = new SpacedustCover();
    cover->MoveTo(window->CenterX(), window->CenterY());
    scene->Add(cover, STATIC);
}

// ------------------------------------------------------------------------------

void Alpha::Update()
{
    timer += gameTime;

    // se o botão esquerdo do mouse for clicado, calcula a direção do mouse em relação ao player
    // e instancia uma bala saindo do player na direção calculada
    if (window->KeyClicked(VK_LBUTTON)) {
        float dx = player->X() - window->MouseX() - scene->camera2d->X();
        float dy = player->Y() - window->MouseY() - scene->camera2d->Y();

        Vector2* direction = new Vector2(dx, dy, TypeVector::CARTESIAN);
        float angle = direction->Angle();
        direction->SetPolar(1200, angle + 180);
        Bullet* bullet = new Bullet(player->X(), player->Y(), direction);
        scene->Add(bullet, MOVING);
    }

    // a cada meio segundo, instancia um monstro ou poeira
    if (timer >= 0.5f) {
        timer = 0.0f;
        
        Random rand(0, 1);
        if (rand.RandomInt() == 0) {
            Monster* monster = new Monster();
            scene->Add(monster, MOVING);
        }
        else {
            Spacedust* spacedust = new Spacedust();
            scene->Add(spacedust, MOVING);
        }
    }

    scene->Update();
    scene->CollisionDetection();
    
    // se vida do player menor ou igual a 0 ou esc for pressionado, vai para a tela de Game Over
    if (player->Health() <= 0 || window->KeyClicked(VK_ESCAPE)) {
        GameOver::score = score;
        Engine::Next<GameOver>();
    }
} 

// ------------------------------------------------------------------------------

void Alpha::Draw()
{
    scene->Draw();
    
    // escreve a vida do player e o score atual na tela
    Color white = { 1,1,1,1 };
    string str = "Health: " + std::to_string(player->Health());
    string str2 = "Score: " + std::to_string(score);

    font->Draw(30 + Scene::camera2d->X(), 30 + Scene::camera2d->Y(), str, white, Layer::FRONT);
    font->Draw(30 + Scene::camera2d->X(), 60 + Scene::camera2d->Y(), str2, white, Layer::FRONT);
} 

// ------------------------------------------------------------------------------

void Alpha::Finalize()
{
    // deleta todas os objetos alocados, até os estáticos de outras classes
    delete scene;
    delete font;
    if (Bullet::image)
        delete Bullet::image;
    if (Monster::tiles)
        delete Monster::tiles;
    if (Spacedust::tiles)
        delete Spacedust::tiles;
}
