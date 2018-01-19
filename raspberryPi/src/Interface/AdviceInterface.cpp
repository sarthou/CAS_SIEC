#include <stdint.h>
#include "Interface/AdviceInterface.h"

int32_t advice = 1;

void initUserAdvice(){
	advice = 1;
}

int32_t* linkUserAdvice()
{
	return &advice;
}


