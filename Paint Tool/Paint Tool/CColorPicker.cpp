#include "CColorPicker.h"


//Constructor // Destructor
CColorPicker::CColorPicker()
{
    InitVariables();
    InitView();
    InitImage();
    InitTexture();
    InitRectangleShape();
    InitSprite();
    InitColor();
}

CColorPicker::~CColorPicker()
{
    delete this->toolView;
    delete this->colorImage;
    delete this->colorTex;
    delete this->colorRect;
    delete this->colorSprite;
    
}

//Init
void CColorPicker::InitVariables()
{
    this->toolView = nullptr;
    this->colorImage = nullptr;
    this->colorTex = nullptr;
    this->colorRect = nullptr;
    this->colorSprite = nullptr;
    
}

void CColorPicker::InitView()
{
    this->toolView = new sf::View();
    this->toolView->reset(sf::FloatRect(128, 136, 256, 277));
}

void CColorPicker::InitImage()
{
    this->colorImage = new sf::Image();
    this->colorImage->create(256, 277, sf::Color::White);
    this->colorImage->loadFromFile("colorImage.png");
}

void CColorPicker::InitTexture()
{
    this->colorTex = new sf::Texture();
    this->colorTex->loadFromImage(*colorImage);
}

void CColorPicker::InitRectangleShape()
{
    this->colorRect = new sf::RectangleShape();
    this->colorRect->setSize(sf::Vector2f(256, 277));
    this->colorRect->setTexture(colorTex);
}

void CColorPicker::InitSprite()
{
    this->colorSprite = new sf::Sprite();
    this->colorSprite->setTexture(*colorTex);
}

void CColorPicker::InitColor()
{
    this->penColor = new sf::Color(sf::Color::Red);
}

//Accessors
sf::View* CColorPicker::GetView()
{
    return toolView;
}

sf::Image* CColorPicker::GetImage()
{
    return colorImage;
}

sf::Texture* CColorPicker::GetTexture()
{
    return colorTex;
}

sf::RectangleShape* CColorPicker::GetRectShape()
{
    return colorRect;
}

sf::Sprite* CColorPicker::GetSprite()
{
    return colorSprite;
}

sf::Color* CColorPicker::GetColor()
{
    return penColor;
}

//void CColorPicker::SetColor(sf::RenderWindow* _window)
//{
//    penColor = colorImage->getPixel(sf::Mouse::getPosition(*_window).x, sf::Mouse::getPosition(*_window).y);
//}



