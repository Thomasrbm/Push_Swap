/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:17:46 by throbert          #+#    #+#             */
/*   Updated: 2024/11/01 22:28:08 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nb_elem, size_t size_elem)
{
	void	*tab;

	tab = malloc(nb_elem * size_elem);
	if (!tab)
		return (NULL);
	ft_bzero(tab, nb_elem * size_elem);
	return (tab);
}

// #include <stdio.h>

// int main()
// {
// 	char str[] = "Hello";
// 	char *ptr = str;
// 	printf("adress : %p, result : %s\n", ptr, ptr);
// 	ptr = ft_calloc(5, 1);
// 	printf("adress changed : %p, result null: %s", ptr, ptr);
// 	return 0;
// }