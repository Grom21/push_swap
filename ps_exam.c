/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_exam.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etisha <etisha@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:26:06 by etisha            #+#    #+#             */
/*   Updated: 2022/05/06 12:26:08 by etisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9') || c == '-' || c == ' ')
		return (1);
	else
		return (0);
}

void	ft_exam_double_minus(const char *str, t_list **list, int i)
{
	if (!(str[i] >= '0' && str[i] <= '9'))
	{
		write (2, "Error\n", 6);
		ft_free_memory(list, NULL);
	}
}

void	ft_exam_argv(char **argv)
{
	int	x;
	int	y;
	int	exam;

	x = 1;
	while (argv[x])
	{
		y = 0;
		while (argv[x][y])
		{
			exam = ft_isdigit(argv[x][y]);
			if (exam == 0)
			{
				write (2, "Error\n", 6);
				exit(1);
			}
			y++;
		}
		x++;
	}
}

static void	ft_double(t_list **list)
{
	t_list	*copy;
	t_list	*copy2;
	int		num;

	copy = *list;
	while (copy)
	{
		num = copy->count;
		copy2 = copy->next;
		while (copy2)
		{
			if (num == copy2->count)
			{
				write (2, "Error\n", 6);
				ft_free_memory(list, NULL);
			}
			copy2 = copy2->next;
		}
		copy = copy->next;
	}
}

void	ft_exam_sort_and_double(t_list **list)
{
	t_list	*copy;
	int		num;
	int		sort;

	copy = (*list)->next;
	num = (*list)->count;
	sort = 0;
	ft_double(list);
	while (copy)
	{
		if (num > copy->count)
			sort = 1;
		num = copy->count;
		copy = copy->next;
	}
	if (sort == 0)
		ft_free_memory(list, NULL);
}
