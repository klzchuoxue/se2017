#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** command)
{
	if (argc < 2)
	{
		cout << "input a command" << endl;
		return 0;
	}
	string argv = command[1];
/*
	string argv;
	cin >> argv;*/
	if (argv.compare("com1")==0)
		cout << "this is com1" << endl;
	else if (argv.compare("com2") == 0)
		cout << "this is com2" << endl;
	else if (argv.compare("com3") == 0)
		cout << "this is com3" << endl;
	else if (argv.compare("com4") == 0)
		cout << "this is com4" << endl;
	else if (argv.compare("com5") == 0)
		cout << "this is com5" << endl;
	else if (argv.compare("com6") == 0)
		cout << "this is com6" << endl;
	else if (argv.compare("com7") == 0)
		cout << "this is com7" << endl;
	else if (argv.compare("com8") == 0)
		cout << "this is com8" << endl;
	else if (argv.compare("com9") == 0)
		cout << "this is com9" << endl;
	else if (argv.compare("-help") == 0 || argv.compare("-h") == 0)
		cout << "this is a test program" << endl
		<< "command list:" << endl
		<< "com1" << endl
		<< "com2" << endl
		<< "com3" << endl
		<< "com4" << endl
		<< "com5" << endl
		<< "com6" << endl
		<< "com7" << endl
		<< "com8" << endl
		<< "com9" << endl
		<< "-help or -h for help" << endl;
	else
		cout << "wrong input. if u need help, input -help or -h";
	return 0;
}
