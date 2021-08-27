/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:29:09 by bahn              #+#    #+#             */
/*   Updated: 2021/08/27 15:39:32 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	array_converter(t_stack *stack, int *arr, int const *limit)
{
	t_stack	*ptr;
	int		cnt;

	ptr = stack;
	cnt = 0;
	while (cnt < *limit)
	{
		arr[cnt++] = ptr->element;
		ptr = ptr->next;
	}
}

static	void	array_ascending(int *arr, int const *limit)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < *limit - 1)
	{
		j = i + 1;
		while (j < *limit)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	select_big_pivot(t_stack *stack, int limit)
{
	int	*arr;
	int	pivot;

	arr = malloc(sizeof(int) * limit);
	if (arr == NULL)
		ft_puterr();
	array_converter(stack, arr, &limit);
	array_ascending(arr, &limit);
	pivot = arr[limit / 2];
	free(arr);
	return (pivot);
}

int	select_small_pivot(t_stack *stack, int limit)
{
	int	*arr;
	int	pivot;

	arr = malloc(sizeof(int) * limit);
	if (arr == NULL)
		ft_puterr();
	array_converter(stack, arr, &limit);
	array_ascending(arr, &limit);
	pivot = arr[limit / 4];
	free(arr);
	return (pivot);
}

void	select_pivot(t_frame *frame, t_stack *stack, int limit)
{
	frame->big_pivot = select_big_pivot(stack, limit);
	frame->small_pivot = select_small_pivot(stack, limit);
}
