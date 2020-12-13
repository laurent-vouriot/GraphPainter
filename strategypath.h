#ifndef STRATEGYPATH_H
#define STRATEGYPATH_H

#include <QMainWindow>

#include "absgraph.h"

class StrategyPath
{
public:
    virtual void drawPath(QMainWindow *window, AbsGraph *graph) = 0;
};

#endif // STRATEGYPATH_H
