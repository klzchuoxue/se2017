#include "function.h"
#include <string.h>

int main(int argc, char ** argv)
{
	if (argc == 1)
	{
		showEmptyInput();
		return 0;
	}

	if (strcmp(argv[1], FUNC1) == 0)
	{
		if (argc == 2)
		{
			showParameterLack();
			return 0;
		}
		com1(argv[2]);
		return 0;
	}
	if (strcmp(argv[1], FUNC2) == 0)
	{
		com2();
		return 0;
	}
	if (strcmp(argv[1], FUNC3) == 0)
	{
		com3();
		return 0;
	}
	if (strcmp(argv[1], FUNC4) == 0)
	{
		com4();
		return 0;
	}
	if (strcmp(argv[1], FUNC5) == 0)
	{
		com5();
		return 0;
	}
	if (strcmp(argv[1], FUNC6) == 0)
	{
		com6();
		return 0;
	}
	if (strcmp(argv[1], FUNC7) == 0)
	{
		com7();
		return 0;
	}
	if (strcmp(argv[1], FUNC8) == 0)
	{
		com8();
		return 0;
	}
	if ((strcmp(argv[1], HELP1) == 0)|| (strcmp(argv[1], HELP2) == 0))
	{
		showHelp();
		return 0;
	}
	showWrongInput();
	return 0;
}