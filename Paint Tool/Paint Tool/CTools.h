#pragma once
#include <SFML/Graphics.hpp>

class CTools
{
private:

	sf::CircleShape* circleBrush;
	sf::RectangleShape* rectBrush;
	sf::Texture* brushTex;
	sf::VertexArray* lineBrush;


public:
	//Constructor // Destructor
	CTools();
	~CTools();

	//Functions
	void InitVariables();
	void InitBrush();
	void InitBrushTex();
	void InitRectBrush();
	void InitLineBrush();
	sf::CircleShape* GetBrush();
	sf::RectangleShape* GetRectBrush();
	void SetBrushTex();
	void SetBrushPosition(sf::RenderWindow*);
	void SetLinePoints(sf::Vector2i _startmousepos, sf::Vector2i _endmousepos);
	sf::VertexArray* GetLineBrush();
	void SetRectangle(sf::Vector2i _startmousepos, sf::Vector2i _endmousepos);


};

