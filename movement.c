/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:11:28 by amahla            #+#    #+#             */
/*   Updated: 2022/05/14 17:04:52 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_swap(t_list **lst)
{
	t_list	*next;
	t_list	*prev;
	t_list	*elem;

	elem = *lst;
	next = elem->next;
	prev = NULL;
	while (next->next)
	{
		prev = elem;
		elem = next;
		next = next->next;
	}
	elem->next = next->next;
	next->next = elem;
	if (!prev)
		*lst = next;
	else
		prev->next = next;
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
	t_list	*prev;

	if (!*lst_src)
		return ;
	elem = *lst_src;
	prev = NULL;
	if (src == 'b')
		ft_putendl_fd("pb", 1);
	else
		ft_putendl_fd("pa", 1);
	while (elem->next)
	{
		prev = elem;
		elem = elem->next;
	}
	if (prev)
		prev->next = NULL;
	else
		*lst_src = NULL;
	elem->stack = 'b';
	ft_lstadd_back(lst_dst, elem);
}
