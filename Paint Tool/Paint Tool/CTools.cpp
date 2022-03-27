#include "CTools.h"
#include <iostream>
#include <math.h>

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
	delete this->brushTex;
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
	this->brushTex->loadFromFile("paintBrushClear.png");
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
void CTools::SetFreeDraw(sf::RenderWindow* _rwindow, int _penthick)
{

	sf::Vector2i mousepos = sf::Mouse::getPosition(*_rwindow);
	this->circleBrush->setPosition((float)mousepos.x,(float)mousepos.y);
	this->circleBrush->setRadius(_penthick);
	this->circleBrush->setOrigin(circleBrush->getRadius(), circleBrush->getRadius());
}


void CTools::SetCircle(sf::Vector2i _startmousepos, sf::Vector2i _endmousepos, sf::CircleShape* _circleref)
{
	int dX = _endmousepos.x - _startmousepos.x;
	int dY = _endmousepos.y - _startmousepos.y;
	float vectordistance = std::sqrt(dX * dX + dY * dY);


	_circleref->setScale(dX,dY);
}

void CTools::SetLine(sf::Vector2f _resizediff, sf::Vector2i _startmousepos, sf::Vector2i _endmousepos, sf::RenderWindow* _window, sf::RectangleShape* _lineref, int _penthick)
{
	int VX = _endmousepos.x - _startmousepos.x;
	int VY = _endmousepos.y - _startmousepos.y;
	float vectordistance = std::sqrt(VX * VX + VY * VY);

	sf::Vector2i pixelPos = sf::Mouse::getPosition(*_window);
	sf::Vector2f offSetVec;
	offSetVec.x = pixelPos.x - (_resizediff.x / 2);

	double pi = 2 * acos(0.0);
	float dX = _endmousepos.x - _startmousepos.x;
	float dY = _endmousepos.y - _startmousepos.y;
	float R1 = (atan2(dY , dX)) * 180 / pi ;

	
	_lineref->setScale(sf::Vector2f(vectordistance, _penthick));
	_lineref->setRotation(R1);

}

void CTools::SetRectangle(sf::RenderTexture* _rtex, sf::Vector2f _resizediff, sf::Vector2i _startmousepos, sf::Vector2i _endmousepos, sf::RenderWindow* _window, sf::RectangleShape* _rectref)
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





