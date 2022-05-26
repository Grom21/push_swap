/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_forsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etisha <etisha@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:26:16 by etisha            #+#    #+#             */
/*   Updated: 2022/05/06 12:26:18 by etisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_found_min(t_list **list, int size)
{
	t_list	*copylist;
	int		i;
	int		x;
	int		number_min;

	x = 0;
	number_min = 0;
	copylist = *list;
	i = copylist->count;
	while (x < size)
	{
		if (i > copylist->count)
		{
			i = copylist->count;
			number_min = x;
		}
		copylist = copylist->next;
		x++;
	}
	return (number_min);
}

static int	ft_found_max(t_list **list, int size)
{
	int		i;
	int		x;
	int		number_max;
	t_list	*copylist;

	copylist = *list;
	x = 0;
	number_max = 0;
	i = copylist->count;
	while (x < size)
	{
		if (i < copylist->count)
		{
			i = copylist->count;
			number_max = x;
		}
		copylist = copylist->next;
		x++;
	}
	return (number_max);
}

static void	ft_back_in_stack_a(t_list **stack_a, t_list **stack_b)
{
	int	x;
	int	y;

	x = ft_size_of_stack(stack_b) + 1;
	while (--x > 0)
	{
		y = ft_found_max(stack_b, x);
		while (y > 0 && y < x)
		{
			if (y <= x / 2)
			{
				ft_rotate_b(stack_b);
				y--;
			}
			else
			{
				ft_revers_rotate_b(stack_b);
				y++;
			}
		}
		ft_push_a(stack_b, stack_a);
	}
}

static int	ft_found_numelem(int size)
{
	if (size > 100)
		return (30);
	else
		return (15);
}

void	ft_for_sort(t_list **stack_a, t_list **stack_b, int size)
{
	int	numelem;
	int	i;

	size = ft_size_of_stack(stack_a);
	numelem = ft_found_numelem(size);
	ft_f_base(stack_a, stack_b, size);
	i = 0;
	while (i < size)
	{
		if ((*stack_a)->index <= (i + numelem))
		{
			if ((*stack_a)->index < (i + (numelem / 4)))
				ft_push_b(stack_a, stack_b);
			else
			{
				ft_push_b(stack_a, stack_b);
				ft_rotate_b(stack_b);
			}
			i++;
		}
		else
			ft_rotate_a(stack_a);
	}	
	ft_back_in_stack_a(stack_a, stack_b);
}
