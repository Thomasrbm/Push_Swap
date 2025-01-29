/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:10:44 by throbert          #+#    #+#             */
/*   Updated: 2024/10/28 19:04:39 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new_str;

	new_str = malloc((ft_strlen((char *)s) + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

// #include <stdio.h>

// char test(unsigned int i, char c) 
// {
//     return c + i;
// }

// int main() 
// {
//     char *str = "0123";
//     char *result = ft_strmapi(str, test);

//     printf("Résultat : %s\n", result);
//     free(result);	
//     return 0;
// }