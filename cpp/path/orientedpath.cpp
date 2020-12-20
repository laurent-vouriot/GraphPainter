/*----------------------------------------------------------------------------
  GraphPainter
  Decembre 2020
-------------------------------------------------------------------------------*/
/**
* @file    orientedpath.cpp
* @author  Laurent VOURIOT
* @version 0.1
* @date    13/12/2020
*/
//-----------------------------------------------------------------------------
// INCLUDES
//-----------------------------------------------------------------------------
#include <math.h> // atan2

#include <QPainter>

#include "headers/path/orientedpath.h"

OrientedPath::OrientedPath() {}

void OrientedPath::drawPath(QMainWindow *window, AbsGraph *graph)
{
    QPainter pathPainter(window);
    QColor color(0,0,0);
    pathPainter.setPen(color);

    qreal arrowSize = 10;
    // on parcours la matrice d'adjacence et si il y true entre 2 sommet on dessine l'arête
    for(unsigned i = 0; i < graph->getNodes().size(); i++)
    {
        for(unsigned j = 0; j < graph->getNodes().size(); j++)
        {
            if(graph->getMatrice()[i][j])
            {

                    // source : doc qt
                    // pour dessiner un triangle au bout de la ligne
                    // ORIENTED PATH
                    QLineF line((*graph->getNodes()[i]->getCoord()),
                                (*graph->getNodes()[j]->getCoord()));



                    double angle = std::atan2(-line.dy(), line.dx());
                    QPointF arrowP1 = line.p1() + QPointF(sin(angle + M_PI / 3) * arrowSize,
                                                          cos(angle + M_PI / 3) * arrowSize);
                    QPointF arrowP2 = line.p1() + QPointF(sin(angle + M_PI - M_PI / 3) * arrowSize,
                                                          cos(angle + M_PI - M_PI / 3) * arrowSize);

                    QPolygonF arrowHead;
                    arrowHead.clear();
                    arrowHead << line.p1() << arrowP1 << arrowP2;
                    pathPainter.drawLine(line);
                    pathPainter.drawPolygon(arrowHead);
             }
        }
    }
}// drawPath()
