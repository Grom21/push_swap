/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_free_memory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etisha <etisha@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:26:24 by etisha            #+#    #+#             */
/*   Updated: 2022/05/06 12:26:31 by etisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_memory(t_list **list_a, t_list **list_b)
{
	t_list	*buffer;

	while (*list_a)
	{
		buffer = (*list_a)->next;
		free (*list_a);
		*list_a = buffer;
	}
	if (list_b != NULL)
	{
		while (*list_b)
		{
			buffer = (*list_b)->next;
			free (*list_b);
			*list_b = buffer;
		}
	}
	exit(EXIT_SUCCESS);
}
