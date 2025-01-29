/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:46:53 by throbert          #+#    #+#             */
/*   Updated: 2025/01/29 04:45:09 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(const char *s, char c)
{
	int	str_i;
	int	count;

	str_i = 0;
	count = 0;
	while (s[str_i])
	{
		while (s[str_i] == c)
			str_i++;
		if (s[str_i])
		{
			count++;
			while (s[str_i] && s[str_i] != c)
				str_i++;
		}
	}
	return (count);
}

static char	*fill(const char *s, char c, int *str_i)
{
	int		len;
	char	*word;

	len = 0;
	while (s[*str_i + len] && s[*str_i + len] != c)
		len++;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	len = 0;
	while (s[*str_i] && s[*str_i] != c)
		word[len++] = s[(*str_i)++];
	word[len] = '\0';
	return (word);
}

static void	*free_tab(char **tab, int double_tab)
{
	while (double_tab > 0)
	{
		double_tab--;
		free(tab[double_tab]);
	}
	free(tab);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**tab;
	int		double_tab;
	int		str_i;

	if (!s)
		return (NULL);
	tab = malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	double_tab = 0;
	str_i = 0;
	while (s[str_i])
	{
		while (s[str_i] == c)
			str_i++;
		if (s[str_i])
		{
			tab[double_tab] = fill(s, c, &str_i);
			if (!tab[double_tab])
				return (free_tab(tab, double_tab));
			double_tab++;
		}
	}
	tab[double_tab] = NULL;
	return (tab);
}

// #include <stdio.h>

// int main()
// {
//     char str[] = "   Hello world   from 42  ";
//     char c = ' ';
//     char **tab = ft_split(str, c);

//     if (!tab)
//     {
//         printf("Erreur d'allocation mémoire.\n");
//         return (1);
//     }

//     int i = 0;
//     while (tab[i]) // Affiche les sous-chaînes
//     {
//         printf("tab[%d] = '%s'\n", i, tab[i]);
//         free(tab[i]); // Libère chaque chaîne
//         i++;
//     }

//     free(tab); // Libère le tableau de pointeurs
//     return 0;
// }