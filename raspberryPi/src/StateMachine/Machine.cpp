#include <iostream>

#include "StateMachine/Machine.h"

Machine::Machine(int init)
{
    initialState=init;
}

Machine::~Machine()
{
    for(unsigned int i=0;i<stateLst.size();i++){
        stateLst[i].~State();
    }

    for(unsigned int i=0; i<transitionLst.size();i++){
        transitionLst[i].~Transition();
    }
}

void Machine::addState(State s)
{
    stateLst.push_back(s);
}

void Machine::addTransition(Transition t)
{
    transitionLst.push_back(t);
}

void Machine::run()
{
    int currentState=initialState;
    int hasToExecute=1; //Default value
    while(1) //While no final state is reached?
    {
    	usleep(100000);
        if(hasToExecute==1)
        {
            unsigned int i=0;
            int executed=0;
            while(i<stateLst.size()&&executed==0)
            {
                if(stateLst[i].getId()==currentState)
                {
                    stateLst[i].run();
                    hasToExecute=0;
                    executed=1;
                }
                i++;
            }
        }

        unsigned int j=0;
        int passed =0;
        while(j<transitionLst.size()&&passed==0)
        {
            if(transitionLst[j].getSrc()==currentState)
            {
                if(transitionLst[j].valuationFunction()==1) //Work only because of determinism
                {
                    currentState=transitionLst[j].getDest();
                    hasToExecute=1;
                    passed=1;
                }
            }
            j++;
        }
    }
}
