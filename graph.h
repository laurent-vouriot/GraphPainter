/*----------------------------------------------------------------------------
  EzPainter
  Decembre 2020
-------------------------------------------------------------------------------*/
/**
* @file    graph.h
* @author  Laurent VOURIOT
* @version 0.1
* @date    11/12/2020
*/
#ifndef GRAPH_H
#define GRAPH_H
//-----------------------------------------------------------------------------
// INCLUDES
//-----------------------------------------------------------------------------
#include <vector>

#include "node.h"

typedef std::vector<std::vector<bool>> matrice;

/**
 * @brief classe qui définie un graphe non orienté
 * 		  - m_graphe (matrice) : matrice d'adjacence du graphe
 * 		  - m_nodes (vector<Node>) : liste des sommets du graphes
 */
class Graph
{
private:
    matrice m_graph;
    std::vector<Node *> m_nodes;
public:
    /**
     * @brief Graph constructor
     * @param nodes (vector<Node>) : liste des noeuds du graphe
     */
    Graph(const std::vector<Node *> &nodes);

    /**
     * @brief link
     * crée une arête entre le sommet begin et end
     * @param begin (Node)
     * @param end (Node)
     */
    void link(const Node &begin, const Node &end);

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

#endif // GRAPH_H
