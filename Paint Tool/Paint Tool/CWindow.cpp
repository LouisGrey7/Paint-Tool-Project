#include <iostream>
#include "CWindow.h"

void CWindow::initVariables()
{
	this->window = nullptr;

}

void CWindow::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1280, 720), "LGPaint");
}

CWindow::CWindow()
{
	this->initVariables();
	this->initWindow();
}

CWindow::~CWindow()
{
	delete this->window;
}

int CWindow::GetxVal()
{
	
	return xVal;
}

int CWindow::GetyVal()
{
	return yVal;
}

void CWindow::IsMouseDown()
{
    if (mouseDown)
    {

        /*circleBrush.setPosition((sf::Vector2f)sf::Mouse::getPosition(window));
        rTex->draw(circleBrush);
        rTex->display();*/

    }
}

const bool CWindow::GetWindowIsOpen()
{
	
	return this->window->isOpen();
}

void CWindow::Update()
{
    while (this->window->pollEvent(event))
    {

        if (event.type == sf::Event::Closed)
        {
            this->window->close();
        }
        else if (event.type == sf::Event::MouseButtonPressed)
        {
            mouseDown = true;
            std::cout << "Mouse Down True" << std::endl;
        }
        else if (event.type == sf::Event::MouseButtonReleased)
        {
            mouseDown = false;
            std::cout << "Mouse Down False" << std::endl;
        }
        else if (event.type == sf::Event::MouseMoved)
        {
           int mousexVal = sf::Mouse::getPosition(*window).x;
           int mouseyVal = sf::Mouse::getPosition(*window).y;

            std::cout << "Mouse Position "
                << mousexVal << "," << mouseyVal << std::endl;
        }


    }
}

void CWindow::Render()
{
    this->window->clear(sf::Color::White);
    this->window->display();
}
