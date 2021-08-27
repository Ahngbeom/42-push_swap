/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scope_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 21:47:04 by bahn              #+#    #+#             */
/*   Updated: 2021/08/27 13:17:15 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	scope_2(t_frame *frame, t_stack *stack)
{
	if (stack == frame->a)
	{
		if (stack->element > stack->next->element)
			swap_a(frame);
	}
	else if (stack == frame->b)
	{
		if (stack->element < stack->next->element)
			swap_b(frame);
		push_a(frame);
		push_a(frame);
	}
}
