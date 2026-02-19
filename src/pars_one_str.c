/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_one_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danzamor <danzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:54:17 by danzamor          #+#    #+#             */
/*   Updated: 2025/12/04 19:43:05 by danzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <limits.h>

void	free_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}

static short	is_repeated(t_list *head, int to_find)
{
	head = head->next;
	while (head)
	{
		if (*(int *)head->content == to_find)
			return (1);
		head = head->next;
	}
	return (0);
}

static short	check_argv(int argc, char ***argv)
{
	static t_list	*head;
	t_list			*cur;
	int				*content;

	while (argc--)
	{
		content = malloc(sizeof(int));
		if (!content)
			return (ft_lstclear(&head, free), 1);
		cur = ft_lstnew(content);
		if (!cur)
			return (ft_lstclear(&head, free), 1);
		ft_lstadd_front(&head, cur);
		*content = ft_atoi((*argv)[argc]);
		if (!is_ok((*argv)[argc]) || is_repeated(head, *content))
			return (ft_lstclear(&head, free), 1);
	}
	return (ft_lstclear(&head, free), 0);
}

static short	stack_first(t_stack *a, t_list	*cur)
{
	if (!a->last)
	{
		a->last = cur;
		a->first = cur;
		return (1);
	}
	return (0);
}

t_stack	*pars_one_str(int argc, char **argv)
{
	t_stack	*a;
	t_list	*cur;
	int		*content;

	if (check_argv(argc, &argv))
		return (NULL);
	a = malloc(sizeof(t_stack));
	if (!a)
		return (NULL);
	a->first = 0;
	a->last = 0;
	while (argc--)
	{
		content = malloc(sizeof(int));
		if (!content)
			return (ft_lstclear(&a->first, free), free(a), NULL);
		*content = ft_atoi(argv[argc]);
		cur = ft_lstnew(content);
		if (!cur)
			return (ft_lstclear(&a->first, free), free(a), NULL);
		if (!stack_first(a, cur))
			ft_lstadd_front(&a->first, cur);
	}
	free_argv(argv);
	return (a);
}
