/*----------------------------------------------------------------------------
  GraphPainter
  Decembre 2020
-------------------------------------------------------------------------------*/
/**
* @file    absGraph.cpp
* @author  Laurent VOURIOT
* @version 0.1
* @date    13/12/2020
*/
//-----------------------------------------------------------------------------
// INCLUDES
//-----------------------------------------------------------------------------
#include <iostream>

#include "headers/graph/absgraph.h"

AbsGraph::AbsGraph(const std::vector<Node *> &nodes)
    : m_nodes(nodes)
{
    // on redimensionne la matrice et on met tout à false
    // cela signifie que l'on a tous les sommets mais il n'y
    // a pour le moment pas d'arêtes entre les sommets
     m_graph = matrice(m_nodes.size(), std::vector<bool>(m_nodes.size(), false));

//     for(unsigned i = 0; i < m_graph.size(); i++)
//     {
//         for(unsigned j = 0; j < m_graph.size(); j++)
//         {
//             std::cout <<  m_graph[i][j] << std::endl;
//         }
//     }


}// AbsGraph()

//-----------------------------------------------------------------------------
//	GETTERS
//-----------------------------------------------------------------------------
std::vector<Node *> AbsGraph::getNodes()                    		  	  {return m_nodes;}
Node 			   *AbsGraph::getNode(const unsigned &i)	        const {return m_nodes[i];}
matrice 		    AbsGraph::getMatrice() 					    	const {return m_graph;}

