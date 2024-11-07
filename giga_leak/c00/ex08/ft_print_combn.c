/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:53:58 by imugica-          #+#    #+#             */
/*   Updated: 2024/10/22 17:41:43 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_combn(int n);
void	print_comb(int n, int *ptr);

void	increment(int pos, int n, int *ptr)
{
	if ((*(ptr + pos - 1)) < (9 - n + pos))
	{
		(*(ptr + pos - 1))++;
	}
	else
	{
		increment(pos - 1, n, ptr);
		(*(ptr + pos - 1)) = (*(ptr + pos - 2)) + 1;
	}
}

void	is_last(int n, int *ptr, int *bol)
{
	int	i;

	i = 0;
	*bol = 1;
	while (i < n)
	{
		if ((*(ptr + i)) != (10 - n + i))
		{
			*bol = 0;
			break ;
		}
		i++;
	}
}

void	ft_print_combn(int n)
{
	int		i;
	int		bol;
	int		*array;
	int		array2[10];

	array = &array2[10 - n];
	i = 0;
	while (i < n)
	{
		*(array + i) = i;
		i++;
	}
	i = 1;
	is_last(n, array, &bol);
	while (!bol)
	{
		print_comb(n, array);
		increment(n, n, array);
		is_last(n, array, &bol);
	}
	print_comb(n, array);
}

void	print_comb(int n, int *ptr)
{
	int		bol;
	int		i;
	char	a;

	i = 0;
	is_last(n, ptr, &bol);
	while (i < n)
	{
		a = *ptr++ + 48;
		write(1, &a, 1);
		i++;
	}
	if (!bol)
		write(1, ", ", 2);
}
