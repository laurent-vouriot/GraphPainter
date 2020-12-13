/*----------------------------------------------------------------------------
  GraphPainter
  Decembre 2020
-------------------------------------------------------------------------------*/
/**
* @file    absgraph.h
* @author  Laurent VOURIOT
* @version 0.2
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
/**
 * @brief classe abstraite AbsGraph pour représenter un graph
 * 		  - m_graph (vector<vector<bool>>) matrice d'adjacence
 * 		  - m_nodes (vector<Node *> liste des sommets du graphe
 */
class AbsGraph
{
protected:
    matrice m_graph;
    std::vector<Node *> m_nodes;
public:
    /**
     * @brief AbsGraph constructor
     * @param nodes (vector<Node *>) liste des sommets du graphe
     */
    AbsGraph(const std::vector<Node *> &nodes);

    /**
     * @brief link
     * 		  fonction virtuelle pure
     * 		  ajoute un arête au graphe entre begin et end
     * @param begin (Node)
     * @param end (Node)
     */
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
