/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danzamor <danzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:47:38 by danz              #+#    #+#             */
/*   Updated: 2025/12/04 19:42:58 by danzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

void	algo_select(t_stack *a, t_stack *b, int argc)
{
	if (argc - 1 <= 5)
		algo_35(a, b);
	else
		algorithm(a, b, argc - 1);
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
	normalize(a);
	argc++;
	if (!is_sorted(a))
		algo_select(a, b, argc);
	ft_lstclear(&a->first, free);
	free(a);
	ft_lstclear(&b->first, free);
	free(b);
}
