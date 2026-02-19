/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danz <danz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:33:26 by danzamor          #+#    #+#             */
/*   Updated: 2025/12/03 14:32:12 by danz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
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
	(void)write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	t_list	*cur;

	if (!b->first || b->first == b->last)
		return ;
	b->last->next = b->first;
	b->first = b->last;
	cur = b->first;
	while (cur->next != b->first)
		cur = cur->next;
	b->last = cur;
	b->last->next = 0;
	(void)write(1, "rrb\n", 4);
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
	(void)write(1, "rrr\n", 4);
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
	(void)write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	t_list	*first;
	t_list	*second;

	if (!b || !b->first || !b->first->next)
		return ;
	first = b->first;
	second = b->first->next;
	first->next = second->next;
	second->next = first;
	b->first = second;
	(void)write(1, "sb\n", 3);
}
