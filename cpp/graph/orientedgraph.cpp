/*----------------------------------------------------------------------------
  GraphPainter
  Decembre 2020
-------------------------------------------------------------------------------*/
/**
* @file    orientedgraph.cpp
* @author  Laurent VOURIOT
* @version 0.1
* @date    13/12/2020
*/
//-----------------------------------------------------------------------------
// INCLUDES
//-----------------------------------------------------------------------------
#include "orientedgraph.h"

OrientedGraph::OrientedGraph(const std::vector<Node *> &nodes)
    : AbsGraph(nodes)
{}

void OrientedGraph::link(const Node &begin, const Node &end)
{
    // on parcours la liste de noeud pour trouver leurs rang
    // dans la matrice d'adjacence
    unsigned rank_begin, rank_end;
    for(unsigned i = 0; i < getNodes().size(); i++)
    {
        Node *tmp = getNodes()[i];
        if((*tmp) == begin)
            rank_begin = i;
        else if((*tmp) == end)
            rank_end = i;
    }

    // on met a vrai la valeur entre les 2 sommets dans la matrice
    // on fait ça pour de manière asymètrique puisque c'est un graphe
    // orienté
    m_graph[rank_begin][rank_end] = true;
}// link()
