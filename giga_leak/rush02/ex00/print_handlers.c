/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovalch <vkovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:58:05 by vkovalch          #+#    #+#             */
/*   Updated: 2024/11/03 21:59:38 by vkovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	print_rest(int threes_array_size, char **dict)
{
	char	*value;
	int		size;
	int		i;

	size = ((threes_array_size - 1) * 3) + 1;
	value = malloc(sizeof(char) * (size + 1));
	if (!value)
		return (0);
	value[0] = '1';
	i = 1;
	while (i < size)
	{
		value[i] = '0';
		i++;
	}
	value[size] = '\0';
	ft_putchar(' ');
	print_tens_value(value, dict);
	free(value);
	return (1);
}

int	print_hundreds(char *nbr, char **dict)
{
	char	*c;

	if (nbr[0] == '0')
		return (1);
	c = malloc(sizeof(char) * 2);
	if (!c)
		return (0);
	*c = nbr[0];
	c[1] = '\0';
	print_dict_value(c, dict);
	ft_putchar(' ');
	print_dict_value("100", dict);
	free(c);
	return (1);
}

int	print_tens(char *nbr, char **dict)
{
	char	*d;

	while (*nbr == '0')
		nbr++;
	if (!*nbr)
		return (1);
	if (*nbr && print_tens_value(nbr, dict))
		return (1);
	d = malloc(sizeof(char) * 3);
	if (!d)
		return (0);
	*d = nbr[0];
	d[1] = '0';
	d[2] = '\0';
	print_tens_value(d, dict);
	free(d);
	return (0);
}

int	print_threes(char *nbr, char **dict)
{
	int	nbr_len;

	nbr_len = ft_strlen(nbr);
	if (nbr_len == 3)
	{
		print_hundreds(nbr, dict);
		if (nbr[0] != '0' && (nbr[1] != '0' || nbr[2] != '0'))
			ft_putstr(" and ");
		nbr++;
	}
	if (print_tens(nbr, dict))
		return (1);
	nbr++;
	ft_putchar('-');
	print_dict_value(nbr, dict);
	return (1);
}
// ft_putchar(' '); - replace the ft_putchar('-');
// ft_putstr(" and "); - print_hundreds(nbr, dict);
// ft_putchar('-'); - above the ft_putchar(' ');