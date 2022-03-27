#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>
#include <Windows.h>
#include <commdlg.h>
#include <string>
#include "CWindow.h"
#include "CTools.h"

enum class PenMode
{
	MODE_FREEDRAW,
	MODE_LINE,
	MODE_RECT,
	MODE_CIRCLE
};

class CUserInt
{
private:

	sf::RectangleShape* freedrawButton;
	sf::Image freeButtonImage;
	sf::Texture* freeButtonTex;

	sf::RectangleShape* rectdrawButton;
	sf::Image rectButtonImage;
	sf::RectangleShape* linedrawButton;
	sf::Image lineButtonImage;
	sf::RectangleShape* circledrawButton;
	sf::Image circleButtonImage;
	sf::RectangleShape* LoadButton;
	sf::Image saveButtonImage;
	std::vector<sf::Shape*> uiButtonVector;
	PenMode currentmode;


public:

	OPENFILENAME currentFileName;

	char szFile[100];

	template<typename T>
	static T maxValue(T x, T y)
	{
		std::cout << sizeof(x) << "," << sizeof(y) << std::endl;
		return (x > y) ? x: y;
	}

	sf::String saveFile();
	sf::String LoadFile();


	//Constructor  //Destructor
	CUserInt();
	~CUserInt();

	//Init
	void InitVariables();
	void InitUI();
	void UpdateUI(sf::RenderWindow*);

	//Accessors
	sf::RectangleShape* GetButton();
	std::vector<sf::Shape*> GetUIVector();
	void DrawUIVector(sf::RenderWindow* _window);
	PenMode GetPenMode();
	//Functions

};

