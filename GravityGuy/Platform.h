/**********************************************************************************
// Platform (Arquivo de Cabe�alho)
// 
// Cria��o:     21 Abr 2012
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Plataformas do jogo
//
**********************************************************************************/

#ifndef _SANCTUARY_PLATFORM_H_
#define _SANCTUARY_PLATFORM_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                                      // tipos espec�ficos da engine
#include "Object.h"                                     // interface de Object
#include "Sprite.h"                                     // desenho de sprites
#include "Image.h"  

// ---------------------------------------------------------------------------------

class Platform : public Object
{
private:
    Sprite * platform = nullptr;            // sprite da plataforma
    Sprite * platform2 = nullptr;            // sprite da plataforma
    Image* img;                       
    float xSprite;                 

public:
    Platform(float posX, float posY);       // construtor    
    ~Platform();                            // destrutor

    void Update();                          // atualiza��o do objeto
    void Draw();                            // desenho do objeto
}; 

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline


// ---------------------------------------------------------------------------------

#endif