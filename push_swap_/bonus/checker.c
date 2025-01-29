/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 02:29:08 by throbert          #+#    #+#             */
/*   Updated: 2025/01/29 01:13:00 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	is_valid_command(char *cmd)
{
	const char	*valid_commands[] = {
		"sa", "sb", "ss", "pa", "pb",
		"ra", "rb", "rr", "rra", "rrb", "rrr", NULL
	};
	int			i;

	if (!cmd || !*cmd)
		return (0);
	i = 0;
	while (valid_commands[i])
	{
		if (!ft_strcmp(cmd, valid_commands[i]))
			return (1);
		i++;
	}
	return (0);
}

void	exec_command(char *cmd, t_stack **a, t_stack **b)
{
	if (!cmd || !*cmd)
		return ;
	if (!handle_swap_push(cmd, a, b))
		if (!handle_rotate_cmd(cmd, a, b))
			exit_with_error(a, b);
}

void	free_static_buffer(void)
{
	static char	*buffer = NULL;

	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}
}

static void	read_instructions(t_stack **a, t_stack **b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0, 0); //0 = entree standard ,  0  je garde le buffer statique
		if (!line)
			break ;
		if (line[0] && line[ft_strlen(line) - 1] == '\n') // si y a une ligne = enleve \n
			line[ft_strlen(line) - 1] = '\0';
		if (!is_valid_command(line)) // verigie cette ligne
		{
			free(line);
			get_next_line(0, 1); // je go le free
			exit_with_error(a, b);
		}
		exec_command(line, a, b);
		free(line);
	}
	get_next_line(0, 1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		*numbers;
	int		count;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	numbers = parse_arguments(argc, argv, &count);
	if (!numbers)
		exit_with_error(&a, &b);
	if (!initialize_stacks(numbers, count, &a, &b))
		exit_with_error(&a, &b);
	read_instructions(&a, &b);
	if (!is_sorted(a) || b)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	clear_stack(&a);
	clear_stack(&b);
	return (0);
}

// void	print_stack(t_stack *stack)
// {
// 	t_stack	*tmp;

// 	tmp = stack;
// 	while (tmp)
// 	{
// 		ft_printf("%d ", tmp->value);
// 		tmp = tmp->next;
// 	}
// 	ft_printf("\n");
// }

// pk ctr + d
