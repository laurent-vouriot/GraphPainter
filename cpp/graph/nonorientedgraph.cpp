/*----------------------------------------------------------------------------
  GraphPainter
  Decembre 2020
-------------------------------------------------------------------------------*/
/**
* @file    nonOrientedGraph.cpp
* @author  Laurent VOURIOT
* @version 0.1.2
* @date    12/12/2020
*/
//-----------------------------------------------------------------------------
// INCLUDES
//-----------------------------------------------------------------------------
#include <iostream>

#include <QPainter>

#include "headers/mainwindow.h"
#include "headers/graph/nonorientedgraph.h"

NonOrientedGraph::NonOrientedGraph(const std::vector<Node *> &nodes)
    : AbsGraph(nodes)
{}

void NonOrientedGraph::link(const Node &begin, const Node &end)
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
    // on fait ça pour de manière symètrique puisque c'est un graphe
    // non orienté
    m_graph[rank_begin][rank_end] = true;
    m_graph[rank_end][rank_begin] = true;
}// link()
