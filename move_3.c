/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:09:13 by amahla            #+#    #+#             */
/*   Updated: 2022/05/17 17:36:44 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_rrotate(t_list **lst)
{
	t_list	*elem;
	t_list	*prev;

	elem = ft_lstlast(*lst);
	prev = ft_list_at(*lst, ft_lstsize(*lst) - 2);
	elem->next = *lst;
	prev->next = NULL;
	*lst = elem;
}

void	rev_rotate(t_list **lst, char c)
{
	if (!lst)
		return ;
	else if (*lst && (*lst)->next && c == 'a')
	{
		ft_rrotate(lst);
		ft_putendl_fd("rra", 1);
	}
	else if (*lst && (*lst)->next && c == 'b')
	{
		ft_rrotate(lst);
		ft_putendl_fd("rrb", 1);
	}
}

void	r_rev_rotate(t_list **lst_a, t_list **lst_b)
{
	if (!lst_a || !lst_b)
		return ;
	else if (*lst_a && (*lst_a)->next && *lst_b && (*lst_b)->next)
	{
		ft_rrotate(lst_a);
		ft_rrotate(lst_b);
		ft_putendl_fd("rrr", 1);
	}
}
