#pragma once
#include "CWindow.h"
#include "SFML/Graphics.hpp"


class CCanvas
{
private:

	sf::RectangleShape* canvas;
	float xVal = 1280;
	float yVal = 720;
	void initVariables();
	void initCanvas();

	sf::RenderTexture* rTex;
	void initRTexture();

	sf::Texture* brushTexture;


public:

	CCanvas();
	~CCanvas();
	void SetRenderTexture();

};

