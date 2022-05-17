/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 18:53:15 by amahla            #+#    #+#             */
/*   Updated: 2022/05/17 18:25:21 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	*init_stroke_array(t_list *lst_a, t_list *lst_b)
{
	int	*stroke;

	stroke = malloc(ft_lstsize(lst_b) * sizeof(int));
	if (!stroke)
	{
		ft_lstclear(&lst_a);
		ft_lstclear(&lst_b);
		exit(EXIT_FAILURE);
	}
	return (stroke);
}

int	calcultator_stroke(t_list *elem_a, t_list *elem_b,
	t_list *lst_a, t_list *lst_b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ft_list_at(lst_a, i) != elem_a)
		i++;
	while (ft_list_at(lst_b, j) != elem_b)
		j++;
	if ((elem_a->value >= 0 && elem_b->value >= 0)
		|| (elem_a->value < 0 && elem_b->value < 0))
		return (max(ft_abs(elem_a->value), ft_abs(elem_b->value)));
	else if (elem_a->value < 0
		&& elem_b->value + ft_abs(elem_a->value) > max(i, elem_b->value))
		return (max(i, elem_b->value));
	else if (elem_b->value < 0
		&& elem_a->value + ft_abs(elem_b->value) > max(j, elem_a->value))
		return (max(j, elem_a->value));
	else
		return (ft_abs(elem_b->value) + ft_abs(elem_a->value));
}	

int	*best_stroke(t_list *lst_a, t_list *lst_b)
{
	int		*stroke;
	t_list	*elem;
	int		i;

	i = 0;
	stroke = init_stroke_array(lst_a, lst_b);
	set_nb_stroke(lst_a);
	set_nb_stroke(lst_b);
	elem = lst_b;
	while (elem)
	{
		if (elem->nb > max_list(lst_a))
			stroke[i] = calcultator_stroke(find_elem(lst_a, max_list(lst_a)),
					elem, lst_a, lst_b);
		else
			stroke[i] = calcultator_stroke(find_next_elem(lst_a, elem->nb),
					elem, lst_a, lst_b);
		elem = elem->next;
		i++;
	}
	return (stroke);
}

void	final_sort(t_list **lst_a)
{
	int		i;
	t_list	*last_move;

	i = ft_index_lst_at(min_list(*lst_a), *lst_a);
	last_move = find_elem(*lst_a, i);
	if (i < ft_lstsize(*lst_a) / 2)
		last_move->value = i;
	else
		last_move->value = i - ft_lstsize(*lst_a);
	if (last_move->value < 0)
		while ((last_move->value)++ < 0)
			rev_rotate(lst_a, 'a');
	else
		while ((last_move->value)-- > 0)
			rotate(lst_a, 'a');
}

void	sort_list(t_list **lst_a, t_list **lst_b)
{
	int		*stroke;
	t_list	*best_move;

	stroke = NULL;
	while (*lst_b)
	{
		stroke = best_stroke(*lst_a, *lst_b);
		best_move = ft_list_at(*lst_b, tab_min_len(stroke, ft_lstsize(*lst_b)));
		if (best_move->nb > max_list(*lst_a))
			solve(lst_a, lst_b, best_move, find_elem(*lst_a, min_list(*lst_a)));
		else
			solve(lst_a, lst_b, best_move,
				find_next_elem(*lst_a, best_move->nb));
		if (stroke)
			free(stroke);
	}
	final_sort(lst_a);
}
