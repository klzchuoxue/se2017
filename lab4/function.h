#include <unordered_map>
#include <iostream>
#include <string>
#include <utility>
using namespace std;

class command
{
public:
	virtual void com(string *argv)=0;
};

class commandCom1 : public command
{
	void com(string *argv);
};

class commandCom2 : public command
{
public:
	void com(string *argv);
};

class commandCom3 : public command
{
public:
	void com(string *argv);
};

class commandHelp : public command
{
public:
	void com(string *argv);
};


class mainClass
{
public:
	mainClass();
	~mainClass();
	void run(string argv);

private:
	unordered_map<string, command*> handler;
	void showEmptyInput();
	void showWrongInput();
};