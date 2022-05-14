/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 18:53:15 by amahla            #+#    #+#             */
/*   Updated: 2022/05/14 20:40:51 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	calcultator_stroke(t_list *elem_a, t_list *elem_b, int size_a, int size_b)
{
	if ((elem_a->value >= 0 && elem_b->value >= 0)
		|| (elem_a->value < 0 && elem_b->value < 0))
		return (max(elem_a->nb, elem_b->nb));
	else if (elem_a->value >= 0 && elem_b->value < 0)
	{
		if (ft_abs(elem_b->value) + elem_a->value > max(elem_a->value, elem_b->value + size_b))
		{
			elem_b->value = elem_b->value + size_b;
			return (max(elem_a->value, elem_b->value));
		}
		else
			return (ft_abs(elem_b->value) + elem_a->value);
	}
	else
	{
		if (ft_abs(elem_a->value) + elem_b->value > max(elem_a->value + size_a, elem_b->value))
		{
			elem_a->value = elem_a->value + size_a;
			return (max(elem_a->value, elem_b->value));
		}
		else
			return (elem_b->value + ft_abs(elem_a->value));
	}
}	

int	*best_stroke(t_list *lst_a, t_list *lst_b)
{
	int	*stroke;
	int	i;

	i = 0;
	stroke = malloc(ft_lstsize(lst_b) * sizeof(int));
	if (!stroke)
	{
		ft_lstclear(&lst_a);
		ft_lstclear(&lst_b);
		exit(EXIT_FAILURE);
	}
	set_nb_stroke(lst_a);
	set_nb_stroke(lst_b);
	while (lst_b)
	{
		if (lst_b->nb > max_list(lst_a))
			stroke[i] = calcultator_stroke(find_elem(lst_a, max_list(lst_a)), lst_b, ft_lstsize(lst_a), ft_lstsize(lst_b));
		else if (lst_b->nb < min_list(lst_a))
			stroke[i] = calcultator_stroke(find_elem(lst_a, min_list(lst_a)), lst_b, ft_lstsize(lst_a), ft_lstsize(lst_b));
		else
			stroke[i] = calcultator_stroke(find_next_elem(lst_a, lst_b->nb), lst_b, ft_lstsize(lst_a), ft_lstsize(lst_b));
		lst_b = lst_b->next;
		i++;
	}
	return (stroke);
}
