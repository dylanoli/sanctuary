/**********************************************************************************
// BasicAI (C�digo Fonte)
// 
// Cria��o:     23 Out 2012
// Atualiza��o: 11 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Demonstra��o de todas as IAs

//
**********************************************************************************/

#include "Resources.h"
#include "BasicAI.h"
#include "Engine.h"
#include "Delay.h"

// ------------------------------------------------------------------------------

Player *BasicAI::player = nullptr;
Audio *BasicAI::audio = nullptr;
Scene *BasicAI::scene = nullptr;
bool BasicAI::viewHUD = false;
Image *BasicAI::stalker = nullptr;
Image *BasicAI::shooter = nullptr;
Image *BasicAI::repeater = nullptr;
Image *BasicAI::soldier = nullptr;

// ------------------------------------------------------------------------------

void BasicAI::Init()
{
    // cria sistema de �udio
    audio = new Audio();
    audio->Add(START, "Resources/Start.wav");
    audio->Add(THEME, "Resources/Theme.wav");
    audio->Add(FIRE, "Resources/Fire.wav", 2);
    audio->Add(HITWALL, "Resources/Hitwall.wav", 5);
    audio->Add(EXPLODE, "Resources/Explode.wav", 3);
    audio->Add(SOLDIER, "Resources/Soldier.wav", 1);
    audio->Add(REPEATER, "Resources/Repeater.wav", 2);
    audio->Add(STALKER, "Resources/Stalker.wav", 2);
    audio->Add(SHOOTER, "Resources/Shooter.wav", 2);

    // ajusta volumes
    audio->Volume(START, 0.30f);
    audio->Volume(THEME, 0.60f);
    audio->Volume(FIRE, 0.10f);
    audio->Volume(EXPLODE, 0.15f);
    audio->Volume(SOLDIER, 0.90f);
    audio->Volume(REPEATER, 0.40f);
    audio->Volume(STALKER, 0.20f);
    audio->Volume(SHOOTER, 0.75f);

    // carrega imagens das geometrias
    stalker = new Image("Resources/Naves/Stalker.png");
    shooter = new Image("Resources/Naves/Shooter.png");
    repeater = new Image("Resources/Naves/Repeater.png");
    soldier = new Image("Resources/Naves/Soldier.png");

    // carrega/incializa objetos
    backg = new Background("Resources/Space.jpg");
    player = new Player();
    scene = new Scene();
    hud = new Hud();

    // adiciona objetos na cena
    scene->Add(player, MOVING);
    scene->Add(new Delay(), STATIC);

    // ----------------------
    // inicializa a viewport
    // ----------------------

    // calcula posi��o para manter viewport centralizada
    float difx = (game->Width() - window->Width()) / 2.0f;
    float dify = (game->Height() - window->Height()) / 2.0f;

    // inicializa viewport para o centro do mundo
    viewport.left = 0.0f + difx;
    viewport.right = viewport.left + window->Width();
    viewport.top = 0.0f + dify;
    viewport.bottom = viewport.top + window->Height();
}

// ------------------------------------------------------------------------------

void BasicAI::Update()
{
    // sai com o pressionamento da tecla ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

    // atualiza cena e calcula colis�es
    scene->Update();
    scene->CollisionDetection();

    // ---------------------------------------------------
    // atualiza a viewport
    // ---------------------------------------------------

    viewport.left = player->X() - window->CenterX();
    viewport.right = player->X() + window->CenterX();
    viewport.top = player->Y() - window->CenterY();
    viewport.bottom = player->Y() + window->CenterY();

    if (viewport.left < 0)
    {
        viewport.left = 0;
        viewport.right = window->Width();
    }
    else if (viewport.right > game->Width())
    {
        viewport.left = game->Width() - window->Width();
        viewport.right = game->Width();
    }

    if (viewport.top < 0)
    {
        viewport.top = 0;
        viewport.bottom = window->Height();
    }
    else if (viewport.bottom > game->Height())
    {
        viewport.top = game->Height() - window->Height();
        viewport.bottom = game->Height();
    }

    // ---------------------------------------------------

    // atualiza o painel de informa��es
    hud->Update();

    // ativa ou desativa a bounding box
    if (window->KeyPress('B'))
        viewBBox = !viewBBox;

    // ativa ou desativa o heads up display
    if (window->KeyPress('H'))
        viewHUD = !viewHUD;
}

// ------------------------------------------------------------------------------

void BasicAI::Draw()
{
    // desenha pano de fundo
    backg->Draw(viewport);

    // desenha a cena
    scene->Draw();

    // desenha o painel de informa��es
    if (viewHUD)
        hud->Draw();

    // desenha bounding box
    if (viewBBox)
        scene->DrawBBox();
}

// ------------------------------------------------------------------------------

void BasicAI::Finalize()
{
    delete audio;
    delete hud;
    delete scene;
    delete backg;

    delete stalker;
    delete shooter;
    delete repeater;
    delete soldier;
}

// ------------------------------------------------------------------------------
//                                  WinMain
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    // cria motor do jogo
    Engine *engine = new Engine();

    // configura janela
    //engine->window->Mode(WINDOWED);
    //engine->window->Size(1152, 648);
    engine->window->Mode(BORDERLESS);
    engine->window->Color(0, 0, 0);
    engine->window->Title("BasicAI");
    engine->window->Icon(IDI_ICON);
    engine->window->Cursor(IDC_CURSOR);
    engine->window->HideCursor(true);
    //engine->graphics->VSync(true);

    // cria o jogo
    Game *game = new BasicAI();

    // configura o jogo
    game->Size(3840, 2160);

    // inicia execu��o
    int status = engine->Start(game);

    // destr�i motor
    delete engine;

    // encerra
    return status;
}

// ----------------------------------------------------------------------------