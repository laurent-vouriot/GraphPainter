#ifndef ORIENTEDGRAPH_H
#define ORIENTEDGRAPH_H

#include "absgraph.h"
class OrientedGraph : public AbsGraph
{
public:
    OrientedGraph(const std::vector<Node *> &nodes);

    // override
    virtual void link(const Node &begin, const Node &end);
};

#endif // ORIENTEDGRAPH_H
