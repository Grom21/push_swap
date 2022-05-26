/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_instructions_ab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etisha <etisha@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:24:03 by etisha            #+#    #+#             */
/*   Updated: 2022/05/06 12:24:05 by etisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_swap_ab(t_list **lista, t_list **listb)
{
	t_list	*buffer;

	if (*lista && (*lista)->next)
	{
		buffer = (*lista)->next;
		(*lista)->next = buffer->next;
		buffer->next = *lista;
		*lista = buffer;
	}
	if (*listb && (*listb)->next)
	{
		buffer = (*listb)->next;
		(*listb)->next = buffer->next;
		buffer->next = *listb;
		*listb = buffer;
	}
}

void	ft_rotate_ab(t_list **lista, t_list **listb)
{
	t_list	*buffer;
	t_list	*newlist;

	if (*lista && (*lista)->next)
	{
		newlist = (*lista)->next;
		buffer = *lista;
		while (buffer->next)
			buffer = buffer->next;
		buffer->next = *lista;
		(*lista)->next = NULL;
		*lista = newlist;
	}
	if (*listb && (*listb)->next)
	{
		newlist = (*listb)->next;
		buffer = *listb;
		while (buffer->next)
			buffer = buffer->next;
		buffer->next = *listb;
		(*listb)->next = NULL;
		*listb = newlist;
	}
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
	if (*lista && (*lista)->next)
		ft_revers_rotate(lista);
	if (*listb && (*listb)->next)
		ft_revers_rotate(listb);
}
