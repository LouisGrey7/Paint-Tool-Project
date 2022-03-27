#include "CUserInt.h"


sf::String CUserInt::saveFile()
{
	return sf::String();
}

sf::String CUserInt::LoadFile()
{
	ZeroMemory(&currentFileName, sizeof(currentFileName));
	currentFileName.lStructSize = sizeof(currentFileName);

	currentFileName.hwndOwner = NULL;
	currentFileName.lpstrFile = (LPWSTR)szFile;
	currentFileName.lpstrFile[0] = '\0';
	currentFileName.nMaxFile = sizeof(szFile);

	currentFileName.lpstrFilter = L"ALL Files (*.*)\0*.*\0";
	currentFileName.nFilterIndex = 1;
	currentFileName.lpstrFileTitle = NULL;
	currentFileName.nMaxFileTitle = 0;
	currentFileName.lpstrInitialDir = NULL;
	currentFileName.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	GetOpenFileName(&currentFileName);

	return currentFileName.lpstrFile;

}

CUserInt::CUserInt()
{
	InitVariables();
	InitUI();
}

CUserInt::~CUserInt()
{
}

void CUserInt::InitVariables()
{
	
	PenMode currentmode = PenMode::MODE_CIRCLE;
}

void CUserInt::InitUI()
{

	this->freeButtonTex = new sf::Texture();
	this->freeButtonTex->loadFromImage(freeButtonImage);

	this->freeButtonImage.create(50, 30, sf::Color::White);
	this->freeButtonImage.loadFromFile("freebutton.png");

	this->freedrawButton = new sf::RectangleShape;
	this->freedrawButton->setSize(sf::Vector2f(50, 30));
	this->freedrawButton->setPosition(sf::Vector2f(10, 10));
	this->freedrawButton->setFillColor(sf::Color::Red);
	this->freedrawButton->setTexture(freeButtonTex);

	this->rectdrawButton = new sf::RectangleShape;
	this->rectdrawButton->setSize(sf::Vector2f(50, 30));
	this->rectdrawButton->setPosition(sf::Vector2f(70, 10));
	this->rectdrawButton->setFillColor(sf::Color::Green);

	this->circledrawButton = new sf::RectangleShape;
	this->circledrawButton->setSize(sf::Vector2f(50, 30));
	this->circledrawButton->setPosition(sf::Vector2f(190, 10));
	this->circledrawButton->setFillColor(sf::Color::Magenta);

	this->linedrawButton = new sf::RectangleShape;
	this->linedrawButton->setSize(sf::Vector2f(50, 30));
	this->linedrawButton->setPosition(sf::Vector2f(130, 10));
	this->linedrawButton->setFillColor(sf::Color::Blue);


	this->LoadButton = new sf::RectangleShape;
	this->LoadButton->setSize(sf::Vector2f(50, 30));
	this->LoadButton->setPosition(sf::Vector2f(250, 10));
	this->LoadButton->setFillColor(sf::Color::Cyan);
	

	uiButtonVector.push_back(freedrawButton);
	uiButtonVector.push_back(rectdrawButton);
	uiButtonVector.push_back(circledrawButton);
	uiButtonVector.push_back(linedrawButton);
	uiButtonVector.push_back(LoadButton);



}

void CUserInt::UpdateUI(sf::RenderWindow* _window)
{
	
		if (uiButtonVector[0]->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_window))))
		{
			 currentmode = PenMode::MODE_FREEDRAW;
			 freedrawButton->setFillColor(sf::Color::Black);
			 rectdrawButton->setFillColor(sf::Color::Green);
			 circledrawButton->setFillColor(sf::Color::Magenta);
			 linedrawButton->setFillColor(sf::Color::Blue);
			 LoadButton->setFillColor(sf::Color::Cyan);
		}
		if (uiButtonVector[1]->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_window))))
		{
			 currentmode = PenMode::MODE_RECT;
			 rectdrawButton->setFillColor(sf::Color::Black);
			 freedrawButton->setFillColor(sf::Color::Red);
			 circledrawButton->setFillColor(sf::Color::Magenta);
			 linedrawButton->setFillColor(sf::Color::Blue);
			 LoadButton->setFillColor(sf::Color::Cyan);
		}
		if (uiButtonVector[2]->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_window))))
		{
			 currentmode = PenMode::MODE_CIRCLE;
			 circledrawButton->setFillColor(sf::Color::Black);
			 freedrawButton->setFillColor(sf::Color::Red);
			 rectdrawButton->setFillColor(sf::Color::Green);
			 linedrawButton->setFillColor(sf::Color::Blue);
			 LoadButton->setFillColor(sf::Color::Cyan);
		}
		if (uiButtonVector[3]->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_window))))
		{
			 currentmode = PenMode::MODE_LINE;
			 linedrawButton->setFillColor(sf::Color::Black);
			 freedrawButton->setFillColor(sf::Color::Red);
			 rectdrawButton->setFillColor(sf::Color::Green);
			 circledrawButton->setFillColor(sf::Color::Magenta);
			 LoadButton->setFillColor(sf::Color::Cyan);
		}
		if (uiButtonVector[4]->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_window))))
		{
			std::string temp = LoadFile();
			
			LoadButton->setFillColor(sf::Color::Black);
			linedrawButton->setFillColor(sf::Color::Blue);
			freedrawButton->setFillColor(sf::Color::Red);
			rectdrawButton->setFillColor(sf::Color::Green);
			circledrawButton->setFillColor(sf::Color::Magenta);
			std::cout << temp << std::endl;
		}
}



sf::RectangleShape* CUserInt::GetButton()
{
	return freedrawButton;
}

std::vector<sf::Shape*> CUserInt::GetUIVector()
{
	return uiButtonVector;
}

void CUserInt::DrawUIVector(sf::RenderWindow* _window)
{
	for (int i = 0; i < uiButtonVector.size(); i++)
	{
		_window->draw(*uiButtonVector[i]);

	}
}

PenMode CUserInt::GetPenMode()
{
	return currentmode;
}

