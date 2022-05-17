/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:12:20 by amahla            #+#    #+#             */
/*   Updated: 2022/05/17 18:10:07 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "./libft/libft.h"

//		parse.c
void		parse(char **av, int ac, t_list **lst);

//		lst_patch.c
void		lst_patch(t_list **lst_a);

//		lst_split.c
void		lst_split(t_list **lst_a, t_list **lst_b);

//		lst_tiny_sort
void		tiny_sort(t_list **lst_a, t_list **lst_b);

//		lst_sort
void		sort_list(t_list **lst_a, t_list **lst_b);

//		lst_solve.c
void		solve(t_list **lst_a, t_list **lst_b,
				t_list *elem_b, t_list *elem_a);

//		move.c
void		swap(t_list **lst, char c);
void		s_swap(t_list **lst_a, t_list **lst_b);
void		push(t_list **lst_src, t_list **lst_dst, char src);

//		move2.c
void		rotate(t_list **lst, char c);
void		r_rotate(t_list **lst_a, t_list **lst_b);

//		move3.c
void		ft_rrotate(t_list **lst);
void		rev_rotate(t_list **lst, char c);
void		r_rev_rotate(t_list **lst_a, t_list **lst_b);

//		utils_1.c
t_list		*min_value(t_list *lst);
int			max_list(t_list *lst);
int			min_list(t_list *lst);
int			max_tab(int *tab);
int			ft_abs(int nb);

//		utils_2.c
int			tab_min_len(int *tab, int size);
int			max(int a, int b);
t_list		*find_next_elem(t_list *lst, int nb_b);
t_list		*find_elem(t_list *lst, int nb);
void		set_nb_stroke(t_list *lst);

#endif
