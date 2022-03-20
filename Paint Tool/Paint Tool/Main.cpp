#include <iostream>
#include <vector>
#include "CWindow.h"
#include "CCanvas.h"
#include "CTools.h"
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

    CWindow mainwindow;
    CCanvas canvas;
    CTools tool;


    PenMode currentmode = PenMode::MODE_FREEDRAW;

    while (mainwindow.GetWindowIsOpen())
    {

        mainwindow.Update();
        
        if (mainwindow.GetMouseDown() == true)
        {


        switch (currentmode)
        {
        case PenMode::MODE_FREEDRAW:
            tool.SetBrushPosition(mainwindow.GetWindow());
            canvas.DrawTexture(tool.GetBrush());
            canvas.DisplayTexture();
            break;
        case PenMode::MODE_LINE:
            tool.SetLinePoints(mainwindow.GetStartMousePos(), mainwindow.GetEndMousePos());
            mainwindow.Draw();
            break;
        case PenMode::MODE_RECT:

            break;
        case PenMode::MODE_CIRCLE:

            break;
        default:
            break;
        }

        }


        canvas.SetCanvasTexture();
        tool.SetBrushTex();
        mainwindow.Draw(canvas.GetCanvas());
        mainwindow.Display();


    }
    //End
    return 0;
}


