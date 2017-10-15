#define _CRT_SECURE_NO_WARNINGS
#include "function.h"
#define MAX_INPUT_LEN 1024
#define MAX_CMD_LEN 128
#define MAX_PARA_NUM 8

int main()
{
	//初始化命令，定义命令的名称和所分配的执行函数
	ftn* cmd = init();
	//获取全部输入，包括空格和回车等
	char * targetName = (char*)malloc(MAX_INPUT_LEN * sizeof(char));
	//获取命令
	char * command = (char*)malloc(MAX_CMD_LEN * sizeof(char));
	//获取参数的字符数组
	char** para = NULL;
	//定位参数写入数组的位置
	int i = 0;
	//获取输入命令所对应的节点，若无返回空
	ftn * ptr = NULL;
	//大循环
	while (1)
	{
		i = 0;
		//若参数数组已经存在，释放，重新分配空间。
		if (para)
			free(para);
		para = (char**)malloc(MAX_PARA_NUM * sizeof(char*));
		//获取输入
		printf(">>>");
		fgets(targetName, MAX_INPUT_LEN, stdin);
		//将输入分割为命令和参数，写入相应位置
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
			//若命令为空，给出错误信息后从头开始循环
			showEmptyInput();
			continue;
		}

		//寻找输入字符对应的命令结点，若为空给出错误信息并继续大循环。否则运行相应的函数
		ptr = findNode(cmd, command);
		if (ptr != NULL)
		{
			ptr->handler(para);
		}
		else
		{
			showWrongInput();
			continue;
		}
	}
	return 0;
}