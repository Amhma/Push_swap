/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:09:13 by amahla            #+#    #+#             */
/*   Updated: 2022/05/17 17:08:16 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_rotate(t_list **lst)
{
	t_list	*elem;
	t_list	*prev;

	elem = ft_lstlast(*lst);
	prev = *lst;
	*lst = (*lst)->next;
	elem->next = prev;
	prev->next = NULL;
}

void	rotate(t_list **lst, char c)
{
	if (!lst)
		return ;
	else if (*lst && (*lst)->next && c == 'a')
	{
		ft_rotate(lst);
		ft_putendl_fd("ra", 1);
	}
	else if (*lst && (*lst)->next && c == 'b')
	{
		ft_rotate(lst);
		ft_putendl_fd("rb", 1);
	}
}

void	r_rotate(t_list **lst_a, t_list **lst_b)
{
	if (!lst_a || !lst_b)
		return ;
	else if (*lst_a && (*lst_a)->next && *lst_b && (*lst_b)->next)
	{
		ft_rotate(lst_a);
		ft_rotate(lst_b);
		ft_putendl_fd("rr", 1);
	}
}
