/**********************************************************************************
// BasicAI (Arquivo de Cabe�alho)
// 
// Cria��o:     23 Out 2012
// Atualiza��o: 11 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Demonstra��o de todas as IAs
//
**********************************************************************************/

#ifndef _BASICAI_H_
#define _BASICAI_H_

// ------------------------------------------------------------------------------

#include "Game.h"
#include "Audio.h"
#include "Scene.h"
#include "Background.h"
#include "Player.h"
#include "Hud.h"
#include "TileSet.h"
#include "Sprite.h"
#include "Animation.h"

// ------------------------------------------------------------------------------

enum Ids
{
    PLAYER,
    MISSILE,
    WALLHIT,
    STALKER,
    SHOOTER,
    REPEATER,
    SOLDIER,
    THEME,
    START,
    FIRE,
    EXPLODE,
    HITWALL,
    EXPLOSION,
    ALEATORIO,
    MENU,
    GAMEOVER,
};

enum GameState 
{
    START_MENU,
    START_RUNNING,
    PLAYING,
    STOP
};

// ------------------------------------------------------------------------------

class BasicAI : public Game
{
private:
    Background *backg = nullptr; // pano de fundo
    Hud *hud = nullptr;          // heads up display
    bool viewBBox = false;       // visualiza��o das bouding boxes
    uint state = GameState::START_MENU;

public:
    static Player *player; // ponteiro para o jogador
    static Audio *audio;   // sitema de �udio
    static Scene *scene;   // cena do jogo

    static Image *stalker;  // imagem do inimigo azul
    static Image *shooter;  // imagem do inimigo shooter
    static Image *repeater; // imagem do inimigo repeater
    static Image *soldier;  // imagem do inimigo soldier
    static Image* aleatorio;  // imagem do inimigo soldier

    static bool viewHUD; // hud vis�vel

    Sprite* logo;
    Sprite* gameOverLogo;
    TileSet* tileset;
    Animation* animation;
    bool isPlaying = false;
    bool isGameOver = false;
    Font* bold = nullptr;      // fonte para exibi��o negrito

    void Init();     // inicializa��o
    void Update();   // atualiza��o
    void Draw();     // desenho
    void Finalize(); // finaliza��o
};

// ---------------------------------------------------------------------------------

#endif