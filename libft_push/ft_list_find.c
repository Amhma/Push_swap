/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:17:12 by amahla            #+#    #+#             */
/*   Updated: 2022/05/12 13:43:28 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_list	*ft_list_find(t_list *lst, int (*cmp)())
{
	while (lst)
	{
		if ((*cmp)(lst->nb, lst) == 0)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
