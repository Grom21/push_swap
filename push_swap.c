/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etisha <etisha@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:27:57 by etisha            #+#    #+#             */
/*   Updated: 2022/05/06 12:27:59 by etisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str, t_list **list)
{
	int				i;
	long long int	result;
	int				minus;

	i = 0;
	minus = 1;
	if (str[i] == '-')
	{
		minus = -minus;
		i++;
	}
	ft_exam_double_minus(str, list, i);
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (result * minus > 2147483647 || result * minus < -2147483648)
		{
			write (2, "Error\n", 6);
			ft_free_memory(list, NULL);
		}
		i++;
	}
	return (result * minus);
}

void	ft_sotr_three(t_list **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->count;
	second = (*stack_a)->next->count;
	third = (*stack_a)->next->next->count;
	if (first < second && first < third && second > third)
	{
		ft_revers_rotate_a(stack_a);
		ft_swap_a(stack_a);
	}
	else if (third > first && third > second && first > second)
		ft_swap_a(stack_a);
	else if (second > first && second > third)
		ft_revers_rotate_a(stack_a);
	else if (first > second && third > second)
		ft_rotate_a(stack_a);
	else if (first > third && second > third)
	{
		ft_rotate_a(stack_a);
		ft_swap_a(stack_a);
	}
}

static void	ft_sort_five(t_list **stack_a, t_list **stack_b, int size)
{
	int	x;
	int	y;

	x = size + 1;
	while (--x > 3)
	{
		y = ft_found_min(stack_a, x);
		while (y > 0 && y < x)
		{
			if (y < x / 2 + 1)
			{
				ft_rotate_a(stack_a);
				y--;
			}
			else
			{
				ft_revers_rotate_a(stack_a);
				y++;
			}
		}
		ft_push_b(stack_a, stack_b);
	}
	ft_sotr_three(stack_a);
	while (++x <= size)
		ft_push_a(stack_b, stack_a);
}

void	ft_push_swap(t_list **stack_a, t_list **stack_b, int size)
{
	size = ft_size_of_stack(stack_a);
	if (size == 2)
		ft_swap_a(stack_a);
	else if (size == 3)
		ft_sotr_three(stack_a);
	else if (size < 6)
		ft_sort_five(stack_a, stack_b, size);
	else
		ft_for_sort(stack_a, stack_b, size);
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
	ft_push_swap(&stack_a, &stack_b, argc - 1);
	ft_free_memory(&stack_a, &stack_b);
	return (0);
}
