#include "ft_printf.h"

int put_c(char c)
{
	return (write(1, &c, 1));
}

int put_str(char *str)
{
	int char_pt;
	int i;

	char_pt = 0;
	i = 0;
	while (str[i])
	{
		if (!put_c(str[i]))
			return (0);
		char_pt += 1;
		i++;
	}
	return (char_pt);
}

int put_nb(int nb)
{
	int char_pt;

	char_pt = 0;
	if (nb == -2147483648)
		return (put_str('-2147483648'));
	if (nb < 0)
	{
		char_pt = put_c('-');
		nb *= -1;
	}
	if (nb > 9)
		put_nb(nb / 10);
	put_c(nb % 10 + '0');
	char_pt += 1;
	return (char_pt);
}

int put_addrs(uintptr_t addr)
{
	int char_pt;
}
