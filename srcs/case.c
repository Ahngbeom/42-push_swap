/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bbu0704@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:02:38 by bahn              #+#    #+#             */
/*   Updated: 2021/08/06 14:58:05 by bahn             ###   ########.fr       */
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

void	after_div_restore(t_frame *frame, int ra, int rb)
{
	int 	ra_cnt;
	int		rb_cnt;

	ra_cnt = ra;
	rb_cnt = rb;
	while (ra_cnt > 0 || rb_cnt > 0)
	{
		if (ra_cnt > 0 && rb_cnt <= 0)
			reverse_rotate_a(frame);
		else if (rb_cnt > 0 && ra_cnt <= 0)
			reverse_rotate_b(frame);
		else
			reverse_rotate_r(frame);
		ra_cnt--;
		rb_cnt--;
	}
}

void	div_by_pivot_to_b(t_frame *frame)
{	
	int		ra_cnt;
	int		rb_cnt;

	ra_cnt = 0;
	rb_cnt = 0;
	if (length(frame->a) < 3)
	{
		if (swap_check(frame, frame->a) == TRUE)
			swap_a(frame);
		return ;
	}
	frame->pivot_a = select_pivot(frame->a, 2);
	if (length(frame->a) >= 5)
		frame->pivot_b = select_pivot(frame->a, 4);
	while (min(frame->a) != frame->pivot_a)
	{
		if (frame->pivot_a <= frame->a->element)
			ra_cnt += rotate_a(frame);
		else
			push_b(frame);
	}
	div_by_pivot_to_b(frame);
	div_by_pivot_to_a(frame);
}

void	div_by_pivot_to_a(t_frame *frame)
{
	while (frame->b != NULL)
	{
		if (swap_check(frame, frame->b) == TRUE)
			swap_b(frame);
		push_a(frame);
	}	
}