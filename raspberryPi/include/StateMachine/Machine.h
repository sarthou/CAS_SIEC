#ifndef MACHINE_H
#define MACHINE_H

#include <vector>
#include "StateMachine/State.h"
#include "StateMachine/Transition.h"

class Machine
{
public:
  Machine(int init);
  ~Machine();

  void addState(State s);
  void addTransition(Transition t);

  void run();

private:
  int initialState;
  std::vector<State> stateLst;
  std::vector<Transition> transitionLst;
};

#endif // MACHINE_H
