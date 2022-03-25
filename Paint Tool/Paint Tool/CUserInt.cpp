#include "CUserInt.h"


CUserInt::CUserInt()
{
	InitVariables();
	InitUI();
}

CUserInt::~CUserInt()
{
}

void CUserInt::InitVariables()
{
	sf::RectangleShape* button = nullptr;
}

void CUserInt::InitUI()
{
	this->freedrawButton = new sf::RectangleShape;
	this->freedrawButton->setSize(sf::Vector2f(50, 30));
	this->freedrawButton->setPosition(sf::Vector2f(10, 10));
	this->freedrawButton->setFillColor(sf::Color::Red);

	this->rectdrawButton = new sf::RectangleShape;
	this->rectdrawButton->setSize(sf::Vector2f(50, 30));
	this->rectdrawButton->setPosition(sf::Vector2f(70, 10));
	this->rectdrawButton->setFillColor(sf::Color::Green);

	this->linedrawButton = new sf::RectangleShape;
	this->linedrawButton->setSize(sf::Vector2f(50, 30));
	this->linedrawButton->setPosition(sf::Vector2f(130, 10));
	this->linedrawButton->setFillColor(sf::Color::Blue);

	this->circledrawButton = new sf::RectangleShape;
	this->circledrawButton->setSize(sf::Vector2f(50, 30));
	this->circledrawButton->setPosition(sf::Vector2f(190, 10));
	this->circledrawButton->setFillColor(sf::Color::Magenta);

	this->saveButton = new sf::RectangleShape;
	this->saveButton->setSize(sf::Vector2f(50, 30));
	this->saveButton->setPosition(sf::Vector2f(250, 10));
	this->saveButton->setFillColor(sf::Color::Black);
	

	uiElementVector.push_back(freedrawButton);
	uiElementVector.push_back(rectdrawButton);
	uiElementVector.push_back(linedrawButton);
	uiElementVector.push_back(circledrawButton);
	uiElementVector.push_back(saveButton);
}

void CUserInt::UpdateUI(sf::RenderWindow* _window)
{
	for (int i = 0; i < uiElementVector.size(); i++)
	{
		if (uiElementVector[i]->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_window))))
		{
			if (currentmode == PenMode::MODE_FREEDRAW)
			{
				currentmode = PenMode::MODE_RECT;
			}
			else if (currentmode == PenMode::MODE_RECT)
			{
				currentmode = PenMode::MODE_FREEDRAW;
			}

			std::cout << "mouse clicky" << std::endl;
		}
	}
}


sf::RectangleShape* CUserInt::GetButton()
{
	return freedrawButton;
}

std::vector<sf::Shape*> CUserInt::GetUIVector()
{
	return uiElementVector;
}

void CUserInt::DrawUIVector(sf::RenderWindow* _window)
{

	for (int i = 0; i < uiElementVector.size(); i++)
	{
		_window->draw(*uiElementVector[i]);

	}
}

PenMode CUserInt::GetPenMode()
{
	return currentmode;
}

