#pragma once
#include "CWindow.h"
#include "SFML/Graphics.hpp"


class CCanvas
{
private:

	sf::RectangleShape* canvas;
	float xVal = 1280;
	float yVal = 720;
	void InitVariables();
	void InitCanvas();

	sf::RenderTexture* canvasTex;
	void InitRTexture();

	sf::Texture* brushTexture;


public:
	//Constructor //Destructor
	CCanvas();
	~CCanvas();

	//Accessors
	void SetCanvasTexture();
	sf::RectangleShape* GetCanvas();

	//Functions
	void DrawTexture(sf::Shape*);
	void DisplayTexture();

};

