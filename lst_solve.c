/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_solve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:05:54 by amahla            #+#    #+#             */
/*   Updated: 2022/05/17 17:04:22 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	mov_rev_rotate(t_list **lst_a, t_list **lst_b,
	t_list *elem_b, t_list *elem_a)
{
	while (elem_a->value < 0 || elem_b->value < 0)
	{
		if (elem_a->value < 0 && elem_b->value < 0)
			r_rev_rotate(lst_a, lst_b);
		else if (elem_a->value < 0)
			rev_rotate(lst_a, 'a');
		else if (elem_b->value < 0)
			rev_rotate(lst_b, 'b');
		if (elem_a->value < 0)
			elem_a->value += 1;
		if (elem_b->value < 0)
			elem_b->value += 1;
	}
}

void	mov_rotate(t_list **lst_a, t_list **lst_b,
	t_list *elem_b, t_list *elem_a)
{
	while (elem_a->value > 0 || elem_b->value > 0)
	{
		if (elem_a->value > 0 && elem_b->value > 0)
			r_rotate(lst_a, lst_b);
		else if (elem_a->value > 0)
			rotate(lst_a, 'a');
		else if (elem_b->value > 0)
			rotate(lst_b, 'b');
		if (elem_a->value > 0)
			elem_a->value -= 1;
		if (elem_b->value > 0)
			elem_b->value -= 1;
	}
}

void	solve(t_list **lst_a, t_list **lst_b, t_list *elem_b, t_list *elem_a)
{
	int	i;
	int	j;

	i = ft_index_lst_at(elem_a->nb, *lst_a);
	j = ft_index_lst_at(elem_b->nb, *lst_b);
	if (elem_a->value < 0
		&& elem_b->value + ft_abs(elem_a->value) > max(i, elem_b->value))
		elem_a->value = i;
	else if (elem_b->value < 0
		&& elem_a->value + ft_abs(elem_b->value) > max(j, elem_a->value))
		elem_b->value = j;
	mov_rev_rotate(lst_a, lst_b, elem_b, elem_a);
	mov_rotate(lst_a, lst_b, elem_b, elem_a);
	push(lst_b, lst_a, 'a');
}
