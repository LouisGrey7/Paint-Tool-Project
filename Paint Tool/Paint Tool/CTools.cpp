#include "CTools.h"
#include <iostream>

//Constructor // Destructor
CTools::CTools()
{
	InitVariables();
	InitBrush();
	InitBrushTex();
}

CTools::~CTools()
{
	delete this->circleBrush;
}

//Init
void CTools::InitVariables()
{
	this->circleBrush = nullptr;
	this->brushTex = nullptr;
}

void CTools::InitBrush()
{
	this->circleBrush = new sf::CircleShape();
	this->circleBrush->setOrigin(circleBrush->getRadius(), circleBrush->getRadius());
	this->circleBrush->setPosition(200, 200);
	this->circleBrush->setRadius(5.0f);
	this->circleBrush->setFillColor(sf::Color::White);
}

void CTools::InitBrushTex()
{
	this->brushTex = new sf::Texture();
	this->brushTex->loadFromFile("paintBrush.png");
}

//Accessors
sf::CircleShape* CTools::GetBrush()
{
	return circleBrush;
}
void CTools::SetBrushTex()
{
	circleBrush->setTexture(brushTex);
}

//Functions
void CTools::SetBrushPosition(sf::RenderWindow* _rwindow)
{
	sf::Vector2i mousepos = sf::Mouse::getPosition(*_rwindow);
	this->circleBrush->setPosition(mousepos.x,mousepos.y);
}

void CTools::SetLinePoints(sf::Vector2i _startmousepos, sf::Vector2i _endmousepos)
{
	sf::VertexArray lines(sf::LinesStrip, 2);
	lines[0].position = (sf::Vector2f)_startmousepos;
	lines[1].position = (sf::Vector2f)_endmousepos;




}







