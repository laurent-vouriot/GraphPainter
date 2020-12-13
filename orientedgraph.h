/*----------------------------------------------------------------------------
  GraphPainter
  Decembre 2020
-------------------------------------------------------------------------------*/
/**
* @file    orientedgraph.h
* @author  Laurent VOURIOT
* @version 0.1
* @date    13/12/2020
*/
#ifndef ORIENTEDGRAPH_H
#define ORIENTEDGRAPH_H
//-----------------------------------------------------------------------------
// INCLUDES
//-----------------------------------------------------------------------------
#include "absgraph.h"

/**
 * @brief classe OrientedGraph hérite de Absgraphe
 * 		  pour les graphes orientés
 */
class OrientedGraph : public AbsGraph
{
public:
    /**
     * @brief OrientedGraph constructor
     * @param nodes (vector<Node *>)
     */
    OrientedGraph(const std::vector<Node *> &nodes);

    /**
     * @brief link (Override)
     * @param begin
     * @param end
     */
    virtual void link(const Node &begin, const Node &end);
};

#endif // ORIENTEDGRAPH_H
