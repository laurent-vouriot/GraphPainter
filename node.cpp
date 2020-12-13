/*----------------------------------------------------------------------------
  GraphPainter
  Decembre 2020
-------------------------------------------------------------------------------*/
/**
* @file    node.cpp
* @author  Laurent VOURIOT
* @version 0.1
* @date    11/12/2020
*/
//-----------------------------------------------------------------------------
// INCLUDES
//-----------------------------------------------------------------------------
#include "node.h"

#include <QPainter>

Node::Node(const int &x, const int &y, const char *name)
    : m_coord(new QPoint(x,y))
    , m_name(new QString(name))
{}

Node::Node(QPoint *coords, const char *name)
    : m_coord(coords)
    , m_name(new QString(name))

{}

int Node::x() const {return m_coord->x();}
int Node::y() const {return m_coord->y();}

//-----------------------------------------------------------------------------
// GETTERS
//-----------------------------------------------------------------------------
QPoint 		*Node::getCoord()     const {return m_coord;}
QString     *Node::getName()      const {return m_name;}

//-----------------------------------------------------------------------------
// OPERATOR
//-----------------------------------------------------------------------------
bool Node::operator==(const Node &node)
{
    return this->getCoord() == node.getCoord()
           && this->getName() == node.getName();
}
