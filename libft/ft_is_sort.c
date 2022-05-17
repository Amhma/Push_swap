/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:22:01 by amahla            #+#    #+#             */
/*   Updated: 2022/05/17 17:47:51 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_is_sort_asc(t_list *lst)
{
	t_list	*elem;
	t_list	*next;

	if (ft_lstsize(lst) <= 1)
		return (1);
	elem = lst;
	next = elem->next;
	while (next)
	{
		if (elem->nb > next->nb)
			return (0);
		elem = next;
		next = elem->next;
	}
	return (1);
}

int	ft_is_sort_desc(t_list *lst)
{
	t_list	*elem;
	t_list	*next;

	if (ft_lstsize(lst) <= 1)
		return (1);
	elem = lst;
	next = elem->next;
	while (next)
	{
		if (elem->nb < next->nb)
			return (0);
		elem = next;
		next = elem->next;
	}
	return (1);
}

int	ft_is_sort(t_list *lst)
{
	if (ft_is_sort_asc(lst))
		return (1);
	if (ft_is_sort_desc(lst))
		return (-1);
	return (0);
}
