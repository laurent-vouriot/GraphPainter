/*----------------------------------------------------------------------------
  GraphPainter
  Decembre 2020
-------------------------------------------------------------------------------*/
/**
* @file    NonOrientedGraph.h
* @author  Laurent VOURIOT
* @version 0.1.2
* @date    12/12/2020
*/

#ifndef GRAPH_H
#define GRAPH_H
//-----------------------------------------------------------------------------
// INCLUDES
//-----------------------------------------------------------------------------
#include <vector>

#include "absgraph.h"
#include "node.h"


class NonOrientedGraph : public AbsGraph
{
public:
    /**
     * @brief Graph constructor
     * @param nodes (vector<Node>) : liste des noeuds du graphe
     */
    NonOrientedGraph(const std::vector<Node *> &nodes);

   // virtual ~NonOrientedGraph();

    /**
     * @brief link (Override)
     * 		  crée une arête entre le sommet begin et end
     * @param begin (Node)
     * @param end (Node)
     */
     virtual void link(const Node &begin, const Node &end);
};

#endif // GRAPH_H
