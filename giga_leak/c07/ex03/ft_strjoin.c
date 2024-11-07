/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:41:35 by imugica-          #+#    #+#             */
/*   Updated: 2024/11/06 11:01:42 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	total_len_str(int size, char **strs, char *sep, int *total)
{
	int	i;
	int	total_len;

	if (size == 0)
		return (0);
	i = 0;
	total_len = 0;
	while (i < size)
		total_len += str_len(&strs[i++][0]);
	total_len += str_len(sep) * (size - 1);
	*total = total_len;
	return (total_len);
}

char	*nulo(void)
{
	char	*concat;

	concat = (char *)malloc(sizeof(char) * 1);
	if (concat == NULL)
		return (NULL);
	concat[0] = '\0';
	return (concat);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		k;
	int		total_len;
	char	*concat;

	i = 0;
	if (!total_len_str(size, strs, sep, &total_len))
		return (nulo());
	concat = (char *)malloc(sizeof(char) * (total_len + 1));
	i = 0;
	j = 0;
	k = 0;
	while (i < total_len)
	{
		while (strs[j][k])
			concat[i++] = strs[j][k++];
		k = 0;
		j++;
		while (sep[k] && i < total_len)
			concat[i++] = sep[k++];
		k = 0;
	}
	concat[i] = '\0';
	return (concat);
}
