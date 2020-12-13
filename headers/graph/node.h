/*----------------------------------------------------------------------------
  GraphPainter
  Decembre 2020
-------------------------------------------------------------------------------*/
/**
* @file    node.h
* @author  Laurent VOURIOT
* @version 0.1
* @date    11/12/2020
*/
#ifndef NODE_H
#define NODE_H
//-----------------------------------------------------------------------------
// INCLUDES
//-----------------------------------------------------------------------------
#include <string>

#include <QPoint>
#include <QMainWindow>

/**
 * @brief classe pour les sommets d'un graphe
 * 		  - m_coord (*QPoint) : qpoint qui coorespond aux coordonnées orthonrmés du sommet
 * 		  - m_name (*QString) : nom du sommet
 */
class Node
{
private:
    QPoint  *m_coord;
    QString *m_name;
public:
    /**
     * @brief Node constructor avec coordonnées entières
     * @param x (int)
     * @param y (int)
     * @param name (string)
     */
    Node(const int &x = -1, const int &y = -1, const char *name = "nullnode");
    /**
     * @brief Node constructor avec QPoint
     * @param coords (*QPoint)
     * @param name (string)
     */
    Node(QPoint *coords = nullptr, const char *name = "nullnode");

//-----------------------------------------------------------------------------
// GETTERS
//-----------------------------------------------------------------------------
    /**
     * @brief x
     * @return (int) coordonnée x
     */
    int x() const;
    /**
     * @brief y
     * @return (int) coordonnée y
     */
    int y() const;

    /**
     * @brief getCoord
     * @return (*QPoint)
     */
    QPoint 	   *getCoord()  const;
    /**
     * @brief getName
     * @return (string)
     */
    QString *getName()   const;

//-----------------------------------------------------------------------------
// OPERATORS
//-----------------------------------------------------------------------------

    /**
     * @brief operator ==
     * @param node (Node)
     * @return (bool)
     */
    bool operator==(const Node &node);
};
#endif // NODE_H
