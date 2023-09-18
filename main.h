#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/*function prototypes*/
int _printf(const char *format, ...);
int _putchar(char c);
int _puts(const char *s);
void print_uns(unsigned int num, int *n);

#endif
