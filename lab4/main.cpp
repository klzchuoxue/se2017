#include "function.h"

int main() {
	mainClass* mcls = new mainClass();
	string fullCommand = "";
	while (true)
	{
		cout << ">>>>";
		getline(cin, fullCommand);
		mcls->run(fullCommand);
	}

	return 0;
}