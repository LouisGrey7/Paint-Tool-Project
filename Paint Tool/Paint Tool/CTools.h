#pragma once
#include <SFML/Graphics.hpp>
#include <vector>



class CTools
{
private:

	sf::CircleShape* circleBrush;
	sf::RectangleShape* rectBrush;
	sf::Texture* brushTex;
	sf::VertexArray* lineBrush;
	std::vector<sf::Shape*> shapeVec;


public:
	//Constructor // Destructor
	CTools();
	~CTools();
	//Init
	void InitVariables();
	void InitBrush();
	void InitBrushTex();
	void InitRectBrush();
	void InitLineBrush();

	//Accessors
	sf::CircleShape* GetBrush();
	sf::RectangleShape* GetRectBrush();
	void SetBrushTex();
	void SetBrushPosition(sf::RenderWindow*);
	void SetLinePoints(sf::Vector2i _startmousepos, sf::Vector2i _endmousepos);
	sf::VertexArray* GetLineBrush();
	void SetRectangle(sf::Vector2i , sf::Vector2i , sf::RenderWindow*);
	std::vector<sf::Shape*> GetShapeVec();



};

