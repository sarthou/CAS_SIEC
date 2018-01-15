#include "StateMachine/Transition.h"

Transition::Transition(int src, int dest, int (*f)())
{
  srcId=src;
  destId=dest;
  valuationFunction=f;
}

Transition::~Transition(){}

int Transition::getSrc()
{
    return srcId;
}

int Transition::getDest()
{
    return destId;
}
