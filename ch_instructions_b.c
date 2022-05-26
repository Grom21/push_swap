/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_instructions_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etisha <etisha@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:23:55 by etisha            #+#    #+#             */
/*   Updated: 2022/05/06 12:23:57 by etisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_swap_b(t_list **list)
{
	t_list	*buffer;

	if (*list == NULL)
		return ;
	buffer = (*list)->next;
	(*list)->next = buffer->next;
	buffer->next = *list;
	*list = buffer;
}

void	ft_rotate_b(t_list **list)
{
	t_list	*buffer;
	t_list	*newlist;

	if (*list == NULL)
		return ;
	if ((*list)->next)
	{
		newlist = (*list)->next;
		buffer = *list;
		while (buffer->next)
		buffer = buffer->next;
		buffer->next = *list;
		(*list)->next = NULL;
		*list = newlist;
	}
}

void	ft_revers_rotate_b(t_list **list)
{
	int		x;
	t_list	*newlist;
	t_list	*lastlist;

	if (*list == NULL)
		return ;
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
}

void	ft_push_b(t_list **sa, t_list **sb)
{
	t_list	*buffer;

	if (*sa == NULL)
		return ;
	buffer = *sa;
	*sa = (*sa)->next;
	buffer->next = *sb;
	*sb = buffer;
}
