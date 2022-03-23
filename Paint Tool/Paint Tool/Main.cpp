#include <iostream>
#include <vector>
#include "CWindow.h"
#include "CCanvas.h"
#include "CTools.h"
#include "CColorPicker.h"
#include "SFML/Graphics.hpp"



    enum class PenMode
    {
        MODE_FREEDRAW,
        MODE_LINE,
        MODE_RECT,
        MODE_CIRCLE

    };

int main()
{

    CWindow mainWindow(sf::Vector2u(1280,720));
    CWindow colorWindow(sf::Vector2u(256, 277));
    CCanvas canvas;
    CTools tool;
    CColorPicker colorPicker;



    PenMode currentmode = PenMode::MODE_RECT;

    while (mainWindow.GetWindowIsOpen())
    {

        mainWindow.Update();

        if (colorWindow.GetWindowIsOpen())
        {
            colorWindow.UpdateColorEvent(colorPicker.GetImage(), colorPicker.GetColor());

            colorWindow.Clear();
            colorWindow.DrawShape(colorPicker.GetRectShape());
            colorWindow.Display();
        }


        if (mainWindow.GetMouseDown() == true)
        {

        
            switch (currentmode)
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

                tool.SetRectangle(mainWindow.GetStartMousePos(), mainWindow.GetEndMousePos());
                tool.GetRectBrush()->setFillColor(*colorPicker.GetColor());
                canvas.DrawBrush(tool.GetRectBrush());

                break;
            case PenMode::MODE_CIRCLE:

                break;
            default:
                break;
            }

        }


        canvas.DisplayTexture();
        canvas.SetCanvasTexture();
        tool.SetBrushTex();
        mainWindow.DrawShape(canvas.GetCanvas());
        mainWindow.Display();


    }
    //End
    return 0;
}


