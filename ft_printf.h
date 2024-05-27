#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h> // for pointer type uintptr_t

int ft_printf(const char *fmt, ...);
int print_c(char c);
int print_str(char *str);
int print_addrs(uintptr_t addr);
int print_nb(int nb);
int print_unb(unsigned int unb);
int	print_hexa(unsigned int nb, char fmt);

#endif