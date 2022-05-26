/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_instructions_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etisha <etisha@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:26:43 by etisha            #+#    #+#             */
/*   Updated: 2022/05/06 12:26:45 by etisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_list **list)
{
	t_list	*buffer;

	buffer = (*list)->next;
	(*list)->next = buffer->next;
	buffer->next = *list;
	*list = buffer;
	write(1, "sa\n", 3);
}

void	ft_rotate_a(t_list **list)
{
	t_list	*buffer;
	t_list	*newlist;

	newlist = (*list)->next;
	buffer = *list;
	while (buffer->next)
	buffer = buffer->next;
	buffer->next = *list;
	(*list)->next = NULL;
	*list = newlist;
	write(1, "ra\n", 3);
}

void	ft_revers_rotate_a(t_list **list)
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
	write(1, "rra\n", 4);
}

void	ft_push_a(t_list **sb, t_list **sa)
{
	t_list	*buffer;

	buffer = *sb;
	*sb = (*sb)->next;
	buffer->next = *sa;
	*sa = buffer;
	write (1, "pa\n", 3);
}
