/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 18:53:15 by amahla            #+#    #+#             */
/*   Updated: 2022/05/16 15:38:55 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
#include<stdio.h>

int	calcultator_stroke(t_list *elem_a, t_list *elem_b, t_list *lst_a, t_list *lst_b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ft_list_at(lst_a, i) != elem_a)
		i++;
	while (ft_list_at(lst_b, j) != elem_b)
		j++;
//	printf("elem_a %d -> value %d\n", elem_a->nb, elem_a->value);
//	printf("elem_b %d -> value %d\n\n", elem_b->nb, elem_b->value);
//	printf("sort asc %d\n", ft_is_sort_rotate(lst_a));
	if (elem_a->value >= 0 && elem_b->value >= 0)
		return (max(elem_a->value, elem_b->value));

	else if (elem_a->value < 0 && elem_b->value < 0)
		return (max(ft_abs(elem_a->value), ft_abs(elem_b->value)));

	else if (elem_a->value < 0
		&& elem_b->value + ft_abs(elem_a->value) > max(i + 1, elem_b->value))
		return (max(i + 1, elem_b->value));

	else if (elem_b->value < 0
		&& elem_a->value + ft_abs(elem_b->value) > max(j + 1, elem_a->value))
		return (max(j + 1, elem_a->value));

	else
		return (ft_abs(elem_b->value) + ft_abs(elem_a->value));
}	

int	*best_stroke(t_list *lst_a, t_list *lst_b)
{
	int		*stroke;
	t_list	*elem;
	int		i;

	i = 0;
	stroke = malloc(ft_lstsize(lst_b) * sizeof(int));
	if (!stroke)
	{
		ft_lstclear(&lst_a);
		ft_lstclear(&lst_b);
		exit(EXIT_FAILURE);
	}
//	if (ft_is_sort_rotate(lst_a) == 1)
//		set_nb_stroke_asc(lst_a);
//	else
	set_nb_stroke(lst_a);
//	for(t_list *elem = lst_a; elem; elem = elem->next)
//		printf("%d\n", elem->value);
	set_nb_stroke(lst_b);
//	for(t_list *elem1 = lst_b; elem1; elem1 = elem1->next)
//		printf("%d\n", elem1->value);
	elem = lst_b;
	while (elem)
	{
		if (elem->nb > max_list(lst_a))
			stroke[i] = calcultator_stroke(find_elem(lst_a, max_list(lst_a)), elem, lst_a, lst_b);
		else
			stroke[i] = calcultator_stroke(find_next_elem(lst_a, elem->nb), elem, lst_a, lst_b);
//		printf("/%d\n", stroke[i]);
		elem = elem->next;
		i++;
	}
	return (stroke);
}

void	solve(t_list **lst_a, t_list **lst_b, t_list *elem_b, t_list *elem_a)
{
//	printf("best_move b %d -> value %d\n", elem_b->nb, elem_b->value);
//	printf("best_move a %d -> value %d\n", elem_a->nb, elem_a->value);

	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ft_list_at(*lst_a, i) != elem_a)
		i++;
	while (ft_list_at(*lst_b, j) != elem_b)
		j++;

	if (elem_a->value < 0
		&& elem_b->value + ft_abs(elem_a->value) > max(i + 1, elem_b->value))
		elem_a->value = i + 1;
	else if (elem_b->value < 0
		&& elem_a->value + ft_abs(elem_b->value) > max(j + 1, elem_a->value))
		elem_b->value = j + 1;

	while (elem_a->value < 0 || elem_b->value < 0)
	{
		if (elem_a->value < 0 && elem_b->value < 0)
			r_rev_rotate(lst_a, lst_b);
		else if (elem_a->value < 0)
			rev_rotate(lst_a, 'a');
		else if (elem_b->value < 0)
			rev_rotate(lst_b, 'b');
		if (elem_a->value < 0)
			elem_a->value += 1;
		if (elem_b->value < 0)
			elem_b->value += 1;
	}
	
	while (elem_a->value > 0 || elem_b->value > 0)
	{
//		printf("best_move b %d -> value %d\n", elem_b->nb, elem_b->value);
//		printf("best_move a %d -> value %d\n", elem_a->nb, elem_a->value);
//		print_lst(*lst_a);
//		print_lst(*lst_b);
		if (elem_a->value > 0 && elem_b->value > 0)
			r_rotate(lst_a, lst_b);
		else if (elem_a->value > 0)
			rotate(lst_a, 'a');
		else if (elem_b->value > 0)
			rotate(lst_b, 'b');
		if (elem_a->value > 0)
			elem_a->value -= 1;
		if (elem_b->value > 0)
			elem_b->value -= 1;
	}
}

void	sort_list(t_list **lst_a, t_list **lst_b)
{
	int		*stroke;
	int		i;
	t_list	*best_move;

	i = 0;
	stroke = NULL;
	while (*lst_b)
	{
		stroke = best_stroke(*lst_a, *lst_b);
		best_move = ft_list_at(*lst_b, tab_min_len(stroke, ft_lstsize(*lst_b)));
//		printf("best_move %d -> value %d\n", best_move->nb, best_move->value);
//		t_list *elem;
//		elem = find_next_elem(*lst_a, best_move->nb);
//		printf("elem->next %d -> value %d\n", elem->nb, elem->value);
		if (best_move->nb > max_list(*lst_a))
			solve(lst_a, lst_b, best_move, find_elem(*lst_a, min_list(*lst_a)));
		else
			solve(lst_a, lst_b, best_move, find_next_elem(*lst_a, best_move->nb));
		push(lst_b, lst_a, 'b');
		if (stroke)
			free(stroke);
//		print_lst(*lst_a);
//		print_lst(*lst_b);
	}
//	if (ft_is_sort_rotate(*lst_a) == 1)
//		set_nb_stroke_asc(*lst_a);
//	else
//		set_nb_stroke(*lst_a);
	i = 0;
	best_move = find_elem(*lst_a, min_list(*lst_a));
	while (ft_list_at(*lst_a, i) != best_move)
		i++;
	if (i < ft_lstsize(*lst_a) / 2)
		best_move->value = i;
	else
		best_move->value = i - ft_lstsize(*lst_a);		
	while ((best_move->value)++ < 0)
		rev_rotate(lst_a, 'a');
	while ((best_move->value)--)
		rotate(lst_a, 'a');
}
