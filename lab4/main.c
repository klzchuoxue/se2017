#define _CRT_SECURE_NO_WARNINGS
#include "function.h"
#define MAX_INPUT_LEN 1024
#define MAX_CMD_LEN 128
#define MAX_PARA_NUM 8

int main()
{
	ftn* cmd = init();
	char * targetName = (char*)malloc(MAX_INPUT_LEN * sizeof(char));
	char * command = (char*)malloc(MAX_CMD_LEN * sizeof(char));
	char** para = NULL;
	int i = 0;
	ftn * ptr = NULL;
	while (1)
	{
		i = 0;
		if (para)
			free(para);
		para = (char**)malloc(MAX_PARA_NUM * sizeof(char*));
		printf(">>>");
		fgets(targetName, MAX_INPUT_LEN, stdin);
		char *delims = " \t\n";
		command = strtok(targetName, delims);
		if (command != NULL)
		{
			para[i] = strtok(NULL, delims);
			while (para[i] != NULL) {
				i++;
				para[i] = strtok(NULL, delims);
			}
		}
		else
		{
			showEmptyInput();
			continue;
		}

		ptr = findNode(cmd, command);
		if (ptr != NULL)
		{
			ptr->handler(para);
		}
		else
		{
			showWrongInput();
		}
	}
	return 0;
}