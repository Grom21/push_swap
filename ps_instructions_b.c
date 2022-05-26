/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_instructions_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etisha <etisha@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:26:58 by etisha            #+#    #+#             */
/*   Updated: 2022/05/06 12:27:00 by etisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_b(t_list **list)
{
	t_list	*buffer;

	buffer = (*list)->next;
	(*list)->next = buffer->next;
	buffer->next = *list;
	*list = buffer;
	write(1, "sb\n", 3);
}

void	ft_rotate_b(t_list **list)
{
	t_list	*buffer;
	t_list	*newlist;

	if ((*list)->next)
	{
		newlist = (*list)->next;
		buffer = *list;
		while (buffer->next)
		buffer = buffer->next;
		buffer->next = *list;
		(*list)->next = NULL;
		*list = newlist;
		write(1, "rb\n", 3);
	}
}

void	ft_revers_rotate_b(t_list **list)
{
	int		x;
	t_list	*newlist;
	t_list	*lastlist;

	newlist = *list;
	x = 0;
	while (newlist->next)
	{
		newlist = newlist->next;
		x++;
	}
	lastlist = *list;
	while (--x > 0)
		lastlist = lastlist->next;
	lastlist->next = NULL;
	newlist->next = *list;
	*list = newlist;
	write(1, "rrb\n", 4);
}

void	ft_push_b(t_list **sa, t_list **sb)
{
	t_list	*buffer;

	buffer = *sa;
	*sa = (*sa)->next;
	buffer->next = *sb;
	*sb = buffer;
	write (1, "pb\n", 3);
}
