/*----------------------------------------------------------------------------
  GraphPainter
  debut : Decembre 2020
-------------------------------------------------------------------------------*/
/**
* @file    mainwindow.cpp
* @author  Laurent VOURIOT
* @version 0.1
* @date    11/12/2020
*/


//-----------------------------------------------------------------------------
// INCLUDES
//-----------------------------------------------------------------------------
#include <math.h> // atan2

#include <QPainter>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, AbsGraph *graph)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_graph(graph)
{
    ui->setupUi(this);
}// mainWindow()

MainWindow::~MainWindow()
{
    delete ui;
}// ~mainWindow()

void MainWindow::drawNodes()
{
    QPainter nodePainter(this);
    // pour chaque sommet du graphe on crée un cerle autour de son
    // centre et son nom
    // TODO :https://stackoverflow.com/questions/42529740/getting-the-qpainter-drawtext-color-change-with-with-shader
    for(const Node *node:m_graph->getNodes())
    {
        nodePainter.drawEllipse((*node->getCoord()),10,10);
        // nodePainter.drawPoint((*node->getCoord()));
        nodePainter.drawText((*node->getCoord()),(*node->getName()));
    }
}// drawNodes()

void MainWindow::drawPaths()
{
    QPainter pathPainter(this);

    qreal arrowSize = 20;
    // on parcours la matrice d'adjacence et si il y true entre 2 sommet on dessine l'arête
    for(unsigned i = 0; i < m_graph->getNodes().size(); i++)
    {
        for(unsigned j = 0; j < m_graph->getNodes().size(); j++)
        {
            if(m_graph->getMatrice()[i][j])
            {


                    // ORIENTED PATH
                    QLineF line((*m_graph->getNodes()[i]->getCoord()),
                                (*m_graph->getNodes()[j]->getCoord()));

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

//                    // NON ORIENTED PATH
//                    pathPainter.drawLine((*m_graph->getNodes()[i]->getCoord()),
//                                         (*m_graph->getNodes()[j]->getCoord()));


             }
        }

    }
}// drawPaths()


void MainWindow::paintEvent(QPaintEvent *event)
{
    drawNodes();
    drawPaths();
}// paintEvent()
