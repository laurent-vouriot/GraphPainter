#ifndef ORIENTEDPATH_H
#define ORIENTEDPATH_H

#include "strategypath.h"

class OrientedPath : public StrategyPath
{
public:
    OrientedPath();

    virtual void drawPath(QMainWindow *window, AbsGraph *graph);
};

#endif // ORIENTEDPATH_H
