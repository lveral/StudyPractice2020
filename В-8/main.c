#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "lib.h"

struct elem {
	char *key;
	int value;
	struct elem* next;
};

int main() {
	int value, fl = 1, i, d;
	char key[15], buff[100];;
	
	struct elem *el;
	FILE* input;

	if ((input = fopen("input.txt", "r")) == NULL)
	{
		printf("!ERROR!File not found!\n");
		return 0;
	}
	
	printf("Associative array");
	
	while (fl){
	
		fscanf(input, "%s", &buff);
		printf("\n\n%s", buff);
	
		switch(buff[0]) {
			case 'E':
				fl = 0;
				break;
			case 'I':	
				memset(&key, '\0', sizeof(key));
				for(i = 8; buff[i] != '"'; i++) key[i-8] = buff[i];
				
				value = 0; d = 1;
				for(i = strlen(buff) - 2; buff[i] != ','; i--) 
				{
					value += (buff[i]-'0') * d;
					d *= 10;
				}
				
				if ((el =INSERT(key, value)) == NULL) printf("\nERROR!");
				else 
				{
					printf ("\nKey: %s", el->key);
					printf("\nValue: %i", el->value);
					printf("\nThe element is inserted.");
				}
		   		break;
			case 'F':
				memset(&key, '\0', sizeof(key));
				for(i = 6; buff[i] != '"'; i++) key[i-6] = buff[i];
				
				if ((el =FIND(key)) == NULL) printf("\nERROR.The element does not exist!");
				else 
				{
					printf("\nValue: %i",  el->value);
					printf("\nThe element is found!");
				}
				break;
			case 'R':
				memset(&key, '\0', sizeof(key));
				for(i = 8; buff[i] != '"'; i++) key[i-8] = buff[i];
				REMOVE(key);
				
		   		break;
			default:
			printf("\n!Invalid command!");
		  }
	}
	
	fclose(input);
	return 0;
}
