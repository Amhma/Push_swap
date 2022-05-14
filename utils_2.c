/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:27:20 by amahla            #+#    #+#             */
/*   Updated: 2022/05/14 20:41:10 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	set_nb_stroke(t_list *lst)
{
	int		i;
	int		size;
	t_list	*elem;

	size = ft_lstsize(lst);
	i = 0;
	while (i < size)
	{
		elem = ft_list_at(lst, i);
		if (i == size - 1)
			elem->value = 0;
		else if (i <= size / 2)
			elem->value = i + 1;
		else
			elem->value = i - size;
		i++;
	}
}

int	max(int a, int b)
{
	if (a < ft_abs(b))
		return (b);
	return (a);
}

t_list	*find_elem(t_list *lst, int nb)
{
	while (lst)
	{
		if (lst->nb == nb)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

t_list	*find_next_elem(t_list *lst, int nb_b)
{
	int		nb_a;
	t_list	*elem;

	nb_a = max_list(lst);
	while (lst)
	{
		if (lst->nb <= nb_a && lst->nb > nb_b)
		{
			elem = lst;
			nb_a = lst->nb;
		}
		lst = lst->next;
	}
	return (elem);
}
	

