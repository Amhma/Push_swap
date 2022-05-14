/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:27:20 by amahla            #+#    #+#             */
/*   Updated: 2022/05/14 20:33:09 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

int	max_tab(int *tab)
{
	int	i;
	int	nb[2];

	i = 0;
	nb[0] = tab[0];
	while (tab[i])
	{
		if (tab[i] > nb[0])
		{
			nb[0] = tab[i];
			nb[1] = i;
		}
		i++;
	}
	return (nb[1]);
}

t_list	*min_value(t_list *lst)
{
	t_list	*elem;
	int		nb;

	nb = lst->value;
	elem = lst;
	while (lst)
	{
		if (ft_abs(lst->value) < nb)
		{
			nb = lst->value;
			elem = lst;
		}
		lst = lst->next;
	}
	return (elem);
}			

int	max_list(t_list *lst)
{
	t_list	*elem;
	int		nb;

	elem = lst;
	nb = elem->nb;
	while (elem)
	{
		if (elem->nb > nb)
			nb = elem->nb;
		elem = elem->next;
	}
	return (nb);
}

int	min_list(t_list *lst)
{
	t_list	*elem;
	int		nb;

	elem = lst;
	nb = elem->nb;
	while (elem)
	{
		if (elem->nb < nb)
			nb = elem->nb;
		elem = elem->next;
	}
	return (nb);
}
