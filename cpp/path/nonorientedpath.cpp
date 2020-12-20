/*----------------------------------------------------------------------------
  GraphPainter
  Decembre 2020
-------------------------------------------------------------------------------*/
/**
* @file    nonorientedpath.cpp
* @author  Laurent VOURIOT
* @version 0.1
* @date    13/12/2020
*/
//-----------------------------------------------------------------------------
// INCLUDES
//-----------------------------------------------------------------------------
#include <QPainter>

#include "headers/path/nonorientedpath.h"

NonOrientedPath::NonOrientedPath(){}

void NonOrientedPath::drawPath(QMainWindow *window, AbsGraph *graph)
{
    QPainter pathPainter(window);
    // pour chaque sommet dans chaque colonne on dessine
    // une ligne entre chaque sommet
    for(unsigned i = 0; i < graph->getNodes().size(); i++)
    {
        for(unsigned j = 0; j < graph->getNodes().size(); j++)
        {
            if(graph->getMatrice()[i][j])
            {
             // NON ORIENTED PATH
                pathPainter.drawLine((*graph->getNodes()[i]->getCoord()),
                                     (*graph->getNodes()[j]->getCoord()));

            }
        }
    }
}
