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
#include <QPainter>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent ,Graph *graph)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_graph(graph)
{
    ui->setupUi(this);
}// mainWindow()

MainWindow::~MainWindow()
{
    delete ui;
    delete m_graph;
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
    // on parcours la matrice d'adjacence et si il y true entre 2 sommet on dessine l'arête
    for(unsigned i = 0; i < m_graph->getNodes().size(); i++)
    {
        for(unsigned j = 0; j < m_graph->getNodes().size(); j++)
        {
            if(m_graph->getMatrice()[i][j])
            {
                pathPainter.drawLine((*m_graph->getNodes()[i]->getCoord()),
                                     (*m_graph->getNodes()[j]->getCoord()));
             }
        }

    }
}// drawPaths()


void MainWindow::paintEvent(QPaintEvent *event)
{
    drawNodes();
    drawPaths();
}// paintEvent()
