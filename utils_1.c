/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:27:20 by amahla            #+#    #+#             */
/*   Updated: 2022/05/13 20:01:08 by amahla           ###   ########.fr       */
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

int	max(int a, int b)
{
	if (a < ft_abs(b))
		return (b);
	return (a);
}
