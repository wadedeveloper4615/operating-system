#ifndef STRINGS_H
#define STRINGS_H

#include <stddef.h>

int strlen(const char * s);
int strnlen( const char* s, int count );
char *strncpy(char *destString, const char *sourceString,int maxLength);
int strcmp(const char *dst, char *src);
char * strstr(const char *in, const char *str);
int strcpy(char *dst,const char *src);
void strcat(void *dest,const void *src);
int strncmp( const char* s1, const char* s2, int c );
void itoa(char *buf, unsigned long int n, int base);
int atoi(char * string);
int isspace(char c);
int isprint(char c);
char *strsep(char **stringp, const char *delim);
#endif
