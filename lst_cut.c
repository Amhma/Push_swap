/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_cut.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:56:08 by amahla            #+#    #+#             */
/*   Updated: 2022/05/12 19:54:44 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
#include<stdio.h>

int	max_lis(t_list *lst, int nb)
{
	int res_max;

	res_max = 0;
	while (lst)
	{
		if (lst->nb > nb)
		{
			nb = lst->nb;
			res_max++;
		}
		lst = lst->next;
	}
	return (res_max);
}

int	min_lis(t_list *lst, int nb)
{
	int res_min;

	res_min = 0;
	while (lst)
	{
		if (lst->nb < nb)
		{
			nb = lst->nb;
			res_min--;
		}
		lst = lst->next;
	}
	return (res_min);
}

t_list	*find_lis(t_list *lst)
{
	t_list	*elem;
	t_list	*lis_begin;
	int		res;

	elem = lst;
	while (elem)
	{
		elem->value = max(max_lis(elem, elem->nb), min_lis(elem, elem->nb));
		elem = elem->next;
	}
	elem = lst;
	lis_begin = lst;
	res = elem->value;
	while (elem)
	{
		if (ft_abs(elem->value) > ft_abs(res))
		{
			res = elem->value;
			lis_begin = elem;
		}
		elem = elem->next;
	}
	return (lis_begin);
}

void	lst_cut(t_list **lst_a/*, t_list **lst_b*/)
{
	t_list	*lis_begin;
	int		nb;

	if (ft_is_sort(*lst_a) != 0)
	{
		if (ft_is_sort(*lst_a) > 0)
			rev_rotate(lst_a);
		exit(EXIT_SUCCESS);
	}
	lis_begin = find_lis(*lst_a);
	if (lis_begin->value < 0)
		rev_rotate(lst_a);
	lis_begin = find_lis(*lst_a);
	nb = lis_begin->nb;
	lis_begin = lis_begin->next;
	while (lis_begin)
	{
		if (lis_begin->nb > nb)
			nb = lis_begin->nb;
		else
			lis_begin->list = 'b';
	lis_begin = lis_begin->next;
	}
}
