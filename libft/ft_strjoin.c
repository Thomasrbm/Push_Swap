/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:01:27 by throbert          #+#    #+#             */
/*   Updated: 2024/10/31 07:45:10 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s_joined;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	s_joined = malloc(s1_len + s2_len + 1);
	if (!s_joined)
		return (NULL);
	ft_strlcpy(s_joined, s1, s1_len + 1);
	ft_strlcpy(s_joined + s1_len, s2, s2_len + 1);
	return (s_joined);
}

// #include <stdio.h>

// int main()
// {
// 	char s1[] = "Hello_";
// 	char s2[] = "World";
// 	char *stock = ft_strjoin(s1, s2);
// 	printf("%s", stock);
// 	free(stock);
// }
