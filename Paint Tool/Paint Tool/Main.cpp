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

        mainWindow.Update(tool.GetShapeVec(), canvas.GetCanvasTex());

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

            
                break;

            case PenMode::MODE_RECT:
               
               
                tool.SetRectangle(canvas.GetCanvasTex(), mainWindow.GetResizeDiff(), mainWindow.GetStartMousePos(), mainWindow.GetEndMousePos(), mainWindow.GetWindow(), mainWindow.GetRectRef());
                mainWindow.GetRectRef()->setFillColor(*colorPicker.GetColor());
                break;

            case PenMode::MODE_CIRCLE:

                tool.SetCircle(mainWindow.GetStartMousePos(), mainWindow.GetEndMousePos(), mainWindow.GetCircleRef());
                mainWindow.GetCircleRef()->setFillColor(*colorPicker.GetColor());
                break;

            default:
                break;
            }

        }

        mainWindow.Draw(mainWindow.GetRectRef());
        mainWindow.DrawVector(tool.GetShapeVec());
        canvas.SetCanvasTexture();
        canvas.DisplayTexture();
        tool.SetBrushTex();
        mainWindow.Draw(canvas.GetCanvas());
        mainUI.DrawUIVector(mainWindow.GetWindow());
        if (mainWindow.GetMouseDown() == true)
        {
            mainWindow.GetWindow()->draw(*mainWindow.GetRectRef());
        }
        mainWindow.Display();


    }
    //End
    return 0;
}


