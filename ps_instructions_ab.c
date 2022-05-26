/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_instructions_ab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etisha <etisha@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:26:51 by etisha            #+#    #+#             */
/*   Updated: 2022/05/06 12:26:54 by etisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_ab(t_list **lista, t_list **listb)
{
	t_list	*buffer;

	if (*lista)
	{
		buffer = (*lista)->next;
		(*lista)->next = buffer->next;
		buffer->next = *lista;
		*lista = buffer;
	}
	if (*listb)
	{
		buffer = (*listb)->next;
		(*listb)->next = buffer->next;
		buffer->next = *listb;
		*listb = buffer;
	}
	write(1, "ss\n", 3);
}

void	ft_rotate_ab(t_list **lista, t_list **listb)
{
	t_list	*buffer;
	t_list	*newlist;

	if (*lista)
	{
		newlist = (*lista)->next;
		buffer = *lista;
		while (buffer->next)
			buffer = buffer->next;
		buffer->next = *lista;
		(*lista)->next = NULL;
		*lista = newlist;
	}
	if (*listb)
	{
		newlist = (*listb)->next;
		buffer = *listb;
		while (buffer->next)
			buffer = buffer->next;
		buffer->next = *listb;
		(*listb)->next = NULL;
		*listb = newlist;
	}
	write(1, "rr\n", 3);
}

static void	ft_revers_rotate(t_list **list)
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
}

void	ft_revers_rotate_ab(t_list **lista, t_list **listb)
{
	if (*lista)
		ft_revers_rotate(lista);
	if (*listb)
		ft_revers_rotate(listb);
	write(1, "rrr\n", 4);
}
