/*----------------------------------------------------------------------------
  GraphPainter
  Decembre 2020
-------------------------------------------------------------------------------*/
/**
* @file    drawer.cpp
* @author  Laurent VOURIOT
* @version 0.1
* @date    13/12/2020
*/
//-----------------------------------------------------------------------------
// INCLUDES
//-----------------------------------------------------------------------------
#include <QPainter>

#include "headers/drawer.h"


Drawer::Drawer(StrategyPath *pathDrawer)
    : m_pathDrawer(pathDrawer)
{}

void Drawer::draw(AbsGraph *graph, QMainWindow *window)
{

    // DRAW NODES
    QPainter nodePainter(window);
    nodePainter.setPen(Qt::white);
    nodePainter.setBrush(Qt::white);

    //    namePainter.setPen(Qt::blue);
    //    namePainter.setBrush(Qt::blue);
    // pour chaque sommet du graphe on crée un cerle autour de son
    // centre et son nom
    // TODO :https://stackoverflow.com/questions/42529740/getting-the-qpainter-drawtext-color-change-with-with-shader
    for(const Node *node:graph->getNodes())
    {
        nodePainter.drawEllipse((*node->getCoord()),5,5);
        QPoint tmp = (*node->getCoord());
        tmp.setX(tmp.x() + 7);
        tmp.setY(tmp.y() + 7);
        nodePainter.drawText(tmp,(*node->getName()));
    }

    // DRAW PATHS
    m_pathDrawer->drawPath(window, graph);
}

