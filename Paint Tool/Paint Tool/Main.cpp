#include <iostream>
#include <vector>
#include "CWindow.h"
#include "CCanvas.h"
#include "SFML/Graphics.hpp"





int main()
{
    //Initialise
    CWindow MainWindow;
    CCanvas Canvas;
   
    
    sf::CircleShape circleBrush(15.0f);
    circleBrush.setOrigin(circleBrush.getRadius(), circleBrush.getRadius());
    circleBrush.setPosition(200, 200);
    circleBrush.setFillColor(sf::Color::Red);

    sf::Image* newImage = new sf::Image();
    newImage->create(MainWindow.GetxVal(), MainWindow.GetyVal(), sf::Color::White);


    //Paint Loop

    while (MainWindow.GetWindowIsOpen())
    {
        MainWindow.Update();
        MainWindow.Render();

        Canvas.SetRenderTexture();


           /*window.draw(*canvas)
            window.draw(circleBrush);*/
            

    }



    //End
    return 0;
}


