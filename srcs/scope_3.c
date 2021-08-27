/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scope_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 21:47:04 by bahn              #+#    #+#             */
/*   Updated: 2021/08/27 13:21:16 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	length_equal_3(t_frame *frame, t_stack *stack, int range)
{
	if (stack == frame->a)
	{
		while (check_asc(frame->a) == FALSE)
		{
			if (frame->a->element == max(frame->a, range))
				rotate_a(frame);
			else if (frame->a->next->element == max(frame->a, range))
				reverse_rotate_a(frame);
			else
				swap_a(frame);
		}
	}
	else if (stack == frame->b)
	{
		while (check_desc(frame->b) == FALSE)
		{
			if (frame->b->element == min(frame->b, length(frame->b)))
				rotate_b(frame);
			else if (frame->b->next->element == min(frame->b, length(frame->b)))
				reverse_rotate_b(frame);
			else
				swap_b(frame);
		}
	}
}

static	void	a_length_greater_3(t_frame *frame, int range)
{
	if (frame->a->element == max(frame->a, range))
	{
		swap_a(frame);
		rotate_a(frame);
		swap_a(frame);
		reverse_rotate_a(frame);
		if (frame->a->element > frame->a->next->element)
			swap_a(frame);
	}
	else if (frame->a->next->element == max(frame->a, range))
	{
		rotate_a(frame);
		swap_a(frame);
		reverse_rotate_a(frame);
		if (frame->a->element > frame->a->next->element)
			swap_a(frame);
	}
	else if (frame->a->next->next->element == max(frame->a, range))
	{
		if (frame->a->element > frame->a->next->element)
			swap_a(frame);
	}
}

static	void	b_length_greater_3(t_frame *frame, int range)
{
	if (frame->b->element == min(frame->b, range))
	{
		swap_b(frame);
		rotate_b(frame);
		swap_b(frame);
		reverse_rotate_b(frame);
		if (frame->b->element < frame->b->next->element)
			swap_b(frame);
	}
	else if (frame->b->next->element == min(frame->b, range))
	{
		rotate_b(frame);
		swap_b(frame);
		reverse_rotate_b(frame);
		if (frame->b->element < frame->b->next->element)
			swap_b(frame);
	}
	else if (frame->b->next->next->element == min(frame->b, range))
	{
		if (frame->b->element < frame->b->next->element)
			swap_b(frame);
	}
}

void	scope_3(t_frame *frame, t_stack *stack, int range)
{
	if (stack == frame->a)
	{
		if (length(stack) == 3)
			length_equal_3(frame, stack, range);
		else
			a_length_greater_3(frame, range);
	}
	else if (stack == frame->b)
	{
		if (length(stack) == 3)
			length_equal_3(frame, stack, range);
		else
			b_length_greater_3(frame, range);
		push_a(frame);
		push_a(frame);
		push_a(frame);
	}
}
