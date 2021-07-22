/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bbu0704@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:02:38 by bahn              #+#    #+#             */
/*   Updated: 2021/07/22 16:39:00 by bahn             ###   ########.fr       */
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
			{
				rotate_a(frame);
			}
			else if (last_element(frame->a)->element == min(frame->a))
				reverse_rotate_a(frame);
			else // (frame->a->element > frame->a->next->element)
				swap_a(frame);
		}
	}
	if (frame->b != NULL && length(frame->b) == 3)
	{
		while (check_desc(frame->b) != 0)
		{
			if (frame->b->element == min(frame->b))
				rotate_b(frame);
			else if (last_element(frame->b)->element == max(frame->b))
				reverse_rotate_b(frame);
			else // (frame->a->element > frame->a->next->element)
				swap_b(frame);
		}
	}
}

void	case_5(t_frame *frame)
{
	frame->pivot_a = median(frame->a, length(frame->a));
	while (check_asc(frame->a) == FALSE)
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
		while (frame->b != NULL)
		{
			if (check_desc(frame->b) != 0)
				swap_b(frame);
			else
				push_a(frame);
		}
		if (swap_check(frame, frame->a))
			swap_a(frame);
	}
}

void	case_other(t_frame *frame)
{
	int		count;

	frame->pivot_a = median(frame->a, length(frame->a));
	while (min(frame->a) != frame->pivot_a)
	{
		if (frame->a->element < frame->pivot_a)
		{
			if (swap_check(frame, frame->a))
				swap_a(frame);
			push_b(frame);
			if (check_desc(frame->b) != 0 && frame->pivot_b > frame->b->element)
				rotate_b(frame);
			else if (swap_check(frame, frame->b))
				swap_b(frame);
		}
		else if (last_element(frame->a)->element < frame->pivot_a)
			reverse_rotate_a(frame);
		else 
			rotate_a(frame);
		case_3(frame);
	}
	if (check_asc(frame->a) == TRUE)
	{
		while (frame->b != NULL)
		{	
			case_3(frame);
			if (swap_check(frame, frame->b))
				swap_b(frame);
				
			if (max(frame->b) == frame->b->element)
				push_a(frame);
			else
			{
				count = 0;
				while (max(frame->b) != frame->b->element)
				{
					reverse_rotate_b(frame);
					count++;
				}
				if (check_desc(frame->b) == FALSE)
				{
					while (count--)
						rotate_b(frame);
				}
			}
			
			if (swap_check(frame, frame->a))
				swap_a(frame);
		}
	}
	else
		case_other(frame);
}