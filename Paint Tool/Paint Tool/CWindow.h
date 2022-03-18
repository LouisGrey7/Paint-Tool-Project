#pragma once
#include "SFML/Graphics.hpp"
#include "CCanvas.h"


class CWindow
{
private:

	sf::RenderWindow* window;
	sf::Event event;
	bool mouseDown = false;
	int xVal = 1280;
	int yVal = 720;
	void initVariables();
	void initWindow();
 

public: 
	//Contructors //Destructors
	CWindow();
	~CWindow();

	//Accessors
	const bool GetWindowIsOpen();
	int GetxVal();
	int GetyVal();

	//Functions
	void IsMouseDown();
	void Update();
	void Render();


};

