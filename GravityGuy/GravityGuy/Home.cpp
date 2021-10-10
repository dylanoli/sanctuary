#include "Home.h"
#include "Engine.h"

// ------------------------------------------------------------------------------

void Home::Init()
{
	backg = new Sprite("Resources/Home/Background.png");
    logo = new Sprite("Resources/Home/Logo.png");
    startMessage = new Sprite("Resources/Home/StartMessage.png");
}

// ------------------------------------------------------------------------------

void Home::Update()
{
    if (ctrlKeyESC && window->KeyDown(VK_ESCAPE))
    {
        ctrlKeyESC = false;
        window->Close();
    }
    else if (window->KeyUp(VK_ESCAPE))
    {
        ctrlKeyESC = true;
    }

    // passa ao primeiro nível com ENTER
    //if (window->KeyDown(VK_RETURN))
      //  Engine::Next<Level1>();
}

// ------------------------------------------------------------------------------

void Home::Draw()
{
	backg->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
    logo->Draw(float(window->CenterX()), float(window->CenterY() - 100.0f), Layer::FRONT);
    startMessage->Draw(float(window->CenterX()), float(window->CenterY() + 70.0f), Layer::FRONT);
}

// ------------------------------------------------------------------------------

void Home::Finalize()
{
    delete backg;
    delete logo;
    delete startMessage;
}

// ------------------------------------------------------------------------------
