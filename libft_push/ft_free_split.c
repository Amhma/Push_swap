/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:03:18 by amahla            #+#    #+#             */
/*   Updated: 2022/05/16 16:18:59 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	len_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

void	ft_free_split(char **split)
{
	int	i;
	int	y;

	y = len_split(split);
	i = 0;
	if (!split)
		return ;
	while (i < y)
		free(split[i++]);
	free(split);
}
