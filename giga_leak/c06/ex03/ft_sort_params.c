/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:19:55 by imugica-          #+#    #+#             */
/*   Updated: 2024/11/05 10:55:30 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	sort_args(char **args)
{
	int		i;
	int		j;
	char	*temp;

	i = 1;
	j = 1;
	while (args[i])
	{
		while (args[j])
		{
			if (ft_strcmp(args[i], args[j]) > 0)
			{
				temp = args[i];
				args[i] = args[j];
				args[j] = temp;
			}
			j++;
		}
		i++;
		j = i;
	}
}

void	write_args(char **sorted)
{
	int	i;
	int	j;

	i = 1;
	while (sorted[i])
	{
		j = 0;
		while (sorted[i][j])
		{
			write(1, &sorted[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int i, char **args)
{
	if (i > 1)
	{
		sort_args(args);
		write_args(args);
	}
	return (0);
}
