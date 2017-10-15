#include "function.h"

//创建链表
ftn * createLinkList()
{
	ftn* head = (ftn*)malloc(sizeof(ftn));
	head->next = NULL;
	return head;
}

//加入节点
ftn * appendNode(ftn* head, int(*handler)(), char* name)
{
	ftn *endNode = head;
	while (endNode->next != NULL)
	{
		endNode = endNode->next;
	}
	ftn* node = (ftn*)malloc(sizeof(ftn));
	if (node != NULL)
	{
		endNode->next = node;
		node->next = NULL;
		node->name = name;
		node->handler = handler;
		return node;
	}
	else
	{
		printf("append failed\n");
		return NULL;
	}
}

//删除结点
void deleteNode(ftn * head, char * targetName)
{
	ftn *endNode = head->next;
	ftn *lastNode = head;
	while (endNode != NULL)
	{
		if (strcmp(endNode->name, targetName) != 0)
		{
			lastNode = endNode;
			endNode = endNode->next;
		}
		else
		{
			if (endNode == head)
			{
				free(endNode);
				return;
			}
			else
			{
				lastNode->next = endNode->next;
				free(endNode);
				return;
			}
		}
	}
	printf("Wrong target name\n");
	return;
}

//寻找结点
ftn* findNode(ftn * head, char * targetName)
{
	ftn *targetNode = head->next;
	while (strcmp(targetNode->name, targetName) != 0)
	{
		if (targetNode->next != NULL)
		{
			targetNode = targetNode->next;
		}
		else
		{
			return NULL;
		}
	}
	return targetNode;
}

//删除链表
void deleteLinkList(ftn* head)
{
	ftn *endNode = head;
	ftn *tmp = endNode;
	while (endNode->next != NULL)
	{
		tmp = endNode;
		endNode = endNode->next;
		free(tmp);
	}
	free(endNode);
}

//帮助函数
int help(char **para)
{
	printf("This is a test program with 8 commands and help command\n\
		com1[parameter]\t--give a instruction and print the parameter\n\
		com2\t\t\t--give a instruction\n\
		com3\t\t\t--give a instruction\n\
		- h OR - help\t\t--give the help\n");
	return 0;
}

//命令1
int com1(char **para)
{
	if (para[0])
		printf("this is com1, and parameter is : %s\n", para[0]);
	else
		printf("this command need one parameter\n");
	return 0;
}

//命令2
int com2(char **para)
{
	printf("this is com2\n");
	return 0;
}

//命令3
int com3(char **para)
{
	printf("this is com3\n");
	return 0;
}

void showWrongInput()
{
	printf("Wrong input. Use -h or -help command to get more information\n");
	return;
}

void showEmptyInput()
{
	printf("Empty Input. Need at least one command\n");
	return;
}


//==================================================================================
//初始化
ftn* init()
{
	ftn* cmd = createLinkList();
	appendNode(cmd, help, "-help");
	appendNode(cmd, com1, "com1");
	appendNode(cmd, com2, "com2");
	appendNode(cmd, com3, "com3");
	appendNode(cmd, help, "-h");
	return cmd;
}