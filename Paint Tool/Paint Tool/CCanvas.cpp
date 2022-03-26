#include "CCanvas.h"

//Constructor // Destructor
CCanvas::CCanvas()
{
	this->InitVariables();
	this->InitCanvas();
	this->InitRTexture();
}

CCanvas::~CCanvas()
{
	delete this->canvas;
	delete this->canvasTex;
}

//Init
void CCanvas::InitVariables()
{
	this->canvas = nullptr;
}

void CCanvas::InitCanvas()
{
	this->canvas = new sf::RectangleShape(sf::Vector2f(xVal, yVal));
	this->canvas->setSize(sf::Vector2f(xVal, yVal));
	this->canvas->setPosition(0, 0);
	this->canvas->setFillColor(sf::Color::White);
}

void CCanvas::InitRTexture()
{
	this->canvasTex = new sf::RenderTexture();
	this->canvasTex->create((int)xVal, (int)yVal);
	this->canvasTex->clear(sf::Color::White);
}



//Functions
void CCanvas::SetCanvasTexture()
{
	this->canvas->setTexture(&canvasTex->getTexture());
}

sf::RectangleShape* CCanvas::GetCanvas()
{
	return canvas;
}

sf::RenderTexture* CCanvas::GetCanvasTex()
{
	return canvasTex;
}

void CCanvas::DrawBrush(sf::Shape* _drawbrush)
{
	this->canvasTex->draw(*_drawbrush);
}

void CCanvas::DrawShapeVector(std::vector<sf::Shape*> _shapevec)
{

	for (int i = 0; i < _shapevec.size(); i++)
	{
		this->canvasTex->draw(*_shapevec[i]);

	}
}

void CCanvas::ClearCanvas()
{
	this->canvasTex->clear();

}

void CCanvas::DisplayTexture()
{
	this->canvasTex->display();
}










