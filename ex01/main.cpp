#include "Interface.hpp"
#include "header.h"

int main()
{
	Interface i;

	if (DEBUG) i.seed();
	i.monitor();

	return (0);
}
