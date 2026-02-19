/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danzamor <danzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:33:26 by danzamor          #+#    #+#             */
/*   Updated: 2025/12/04 19:00:31 by danzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "libft.h"

void	rra(t_stack *a)
{
	t_list	*cur;

	if (!a->first || a->first == a->last)
		return ;
	a->last->next = a->first;
	a->first = a->last;
	cur = a->first;
	while (cur->next != a->first)
		cur = cur->next;
	a->last = cur;
	a->last->next = 0;
}

void	rrr(t_stack *a, t_stack *b)
{
	t_list	*cur;

	if (!a->first || a->first == a->last)
		return ;
	a->last->next = a->first;
	a->first = a->last;
	cur = a->first;
	while (cur->next != a->first)
		cur = cur->next;
	a->last = cur;
	a->last->next = 0;
	if (!b->first || b->first == b->last)
		return ;
	b->last->next = b->first;
	b->first = b->last;
	cur = b->first;
	while (cur->next != b->first)
		cur = cur->next;
	b->last = cur;
	b->last->next = 0;
}

void	sa(t_stack *a)
{
	t_list	*first;
	t_list	*second;

	if (!a || !a->first || !a->first->next)
		return ;
	first = a->first;
	second = a->first->next;
	first->next = second->next;
	second->next = first;
	a->first = second;
}

void	ss(t_stack *a, t_stack *b)
{
	t_list	*first;
	t_list	*second;

	if (!a || !a->first || !a->first->next)
		return ;
	first = a->first;
	second = a->first->next;
	first->next = second->next;
	second->next = first;
	a->first = second;
	if (!b || !b->first || !b->first->next)
		return ;
	first = b->first;
	second = b->first->next;
	first->next = second->next;
	second->next = first;
	b->first = second;
}
