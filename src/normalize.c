/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danzamor <danzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:27:48 by danz              #+#    #+#             */
/*   Updated: 2025/12/04 17:54:26 by danzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

static void	normalize_mod(t_stack *a, int size, int *arr)
{
	t_list	*current;
	int		i;

	current = a->first;
	while (current)
	{
		i = 0;
		while (i < size)
		{
			if (*(int *)current->content == arr[i])
			{
				*(int *)current->content = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
}

void	normalize(t_stack *a)
{
	int		size;
	int		*arr;
	t_list	*current;
	int		i;

	size = ft_lstsize(a->first);
	if (size == 0)
		return ;
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return ;
	current = a->first;
	i = 0;
	while (current)
	{
		arr[i++] = *(int *)current->content;
		current = current->next;
	}
	sort_array(arr, size);
	normalize_mod(a, size, arr);
	free(arr);
}
