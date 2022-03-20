#include <iostream>
#include "CWindow.h"

//Constructor //Destructor
CWindow::CWindow()
{
	this->InitVariables();
	this->InitWindow();
}

CWindow::~CWindow()
{
	delete this->window;
}


//Init
void CWindow::InitVariables()
{
	this->window = nullptr;
}

void CWindow::InitWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1280, 720), "LGPaint", sf::Style::Close | sf::Style::Resize);
}

//Accessors
int CWindow::GetxVal()
{
	return xVal;
}

int CWindow::GetyVal()
{
	return yVal;
}

sf::RenderWindow* CWindow::GetWindow()
{
    return window;
}

sf::Vector2i CWindow::GetStartMousePos()
{
    return sf::Vector2i();
}

bool CWindow::GetMouseDown()
{
    return mouseDown;
}

sf::Vector2i CWindow::GetEndMousePos()
{
    return sf::Vector2i();
}


const bool CWindow::GetWindowIsOpen()
{
	return this->window->isOpen();
}

//Update // Render // Draw
void CWindow::Update()
{
    while (this->window->pollEvent(event))
    {

            if (event.type == sf::Event::Closed)
            {
                this->window->close();
            }
            else if (event.type == sf::Event::Resized)
            {
                printf("New window width: %i New window Height: %i \n", event.size.width, event.size.height);
            }
            else if (event.type == sf::Event::TextEntered)
            {
                printf("%c", event.text.unicode);
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                mouseDown = true;
                sf::Vector2i startmousepos = sf::Mouse::getPosition(*window);
                std::cout << "Mouse Down True" << std::endl;
            }
            else if (event.type == sf::Event::MouseButtonReleased)
            {
                mouseDown = false;
                sf::Vector2i endmousepos = sf::Mouse::getPosition(*window);
                std::cout << "Mouse Down False" << std::endl;
            }
            else if (event.type == sf::Event::MouseMoved)
            {
                int mousexVal = sf::Mouse::getPosition(*window).x;
                int mouseyVal = sf::Mouse::getPosition(*window).y;

                std::cout << "Mouse Position "<< mousexVal << "," << mouseyVal << std::endl;
            }
        
    }
}

void CWindow::Clear()
{
    this->window->clear();
}



void CWindow::Display()
{
    this->window->display();
}

void CWindow::Draw(sf::Shape* _drawobject)
{
    this->window->draw(*_drawobject);
}
