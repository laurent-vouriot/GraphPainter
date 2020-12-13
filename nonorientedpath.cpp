#include <QPainter>

#include "nonorientedpath.h"

NonOrientedPath::NonOrientedPath(){}

void NonOrientedPath::drawPath(QMainWindow *window, AbsGraph *graph)
{
    QPainter pathPainter(window);
    for(unsigned i = 0; i < graph->getNodes().size(); i++)
    {
        for(unsigned j = 0; j < graph->getNodes().size(); j++)
        {
           // NON ORIENTED PATH
            pathPainter.drawLine((*graph->getNodes()[i]->getCoord()),
                                 (*graph->getNodes()[j]->getCoord()));


        }
    }
}
