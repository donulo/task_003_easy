#ifndef IP_LIB_H
#define IP_LIB_H

#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getAddress();
int stringValidity(char* string);
int addressValidity(char* address);
int match(char* string, char* pattern);
int oneSubnet(char* address1, char* address2);
int menu(int itemMenu);
void exception();

#endif
