#ifndef NONORIENTEDPATH_H
#define NONORIENTEDPATH_H

#include "strategypath.h"

class NonOrientedPath : public StrategyPath
{
public:
    NonOrientedPath();

    virtual void drawPath(QMainWindow *window, AbsGraph *graph);
};

#endif // NONORIENTEDPATH_H
