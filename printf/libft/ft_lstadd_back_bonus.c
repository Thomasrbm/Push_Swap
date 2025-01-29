/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:58:54 by throbert          #+#    #+#             */
/*   Updated: 2024/10/28 19:03:19 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp_last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		temp_last = ft_lstlast(*lst);
		temp_last->next = new;
	}
}

// #include <stdlib.h>

// int	main()
// {
// 	t_list	*first = malloc(sizeof(t_list));
// 	t_list	second;
// 	t_list	third;
// 	t_list	new;

// 	first->next = &second;
// 	second.next = &third;
// 	third.next = NULL;
// 	new.next = NULL;
// 	t_list **lst = &first;

// 	first->content = "first";
// 	second.content = "second";
// 	third.content =  "third";
// 	printf("il n y a rien apres third : %p\n", third.next);
// 	printf("l adresse de new est : %p\n\n", &new);
// 	ft_lstadd_back(lst, &new);
// 	printf("adresse de apres third : %p", third.next);
// 	free(first);
// 	return 0;
// }
