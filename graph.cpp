/*----------------------------------------------------------------------------
  GraphPainter
  Decembre 2020
-------------------------------------------------------------------------------*/
/**
* @file    graph.cpp
* @author  Laurent VOURIOT
* @version 0.1
* @date    11/12/2020
*/
//-----------------------------------------------------------------------------
// INCLUDES
//-----------------------------------------------------------------------------
#include <iostream>

#include <QPainter>

#include "mainwindow.h"
#include "graph.h"

Graph::Graph(const std::vector<Node *> &nodes):
    m_nodes(nodes)
{
    // on redimensionne la matrice et on met tout à false
    // cela signifie que l'on a tous les noeuds mais il n'y
    // a pour le moment pas d'arêtes entre les noeuds
    m_graph = matrice(m_nodes.size(), std::vector<bool>(m_nodes.size(), false));
}// Graph()

void Graph::link(const Node &begin, const Node &end)
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

//-----------------------------------------------------------------------------
//	GETTERS
//-----------------------------------------------------------------------------
std::vector<Node *> Graph::getNodes()                    		  	  {return m_nodes;}
Node 			   *Graph::getNode(const unsigned &i)	        const {return m_nodes[i];}
matrice 		    Graph::getMatrice() 					    const {return m_graph;}

