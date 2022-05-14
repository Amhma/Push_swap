/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:12:20 by amahla            #+#    #+#             */
/*   Updated: 2022/05/14 20:34:40 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				nb;
	int				value;
	char			stack;
	struct s_list	*next;
}				t_list;

//		pour les test => a enlever
void    print_lst(t_list *lst);
void	print_lst_value(t_list *lst);
void	ft_putnbr_fd(int n, int fd);

//		parse.c
void		parse(char **av, int ac, t_list **lst);

//		lst_patch.c
void		lst_patch(t_list **lst_a);

//		lst_split.c
void		lst_split(t_list **lst_a, t_list **lst_b);

//		movement.c
void		swap(t_list **lst, char c);
void		s_swap(t_list **lst_a, t_list **lst_b);
void		push(t_list **lst_src, t_list **lst_dst, char src);

//		movement2.c
void		rotate(t_list **lst, char c);
void		r_rotate(t_list **lst_a, t_list **lst_b);

//		movement3.c
void		ft_rrotate(t_list **lst);
void		rev_rotate(t_list **lst, char c);
void		r_rev_rotate(t_list **lst_a, t_list **lst_b);

//		libft
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_strlen(const char *s);
int			ft_isdigit(int c);
void		ft_putendl_fd(char *s, int fd);
long long	ft_atoi(const char *nptr);

//		libft_lst
t_list		*ft_lstnew(int nb, int value, char c);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstclear(t_list **lst);

//		lst_function
t_list		*ft_list_at(t_list *begin_list, unsigned int nbr);
t_list		*ft_list_find(t_list *lst, int (*cmp)());
int			ft_is_sort(t_list *lst);

//		utils_1.c
t_list		*min_value(t_list *lst);
int			max_list(t_list *lst);
int			min_list(t_list *lst);
int			max_tab(int *tab);
int			ft_abs(int nb);

//		utils_2.c
int			max(int a, int b);
t_list		*find_next_elem(t_list *lst, int nb_b);
t_list		*find_elem(t_list *lst, int nb);
void		set_nb_stroke(t_list *lst);

#endif
