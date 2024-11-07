/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovalch <vkovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 10:33:57 by vkovalch          #+#    #+#             */
/*   Updated: 2024/11/03 23:27:30 by vkovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	manual_input(char *number, char *path)
{
	char	buffer[256];
	int		bytes_read;

	write(1, "Enter an integer: ", 18);
	bytes_read = read(1, buffer, 256);
	buffer[bytes_read - 1] = '\0';
	number = ft_atoi(buffer);
	if (number == 0)
		return (0);
	path = PATH;
	return (1);
}

int	validate_arguments(int ac, char **av, char **number, char **path)
{
	if (ac == 3)
	{
		*number = ft_atoi(av[2]);
		if (*number == 0)
			return (0);
		*path = av[1];
		return (1);
	}
	else if (ac == 2)
	{
		*number = ft_atoi(av[1]);
		if (*number == 0)
			return (0);
		*path = PATH;
		return (1);
	}
	else if (ac == 1)
	{
		return (manual_input(*number, *path));
	}
	return (0);
}

int	main(int ac, char **av)
{
	char	*path;
	char	*number;

	if (!validate_arguments(ac, av, &number, &path))
	{
		write (2, "Error\n", 6);
		return (1);
	}
	if (!validate_dict(path))
	{
		free(number);
		write(2, "Dict Error\n", 11);
		return (1);
	}
	if (!show_solution(number, path))
	{
		write(2, "Dict Error\n", 12);
		return (1);
	}
	return (0);
}
