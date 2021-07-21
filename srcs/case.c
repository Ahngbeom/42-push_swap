/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bbu0704@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:02:38 by bahn              #+#    #+#             */
/*   Updated: 2021/07/20 21:11:11 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_3(t_frame *frame)
{
	if (frame->a != NULL && length(frame->a) == 3)
	{
		while (check_asc(frame->a) != 0)
		{
			if (frame->a->element == max(frame->a))
			{
				rotate(frame, 'A');
			}
			else if (last_element(frame->a)->element == min(frame->a))
				reverse_rotate(frame, 'A');
			else // (frame->a->element > frame->a->next->element)
				swap_a(frame);
		}
	}
	if (frame->b != NULL && length(frame->b) == 3)
	{
		while (check_desc(frame->b) != 0)
		{
			if (frame->b->element == min(frame->b))
				rotate(frame, 'B');
			else if (last_element(frame->b)->element == max(frame->b))
				reverse_rotate(frame, 'B');
			else // (frame->a->element > frame->a->next->element)
				swap_b(frame);
		}
	}
}

void	case_5(t_frame *frame)
{
	frame->pivot_a = median(frame->a, length(frame->a));
	while (check_asc(frame->a) != 0)
	{
		while (length(frame->a) != 3 && min(frame->a) != frame->pivot_a)
		{
			if (frame->a->element < frame->pivot_a)
				push_b(frame);
			else if (last_element(frame->a)->element < frame->pivot_a)
				reverse_rotate(frame, 'A');
			else 
				rotate(frame, 'A');
		}
		case_3(frame);
		while (frame->b != NULL)
		{
			if (check_desc(frame->b) != 0)
				swap_b(frame);
			else
				push_a(frame);
		}
		if (frame->a->element > frame->a->next->element)
			swap_a(frame);
	}
}

void	case_other(t_frame *frame)
{
	frame->pivot_a = median(frame->a, length(frame->a));
	frame->pivot_b = median(frame->a, length(frame->a) / 2);
	while (min(frame->a) != frame->pivot_a)
	{
		if (frame->a->element < frame->pivot_a)
		{
			push_b(frame);
			if (frame->b->element == min(frame->b))
				rotate(frame, 'B');
		}
		else if (last_element(frame->a)->element < frame->pivot_a)
			reverse_rotate(frame, 'A');
		else 
			rotate(frame, 'A');
		case_3(frame);
	}
	if (check_asc(frame->a) == 0)
	{
		while (frame->b != NULL)
		{
			push_a(frame);
			if (frame->a->element > frame->a->next->element)
				swap_a(frame);
		}
	}
	else
		case_other(frame);
}