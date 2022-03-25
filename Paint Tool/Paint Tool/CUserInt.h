#pragma once
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "CWindow.h"
#include "CTools.h"

enum class PenMode
{
	MODE_FREEDRAW,
	MODE_LINE,
	MODE_RECT,
	MODE_CIRCLE

};

class CUserInt
{
private:

	sf::RectangleShape* freedrawButton;
	sf::RectangleShape* rectdrawButton;
	sf::RectangleShape* linedrawButton;
	sf::RectangleShape* circledrawButton;
	sf::RectangleShape* saveButton;
	std::vector<sf::Shape*> uiElementVector;
	PenMode currentmode;

public:

	//Constructor  //Destructor
	CUserInt();
	~CUserInt();


	//Init
	void InitVariables();
	void InitUI();
	void UpdateUI(sf::RenderWindow*);

	//Accessors
	sf::RectangleShape* GetButton();
	std::vector<sf::Shape*> GetUIVector();
	void DrawUIVector(sf::RenderWindow* _window);
	PenMode GetPenMode();
	//Functions

};

