/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:47:27 by imugica-          #+#    #+#             */
/*   Updated: 2024/10/30 12:28:47 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_lower(char a)
{
	if (a >= 'a' && a <= 'z')
		return (1);
	return (0);
}

int	is_upper(char a)
{
	if (a >= 'A' && a <= 'Z')
		return (1);
	return (0);
}

int	is_number(char a)
{
	if (a >= '0' && a <= '9')
		return (1);
	return (0);
}

int	check(char a)
{
	if (is_upper(a) || is_number(a) || is_lower(a))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	unsigned int	i;

	i = 0;
	if (str[i] != '\0' && is_lower(str[i]))
		str[i] -= 32;
	i++;
	while (str[i])
	{
		if (is_lower(str[i]))
		{
			if (!check(str[i - 1]))
				str[i] -= 32;
		}
		else if (is_upper(str[i]))
		{
			if (check(str[i - 1]))
				str[i] += 32;
		}
		i++;
	}
	return (str);
}
