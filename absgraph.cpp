#include "absgraph.h"

AbsGraph::AbsGraph(const std::vector<Node *> &nodes)
    : m_nodes(nodes)
{
     m_graph = matrice(m_nodes.size(), std::vector<bool>(m_nodes.size(), false));
}// AbsGraph()

//-----------------------------------------------------------------------------
//	GETTERS
//-----------------------------------------------------------------------------
std::vector<Node *> AbsGraph::getNodes()                    		  	  {return m_nodes;}
Node 			   *AbsGraph::getNode(const unsigned &i)	        const {return m_nodes[i];}
matrice 		    AbsGraph::getMatrice() 					    	const {return m_graph;}

