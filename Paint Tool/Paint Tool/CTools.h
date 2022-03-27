#pragma once
#include <SFML/Graphics.hpp>
#include <vector>



class CTools
{
private:

	sf::CircleShape* circleBrush;
	sf::Texture* brushTex;
	std::vector<sf::Shape*> shapeVec;


public:
	//Constructor // Destructor
	CTools();
	~CTools();

	//Init
	void InitVariables();
	void InitBrush();
	void InitBrushTex();

	//Accessors
	sf::CircleShape* GetBrush();
	sf::RectangleShape* GetRectBrush();
	void SetBrushTex();
	void SetFreeDraw(sf::RenderWindow*, int);
	sf::VertexArray* GetLineBrush();
	void SetRectangle(sf::RenderTexture*, sf::Vector2f, sf::Vector2i , sf::Vector2i , sf::RenderWindow*, sf::RectangleShape*);
	void SetCircle(sf::Vector2i _startmousepos, sf::Vector2i _endmousepos, sf::CircleShape*);
	void SetLine(sf::Vector2f, sf::Vector2i, sf::Vector2i, sf::RenderWindow*, sf::RectangleShape*, int);
	std::vector<sf::Shape*> GetShapeVec();



};

