/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_presort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etisha <etisha@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:27:10 by etisha            #+#    #+#             */
/*   Updated: 2022/05/06 12:27:12 by etisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_stack(t_list **list, int size, int midl)
{
	int		check;
	t_list	*copylist;
	int		number;

	number = 0;
	copylist = *list;
	check = 0;
	while (copylist)
	{
		if (copylist->count <= midl)
		{
			check = 1;
			number++;
			break ;
		}
		copylist = copylist->next;
		number++;
	}
	if (check == 1 && number > size / 2)
		return (-1);
	return (check);
}

int	ft_size_of_stack(t_list **list)
{
	int		x;
	t_list	*copylist;

	copylist = *list;
	x = 0;
	while (copylist)
	{
		copylist = copylist->next;
		x++;
	}
	return (x);
}

static int	*ft_sort(int *mas, int size)
{
	int	a;
	int	b;
	int	t;

	a = 1;
	while (a < size)
	{
		t = mas[a];
		b = a - 1;
		while (b >= 0 && t < mas[b])
		{
			mas[b + 1] = mas[b];
			b--;
		}
		mas[b + 1] = t;
		a++;
	}
	return (mas);
}

static void	ft_save_index(t_list *copylist, int *mas, int size)
{
	int	a;

	while (copylist)
	{
		a = 0;
		while (a < size)
		{
			if (copylist->count == mas[a])
			{
				copylist->index = a;
				break ;
			}
			a++;
		}
		copylist = copylist->next;
	}
}

void	ft_f_base(t_list **stack_a, t_list **stack_b, int size)
{
	t_list	*copylist;
	int		*mas;
	int		a;

	mas = (int *)malloc(sizeof(int) * size);
	if (!mas)
		ft_free_memory(stack_a, stack_b);
	copylist = *stack_a;
	a = 0;
	while (copylist)
	{
		mas[a] = copylist->count;
		copylist = copylist->next;
		a++;
	}
	mas = ft_sort(mas, size);
	copylist = *stack_a;
	ft_save_index(copylist, mas, size);
	free (mas);
}
