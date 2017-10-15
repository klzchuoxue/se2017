#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct function
{
	char* name;
	int (*handler)();
	struct function* next;
};

typedef struct function ftn;

ftn * createLinkList();

ftn * appendNode(ftn* head, int(*handler)(), char* name);

void deleteNode(ftn * head, char * targetName);

void deleteLinkList(ftn* head);

ftn* findNode(ftn * head, char * targetName);

//=====================================================

int help(char **para);
int com1(char **para);
int com2(char **para);
int com3(char **para);

ftn * init();
void showWrongInput();
void showEmptyInput();