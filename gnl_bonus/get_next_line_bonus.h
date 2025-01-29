/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 03:41:13 by throbert          #+#    #+#             */
/*   Updated: 2025/01/27 18:58:38 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../push_swap_/push_swap_bonus.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*read_file(int fd, char *buffer);
char	*extract_line(char *buffer);
char	*buffer_clean(char *buffer);
char	*get_next_line(int fd, int should_free);

#endif
