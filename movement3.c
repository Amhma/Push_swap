/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:09:13 by amahla            #+#    #+#             */
/*   Updated: 2022/05/12 14:49:19 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_rrotate(t_list **lst)
{
	t_list	*next;
	t_list	*elem;
	t_list	*prev;

	elem = *lst;
	prev = NULL;
	while (elem)
	{
		next = elem->next;
		elem->next = prev;
		prev = elem;
		elem = next;
	}
	*lst = prev;
}

void	rev_rotate(t_list **lst)
{
	if (!lst)
		return ;
	else if (*lst && (*lst)->next && (*lst)->list == 'a')
	{
		ft_rrotate(lst);
		ft_putendl_fd("rra", 1);
	}
	else if (*lst && (*lst)->next && (*lst)->list == 'b')
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
