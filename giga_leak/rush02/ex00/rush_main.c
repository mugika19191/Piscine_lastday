/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovalch <vkovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:56:09 by vkovalch          #+#    #+#             */
/*   Updated: 2024/11/03 19:45:39 by vkovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	**create_dict(char *path)
{
	char	*temp;
	char	**dict;
	int		file;
	int		size;

	size = count_lines(path);
	if (size < 0)
		return (0);
	file = open(path, O_RDONLY);
	if (file == -1)
		return (0);
	temp = malloc (sizeof(char) * (size + 1));
	if (!temp)
	{
		close (file);
		return (0);
	}
	read(file, temp, size);
	temp[size] = '\0';
	dict = ft_split(temp);
	free(temp);
	close(file);
	return (dict);
}

char	*create_skip_value(void)
{
	int		i;
	char	*skip_value;

	i = 0;
	skip_value = malloc(sizeof(char) * 4);
	if (!skip_value)
		return (0);
	*skip_value = 0;
	while (i < 3)
	{
		skip_value[i] = '0';
		i++;
	}
	skip_value[i] = 0;
	return (skip_value);
}

int	check_next(char **threes_array, char *skip_value, int index)
{
	int		i;

	i = index;
	while (threes_array[i])
	{
		if (ft_strcmp(threes_array[i], skip_value) > 0)
			return (1);
		i++;
	}
	return (0);
}

int	process(char **dict,
		char **threes_array,
		int threes_count,
		char *skip_value)
{
	int	i;

	i = 0;
	while (threes_array[i])
	{
		if (i > 0 && ft_strcmp(threes_array[i], skip_value) > 0)
			ft_putchar(' ');
		print_threes(threes_array[i], dict);
		if (threes_count - i > 1 && ft_strcmp(threes_array[i], skip_value) > 0)
		{
			print_rest(threes_count - i, dict);
			if (check_next(threes_array, skip_value, i + 1))
				ft_putchar(',');
		}
		i++;
	}
	ft_putchar('\n');
	return (1);
}

int	show_solution(char *number, char *path)
{
	char	**threes_array;
	char	**dict;
	char	*skip_value;
	int		threes_count;

	dict = create_dict(path);
	threes_count = count_threes(number);
	threes_array = create_threes_array(number, threes_count);
	skip_value = create_skip_value();
	if (ft_strlen(number) == 1 && number[0] == '0')
	{
		print_tens_value(number, dict);
		ft_putchar('\n');
		ft_free(dict, threes_array, number, skip_value);
		return (1);
	}
	if (process(dict, threes_array, threes_count, skip_value))
	{
		ft_free(dict, threes_array, number, skip_value);
		return (1);
	}
	ft_free(dict, threes_array, number, skip_value);
	return (0);
}
