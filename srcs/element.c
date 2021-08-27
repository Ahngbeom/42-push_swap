/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:42:19 by bahn              #+#    #+#             */
/*   Updated: 2021/08/27 15:51:36 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*last_element(t_stack *stack)
{
	t_stack	*ptr;

	ptr = stack;
	while (ptr->next != NULL)
		ptr = ptr->next;
	return (ptr);
}

t_stack	*mid_element(t_stack *stack)
{
	t_stack	*ptr;
	int		count;

	count = 0;
	ptr = stack;
	while (count++ < length(stack) / 2)
		ptr = ptr->next;
	return (ptr);
}

int	min(t_stack *stack, int range)
{
	int		min;
	t_stack	*ptr;

	min = stack->element;
	ptr = stack->next;
	while (ptr != NULL && --range)
	{
		if (min > ptr->element)
			min = ptr->element;
		ptr = ptr->next;
	}
	return (min);
}

int	max(t_stack *stack, int range)
{
	int		max;
	t_stack	*ptr;

	max = stack->element;
	ptr = stack->next;
	while (ptr != NULL && --range)
	{
		if (max < ptr->element)
			max = ptr->element;
		ptr = ptr->next;
	}
	return (max);
}
