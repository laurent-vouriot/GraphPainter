/*----------------------------------------------------------------------------
  GraphPainter
  Decembre 2020
-------------------------------------------------------------------------------*/
/**
* @file    strategypath.h
* @author  Laurent VOURIOT
* @version 0.1
* @date    13/12/2020
*/
#ifndef STRATEGYPATH_H
#define STRATEGYPATH_H
//-----------------------------------------------------------------------------
// INCLUDES
//-----------------------------------------------------------------------------
#include <QMainWindow>

#include "headers/graph/absgraph.h"

/**
 * @brief Interface StrategyPath
 * 		  pattern strategy pour dessiner les arêtes de notre graphe
 */
class StrategyPath
{
public:
    /**
     * @brief drawPath
     * 		  fonction qui va être surchargée(?) pour dessiner different type d'arêtes
     * 		  (orienté ou non ...)
     * @param window (QMainWindow *) : fenêtre sur laquelle on va dessiner
     * @param graph (AbsGraph *) : graphe sur lequel on travail
     */
    virtual void drawPath(QMainWindow *window, AbsGraph *graph) = 0;
};

#endif // STRATEGYPATH_H
