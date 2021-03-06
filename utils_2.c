/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:27:20 by amahla            #+#    #+#             */
/*   Updated: 2022/05/17 17:13:46 by amahla           ###   ########.fr       */
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
		if (i <= size / 2)
			elem->value = i;
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
	elem = find_elem(lst, nb_a);
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

int	tab_min_len(int *tab, int size)
{
	int	i;
	int	nb[2];

	i = 0;
	nb[0] = tab[i];
	nb[1] = i;
	while (i < size)
	{
		if (tab[i] < nb[0])
		{
			nb[0] = tab[i];
			nb[1] = i;
		}
		i++;
	}
	return (nb[1]);
}
