#include "CCanvas.h"

void CCanvas::initVariables()
{
}

void CCanvas::initCanvas()
{
	this->canvas = new sf::RectangleShape();
	canvas->setSize(sf::Vector2f(xVal, yVal));
	canvas->setPosition(0, 0);
}

void CCanvas::initRTexture()
{
	this->rTex = new sf::RenderTexture();
	rTex->create(1280, 720);
	rTex->clear(sf::Color::White);
}
//Constructor // Destructor
CCanvas::CCanvas()
{
	this->initVariables();
	this->initCanvas();
	this->initRTexture();
}

CCanvas::~CCanvas()
{
	delete this->canvas;
	delete this->rTex;
}


//Functions
void CCanvas::SetRenderTexture()
{
	canvas->setTexture(&rTex->getTexture());
}






