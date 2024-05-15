#include "ft_printf.h"

int put_c(int c)
{
	char ch;
	ch = (char)c;
	return (write(1, &ch, 1));
}

int put_str(char *str)
{
	int char_printed;
}