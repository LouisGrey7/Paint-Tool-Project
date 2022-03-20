#pragma once
#include "SFML/Graphics.hpp"
#include "CCanvas.h"
#include "CTools.h"


class CWindow
{
private:

	sf::RenderWindow* window;
	sf::Event event;
	bool mouseDown = false;
	int xVal = 1280;
	int yVal = 720;
	sf::Vector2i startmousepos;
	sf::Vector2i endmousepos;
	void InitVariables();
	void InitWindow();
 

public: 
	//Contructors //Destructors
	CWindow();
	~CWindow();

	//Accessors
	const bool GetWindowIsOpen();
	int GetxVal();
	int GetyVal();
	sf::Vector2i GetStartMousePos();
	sf::Vector2i GetEndMousePos();
	sf::RenderWindow* GetWindow();
	bool GetMouseDown();


	//Update //Render // Draw
	void Update();
	void Clear();
	void Display();
	void Draw(sf::Shape*);

};

