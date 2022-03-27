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
    
    //Main Paint Loop
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

                mainWindow.SetCurrentPen(0);
                tool.SetFreeDraw(mainWindow.GetWindow(), mainWindow.GetPenThickness());
                tool.GetBrush()->setFillColor(*colorPicker.GetColor());
                canvas.DrawBrush(tool.GetBrush());
                break;

            case PenMode::MODE_RECT:

                mainWindow.SetCurrentPen(1);
                tool.SetRectangle(canvas.GetCanvasTex(), mainWindow.GetResizeDiff(), mainWindow.GetStartMousePos(), mainWindow.GetEndMousePos(), mainWindow.GetWindow(), mainWindow.GetRectRef());
                mainWindow.GetRectRef()->setFillColor(*colorPicker.GetColor());
                break;

            case PenMode::MODE_CIRCLE:

                mainWindow.SetCurrentPen(2);
                tool.SetCircle(mainWindow.GetStartMousePos(), mainWindow.GetEndMousePos(), mainWindow.GetCircleRef());
                mainWindow.GetCircleRef()->setFillColor(*colorPicker.GetColor());
                break;

            case PenMode::MODE_LINE:

                mainWindow.SetCurrentPen(3);
                tool.SetLine(mainWindow.GetResizeDiff(), mainWindow.GetStartMousePos(), mainWindow.GetEndMousePos(), mainWindow.GetWindow(), mainWindow.GetLineRef(), mainWindow.GetPenThickness());
                mainWindow.GetLineRef()->setFillColor(*colorPicker.GetColor());
                break;

            default:
                break;
            }

        }

        //Draw and Display everything

        canvas.SetCanvasTexture();
        canvas.DisplayTexture();
        tool.SetBrushTex();
        mainWindow.Draw(canvas.GetCanvas());
        mainUI.DrawUIVector(mainWindow.GetWindow());
        if (mainWindow.GetMouseDown() == true)
        {
            if (mainUI.GetPenMode() == PenMode::MODE_RECT)
            mainWindow.GetWindow()->draw(*mainWindow.GetRectRef());
            if (mainUI.GetPenMode() == PenMode::MODE_CIRCLE)
            mainWindow.GetWindow()->draw(*mainWindow.GetCircleRef());
            if (mainUI.GetPenMode() == PenMode::MODE_LINE)
            mainWindow.GetWindow()->draw(*mainWindow.GetLineRef());
        }
        mainWindow.Display();


    }
    //End
    return 0;
}


