#include <stdint.h>
#include <stm32f10x.h>

#include "system_time.h"
#include "manager.h"

#include "misc.h"

int main(void)
{
	Manager_Init();
	while (1){}
}
