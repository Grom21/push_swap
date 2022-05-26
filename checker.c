/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etisha <etisha@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:25:39 by etisha            #+#    #+#             */
/*   Updated: 2022/05/06 12:25:41 by etisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_move_error(t_list **stack_a, t_list **stack_b, char *s)
{
	write (2, "Error\n", 6);
	free (s);
	ft_free_memory(stack_a, stack_b);
}

static void	ft_move(t_list **stack_a, t_list **stack_b, char *s)
{
	if (s[0] == 's' && s[1] == 'a' && s[2] == '\n')
		ft_swap_a(stack_a);
	else if (s[0] == 's' && s[1] == 'b' && s[2] == '\n')
		ft_swap_b(stack_b);
	else if (s[0] == 's' && s[1] == 's' && s[2] == '\n')
		ft_swap_ab(stack_a, stack_b);
	else if (s[0] == 'r' && s[1] == 'a' && s[2] == '\n')
		ft_rotate_a(stack_a);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'a' && s[3] == '\n')
		ft_revers_rotate_a(stack_a);
	else if (s[0] == 'r' && s[1] == 'b' && s[2] == '\n')
		ft_rotate_b(stack_b);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'b' && s[3] == '\n')
		ft_revers_rotate_b(stack_b);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == '\n')
		ft_rotate_ab(stack_a, stack_b);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'r' && s[3] == '\n')
		ft_revers_rotate_ab(stack_a, stack_b);
	else if (s[0] == 'p' && s[1] == 'a' && s[2] == '\n')
		ft_push_a(stack_b, stack_a);
	else if (s[0] == 'p' && s[1] == 'b' && s[2] == '\n')
		ft_push_b(stack_a, stack_b);
	else
		ft_move_error(stack_a, stack_b, s);
}

static void	ft_checker(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (ft_strlen(line) == 0)
			break ;
		ft_move(stack_a, stack_b, line);
		free(line);
	}
}

static void	ft_exam_result(t_list **stack_a, t_list **stack_b)
{
	t_list	*copy_list;
	int		count;

	if (*stack_b != NULL)
	{
		write(1, "KO\n", 3);
		ft_free_memory(stack_a, stack_b);
	}
	copy_list = *stack_a;
	count = -2147483648;
	while (copy_list)
	{
		if (count < copy_list->count)
			count = copy_list->count;
		else
		{
			write(1, "KO\n", 3);
			ft_free_memory(stack_a, stack_b);
		}
		copy_list = copy_list->next;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		exit(1);
	if (argc == 2 && ft_strlen(argv[1]) == 0)
		return (0);
	ft_exam_argv(argv);
	ft_write_on_stack(&stack_a, argv);
	ft_exam_sort_and_double(&stack_a);
	ft_checker(&stack_a, &stack_b);
	ft_exam_result(&stack_a, &stack_b);
	write(1, "OK\n", 3);
	ft_free_memory(&stack_a, &stack_b);
	return (0);
}
