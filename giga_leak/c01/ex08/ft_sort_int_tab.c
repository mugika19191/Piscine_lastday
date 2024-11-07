/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:18:39 by imugica-          #+#    #+#             */
/*   Updated: 2024/10/22 18:18:42 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size);

void	ft_sort_int_tab(int *tab, int size)
{
	int		i;
	int		j;
	int		minimum;

	i = 0;
	j = 0;
	minimum = *tab;
	while (j < size)
	{
		while (i < size)
		{
			if ((*(tab + i)) < minimum)
			{
				minimum = *(tab + i);
				*(tab + i) = *(tab + j);
				*(tab + j) = minimum;
			}
			i++;
		}
		j++;
		i = j;
		minimum = *(tab + i);
	}
}
