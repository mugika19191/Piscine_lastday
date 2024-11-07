/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovalch <vkovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:52:46 by vkovalch          #+#    #+#             */
/*   Updated: 2024/11/03 22:11:47 by vkovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>	
# include <fcntl.h>
# include <stdio.h>

# define PATH "dictionaries/numbers.dict"

void	ft_error(void);

// validators
int		validate_arguments(int ac, char **av, char **number, char **path);
char	*ft_atoi_finish(char *str);
char	*ft_atoi(char *str);
int		count_lines(char *path);
int		validate_dict(char *path);

// rush_main
int		show_solution(char *number, char *path);
int		process(
			char **dict,
			char **threes_array,
			int threes_count,
			char *skip_value
			);
int		check_next(char **threes_array, char *skip_value, int index);
char	*create_skip_value(void);
char	**create_dict(char *path);

// manage_threes
int		count_threes(char *nb);
char	**create_threes_array(char *nbr, int size);

// print_handlers
int		print_rest(int threes_count, char **dict);
int		print_hundreds(char *nbr, char **dict);
int		print_tens(char *nbr, char **dict);
int		print_threes(char *nbr, char **dict);

// print_values
int		print_dict_value(char *nbr, char **dict);
int		print_tens_value(char *nbr, char **dict);

// checkers
int		is_space(char c);
int		is_alphanumerical(char c);
int		is_lowercase(char c);
int		is_uppercase(char c);
int		is_numerical(char c);

// utils
void	ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
void	ft_free(char **dict, char **threes_array, char *nbr, char *skip_value);

// // dict_navigator
int		get_word_length(char *str);
int		get_number_length(char *str);
char	*get_dict_value(char *str);
char	*get_dict_key(char *line);

// parse_info
char	*add_word(char *src, int size);
int		count_words_len(char *str);
int		count_words(char *phrase);
char	**ft_split(char *str);

#endif
