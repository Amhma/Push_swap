/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 12:29:49 by amahla            #+#    #+#             */
/*   Updated: 2022/05/12 13:24:08 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*elem;
	t_list	*next;

	elem = *lst;
	while (elem)
	{
		next = elem->next;
		free(elem);
		elem = next;
	}
	*lst = NULL;
}
