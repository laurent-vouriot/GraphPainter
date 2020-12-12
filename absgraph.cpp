#include "absgraph.h"

AbsGraph::AbsGraph(const std::vector<Node *> &nodes)
    : m_nodes(nodes)
{
    // on redimensionne la matrice et on met tout à false
    // cela signifie que l'on a tous les noeuds mais il n'y
    // a pour le moment pas d'arêtes entre les noeuds
     m_graph = matrice(m_nodes.size(), std::vector<bool>(m_nodes.size(), false));
}// AbsGraph()

//-----------------------------------------------------------------------------
//	GETTERS
//-----------------------------------------------------------------------------
std::vector<Node *> AbsGraph::getNodes()                    		  	  {return m_nodes;}
Node 			   *AbsGraph::getNode(const unsigned &i)	        const {return m_nodes[i];}
matrice 		    AbsGraph::getMatrice() 					    	const {return m_graph;}

