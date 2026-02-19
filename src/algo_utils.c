/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danzamor <danzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:42:12 by danz              #+#    #+#             */
/*   Updated: 2025/12/04 18:35:06 by danzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

short	is_sorted(t_stack *a)
{
	int		*nb1;
	int		*nb2;
	t_list	*cur;

	cur = a->first;
	if (!cur)
		return (1);
	while (cur->next)
	{
		nb1 = cur->content;
		nb2 = cur->next->content;
		if (*nb1 > *nb2)
			return (0);
		cur = cur->next;
	}
	return (1);
}
