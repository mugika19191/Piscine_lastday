/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorcuer <hcorcuer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:30:58 by vkovalch          #+#    #+#             */
/*   Updated: 2024/11/03 17:35:51 by hcorcuer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*add_word(char *src, int size)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc (sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	while (src[i] && i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	count_words_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	count_words(char *str)
{
	int	i;
	int	count;
	int	word_len;

	i = 0;
	count = 0;
	word_len = 0;
	while (str[i])
	{
		while (str[i] && str[i] == '\n')
			i++;
		word_len = count_words_len(str + i);
		if (word_len)
			count++;
		i += word_len;
		word_len = 0;
	}
	return (count);
}

char	**ft_split(char *str)
{
	int		i;
	int		j;
	int		word_len;
	int		word_count;
	char	**container;

	i = 0;
	j = 0;
	word_len = 0;
	word_count = count_words(str);
	container = malloc(sizeof(char *) * (word_count + 1));
	if (!container)
		return (NULL);
	while (str[i])
	{
		while (str[i] && str[i] == '\n')
			i++;
		word_len = count_words_len(str + i);
		if (word_len)
			container[j++] = add_word(str + i, word_len);
		i += word_len;
		word_len = 0;
	}
	container[j] = 0;
	return (container);
}
