#ifndef TRANSITION_H
#define TRANSITION_H

class Transition
{
public :
  int(*valuationFunction)(void);

  Transition(int src, int dest, int (*f)());
  ~Transition();

  int getSrc();
  int getDest();

private :
  int srcId;
  int destId;
};

#endif // TRANSITION_H
