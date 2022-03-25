#pragma once
#include "SFML/Graphics.hpp"

class CColorPicker
{
private:
    sf::View* toolView;
    sf::Image* colorImage;
    sf::Texture* colorTex;
    sf::RectangleShape* colorRect;
    sf::Sprite* colorSprite;
    sf::Color* penColor;

public:
    //Constructor // Destructor
    CColorPicker();
    ~CColorPicker();
    //Init
    void InitVariables();
    void InitView();
    void InitImage();
    void InitTexture();
    void InitRectangleShape();
    void InitSprite();
    void InitColor();
    //Accessors
    sf::View* GetView();
    sf::Image* GetImage();
    sf::Texture* GetTexture();
    sf::RectangleShape* GetRectShape();
    sf::Sprite* GetSprite();
    sf::Color* GetColor();
    //Functions
    


};

