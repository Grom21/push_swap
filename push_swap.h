/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etisha <etisha@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:28:04 by etisha            #+#    #+#             */
/*   Updated: 2022/05/06 12:28:08 by etisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	struct s_list	*next;
	int				count;
	int				index;
}	t_list;

int		ft_atoi(const char *str, t_list **list);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
void	ft_create_next(t_list **list, int count);
void	ft_write_on_stack(t_list **list, char **argv);
void	ft_free_memory(t_list **list_a, t_list **list_b);
void	ft_free_memory_split(char **matrix, int x);
int		ft_size_of_stack(t_list **list);
int		ft_found_min(t_list **list, int size);

void	ft_exam_argv(char **argv);
void	ft_exam_sort_and_double(t_list **list);
void	ft_exam_double_minus(const char *str, t_list **list, int i);

void	ft_swap_a(t_list **list);
void	ft_swap_b(t_list **list);
void	ft_swap_ab(t_list **lista, t_list **listb);
void	ft_rotate_a(t_list **list);
void	ft_rotate_b(t_list **list);
void	ft_rotate_ab(t_list **lista, t_list **listb);
void	ft_revers_rotate_a(t_list **list);
void	ft_revers_rotate_b(t_list **list);
void	ft_revers_rotate_ab(t_list **lista, t_list **listb);
void	ft_push_a(t_list **sb, t_list **sa);
void	ft_push_b(t_list **sa, t_list **sb);

void	ft_push_swap(t_list **stack_a, t_list **stack_b, int size);
void	ft_sotr_three(t_list **stack_a);
void	ft_for_sort(t_list **stack_a, t_list **stack_b, int size);
int		ft_check_stack(t_list **list, int size, int midl);
void	ft_f_base(t_list **stack_a, t_list **stack_b, int size);

#endif
