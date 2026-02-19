/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danz <danz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:56:50 by danz              #+#    #+#             */
/*   Updated: 2025/12/03 14:30:03 by danz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <limits.h>

static void	push_back(t_stack *a, t_stack *b)
{
	int	max_p;
	int	current_size;

	while (b->first)
	{
		current_size = ft_lstsize(b->first);
		max_p = max_pos(b);
		if (max_p <= current_size / 2)
		{
			while (max_p-- > 0)
				rb(b);
		}
		else
		{
			max_p = current_size - max_p;
			while (max_p-- > 0)
				rrb(b);
		}
		pa(a, b);
	}
}

void	algorithm(t_stack *a, t_stack *b, int size)
{
	int	pmax;
	int	window;

	window = (size / 20) + 7;
	pmax = 0;
	while (a->first)
	{
		if (*(int *)a->first->content <= pmax + window)
		{
			pb(a, b);
			if (*(int *)b->first->content <= pmax)
				rb(b);
			pmax++;
		}
		else
			ra(a);
	}
	push_back(a, b);
}
