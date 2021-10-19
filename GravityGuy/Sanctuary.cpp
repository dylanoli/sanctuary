/**********************************************************************************
// GravityGuy (Código Fonte)
// 
// Criação:     05 Out 2011
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Jogo estilo plataforma usando a engine do curso
//
**********************************************************************************/

#include "Engine.h"
#include "Sanctuary.h"
#include "Home.h"
#include "GameOver.h"

// ------------------------------------------------------------------------------

// inicializa membros estáticos da classe
Game*   Sanctuary::level = nullptr;
Player* Sanctuary::player = nullptr;
Audio*  Sanctuary::audio = nullptr;
bool    Sanctuary::viewBBox = false;

// ------------------------------------------------------------------------------

void Sanctuary::Init()
{
    // cria sistema de áudio
    audio = new Audio();
    audio->Add(MENU, "Resources/Menu.wav");
    audio->Add(MUSIC, "Resources/Music.wav");
    audio->Add(JUMP, "Resources/Transition.wav", 2);
    audio->Add(MUSIC2, "Resources/Music2.wav");
    audio->Add(FINAL, "Resources/Final.wav");

    // bounding box não visível
    viewBBox = false;

    // cria jogador
    player = new Player();

    // inicializa nível de abertura do jogo
    level = new Home();
    level->Init();
}

// ------------------------------------------------------------------------------

void Sanctuary::Update()
{
    // habilita/desabilita visualização da bounding box
    if (window->KeyPress('B'))
        viewBBox = !viewBBox;    

    // atualiza nível
    level->Update();
} 

// ------------------------------------------------------------------------------

void Sanctuary::Draw()
{
    // desenha nível
    level->Draw();
} 

// ------------------------------------------------------------------------------

void Sanctuary::Finalize()
{
    level->Finalize();

    delete player;
    delete audio;
    delete level;
}


// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    Engine * engine = new Engine();

    // configura o motor
    engine->window->Mode(WINDOWED);
    engine->window->Size(960, 540);
    engine->window->Color(0, 0, 0);
    engine->window->Title("Sanctuary Platform");
    engine->window->Icon(IDI_ICON);
    engine->window->Cursor(IDC_CURSOR);
    //engine->graphics->VSync(true);

    // inicia o jogo
    int status = engine->Start(new Sanctuary());

    delete engine;
    return status;
}

// ----------------------------------------------------------------------------

