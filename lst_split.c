/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:26:25 by amahla            #+#    #+#             */
/*   Updated: 2022/05/17 14:44:03 by amahla           ###   ########.fr       */
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
	while (elem)
	{
		next = lst;
		while (next)
		{
			if (elem->nb < next->nb)
				(elem->value)++;
			else if (elem->nb > next->nb)
				(elem->value)--;
			next = next->next;
		}
		elem = elem->next;
	}
	elem = min_value(lst);
	return (elem->value);
}

int	split_more_med(t_list *lst, int *count)
{
	t_list	*elem;
	int		value;

	elem = lst;
	while (elem && elem->stack == 'a')
		elem = elem->next;
	if (!elem)
		return (0);
	(*count)++;
	value = elem->value;
	while (elem)
	{
		if (ft_abs(elem->value) < value && elem->stack == 'b')
		{
			value = elem->value;
			(*count)++;
		}
		elem = elem->next;
	}
	return (value);
}

int	split_less_med(t_list *lst, int med, int *count)
{
	t_list	*elem;
	int		value;

	elem = lst;
	while ((elem && elem->stack == 'a')
		|| (elem && elem->stack == 'b' && elem->nb > med))
		elem = elem->next;
	if (!elem)
		return (split_more_med(lst, count));
	(*count)++;
	value = elem->value;
	while (elem)
	{
		if (ft_abs(elem->value) < value && elem->stack == 'b'
			&& elem->nb <= med)
		{
			value = elem->value;
			(*count)++;
		}
		elem = elem->next;
	}
	return (value);
}

int	push_it(t_list **lst_a, t_list **lst_b, int med, int *count)
{
	push(lst_a, lst_b, 'b');
	set_nb_stroke(*lst_a);
	*count = 0;
	return (split_less_med(*lst_a, med, count));
}

void	lst_split(t_list **lst_a, t_list **lst_b)
{
	int		med;
	int		value;
	int		count;

	count = 0;
	med = search_med(*lst_a);
	set_nb_stroke(*lst_a);
	value = split_less_med(*lst_a, med, &count);
	while (count)
	{
		if ((*lst_a)->next && (*lst_a)->next->stack == 'b'
			&& (*lst_a)->stack == 'a')
			swap(lst_a, 'a');
		else if (value != 0)
		{
			while (value < 0)
			{
				rev_rotate(lst_a, 'a');
				value = value + 1;
			}
			while (value--)
				rotate(lst_a, 'a');
		}
		value = push_it(lst_a, lst_b, med, &count);
	}
}
