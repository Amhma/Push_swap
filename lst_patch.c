/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_patch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:56:08 by amahla            #+#    #+#             */
/*   Updated: 2022/05/13 20:20:41 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
#include<stdio.h>

int	*init_tab(t_list **lst)
{
	int	*tab;
	int	size;

	size = ft_lstsize(*lst);
	tab = calloc((size + 1), sizeof(int));
	if (!tab)
	{
		ft_lstclear(lst);
		exit(EXIT_FAILURE);
	}
	return (tab);
}

void	lis(t_list *lst, int *lis)
{
	int		i;
	int		j;
	t_list	*elem_i;
	t_list	*elem_j;

	i = 1;
	elem_i = ft_list_at(lst, i);
	lis[0] = 1;
	while (elem_i)
	{
		lis[i] = 1;
		j = 0;
		while (j < i)
		{
			elem_j = ft_list_at(lst, j);
			if (elem_i->nb > elem_j->nb && lis[i] < lis[j] + 1)
				lis[i]= lis[j] + 1;
			j++;
		}
		elem_i = ft_list_at(lst, ++i);
	}
}

void	fill_lst(t_list **lst, int *tab)
{
	int		i;
	int		nb;
	int		index;
	t_list	*elem;

	i = ft_lstsize(*lst) - 1;
	while (i > max_tab(tab))
	{
		elem = ft_list_at(*lst, i--);
		elem->stack = 'b';
	}
	elem = ft_list_at(*lst, i);
	nb = elem->nb;
	index = tab[i];
	while (--i >= 0)
	{
		elem = ft_list_at(*lst, i);
		if (tab[i] == index - 1 && elem->nb < nb)
		{
			nb = elem->nb;
			index = tab[i];
		}
		else
			elem->stack = 'b';
	}
}

void	max_lis(t_list **lst)
{
	int	*tab_up;
	int	*tab_down;

	tab_up = init_tab(lst);
	tab_down = init_tab(lst);
	lis(*lst, tab_up);
	ft_rrotate(lst);
	lis(*lst, tab_down);
	if (tab_down[max_tab(tab_down)] >= tab_up[max_tab(tab_up)])
	{
		free(tab_up);
		fill_lst(lst, tab_down);
		ft_rrotate(lst);
		free(tab_down);
	}
	else
	{
		ft_rrotate(lst);
		free(tab_down);
		fill_lst(lst, tab_up);
		free(tab_up);
	}
}

void	lst_patch(t_list **lst)
{
	if (ft_is_sort(*lst) != 0)
	{
		if (ft_is_sort(*lst) > 0)
			rev_rotate(lst);
		exit(EXIT_SUCCESS);
	}
	max_lis(lst);
}
