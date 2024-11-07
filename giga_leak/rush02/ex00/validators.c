/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovalch <vkovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:37:25 by vkovalch          #+#    #+#             */
/*   Updated: 2024/11/03 23:16:39 by vkovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_atoi_finish(char *str)
{
	char	*temp;
	int		len;
	int		i;

	len = 0;
	while (str[len] >= '0' && str[len] <= '9')
		len++;
	if (str[len] != 0)
		return (NULL);
	temp = malloc(sizeof(char) * len);
	i = 0;
	while (str[i] && i < len)
	{
		temp[i] = str[i];
		i++;
	}
	temp[len] = 0;
	if (temp[0] == 0)
	{
		return (NULL);
	}
	return (temp);
}

char	*ft_atoi(char *str)
{
	while (*str == 32)
		return (NULL);
	while (
		*str == ' ' || *str == '\f' || *str == '\n'
		|| *str == '\r' || *str == '\t' || *str == '\v'
	)
		return (NULL);
	while (*str == '-' || *str == '+')
		return (NULL);
	return (ft_atoi_finish(str));
}

int	count_lines(char *path)
{
	char	check;
	int		fd;
	int		count;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	count = 0;
	while (read(fd, &check, 1))
		count++;
	close(fd);
	return (count);
}

// int	count_lines(int fd)
// {
// 	char	check;
// 	int		counter;

// 	counter = 0;
// 	while (read(fd, &check, 1))
// 	{
// 		counter++;
// 	}
// 	return (counter);
// }
int	validate_dict(char *path)
{
	int	fd;
	int	line_count;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	line_count = count_lines(path);
	if (!line_count)
		return (0);
	return (1);
}
