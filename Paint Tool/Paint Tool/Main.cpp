#include <iostream>
#include <vector>
#include "CWindow.h"
#include "CCanvas.h"
#include "CTools.h"
#include "CColorPicker.h"
#include "CUserInt.h"
#include "SFML/Graphics.hpp"


int main()
{

    CWindow mainWindow(sf::Vector2u(1280,720));
    CWindow colorWindow(sf::Vector2u(256, 277));
    CCanvas canvas;
    CTools tool;
    CUserInt mainUI;
    CColorPicker colorPicker;
    
    

    while (mainWindow.GetWindowIsOpen())
    {

        mainWindow.Update();

        if (colorWindow.GetWindowIsOpen() && colorWindow.HasFocus())
        {
            colorWindow.UpdateColorEvent(colorPicker.GetImage(), colorPicker.GetColor());

            colorWindow.Clear();
            colorWindow.Draw(colorPicker.GetRectShape());
            colorWindow.Display();
        }



        if (mainWindow.GetMouseDown() == true)
        {

        mainUI.UpdateUI(mainWindow.GetWindow());
            

            switch (mainUI.GetPenMode())
            {
            case PenMode::MODE_FREEDRAW:

                tool.SetBrushPosition(mainWindow.GetWindow());
                tool.GetBrush()->setFillColor(*colorPicker.GetColor());
                canvas.DrawBrush(tool.GetBrush());
                break;

            case PenMode::MODE_LINE:

                tool.GetBrush()->setFillColor(*colorPicker.GetColor());
                tool.SetLinePoints(mainWindow.GetStartMousePos(), mainWindow.GetEndMousePos());
                canvas.DrawVertex(tool.GetLineBrush());
                break;


            case PenMode::MODE_RECT:
               
                    tool.GetRectBrush()->setPosition(sf::Vector2f(mainWindow.GetStartMousePos()));
                    tool.SetRectangle(mainWindow.GetStartMousePos(), mainWindow.GetEndMousePos(), mainWindow.GetWindow());
                    tool.GetRectBrush()->setFillColor(*colorPicker.GetColor());
                    canvas.DrawBrush(tool.GetRectBrush());
                    
                
                break;
            case PenMode::MODE_CIRCLE:

                break;
            default:
                break;
            }

        }


        canvas.SetCanvasTexture();
        canvas.DisplayTexture();
        tool.SetBrushTex();
        mainWindow.Draw(canvas.GetCanvas());
        mainUI.DrawUIVector(mainWindow.GetWindow());
        mainWindow.Display();


    }
    //End
    return 0;
}


