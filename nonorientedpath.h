#ifndef NONORIENTEDPATH_H
#define NONORIENTEDPATH_H
/*----------------------------------------------------------------------------
  GraphPainter
  Decembre 2020
-------------------------------------------------------------------------------*/
/**
* @file    nonorientedpath.h
* @author  Laurent VOURIOT
* @version 0.1
* @date    13/12/2020
*/
//-----------------------------------------------------------------------------
// INCLUDES
//-----------------------------------------------------------------------------
#include "strategypath.h"
/**
 * @brief classe NonOrientedPath hérite de StrategyPath
 * 		  pattern strategy pour dessiner des arêtes non orientées
 */
class NonOrientedPath : public StrategyPath
{
public:
    NonOrientedPath();

    /**
     * @brief drawPath (override)
     * @param window (QMainWindow *)
     * @param graph  (AbsGraph *)
     */
    virtual void drawPath(QMainWindow *window, AbsGraph *graph);
};

#endif // NONORIENTEDPATH_H
