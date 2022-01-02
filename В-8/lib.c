#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "lib.h"

static struct elem *array[100];

struct elem {
	char *key;
	int value;
	struct elem* next;
};

unsigned HASH(char *key)
{
    unsigned int hash = 0, j;
	
	for (j = 0; j < strlen(key); j++) {
		hash += (int)key[j];
	}

    return (hash % 100);
}

struct elem *FIND(char *key)
{
	struct elem *el;
	
	for (el = array[HASH(key)]; el != NULL; el = el->next)
		if (strcmp(key, el->key) == 0)
			return el;
	return NULL;
}

struct elem *INSERT(char *key, int value)
{
	struct elem *el;
	unsigned hash;
	
	if ((el = (FIND(key))) == NULL)
	{
		el = (struct elem *)malloc(sizeof(*el));
		if (el == NULL || (el->key = strdup(key)) == NULL)
			return NULL;
		hash = HASH(key);
		el->value =	value;	
		el->next = array[hash];
		array[hash] = el;
	} else el->value = value;
		
	return el;
}

void REMOVE(char *key)
{
	struct elem *el, *prev;
	unsigned hash;
	prev = 0;
	hash = HASH(key);
	el = array[hash];
	
	while (el && (strcmp(el->key, key)!= 0))
	{
		prev = el;
		el = el->next;
	}
	if (el == NULL)
	{
		printf("\nERROR.The element does not exist!");
		return;	
	} 
	
	if (prev)
		prev->next = el->next;
	else
		array[hash] = el->next;
	printf("\nThe element is removed!");	
	free(el);
}
