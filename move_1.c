/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:11:28 by amahla            #+#    #+#             */
/*   Updated: 2022/05/16 19:30:47 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_swap(t_list **lst)
{
	t_list	*elem;

	if (*lst && (*lst)->next)
	{
		elem = (*lst)->next;
		(*lst)->next = elem->next;
		elem->next = *lst;
		*lst = elem;
	}
}

void	swap(t_list **lst, char c)
{
	if (!lst)
		return ;
	else if (*lst && (*lst)->next && c == 'a')
	{
		ft_swap(lst);
		ft_putendl_fd("sa", 1);
	}
	else if (*lst && (*lst)->next && c == 'b')
	{
		ft_swap(lst);
		ft_putendl_fd("sb", 1);
	}
}

void	s_swap(t_list **lst_a, t_list **lst_b)
{
	if (!lst_a || !lst_b)
		return ;
	else if (*lst_a && (*lst_a)->next && *lst_b && (*lst_b)->next)
	{
		ft_swap(lst_a);
		ft_swap(lst_b);
		ft_putendl_fd("ss", 1);
	}
}

void	push(t_list **lst_src, t_list **lst_dst, char src)
{
	t_list	*elem;

	if (!*lst_src)
		return ;
	elem = *lst_src;
	*lst_src = (*lst_src)->next;
	if (src == 'b')
		ft_putendl_fd("pb", 1);
	else
		ft_putendl_fd("pa", 1);
	if (src == 'b')
		elem->stack = 'b';
	else
		elem->stack = 'a';
	elem->next = NULL;
	ft_lstadd_front(lst_dst, elem);
}
