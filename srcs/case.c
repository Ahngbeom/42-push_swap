/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bbu0704@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:02:38 by bahn              #+#    #+#             */
/*   Updated: 2021/07/26 20:27:24 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_3(t_frame *frame)
{
	if (frame->a != NULL && length(frame->a) == 3)
	{
		while (check_asc(frame->a) == FALSE)
		{
			if (frame->a->element == max(frame->a))
				rotate_a(frame);
			else if (last_element(frame->a)->element == min(frame->a))
				reverse_rotate_a(frame);
			else
				swap_a(frame);
		}
	}
	if (frame->b != NULL && length(frame->b) == 3)
	{
		while (check_desc(frame->b) == FALSE)
		{
			if (frame->b->element == min(frame->b))
				rotate_b(frame);
			else if (last_element(frame->b)->element == max(frame->b))
				reverse_rotate_b(frame);
			else
				swap_b(frame);
		}
	}
}

void	case_5(t_frame *frame)
{
	frame->pivot_a = median(frame->a, length(frame->a));
	if (check_asc(frame->a) == FALSE)
	{
		while (length(frame->a) != 3 && min(frame->a) != frame->pivot_a)
		{
			if (frame->a->element < frame->pivot_a)
				push_b(frame);
			else if (last_element(frame->a)->element < frame->pivot_a)
				reverse_rotate_a(frame);
			else 
				rotate_a(frame);
		}
		case_3(frame);
		while (length(frame->a) != 5)
		{
			if (check_desc(frame->b) == FALSE)
				swap_b(frame);
			else
				push_a(frame);
		}
		if (swap_check(frame, frame->a))
			swap_a(frame);
	}
}

void	div_by_pivot_to_a(t_frame *frame)
{
	frame->pivot_a = median(frame->a, length(frame->a));
	while (check_asc(frame->a) == FALSE && \
			min(frame->a) != frame->pivot_a)
	{
		frame->pivot_b = median(frame->b, length(frame->b));
		if (frame->pivot_a > frame->a->element)
		{
			push_b(frame);
			if (rotate_check(frame, frame->b) == TRUE)
				rotate_b(frame);
		}
		else
			rotate_a(frame);
	}
	if (check_asc(frame->a) == FALSE)
	{
		if (length(frame->a) == 2)
			swap_a(frame);
		else if (length(frame->a) == 3)
			case_3(frame);
		else
			div_by_pivot_to_a(frame);
	}
	else
		div_by_pivot_to_b(frame);
	
}

void	div_by_pivot_to_b(t_frame *frame)
{
	while (frame->b != NULL)
	{
		frame->pivot_b = median(frame->b, length(frame->b));
		if (check_desc(frame->b) == TRUE)
		{
			push_a(frame);
			if (frame->a->element > frame->a->next->element)
				swap_a(frame);
		}
		else if (frame->b->element > frame->pivot_b)
		{
			push_a(frame);
			if (frame->a->element > frame->a->next->element)
				swap_a(frame);
		}
		else
			rotate_b(frame);
	}
}