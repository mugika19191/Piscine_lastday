/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:28:06 by imugica-          #+#    #+#             */
/*   Updated: 2024/10/30 10:48:41 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	d_len;
	unsigned int	s_len;
	unsigned int	i;

	d_len = 0;
	while (dest[d_len])
		d_len++;
	s_len = 0;
	while (src[s_len])
		s_len++;
	if (size == 0 || d_len >= size)
		return (s_len + d_len);
	i = 0;
	while (src[i] && (d_len + i < size -1))
	{
		dest[i + d_len] = src[i];
		i++;
	}
	dest[d_len + i] = '\0';
	return (s_len + d_len);
}
