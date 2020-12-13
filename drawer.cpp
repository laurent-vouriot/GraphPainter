#include <QPainter>

#include "drawer.h"


Drawer::Drawer(StrategyPath *pathDrawer)
    : m_pathDrawer(pathDrawer)
{}

void Drawer::draw(AbsGraph *graph, QMainWindow *window)
{

    // DRAW NODES
    QColor color(0,0,0);
    QPainter nodePainter(window);
    nodePainter.setPen(color);
    // pour chaque sommet du graphe on crée un cerle autour de son
    // centre et son nom
    // TODO :https://stackoverflow.com/questions/42529740/getting-the-qpainter-drawtext-color-change-with-with-shader
    for(const Node *node:graph->getNodes())
    {
        nodePainter.drawEllipse((*node->getCoord()),10,10);
        // nodePainter.drawPoint((*node->getCoord()));
        nodePainter.drawText((*node->getCoord()),(*node->getName()));
    }

    m_pathDrawer->drawPath(window, graph);

}

