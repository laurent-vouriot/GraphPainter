#ifndef DRAWER_H
#define DRAWER_H

#include "strategypath.h"
#include "nonorientedpath.h"

class Drawer
{
private:
    StrategyPath *m_pathDrawer;
public:
    Drawer(StrategyPath *pathDrawer = new NonOrientedPath);

    void draw(AbsGraph *graph, QMainWindow *window);
};

#endif // DRAWER_H
