/*----------------------------------------------------------------------------
  GraphPainter
  Decembre 2020
-------------------------------------------------------------------------------*/
/**
* @file    orientedpath.h
* @author  Laurent VOURIOT
* @version 0.1
* @date    13/12/2020
*/
#ifndef ORIENTEDPATH_H
#define ORIENTEDPATH_H
//-----------------------------------------------------------------------------
// INCLUDES
//-----------------------------------------------------------------------------
#include "strategypath.h"

/**
 * @brief classe OrientedPath hérite de StrategyPath
 * 		  pattern strategy pour dessiner des arêtes orientées
 */
class OrientedPath : public StrategyPath
{
public:
    /**
     * @brief OrientedPath constructor
     */
    OrientedPath();

    /**
     * @brief drawPath (override)
     * @param window
     * @param graph
     */
    virtual void drawPath(QMainWindow *window, AbsGraph *graph);
};

#endif // ORIENTEDPATH_H
