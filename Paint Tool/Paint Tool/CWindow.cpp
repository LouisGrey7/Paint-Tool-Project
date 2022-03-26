#include <iostream>
#include "CWindow.h"
#include "CColorPicker.h"
#include "mutex"


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

    this->canvasview.reset(sf::FloatRect(0, 0, 1280, 720));
    this->resizeDiff = sf::Vector2f(0, 0);
    this->initWindowSize = sf::Vector2f(1280, 720);

    this->currentRectRef = new sf::RectangleShape();
    this->currentRectRef->setPosition(sf::Vector2f(-200, 0));
    this->currentRectRef->setSize(sf::Vector2f(3.0f, 3.0f));
    this->currentRectRef->setFillColor(sf::Color::White);
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
       if (sf::Mouse::getPosition(*window).x > 0 && sf::Mouse::getPosition(*window).x <= (int)_image->getSize().x)
        {
            if (sf::Mouse::getPosition(*window).y > 0 && sf::Mouse::getPosition(*window).y <= (int)_image->getSize().y)
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

sf::Event CWindow::GetEvent()
{
    return event;
}


//Update // Render // Draw
void CWindow::Update(std::vector<sf::Shape*> _shapevec, sf::RenderTexture* _rtex)
{
    while (this->window->pollEvent(event))
    {

            if (event.type == sf::Event::Closed)
            {
                this->window->close();
            }
            else if (event.type == sf::Event::Resized)
            {
                canvasview.setSize(event.size.width, event.size.height);
                resizeDiff.x = event.size.width - initWindowSize.x;
                resizeDiff.y = event.size.height - initWindowSize.y;

                printf("New window width: %i New window Height: %i \n", event.size.width, event.size.height);

                window->setView(canvasview);
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                


                mouseDown = true;

                startmousepos = sf::Mouse::getPosition(*window);
                currentRectRef->setPosition(sf::Vector2f(sf::Mouse::getPosition(*window)));


                this->currentCircleRef = new sf::CircleShape();
                this->currentCircleRef->setOrigin(currentCircleRef->getRadius(), currentCircleRef->getRadius());
                this->currentCircleRef->setPosition(sf::Vector2f(startmousepos));
                this->currentCircleRef->setRadius(0.5f);
                this->currentCircleRef->setFillColor(sf::Color::White);

                std::cout << "creating";
                std::cout << "Mouse Down True" << std::endl;
                _shapevec.push_back(currentRectRef);
                
            }
            else if (event.type == sf::Event::MouseButtonReleased)
            {

                _rtex->draw(*currentRectRef);

                mouseDown = false;

                _rtex->draw(*currentCircleRef);

                
                std::cout << "Mouse Down False" << std::endl;
            }
            else if (event.type == sf::Event::MouseMoved)
            {
                _rtex->display();
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

void CWindow::Draw(sf::Drawable* _drawobject)
{
    this->window->draw(*_drawobject);
}


void CWindow::DrawVector(std::vector<sf::Shape*> _shapevec)
{
    for (int i = 0; i < _shapevec.size(); i++)
    {
        this->window->draw(*_shapevec[i]);
    }
}

sf::RectangleShape* CWindow::GetRectRef()
{
    return currentRectRef;
}

sf::CircleShape* CWindow::GetCircleRef()
{
    return currentCircleRef;
}

void CWindow::DrawSprite(sf::Sprite* _drawsprite)
{
    this->window->draw(*_drawsprite);
}

sf::Vector2f CWindow::GetResizeDiff()
{
    return resizeDiff;
}

bool CWindow::HasFocus()
{

    bool windowhasfocus = window->hasFocus();
    return windowhasfocus;

}
