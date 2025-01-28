/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:42:00 by ariyad            #+#    #+#             */
/*   Updated: 2025/01/28 19:07:16 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	**ft_split(char const *s, char c);
void	free_table(char **split);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_plus(char *s1, char *s2);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t len);
int		ft_isspace(char c);

//linked list

typedef struct s_list
{
	int				num;
	int				sorted_index;
	struct s_list	*next;
	struct s_list	*back;
}	t_list;

t_list	*ft_lstnew(int number);
int		ft_atoi_plus(char *str, t_list **stack_a, char **nbrs);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstfirst(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst);
int		check_dup(t_list *lst);
void	ft_lstiter(t_list *lst, void (*f)(int));
t_list	*get_nbr_lst(int ac, char **av);
int		is_sorted(t_list *lst);
void	update_index(t_list *lst);
t_list	*smallest_nbr(t_list *lst);
t_list	*biggest_nbr(t_list *lst);
int		index_in_lst(t_list *lst, t_list *node);
int		dominant_side(t_list *lst);

// manipulation

void	swap(t_list	**lst);
void	push(t_list **lst_to, t_list **lst_from);
void	rotate(t_list **lst);
void	rev_rotate(t_list **lst);

// operations

void	sa(t_list	**stack_a);
void	sb(t_list	**stack_b);
void	ss(t_list	**stack_a, t_list	**stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_b, t_list **stack_a);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list	**stack_a);
void	rrb(t_list	**stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

// sorting

void	nano_sort(t_list **stack_a);
void	microsort(t_list **stack_a);
void	macrosort(t_list **stack_a, t_list **stack_b);
void	millisort(t_list **stack_a, t_list **stack_b);
void	hourglass(t_list **stack_a, t_list **stack_b, int chunk, int lstsize);
void	megasort(t_list **stack_a, t_list **stack_b);

#endif