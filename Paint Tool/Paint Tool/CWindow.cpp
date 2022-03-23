#include <iostream>
#include "CWindow.h"
#include "CColorPicker.h"

//Constructor //Destructor
CWindow::CWindow(sf::Vector2u _size)
{
	this->InitVariables();
	this->InitWindow(_size);
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

void CWindow::InitWindow(sf::Vector2u _size)
{
	this->window = new sf::RenderWindow(sf::VideoMode(_size.x,_size.y), "LGPaint", sf::Style::Close | sf::Style::Resize);
}

//Accessors


void CWindow::SetxVal(int _xval)
{
    xVal = _xval;
}


int CWindow::GetxVal()
{
	return xVal;
}


void CWindow::SetyVal(int _yval)
{
    yVal = _yval;
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
    return startmousepos;
}


bool CWindow::GetMouseDown()
{
    return mouseDown;
}

sf::Vector2i CWindow::GetEndMousePos()
{
    return endmousepos;
}


void CWindow::SetWindowSize(sf::Vector2u _winsize)
{
    this->window->setSize(_winsize);
}

void CWindow::UpdateColorEvent(sf::Image* _image, sf::Color* _pencolor)
{
    while (this->window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
           this->window->close();
        }


    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
       if (sf::Mouse::getPosition(*window).x > 0 && sf::Mouse::getPosition(*window).x <= _image->getSize().x)
        {
            if (sf::Mouse::getPosition(*window).y > 0 && sf::Mouse::getPosition(*window).y <= _image->getSize().y)
            {
                *_pencolor = _image->getPixel(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y);
            }

        }
    }
}


const bool CWindow::GetWindowIsOpen()
{
	return this->window->isOpen();
}

void CWindow::SetWindowView(sf::View* _view)
{

    window->setView(*_view);

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
                startmousepos = sf::Mouse::getPosition(*window);
                std::cout << "Mouse Down True" << std::endl;
            }
            else if (event.type == sf::Event::MouseButtonReleased)
            {
                mouseDown = false;
                std::cout << "Mouse Down False" << std::endl;
            }
            else if (event.type == sf::Event::MouseMoved)
            {
                endmousepos = sf::Mouse::getPosition(*window);
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


void CWindow::DrawShape(sf::Shape* _drawobject)
{
    this->window->draw(*_drawobject);
}

void CWindow::DrawSprite(sf::Sprite* _drawsprite)
{
    this->window->draw(*_drawsprite);
}