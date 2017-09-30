#include "function.h"
#include <stdio.h>

void showEmptyInput()
{
	printf("Need at least one command\n");
	return;
}

void showParameterLack()
{
	printf("This function need a parameter\n");
	return;
}

void com1(char *argv)
{
	printf("This is com1, the input is \"%s\"", argv);
}

void com2()
{
	printf("This is com2\n");
	return;
}

void com3()
{
	printf("This is com3\n");
	return;
}

void com4()
{
	printf("This is com4\n");
	return;
}

void com5()
{
	printf("This is com5\n");
	return;
}

void com6()
{
	printf("This is com6\n");
	return;
}

void com7()
{
	printf("This is com7\n");
	return;
}

void com8()
{
	printf("This is com8\n");
	return;
}

void showHelp()
{
	printf("This is a test program with 8 commands and help command\n"
		"com1 [parameter]\t--give a instruction and print the parameter\n"
		"com2\t\t\t--give a instruction\n"
		"com3\t\t\t--give a instruction\n"
		"com4\t\t\t--give a instruction\n"
		"com5\t\t\t--give a instruction\n"
		"com6\t\t\t--give a instruction\n"
		"com7\t\t\t--give a instruction\n"
		"com8\t\t\t--give a instruction\n"
		"-h OR -help\t\t--give the help"
	);
}

void showWrongInput()
{
	printf("Wrong input. Use -h or -help command to get more information");
	return;
}