/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:26:25 by amahla            #+#    #+#             */
/*   Updated: 2022/05/13 20:43:17 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	search_med(t_list *lst)
{
	t_list	*elem;
	t_list	*next;

	elem = lst;
	while (elem)
	{
		elem->value = 0;
		elem = elem->next;
	}
	elem = lst;
	while (lst)
	{
		next = lst->next;
		while (next);
		{
			if (elem->nb < next->nb)
				(elem->value)++;
			else
				(elem->value)--;
			next= next->next;
		}
		elem = elem->next;
	}
}

void	set_nb_stroke(t_list **lst_a)
{
	

void	lst_split(t_list **lst_a, t_list **lst_b)
{
	int	med;
	
