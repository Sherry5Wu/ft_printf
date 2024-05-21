#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdint.h> // for pointer type uintptr_t

int ft_printf(const char *fmt, ...);
int put_c(char c);
int put_str(char *str);
int put_addrs(uintptr_t addr);
int put_nb(int nb);

#endif