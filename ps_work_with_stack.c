/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_work_with_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etisha <etisha@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:27:40 by etisha            #+#    #+#             */
/*   Updated: 2022/05/06 12:27:47 by etisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*ft_create_elem(int count)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		ft_free_memory(&list, NULL);
	list->count = count;
	list->next = NULL;
	return (list);
}

void	ft_create_next(t_list **list, int count)
{
	t_list	*lastlist;

	lastlist = *list;
	if (!lastlist)
		*list = ft_create_elem(count);
	else
	{
		while (lastlist->next)
			lastlist = lastlist->next;
	lastlist->next = ft_create_elem(count);
	}
}

static void	ft_write_split(t_list **list, char *argv)
{
	int		x;
	int		count;
	char	**matrix;

	matrix = ft_split(argv, ' ');
	if (!matrix)
		exit(1);
	x = 0;
	while (matrix[x])
	{
		count = ft_atoi(matrix[x], list);
		ft_create_next(list, count);
		x++;
	}
	ft_free_memory_split(matrix, x);
}

static int	ft_split_or_not(char *argv)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (argv[i])
	{
		if (argv[i] >= '0' && argv[i] <= '9')
			flag = 1;
		i++;
	}
	if (flag == 0)
		return (-1);
	i = 0;
	while (argv[i])
	{
		if (argv[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

void	ft_write_on_stack(t_list **list, char **argv)
{
	int	x;
	int	count;
	int	ret;

	x = 1;
	while (argv[x])
	{
		ret = ft_split_or_not(argv[x]);
		if (ret == 1)
			ft_write_split(list, argv[x]);
		else if (ret == 0)
		{
			count = ft_atoi(argv[x], list);
			ft_create_next(list, count);
		}
		else if (ret == -1)
		{
			write (2, "Error\n", 6);
			ft_free_memory(list, NULL);
		}
		x++;
	}
}
