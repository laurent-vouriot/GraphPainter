/*----------------------------------------------------------------------------
  GraphPainter
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

#include "nonorientedoraph.h"
#include "orientedgraph.h"
#include "drawer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief classe MainWindow, hérite de QMainWindow
 * 		  - ui (*Ui::MainWindow) : qt
 * 		  - m_graph (AbsGraph *) : pointeur vers le graphe sur lequel on travail
 * 		  - m_drawer (Drawer *) : Drawer du graphe
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief MainWindow constructor
     * @param parent (*QWidget)
     */
    MainWindow(QWidget *parent = nullptr);
    /**
     * @brief MainWindow constructor
     * @param drawer (Drawer *)
     * @param graph (AbsGraphe *)
     */
    MainWindow(Drawer *drawer, AbsGraph *graph);
    /**
    * @brief destructor
    */
    ~MainWindow();
    /**
     * @brief paintEvent (void) virtual
     * @param event (*QPaintEvent)
     */
    virtual void paintEvent(QPaintEvent *event);
private:
    Ui::MainWindow *ui;
    AbsGraph  *m_graph;
    Drawer 	  *m_drawer;
};
#endif // MAINWINDOW_H
