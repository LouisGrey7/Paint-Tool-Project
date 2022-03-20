#pragma once
#include <SFML/Graphics.hpp>

class CTools
{
private:

	sf::CircleShape* circleBrush;
	sf::Texture* brushTex;


public:
	//Constructor // Destructor
	CTools();
	~CTools();

	//Functions
	void InitVariables();
	void InitBrush();
	void InitBrushTex();
	sf::CircleShape* GetBrush();
	void SetBrushTex();
	void SetBrushPosition(sf::RenderWindow*);
	void SetLinePoints(sf::Vector2i _startmousepos, sf::Vector2i _endmousepos);


};

