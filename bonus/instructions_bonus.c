/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danzamor <danzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:50:28 by danz              #+#    #+#             */
/*   Updated: 2025/12/04 19:47:53 by danzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "libft.h"

void	pa(t_stack *a, t_stack *b)
{
	t_list	*tmp;

	if (!b->first)
		return ;
	tmp = b->first->next;
	ft_lstadd_front(&a->first, b->first);
	b->first = tmp;
	if (!a->last)
		a->last = a->first;
}

void	pb(t_stack *a, t_stack *b)
{
	t_list	*tmp;

	if (!a->first)
		return ;
	tmp = a->first->next;
	ft_lstadd_front(&b->first, a->first);
	a->first = tmp;
	if (!b->last)
		b->last = b->first;
}

void	ra(t_stack *a)
{
	if (!a->first || a->first == a->last)
		return ;
	a->last->next = a->first;
	a->last = a->last->next;
	a->first = a->first->next;
	a->last->next = 0;
}

void	rr(t_stack *a, t_stack *b)
{
	if (!a->first || a->first == a->last)
		return (ra(b));
	a->last->next = a->first;
	a->last = a->last->next;
	a->first = a->first->next;
	a->last->next = 0;
	if (!b->first || b->first == b->last)
		return ;
	b->last->next = b->first;
	b->last = b->last->next;
	b->first = b->first->next;
	b->last->next = 0;
}
