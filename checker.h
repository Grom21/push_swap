/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etisha <etisha@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:25:45 by etisha            #+#    #+#             */
/*   Updated: 2022/05/06 12:25:48 by etisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	struct s_list	*next;
	int				count;
	int				index;
}	t_list;

/*CHECKER FUNCTIONS*/

void	ft_exam_argv(char **argv);
void	ft_write_on_stack(t_list **list, char **argv);
void	ft_exam_double_minus(const char *str, t_list **list, int i);
void	ft_create_next(t_list **list, int count);
void	ft_exam_sort_and_double(t_list **list);
void	ft_free_memory(t_list **list_a, t_list **list_b);
int		ft_atoi(const char *str, t_list **list);
char	**ft_split(char const *s, char c);
void	ft_free_memory_split(char **matrix, int x);

void	ft_swap_a(t_list **list);
void	ft_rotate_a(t_list **list);
void	ft_revers_rotate_a(t_list **list);
void	ft_push_a(t_list **sb, t_list **sa);
void	ft_swap_b(t_list **list);
void	ft_rotate_b(t_list **list);
void	ft_revers_rotate_b(t_list **list);
void	ft_push_b(t_list **sa, t_list **sb);
void	ft_swap_ab(t_list **lista, t_list **listb);
void	ft_rotate_ab(t_list **lista, t_list **listb);
void	ft_revers_rotate_ab(t_list **lista, t_list **listb);

/*GNL FUNCTIONS*/

char	*get_next_line(int fd);
char	*get_next_line(int fd);
char	*ft_read_file(char *line, char *reminder, int fd);
char	*ft_find_line(char *reminder);
void	ft_new_reminder(char *reminder);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_free_reminder(char *reminder);
char	*ft_copy_in_line(char *line, char *reminder);
char	*ft_copy_from_read(char *line, char *reminder);

#endif
