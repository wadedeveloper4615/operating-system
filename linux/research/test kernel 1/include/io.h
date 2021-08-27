#ifndef IO_H
#define IO_H

#include <stdint.h>
#include <stddef.h>
#include <kernel.h>
#include <screen.h>

#define ZEROPAD	1		/* pad with zero */
#define SIGN	2		/* unsigned/signed long */
#define PLUS	4		/* show plus */
#define SPACE	8		/* space if plus */
#define LEFT	16		/* left justified */
#define SMALL	32		/* Must be 32 == 0x20 */
#define SPECIAL	64		/* 0x */

typedef __builtin_va_list va_list;
#define va_start(ap,last) __builtin_va_start(ap, last)
#define va_end(ap) __builtin_va_end(ap)
#define va_arg(ap,type) __builtin_va_arg(ap,type)
#define va_copy(dest, src) __builtin_va_copy(dest,src)

static inline int isdigit(int c);
static int skip_atoi(const char **s);
static char *knumber(char *str, long num, int base, int size, int precision,int type);
int kvsprintf(char *buf, const char *fmt, va_list args);
int ksprintf(char *buf, const char *fmt, ...);
int kprintf(const char *fmt, ...);
#endif