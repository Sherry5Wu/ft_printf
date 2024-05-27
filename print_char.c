/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:19:10 by jingwu            #+#    #+#             */
/*   Updated: 2024/05/27 12:19:10 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// For the wrtie function, on failure, 'write' returns '-1' and sets 'errno' to
// indicate the error
int print_c(char c)
{
	if ((write(1, &c, 1) != 1))
		return (-1);
	return (1);
}

int print_str(char *str)
{
	int i;

	if (!str)
	{
		if ((write(1, "(null)"), 6) != 6)
			return(-1);
		return (6);
	}
	i = 0;
	while (str[i])
	{
		if (print_c(str[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}