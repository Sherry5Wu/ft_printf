#include "ft_printf.h"

static int fmt_conversion(const char fmt, va_list arg)
{
	int char_printed;

	count = 0;
	if (fmt == 'c')
		char_printed = put_c(va_arg(arg, char));
	if (fmt == 's')
		char_printed = put_str(va_arg(arg, char *));
	if (fmt == 'p')
		char_printed = put_adrs(va_arg(arg, uintptr_t));
	if (fmt == 'd' || fmt == 'i')
		char_printed = put_nb(va_arg(arg, int));
	if (fmt == 'u')
		char_printed = put_unb(va_arg(arg, unsigned int));
	if (fmt == 'x' || fmt == 'X')
		char_printed = put_hexa(va_arg(arg, unsigned int), fmt);
	if (fmt == '%')
		char_printed += put_c(fmt);
	return (char_printed);
}

int ft_printf(const char *fmt, ...)
{
	va_list arg;
	int count;
	int i;

	va_start(arg, fmt);
	if (!fmt || !*fmt)
		return (0);
	i = 0;
	count = 0;
	while (fmt[i] != '%' && fmt[i])
	{
		count += put_c(&fmt[i]);
		i++;
	}
	if (fmt[i] == '%')
		count += fmt_conversion(fmt + i + 1);
	va_end(arg);
	return (count);
}