#include "CTools.h"
#include <iostream>

//Constructor // Destructor
CTools::CTools()
{
	InitVariables();
	InitBrush();
	InitBrushTex();
	InitLineBrush();
	InitRectBrush();
}

CTools::~CTools()
{
	delete this->circleBrush;
	delete this->rectBrush;
	delete this->brushTex;

}

//Init
void CTools::InitVariables()
{
	this->circleBrush = nullptr;
	this->brushTex = nullptr;
	this->rectBrush = nullptr;
	
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
	this->brushTex->loadFromFile("paintBrushClear.png");
}

void CTools::InitRectBrush()
{
	//this->rectBrush = new sf::RectangleShape();
}

void CTools::InitLineBrush()
{
	this->lineBrush = new sf::VertexArray(sf::LinesStrip, 2);
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
	this->circleBrush->setPosition((float)mousepos.x,(float)mousepos.y);
}

sf::RectangleShape* CTools::GetRectBrush()
{
	return rectBrush;
}



void CTools::SetLinePoints(sf::Vector2i _startmousepos, sf::Vector2i _endmousepos)
{

	(*lineBrush)[0].position = sf::Vector2f(_startmousepos);
	(*lineBrush)[1].position = sf::Vector2f(_endmousepos);



}

sf::VertexArray* CTools::GetLineBrush()
{
	return lineBrush;
}

void CTools::SetRectangle(sf:: RenderTexture* _rtex, sf::Vector2f _resizediff, sf::Vector2i _startmousepos, sf::Vector2i _endmousepos, sf::RenderWindow* _window, sf::RectangleShape* _rectref)
{

	sf::Vector2i pixelPos = sf::Mouse::getPosition(*_window);
	sf::Vector2f mouseWorldPos = _window->mapPixelToCoords(pixelPos);

	if (_endmousepos.x == 0 && _endmousepos.y == 0)
	{
		_endmousepos = sf::Mouse::getPosition(*_window);
	}

	sf::Vector2f offSetVec;
	offSetVec.x = pixelPos.x - (_resizediff.x / 2);
	offSetVec.y = pixelPos.y - (_resizediff.y / 2);

	sf::Vector2f offsetVecOriginalPos;
	sf::Vector2i pixelPosOriginal = _startmousepos;
	offsetVecOriginalPos.x = pixelPosOriginal.x - (_resizediff.x / 2);
	offsetVecOriginalPos.y = pixelPosOriginal.y - (_resizediff.y / 2);



	sf::Vector2f diffVec(0.0f, 0.0f);
	diffVec.x = offSetVec.x - offsetVecOriginalPos.x;
	diffVec.y = offSetVec.y - offsetVecOriginalPos.y;


	_rectref->setSize(diffVec);
	

}

void CTools::SetCircle(sf::Vector2i _startmousepos, sf::Vector2i _endmousepos, sf::CircleShape* _circleref)
{
	int dX = _endmousepos.x - _startmousepos.x;
	int dY = _endmousepos.y - _startmousepos.y;
	float vectordistance = std::sqrt(dX * dX + dY * dY);

	_circleref->setScale(dX,dY);
}

std::vector<sf::Shape*> CTools::GetShapeVec()
{
	return shapeVec;
}

float VecDistance(sf::Vector2i _startmousepos, sf::Vector2i _endmousepos)
{
	int dX = _endmousepos.x - _startmousepos.x;
	int dY = _endmousepos.y - _startmousepos.y;
	float vectordistance = std::sqrt(dX * dX + dY * dY);
	return vectordistance;
}





