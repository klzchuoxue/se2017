#include "function.h"
#include <sstream>

void commandCom1::com(string* argv)
{
	if (argv[0].compare("defaultString"s) != 0)
		cout << "command 1, the input is: " << argv[0] << endl;
	else
		cout << "This command need a parameter" << endl;
}

void commandCom2::com(string* argv)
{
	cout << "command 2" << endl;
}

void commandCom3::com(string* argv)
{
	cout << "command 3" << endl;
}

void commandHelp::com(string* argv)
{
	cout << "This is a test program with 8 commands and help command" << endl
		<< "com1 [parameter]\t--give a instruction and print the parameter" << endl
		<< "com2\t\t\t--give a instruction" << endl
		<< "com3\t\t\t--give a instruction" << endl
		<< "com4\t\t\t--give a instruction" << endl
		<< "com5\t\t\t--give a instruction" << endl
		<< "com6\t\t\t--give a instruction" << endl
		<< "com7\t\t\t--give a instruction" << endl
		<< "com8\t\t\t--give a instruction" << endl
		<< "-h OR -help\t\t--give the help" << endl;
}


//=================================================================================================

void mainClass::showEmptyInput()
{
	cout << "Need at least one command" << endl;
}

void mainClass::showWrongInput()
{
	cout << "Wrong input. Use -h or -help command to get more information" << endl;
}

void mainClass::run(string argv)
{
	string userCommand = "";
	string parameter = "";
	istringstream istr(argv);
	if (istr >> userCommand)
	{
		unordered_map <string, command*> ::const_iterator it = handler.find(userCommand);
		if (it != handler.end())
		{
			if (istr >> parameter)
			{
				//parameter.append("\0");
				it->second->com(&parameter);
			}
			else
			{
				it->second->com(&"defaultString"s);
			}
		}
		else
		{
			showWrongInput();
		}
	}
	else
	{
		showEmptyInput();
	}
}

mainClass::mainClass()
{
	command* com1 = new commandCom1();
	command* com2 = new commandCom2();
	command* com3 = new commandCom3();
	command* help = new commandHelp();

	handler["com1"] = com1;
	handler["com2"] = com2;
	handler["com3"] = com3;
	handler["-help"] = help;
	handler["-h"] = help;
}

mainClass::~mainClass()
{
}