#pragma once
#include "SFML/Graphics.hpp"
#include "CCanvas.h"
#include "CTools.h"
#include "CUserInt.h"
#include "CColorPicker.h"


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
	void InitWindow(sf::Vector2u);
	sf::RectangleShape* currentRectRef;
 

public: 
	//Contructors //Destructors
	CWindow(sf::Vector2u);
	~CWindow();

	//Accessors
	const bool GetWindowIsOpen();
	void SetxVal(int _xval);
	int GetxVal();
	void SetyVal(int _yval);
	int GetyVal();
	sf::Event GetEvent();
	void SetWindowSize(sf::Vector2u _winsize);
	void SetWindowView(sf::View*);
	sf::Vector2i GetStartMousePos();
	sf::Vector2i GetEndMousePos();
	sf::RenderWindow* GetWindow();
	bool GetMouseDown();
	sf::RectangleShape* GetRectRef();

	//Update //Render // Draw
	void Update();
	void UpdateColorEvent(sf::Image* _image, sf::Color* _pencolor);
	void Clear();
	void Display();
	void Draw(sf::Drawable*);
	void DrawSprite(sf::Sprite*);

	//Functions
	bool HasFocus();

};

