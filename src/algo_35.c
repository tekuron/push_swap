/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_35.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danzamor <danzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:54:30 by danzamor          #+#    #+#             */
/*   Updated: 2025/12/04 18:24:39 by danzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <limits.h>

int	max_pos(t_stack *b)
{
	t_list	*cur;
	int		max;
	int		ret;
	int		i;

	cur = b->first;
	max = -1;
	i = 0;
	ret = 0;
	while (cur)
	{
		if (*(int *)cur->content > max)
		{
			ret = i;
			max = *(int *)cur->content;
		}
		i++;
		cur = cur->next;
	}
	return (ret);
}

static int	find_min_pos(t_stack *a)
{
	t_list	*cur;
	int		min_val;
	int		min_pos;
	int		i;

	if (!a->first)
		return (0);
	cur = a->first;
	min_val = *(int *)cur->content;
	min_pos = 0;
	i = 0;
	while (cur)
	{
		if (*(int *)cur->content < min_val)
		{
			min_val = *(int *)cur->content;
			min_pos = i;
		}
		cur = cur->next;
		i++;
	}
	return (min_pos);
}

static void	move_to_top_a(t_stack *a, int pos)
{
	int	size;

	size = ft_lstsize(a->first);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(a);
	}
	else
	{
		while (pos++ < size)
			rra(a);
	}
}

static void	sort_3(t_stack *a)
{
	int	top;
	int	mid;
	int	bot;

	top = *(int *)a->first->content;
	mid = *(int *)a->first->next->content;
	bot = *(int *)a->first->next->next->content;
	if (top > mid && mid < bot && top < bot)
		sa(a);
	else if (top > mid && mid < bot && top > bot)
		ra(a);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(a);
		ra(a);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(a);
	else if (top > mid && mid > bot)
	{
		sa(a);
		rra(a);
	}
}

void	algo_35(t_stack *a, t_stack *b)
{
	int	min_pos;

	if (ft_lstsize(a->first) == 2)
	{
		if (*(int *)a->first->content > *(int *)a->first->next->content)
			sa(a);
		return ;
	}
	while (ft_lstsize(a->first) > 3)
	{
		min_pos = find_min_pos(a);
		move_to_top_a(a, min_pos);
		pb(a, b);
	}
	sort_3(a);
	while (b->first)
		pa(a, b);
}
