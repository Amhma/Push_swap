/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_patch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:56:08 by amahla            #+#    #+#             */
/*   Updated: 2022/05/17 14:28:54 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

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
				lis[i] = lis[j] + 1;
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
	int	*tab;

	tab = init_tab(lst);
	lis(*lst, tab);
	fill_lst(lst, tab);
	free(tab);
}

void	lst_patch(t_list **lst)
{
	int		i;
	t_list	*elem;

	i = 0;
	elem = min_value(*lst);
	if (ft_is_sort(*lst) > 0)
	{
		ft_lstclear(lst);
		exit(EXIT_SUCCESS);
	}
	else if (ft_is_sort_rotate(*lst) > 0 && ft_lstsize(*lst) < 20)
	{
		while (ft_list_at(*lst, i) != elem)
			i++;
		if (i < ft_lstsize(*lst) / 2)
			while (*lst != elem)
				rotate(lst, 'a');
		else
			while (*lst != elem)
				rev_rotate(lst, 'a');
	}
	max_lis(lst);
}
