/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:22:01 by amahla            #+#    #+#             */
/*   Updated: 2022/05/12 13:41:18 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_is_sort_asc_rotate(t_list *lst)
{
	t_list	*elem;
	t_list	*next;
	int		count;

	count = 0;
	if (ft_lstsize(lst) <= 1)
		return (1);
	elem = lst;
	next = elem->next;
	while (next)
	{
		if (elem->nb > next->nb)
			count++;
		elem = next;
		next = elem->next;
	}
	return (count);
}

int	ft_is_sort_desc_rotate(t_list *lst)
{
	t_list	*elem;
	t_list	*next;
	int		count;

	count = 0;
	if (ft_lstsize(lst) <= 1)
		return (1);
	elem = lst;
	next = elem->next;
	while (next)
	{
		if (elem->nb < next->nb)
			count++;
		elem = next;
		next = elem->next;
	}
	return (count);
}

int	ft_is_sort_rotate(t_list *lst)
{
	if (ft_is_sort_asc_rotate(lst) <= 1)
		return (1);
	if (ft_is_sort_desc_rotate(lst) <= 1)
		return (-1);
	return (0);
}
