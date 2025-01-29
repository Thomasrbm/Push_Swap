/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:15:43 by throbert          #+#    #+#             */
/*   Updated: 2025/01/29 05:03:12 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(char *str)
{
	int		i;
	long	num;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	num = ft_atol(str);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}

static int	count_total_elements(char **argv, int argc)
{
	int		count;
	char	**split;
	int		i;
	int		j;

	count = 0;
	i = 0;
	while (++i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			exit_with_error(NULL, NULL);
		j = 0;
		while (split[j])
		{
			count++;
			free(split[j]);
			j++;
		}
		free(split);
	}
	return (count);
}

int	*malloc_and_count_numbers(int argc, char **argv, int *count)
{
	int	*numbers;

	*count = count_total_elements(argv, argc);
	numbers = malloc(sizeof(int) * (*count));
	if (!numbers)
		exit_with_error(NULL, NULL);
	return (numbers);
}

int	validate_args(int *numbers, char **argv, int *index)
{
	char	**split;
	int		j;
	int		i;

	i = 0;
	while (argv[++i]) // au cas ou ./pushswap "48984 asda " "sadad 78" "asd48 887" etc
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			return (0);
		j = 0;
		while (split[j])
		{
			if (!is_valid_number(split[j]))
			{
				free_split(split);
				return (0);
			}
			numbers[(*index)++] = ft_atoi(split[j]);
			j++;
		}
		free_split(split);
	}
	return (1);
}

int	*parse_arguments(int argc, char **argv, int *count)
{
	int	*numbers;
	int	index;

	numbers = malloc_and_count_numbers(argc, argv, count);
	if (!numbers)
		return (NULL);
	index = 0;
	if (!validate_args(numbers, argv, &index))
	{
		free(numbers);
		return (NULL);
	}
	if (!check_duplicates(numbers, *count))
	{
		free(numbers);
		return (NULL);
	}
	return (numbers);
}
