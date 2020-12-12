/*----------------------------------------------------------------------------
  EzPainter
  debut : Decembre 2020
-------------------------------------------------------------------------------*/
/**
* @file    mainwindow.h
* @author  Laurent VOURIOT
* @version 0.1
* @date    11/12/2020
*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//-----------------------------------------------------------------------------
// INCLUDES
//-----------------------------------------------------------------------------
#include <QMainWindow>

#include "graph.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief classe MainWindow, hérite de QMainWindow
 * 		  - ui (*Ui::MainWindow) : qt
 * 		  - m_graph (*Graph) : pointeur vers le graphe sur lequel on travail
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief MainWindow constructor
     * @param parent (*QWidget)
     * @param graph (*Graph)
     */
    MainWindow(QWidget *parent = nullptr, Graph *graph = nullptr);
    /**
    * @brief destructor
    */
    ~MainWindow();

    /**
     * @brief paintEvent (void) virtual
     * @param event (*QPaintEvent)
     */
    virtual void paintEvent(QPaintEvent *event);

    /**
     * @brief dessine sur le painter tous les sommets du graphe
     */
    void drawNodes();
    /**
     * @brief dessine sur le painter les arêtes entre les sommets
     */
    void drawPaths();

private:
    Ui::MainWindow *ui;
    Graph *m_graph;
};
#endif // MAINWINDOW_H
