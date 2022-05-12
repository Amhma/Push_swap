/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:12:20 by amahla            #+#    #+#             */
/*   Updated: 2022/05/12 19:54:54 by amahla           ###   ########.fr       */
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
	char			list;
	struct s_list	*next;
}				t_list;

//		pour les test => a enlever
void	ft_putnbr_fd(int n, int fd);

//		parse.c
void		parse(char **av, int ac, t_list **lst);

//		lst_cut
void		lst_cut(t_list **lst_a/*, t_list **lst_b*/);

//		movement.c
void		swap(t_list **lst);
void		s_swap(t_list **lst_a, t_list **lst_b);
void		push(t_list **lst_src, t_list **lst_dst);

//		movement2.c
void		rotate(t_list **lst);
void		r_rotate(t_list **lst_a, t_list **lst_b);

//		movement3.c
void		rev_rotate(t_list **lst);
void		r_rev_rotate(t_list **lst_a, t_list **lst_b);

//		libft
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
int			ft_abs(int nb);
int			max(int a, int b);

#endif
