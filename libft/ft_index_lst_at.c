/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_lst_at.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:50:31 by amahla            #+#    #+#             */
/*   Updated: 2022/05/17 17:47:35 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_index_lst_at(int data_ref, t_list *lst)
{
	int	i;

	i = 0;
	while (lst && lst->nb != data_ref)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
