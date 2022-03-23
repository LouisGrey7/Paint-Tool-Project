#pragma once
#include "CWindow.h"
#include <vector>
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
	void DrawBrush(sf::Shape*);
	void DrawRectBrush(std::vector <sf::RectangleShape>*);
	void DrawVertex(sf::VertexArray*);
	void ClearCanvas();
	void DisplayTexture();

};

