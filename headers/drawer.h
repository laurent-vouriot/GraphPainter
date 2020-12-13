/*----------------------------------------------------------------------------
  GraphPainter
  Decembre 2020
-------------------------------------------------------------------------------*/
/**
* @file    drawer.h
* @author  Laurent VOURIOT
* @version 0.1
* @date    13/12/2020
*/
#ifndef DRAWER_H
#define DRAWER_H
//-----------------------------------------------------------------------------
// INCLUDES
//-----------------------------------------------------------------------------
#include "strategypath.h"
#include "nonorientedpath.h"

/**
 * @brief classe Drawer
 * 		  pour dessiner le graphe
 * 		  - m_pathDrawer (StrategyPath) : stratégie pour dessiner les arêtes du graphe
 */
class Drawer
{
private:
    StrategyPath *m_pathDrawer;
public:
    /**
     * @brief Drawer constructor
     * @param pathDrawer (StrategyPath *) : stratégie pour dessiner les arêtes du graphe
     */
    Drawer(StrategyPath *pathDrawer = new NonOrientedPath);

    /**
     * @brief draw
     * 		  dessine le graphe
     * @param graph (AbsGraph *)
     * @param window (QMainWindow *)
     */
    void draw(AbsGraph *graph, QMainWindow *window);
};

#endif // DRAWER_H
