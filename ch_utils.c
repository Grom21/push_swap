/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etisha <etisha@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:25:07 by etisha            #+#    #+#             */
/*   Updated: 2022/05/06 12:25:10 by etisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
