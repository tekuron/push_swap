/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danzamor <danzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 18:32:25 by danzamor          #+#    #+#             */
/*   Updated: 2025/12/04 19:43:18 by danzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "libft.h"
#include "get_next_line.h"

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

static short	r_inst(t_stack *a, t_stack *b, char *inst)
{
	if (!ft_strncmp("ra\n", inst, 3))
		ra(a);
	else if (!ft_strncmp("rb\n", inst, 3))
		ra(b);
	else if (!ft_strncmp("rr\n", inst, 3))
		rr(a, b);
	else if (!ft_strncmp("rra\n", inst, 4))
		rra(a);
	else if (!ft_strncmp("rrb\n", inst, 4))
		rra(b);
	else if (!ft_strncmp("rrr\n", inst, 4))
		rrr(a, b);
	else if (!ft_strncmp("sa\n", inst, 3))
		sa(a);
	else if (!ft_strncmp("sb\n", inst, 3))
		sa(b);
	else if (!ft_strncmp("ss\n", inst, 3))
		ss(a, b);
	else if (!ft_strncmp("pa\n", inst, 3))
		pa(a, b);
	else if (!ft_strncmp("pb\n", inst, 3))
		pb(a, b);
	else
		return (1);
	return (0);
}

static short	apply_inst(t_stack *a, t_stack *b)
{
	char	*inst;

	inst = get_next_line(0);
	while (inst)
	{
		if (r_inst(a, b, inst))
		{
			if (r_inst(a, b, inst))
			{
				if (inst[0] == '\n')
					return (free(inst), 0);
				else
					return ((void)write(2, "Error\n", 7), free(inst), 1);
			}
		}
		free(inst);
		if (is_sorted(a) && !b->first)
			return (0);
		inst = get_next_line(0);
	}
	return (0);
}

short	split_argv(int *argc, char ***argv)
{
	if (*argc == 2)
	{
		*argc = 0;
		*argv = ft_split((*argv)[1], ' ');
		while ((*argv)[*argc])
			(*argc)++;
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (split_argv(&argc, &argv))
		a = pars_one_str(argc, argv);
	else
		a = pars(argc, argv);
	if (!a)
		return (write(2, "Error\n", 6));
	b = malloc(sizeof(t_stack));
	if (!b)
		return (ft_lstclear(&a->first, free), free(a), write(2, "Error\n", 6));
	b->first = 0;
	b->last = 0;
	if (!apply_inst(a, b))
	{
		if (is_sorted(a))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	ft_lstclear(&a->first, free);
	free(a);
	ft_lstclear(&b->first, free);
	free(b);
}
