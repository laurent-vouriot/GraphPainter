/*----------------------------------------------------------------------------
  GraphPainter
  Decembre 2020
-------------------------------------------------------------------------------*/
/**
* @file    absgraph.h
* @author  Laurent VOURIOT
* @version 0.1
* @date    12/12/2020
*/
#ifndef ABSGRAPH_H
#define ABSGRAPH_H
//-----------------------------------------------------------------------------
// INCLUDES
//-----------------------------------------------------------------------------
#include <vector>

#include "node.h"

typedef std::vector<std::vector<bool>> matrice;

class AbsGraph
{
protected:
    matrice m_graph;
    std::vector<Node *> m_nodes;
public:
    AbsGraph(const std::vector<Node *> &nodes);

    virtual void link(const Node &begin, const Node &end) = 0;

//-----------------------------------------------------------------------------
//	GETTERS
//-----------------------------------------------------------------------------
    /**
     * @brief getMatrice
     * @return (matrice)
     */
    matrice getMatrice() const;
    /**
     * @brief getNodes
     * @return (vector<Node>)
     */
    std::vector<Node *> getNodes();
    /**
     * @brief getNode
     * @param i (unsigned) rang du noeud
     * @return (Node)
     */
    Node *getNode(const unsigned &i) const;
};

#endif // ABSGRAPH_H
